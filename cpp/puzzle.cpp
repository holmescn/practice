#include <cstdio>

void run() {
    puts("Win");
}

int f () {
    // one line
    // less than 19 chars
    // Disallow: main run asm # & * # % / _ (
    // One semicolon
    return new char[0] - "";
}

int main (int argc, char ** argv) {
    printf("%d\n", f());
    printf("%d\n", f());
    if (f() != f()) {
        run();
    } else {
        puts("failed.");
    }
    return 0;
}
