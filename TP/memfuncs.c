void *_memcpy(void *dest, const void * src, int n){
    char *cdest =(char *)dest;                      // Create a pointer to the destiny of the byte to be copied.
    const char *csrc = (const char *)src;           // Create a pointer to the byte of source to be copied.

    for (int i = 0; i < n; i++){                    // Iterate to copy each byte for all the necessary space.
        cdest[i] = csrc[i];
    }

    return dest;                                    
}

void *memmove(void *dest, const void *src, int n){
    char *cdest =(char *)dest;                      // Create a pointer to the destiny of pasting.
    const char *csrc = (const char *)src;           // Create a pointer to the byte of source to be copied.

    if (cdest < csrc) {
        cdest += n;
        csrc += n;
        while (n--) {
            *--cdest = *--csrc;
        }
    } else {
        while (n--) {
            *cdest++ = *csrc++;
        }
    }
    return dest;
}

void *memset(void *dest, int value, int n) {
    unsigned char *cdest = (unsigned char *)dest;
    unsigned char v = (unsigned char)value;

    for (int i = 0; i < n; i++) {
        cdest[i] = v;
    }

    return dest;
}

int memcmp_custom(const void *s1, const void *s2, int n) {
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;

    for (int i = 0; i < n; i++) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
    }

    return 0;
}