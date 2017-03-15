#include <iostream>
#include <vector>
#include <bitset>
#include <map>

using namespace std;

int solve(bitset<23> board, map<int, int> &cache) {
    auto it = cache.find(board.to_ulong());
    if (it != cache.end()) {
        return it->second;
    }
    int ans = 0;
    for (int i = 0; i < 23; ++i) {
        ans += board[i];
    }

    for (int j = 0; j < 23; ++j) {
        if (j >= 2 && board[j] && board[j - 1] && !board[j - 2]) {
            bitset<23> new_board(board);
            new_board[j] = false;
            new_board[j - 1] = false;
            new_board[j - 2] = true;
            ans = min(ans, solve(new_board, cache));
        }
        if (j <= 20 && board[j] && board[j + 1] && !board[j + 2]) {
            bitset<23> new_board(board);
            new_board[j] = false;
            new_board[j + 1] = false;
            new_board[j + 2] = true;
            ans = min(ans, solve(new_board, cache));
        }
    }
    cache[board.to_ulong()] = ans;
    return ans;
}

int main()
{
    map<int, int> cache;
    int n;
    scanf("%d", &n);
    while (n--) {
        char s[30];
        scanf("%s", s);
        bitset<23> board(0);
        for (int i = 0; i < 23; ++i) {
            board[i] = s[i] == 'o';
        }
        printf("%d\n", solve(board, cache));
    }
}
