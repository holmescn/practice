#include <map>
#include <set>
#include <vector>
#include <string>
#include "has_key.h"

using namespace std;

int main(int argc, const char *argv[])
{
    map<int, int>    m1;
    map<string, int> m2;
    set<int>         s1;
    set<string>      s2;
    vector<int>      v1;
    vector<string>   v2;

    has_key(m1, 1);
    has_key(m2, "1");

    has_key(s1, 1);
    has_key(s2, "1");

    has_key(v1, 1);
    has_key(v2, "1");

    return 0;
}
