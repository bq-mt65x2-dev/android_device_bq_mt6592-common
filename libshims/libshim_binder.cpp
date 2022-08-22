#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// android::Parcel::writeString16(char16_t const*, unsigned int)
extern "C" void _ZN7android6Parcel13writeString16EPKDsj(void **str16P,
        uint16_t const *str, unsigned int len);

// android::Parcel::writeString16(unsigned short const*, unsigned int)
extern "C" void _ZN7android6Parcel13writeString16EPKtj(void **str16P,
        unsigned short const *str, unsigned int len) {
    _ZN7android6Parcel13writeString16EPKDsj(str16P, str, len);
}
