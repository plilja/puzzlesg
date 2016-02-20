#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
    int p;
    cin >> p;
    while (p--) {
        int t;
        vector<int> v(12);
        cin >> t;
        for (int i = 0; i < 12; ++i) {
            cin >> v[i];
        }
        int r = 0;
        for (int i = 0; i < 12; ++i) {
            int h = v[i];
            int m = numeric_limits<int>::max();
            for (int j = i + 1; j < 11; ++j) {
                m = min(v[j], m);
                if (m <= h) {
                    break;
                }
                if (v[j + 1] < m) {
                    r++;
                }
            }
        }
        cout << t << " " << r << endl;
    }
}