#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> read_inp(int num)
{
    vector<int> r(num);
    for (int i = 0; i < num; ++i) {
        scanf("%d", &r[i]);
    }
    return r;
}

int main()
{
    int n, m;
    while (true) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0)
            break;
        vector<int> heads = read_inp(n);
        vector<int> knights = read_inp(m);
        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());

        int i = 0;
        int j = 0;
        int cost = 0;
        while (i < (int)heads.size() && j < (int)knights.size()) {
            int head = heads[i];
            int knight = knights[j];

            if (head <= knight) {
                cost += knight;
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i >= (int)heads.size()) {
            printf("%d\n", cost);
        } else {
            printf("Loowater is doomed!\n");
        }
    }
}
