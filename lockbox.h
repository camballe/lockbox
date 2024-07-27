#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#define lockboxDecrypt(x, y) lockboxEncrypt(x, y)

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
struct s_lockbox
{
    int16 i, j, k;
    int8 s[256];
};

typedef struct s_lockbox Lockbox;

Lockbox *lockboxInit(int8 *, int16);
int8 lockboxByte(Lockbox *);
int8 *lockboxEncrypt(Lockbox *, int8 *, int16);