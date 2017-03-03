#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * convert(char *s, int numRows) {
    int strLen = strlen(s);
    char *t = (char *)malloc(strLen + 1);
    t[strLen] = 0;

    char *pp = t;
    for (int i = 0; i < numRows; i++) {
        int row = i;        
        int rowStep = 1;

        for (char *p = s + i; p < s + strLen; p++) {
            if (row == i) {
                *pp++ = *p;
            }

            if (numRows > 1 && (row + rowStep < 0 || row + rowStep >= numRows)) {
                rowStep = -rowStep;
            } else if (numRows == 1) {
                rowStep = 0;
            }

            row += rowStep;
        }
    }

    return t;
}

int main(int argc, char ** argv) {
    printf("%s\n%s\n", convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    printf("%s\n%s\n", convert("AB", 1), "AB");
    //printf("%s\n", convert("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.", 2));
    return 0; 
}