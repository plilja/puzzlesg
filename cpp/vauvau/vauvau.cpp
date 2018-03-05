#include <iostream>

using namespace std;

char out[][10] = { "none", "one", "both"};

bool barks(int a, int b, int minute) {
    int t = (minute - 1) / (a + b);
    return t * (a + b) + a > (minute - 1);
}

char* get_out(int a, int b, int c, int d, int minute) {
    int r = 0;
    if (barks(a, b, minute)) {
        r += 1;
    }
    if (barks(c, d, minute)) {
        r += 1;
    }
    return out[r];
}

int main() {
    int a, b, c, d, p, m, g;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    scanf("%d %d %d", &p, &m, &g);
    puts(get_out(a, b, c, d, p));
    puts(get_out(a, b, c, d, m));
    puts(get_out(a, b, c, d, g));
}
