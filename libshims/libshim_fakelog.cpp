#include <log/log.h>

struct xlog_record {
	const char *tag_str;
	const char *fmt_str;
	int prio;
};

extern "C" int __android_stfuprint(int prio, const char* tag, const char* fmt, ...) {
    return 0;
}

extern "C" int __xlog_stfuprintf(int bufid, const struct xlog_record *rec, ...) {
    return 0;
}
