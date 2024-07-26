#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#define lockboxDecrypt(x, y) lockboxEncrypt(x, y)

struct s_lockbox
{
    int x;
};

typedef struct s_lockbox Lockbox;
typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

Lockbox *lockboxInit(int8 *, int16);
int8 lockboxByte(void);
int8 *lockboxEncrypt(int8 *, int16);