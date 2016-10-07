#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    char inp[1000003];
    char out[1000003];
    fgets(inp, 1000003, stdin);
    int i = 0;
    int j = 0;
    while (inp[i] != '\0') {
        if (inp[i] == '<') {
            j = max(0, j - 1);
        } else {
            out[j] = inp[i];
            j++;
        }
        i++;
    }
    out[j] = '\0';
    printf("%s", out);
}
