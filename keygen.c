#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rand.h>

#define KEY_LENGTH 256 // 2048 bits

int generate_key(unsigned char *key, int key_length)
{
    if (RAND_bytes(key, key_length) != 1)
    {
        return -1; // Error in key generation
    }
    return 0; // Success
}

int main()
{
    unsigned char key[KEY_LENGTH];

    if (generate_key(key, KEY_LENGTH) != 0)
    {
        fprintf(stderr, "Error generating the key\n");
        return 1;
    }

    printf("Generated key (in hex):\n");
    for (int i = 0; i < KEY_LENGTH; i++)
    {
        printf("%02x", key[i]);
    }
    printf("\n");

    return 0;
}