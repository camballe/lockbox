#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#define MS 500
#define export __attribute__((visibility("default")))
#define lockboxDecrypt(x, y, z) lockboxEncrypt(x, y, z)
#define lockboxUninit(x) free(x)
#define lockboxWhiteWash(x, y)           \
    for (x = 0; x < (MS * 1000000); x++) \
        (volatile int8) lockboxByte(y);

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
struct s_lockbox
{
    int16 i, j, k;
    int8 s[256];
};

typedef struct s_lockbox Lockbox;

export Lockbox *lockboxInit(int8 *, int16);
int8 lockboxByte(Lockbox *);
export int8 *lockboxEncrypt(Lockbox *, int8 *, int16);