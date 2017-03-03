#include <stdio.h>
#include <stdlib.h>

typedef int bool;

#define true 1
#define false 0

struct Node {
    char c; // character, '.'
    char n; // '1', '*', 'e'
    struct Node* next;
};

#define NODE_SIZE (sizeof(struct Node))


struct Node* GenerateNFA(char *p) {
    struct Node *root = NULL;
    struct Node *node = NULL;

    while(*p != '\0') {
        char *ahead = p + 1;

        if (node == NULL) {
            node = (struct Node*)malloc(NODE_SIZE);
        } else {
            node->next = (struct Node*)malloc(NODE_SIZE);
            node = node->next;
        }
        node->next = NULL;

        if (root == NULL) root = node;

        node->c = *p;

        switch (*ahead) {
            case '\0':
                node->n = '1';
                p = ahead;
                break;
            case '*':
                node->n = '*';
                p = ahead + 1;
                break;
            default:
                node->n = '1';
                p = ahead;
                break;
        }
    }

    return root;
}

bool MatchNFA(int line, struct Node* nfa, char *s) {
    if (nfa == NULL) return *s == '\0';

    printf("%4d Node{ c = '%c', n = '%c' }, x = '%c' s='%s' \n", line, nfa->c, nfa->n, *s, s);

    if (nfa->c == *s || nfa->c == '.') {
        if (nfa->n == '1') {
            return MatchNFA(__LINE__, nfa->next, s+1);
        } else {
            if (*s == '\0') {
                return MatchNFA(__LINE__, nfa->next, s);
            } else if (MatchNFA(__LINE__, nfa, s+1)) {
                puts("match");
                return true;
            } else {
                return MatchNFA(__LINE__, nfa->next, s+1);
            }
        }
    } else {
        if (nfa->n == '*') {
            return MatchNFA(__LINE__, nfa->next, s);
        } else {
            puts("mismatch");
            return false;
        }
    }
}

bool isMatch(char* s, char* p) {
    if (*s == '\0' && *p == '\0') return true;
    if (*p == '\0') return false;

    struct Node *nfa = GenerateNFA(p);
    return MatchNFA(__LINE__, nfa, s);
}

int main(int argc, char** argv) {

    printf("%d %d\n", isMatch("aaa", "a*a"), true);
    printf("%d %d\n", isMatch("aa", "a"), false);
    printf("%d %d\n", isMatch("aa", ".*"), true);
    printf("%d %d\n", isMatch("aab", "c*a*b"), true);
    printf("%d %d\n", isMatch("ab", ".*c"), false);
    printf("%d %d\n", isMatch("a", "ab*"), true);
    printf("%d %d\n", isMatch("bbbba", ".*a*a"), true);

    return 0;
}
