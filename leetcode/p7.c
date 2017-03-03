#include <stdio.h>
#include <string.h>

int reverse(int x) {
    char str[32] = {0};
    int t = x > 0 ? x : -x;
    int sign = x > 0 ? 1 : -1;
    int index = 0;
    
    for(index = 0; index < 32; index++) {
        if (t > 0) {
            str[index] = t % 10 + '0';
            t = t / 10;
        } else {
            break;
        }
    }
    
    t = 0;
    for(int i = 0; i < index; i++) {
        t = t * 10;
        t += str[i] - '0';
    }

    if (index == 10 && cmp(str, "2147483641") > 0) {
        return 0;
    } else {
        return t * sign;
    }
}

int main(int argc, char** argv) {
    reverse(1534236469);
    return 0;
}
