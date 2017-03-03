int isPalindrome(char *s, int l, int r) {
    int m = (r - l) / 2;
    int ll = l + m, rr = r - m;
    while (ll >= l) {
        if (s[ll] == s[rr]) {
            ll -= 1;
            rr += 1;
        } else {
            return 0;
        }
    }
    return 1;
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    
    int l = 0, r = len - 1;
    
    char *rs = (char*)malloc(1); rs[0] = 0;
    int max_len = 0;

    while(r >= 0) {
        if (s[l] == s[r]) {
            int _len = (r - l) + 1;
            if (_len > max_len && isPalindrome(s, l, r)) {
                max_len = _len;
                rs = realloc(rs, max_len + 1);
                memcpy(rs, s + l, max_len);
                rs[max_len] = 0;
            } else {
                // Not
            }
        } else {
            // Not
        }
        
        if (max_len >= r) {
            break;
        }
        
        if (l < r && r - l + 1 > max_len) {
            l += 1;
        } else {
            l = 0;
            r -= 1;
        }
    }

    return rs;
}
