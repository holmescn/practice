int lengthOfLongestSubstring(char* s) {
    int slen = strlen(s);
    char *ss = (char*)malloc(slen);
    int max_sslen = 0;
    for (int i = 0; i < slen; ++i) {
        int sslen = 0;
        memset(ss, 0, slen);
        for (int j = i; j < slen; ++j) {
            if (strchr(ss, s[j]) == NULL) {
                ss[sslen] = s[j];
                sslen += 1;
            } else {
                break;
            }
        }
        if (sslen > max_sslen) {
            max_sslen = sslen;
        }
    }

    return max_sslen;
}
