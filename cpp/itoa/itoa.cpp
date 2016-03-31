#include <cstdio>
#include "itoa.h"

char *itoa_1(int x, char *out) {
    int ndigits = 1;

    out[0] = 0; out[1] = 0;

    while (x > 0) {
        int digit = x % 10;
        out[ndigits-1] = digit;
        x = x / 10;
        ndigits += 1;
    }

    if (ndigits > 1) {
        out[--ndigits] = 0;
    }

    for (int i = 0, j = ndigits - 1; i < (ndigits + 1)/ 2; i++, j--) {
        char t = out[i];
        out[i] = out[j] + '0';
        out[j] = t + '0';
    }

    return out;
}

void debug(const char *message, char *seq) {
    printf("%s\n", message);
    for (int i = 0; i < 32; i++) {
        printf("%d ", seq[i]);
    }
    printf("\n");
}

char *itoa_2(int x, char *out) {
    char pow2[32] = {0};
    int ndigits = 1;
    bool carry = false;

    pow2[0] = 1;

    out[0] = 0; out[1] = 0;

    //printf("start x = %d\n", x);
    //debug("start out", out);

    while (x > 0) {
        //printf("x = %d\n", x);
        //debug("out", out);
        //debug("pow2", pow2);

        if (x & 1) {
            carry = false;
            for (int i = 0; i < ndigits; i++) {
                out[i] = out[i] + pow2[i] + (carry ? 1 : 0);
                carry = out[i] >= 10;
                out[i] -= (carry ? 10 : 0);
            }

            if (carry) {
                out[ndigits++] = 1;
            }
        }
        x = x >> 1;

        carry = false;
        for (int i = 0; i < ndigits; i++) {
            pow2[i] = pow2[i] * 2 + (carry ? 1 : 0);
            carry = pow2[i] >= 10;
            pow2[i] -= (carry ? 10 : 0);
        }
        if (carry) {
            pow2[ndigits++] = 1;
        }
    }
    out[ndigits] = 0;

    // debug("final out", out);

    for (int i = 0, j = ndigits - 1; i < (ndigits + 1) / 2; i++, j--) {
        char t = out[i];
        out[i] = out[j] + '0';
        out[j] = t + '0';
    }

    return out;
}
