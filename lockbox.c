#include "lockbox.h"

export Lockbox *lockboxInit(int8 *key, int16 size)
{
    int16 x;
    int8 temp1, temp2;
    Lockbox *p;
    int32 n;

    if (!(p = malloc(sizeof(struct s_lockbox))))
        assert_perror(errno);

    for (x = 0; x < 256; x++)
        p->s[x] = 0;

    p->i = p->j = p->k = 0;
    temp1 = temp2 = 0;

    for (p->i = 0; p->i < 256; p->i++)
        p->s[p->i] = p->i;

    for (p->i = 0; p->i < 256; p->i++)
    {
        temp1 = p->i % size;
        temp2 = p->j + p->s[p->i] + key[temp1];
        p->j = temp2 % 256;
        temp1 = p->s[p->i];
        temp2 = p->s[p->j];
        p->s[p->i] = temp2;
        p->s[p->j] = temp1;
    }

    p->i = p->j = 0;
    lockboxWhiteWash(n, p);

    return p;
};

int8 lockboxByte(Lockbox *p)
{
    int16 temp1, temp2;

    p->i = (p->i + 1) % 256;
    p->j = (p->j + p->s[p->i]) % 256;

    temp1 = p->s[p->i];
    temp2 = p->s[p->j];
    p->s[p->i] = temp2;
    p->s[p->j] = temp1;
    temp1 = (p->s[p->i] + p->s[p->j]) % 256;
    p->k = p->s[temp1];

    return p->k;
}

export int8 *lockboxEncrypt(Lockbox *p, int8 *normalText, int16 size)
{
    int8 *cipherText;
    int16 x;

    cipherText = (int8 *)malloc(size + 1);
    if (!cipherText)
        assert_perror(errno);

    for (x = 0; x < size; x++)
        cipherText[x] = normalText[x] ^ lockboxByte(p);

    return cipherText;
}