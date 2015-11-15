#include <iostream>
#include <cstring>

using namespace std;

char _switch(char c)
{
    if (c == '#')
        return '.';
    else
        return '#';
}

int main()
{
    bool first = true;
    while (true) {
        int n;
        scanf("%d\n", &n);
        if (n == 0)
            break;
        if (!first)
            puts("");
        first = false;
        bool valid = true;
        int line_length = -1;
        for (int i = 0; i < n; ++i) {
            char c;
            scanf("%c", &c);
            int s = 0;
            char line[1000];
            fgets(line, 1000, stdin);
            char *tok = strtok(line, " ");
            while (tok != NULL) {
                int t = stoi(tok);
                for (int j = 0; j < t; ++j) {
                    printf("%c", c);
                }
                s += t;
                tok = strtok(NULL, " ");
                c = _switch(c);
            }
            puts("");
            if (line_length == -1)
                line_length = s;
            else {
                valid = valid && (line_length == s);
            }
        }
        if (!valid) {
            puts("Error decoding image");
        }

    }
}
