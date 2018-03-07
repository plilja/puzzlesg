#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        // Color bottom row
        cout << "5 1 5 6" << endl; 
        while (true) {
            int r1, c1, r2, c2;
            string resp;
            cin >> resp;
            if (resp == "GAME") {
                break;
            } else {
                assert(resp == "MOVE");
                cin >> r1 >> c1 >> r2 >> c2;
                r1 = min(r1, 4);
                r2 = min(r2, 4);
                // Mirror opponents move
                cout << 5 - r2 << " " << 7 - c2 << " " << 5 - r1 << " " << 7 - c1 << endl;
            }
        }
    }
}
