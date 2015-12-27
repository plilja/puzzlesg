#include <iostream>
#include <stack>

using namespace std;

bool is_even(int d)
{
    return d % 2 == 0;
}

int main()
{
    int n;
    while (1 == scanf("%d", &n)) {
        stack<int> cards;
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            int b = cards.empty() ? a + 1 : cards.top();
            if (is_even(a + b)) {
                cards.pop();
            } else {
                cards.push(a);
            }
        }
        printf("%lu\n", cards.size());
    }
}
