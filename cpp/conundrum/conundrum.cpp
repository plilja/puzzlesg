#include <iostream>
#include <cstring>

char TARGET[] = "PER";

int main()
{
    char text[302];
    scanf("%s", text);
    int n = strlen(text);
    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (text[i] != TARGET[i % 3])
            r++;
    }
    printf("%d\n", r);

}
