#include "lockbox.h"

#define F fflush(stdout)

int main(void);

// ef20 ac12

void printBinaryData(int8 *binaryData, const int16 size)
{
    int16 i;
    int8 *p;

    assert(size > 0);

    for (i = size, p = binaryData; i; i--, p++)
    {
        if (!(i % 2))
            printf(" ");
        printf("%.02x", *p);
    }

    printf("\n");

    return;
}

int main()
{
    Lockbox *lockbox;
    int16 keySize, textSize;
    char *key, *text, *encrypted, *decrypted;

    key = text = encrypted = decrypted = 0;
    text = key;

    keySize = textSize = 0;

    key = "f5db59d43f7adfbd48c22f7eba8ec7e06ef3ed55dc98b824c436a405f84fb7e23426d42f989b78f6fd2f20cc246ce5af4fbbc694fcff2000c1c0f05811bbc5acbfa2d2a928fca40255a6098bbc12a93af3c9546969b2e30e322ad1832d951203a474a0dc81f7a3c2b3af5c0ead42b968bba1c3f2cc6e9143c715c29eef7dee2034416b21e930a583732047f4010628f4bd152e4a4db72d65fa95b75e8e17fe43edb86b19c1d6a0a6ff96480a5a2c98b385090f2ec12a8eb52d992ef631f3fee7399699229d271ea268e5f6ce7235d1505a43d8e73c3e569b636f744cf31a60a92f6408d71e13155e071c99d5f7a26768b11ad3409a1b3dc28a80957937cc52a"; /* 8 bits - 2048 bits */
    keySize = strlen(key);
    text = "Dear Sarah,\n\nYour request for a transfer of $50,000 to account number 12345678 at Secure Bank has been processed. The transaction ID is TRX-987654321. Please allow 2-3 business days for the funds to appear in the destination account.\n\nFor security reasons, we'll need you to confirm this transaction by calling our verification hotline at 1-800-555-1234 within the next 24 hours. Please have your account number and the last 4 digits of your social security number ready.\n\nIf you did not initiate this transfer, please contact our fraud department immediately at 1-888-999-5678.\n\nBest regards,\nJohn Smith\nCustomer Service Representative\nGlobal Financial Services";
    textSize = strlen(text);

    printf("Initializing encryption...");
    F;
    lockbox = lockboxInit((int8 *)key, keySize);
    printf("done\n");

    printf("'%s'\n ->", text);
    // encrypted = lockboxEncrypt(text, textSize);

    printBinaryData(lockbox->s, keySize);

    return 0;
}