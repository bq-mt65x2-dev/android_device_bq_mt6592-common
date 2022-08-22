#include <pthread.h>

#include <openssl/mem.h>
#include <openssl/ssl.h>

static pthread_mutex_t locks[] = {
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
};

#define CRYPTO_NUM_LOCKS 100
#define CRYPTO_LOCK     0x01
#define CRYPTO_UNLOCK   0x02
#define CRYPTO_READ     0x04
#define CRYPTO_WRITE    0x08

#define OPENSSL_CTRL_SET_MSG_CALLBACK_ARG   16
#define OPENSSL_CTRL_OPTIONS                32
#define OPENSSL_CTRL_MODE                   33
#define OPENSSL_CTRL_GET_READ_AHEAD         40
#define OPENSSL_CTRL_SET_READ_AHEAD         41
#define OPENSSL_CTRL_GET_MAX_CERT_LIST      50
#define OPENSSL_CTRL_SET_MAX_CERT_LIST      51
#define OPENSSL_CTRL_SET_MAX_SEND_FRAGMENT  52
#define OPENSSL_CTRL_GET_RI_SUPPORT         76
#define OPENSSL_CTRL_CLEAR_OPTIONS          77
#define OPENSSL_CTRL_CLEAR_MODE             78

extern "C" long SSL_ctrl(SSL *s, int cmd, long larg, void *parg) {
	long l;

	switch (cmd) {
		case OPENSSL_CTRL_GET_READ_AHEAD:
			return SSL_get_read_ahead(s);

		case OPENSSL_CTRL_SET_READ_AHEAD:
			l = SSL_get_read_ahead(s);
			SSL_set_read_ahead(s, (int)larg);
			return l;

		case OPENSSL_CTRL_SET_MSG_CALLBACK_ARG:
			SSL_set_msg_callback_arg(s, parg);
			return 1;

		case OPENSSL_CTRL_OPTIONS:
			return SSL_set_options(s, larg);

		case OPENSSL_CTRL_CLEAR_OPTIONS:
			return SSL_clear_options(s, larg);

		case OPENSSL_CTRL_MODE:
			return SSL_set_mode(s, larg);

		case OPENSSL_CTRL_CLEAR_MODE:
			return SSL_clear_mode(s, larg);

		case OPENSSL_CTRL_GET_MAX_CERT_LIST:
			return SSL_get_max_cert_list(s);

		case OPENSSL_CTRL_SET_MAX_CERT_LIST:
			l = SSL_get_max_cert_list(s);
			SSL_set_max_cert_list(s, larg);
			return l;

		case OPENSSL_CTRL_SET_MAX_SEND_FRAGMENT:
			if (larg < 512 || larg > SSL3_RT_MAX_PLAIN_LENGTH)
				return 0;
			SSL_set_max_send_fragment(s, larg);
			return 1;

		case OPENSSL_CTRL_GET_RI_SUPPORT:
                        return SSL_get_secure_renegotiation_support(s);

		default:
			return 0;
	}
}

extern "C" long SSL_CTX_ctrl(SSL *s, int cmd, long larg, void *parg) {
    return SSL_ctrl(s, cmd, larg, parg);
}

extern "C" void ENGINE_cleanup(void) {}

extern "C" void CONF_modules_unload(int p) {}

extern "C" {

#undef CRYPTO_malloc
#undef CRYPTO_realloc
#undef CRYPTO_free
#undef CRYPTO_lock

void *CRYPTO_malloc(size_t size) {
	return OPENSSL_malloc(size);
}

void *CRYPTO_realloc(void *ptr, size_t new_size) { 
	return OPENSSL_realloc(ptr, new_size);
}
void CRYPTO_free(void *ptr) { 
	return OPENSSL_free(ptr);
}

void CRYPTO_lock(int mode, int type, const char *file, int line)
{
	if (type < 0 || type >= CRYPTO_NUM_LOCKS)
		return;

	if (mode & CRYPTO_LOCK)
		(void) pthread_mutex_lock(&locks[type]);
	else if (mode & CRYPTO_UNLOCK)
		(void) pthread_mutex_unlock(&locks[type]);
}

int CRYPTO_add_lock(int *pointer, int amount, int type, const char *file, int line)
{
	int ret;

	CRYPTO_lock(CRYPTO_LOCK|CRYPTO_WRITE, type, file, line);
	ret = *pointer + amount;
	*pointer = ret;
	CRYPTO_lock(CRYPTO_UNLOCK|CRYPTO_WRITE, type, file, line);

	return (ret);
}

void OBJ_cleanup(void) {}

}
