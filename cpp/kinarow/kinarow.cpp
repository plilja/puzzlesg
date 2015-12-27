#include <iostream>
#include <vector>

using namespace std;

bool hasKInRow(vector<vector<char>> &board, int N, int M, int K, char p)
{
    for (int i = 0; i < N; ++i) {
        int leftright = 0;
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == p) {
                ++leftright;
            } else {
                leftright = 0;
            }
            if (leftright == K) {
                return true;
            }
        }
    }
    for (int i = 0; i < M; ++i) {
        int topdown = 0;
        for (int j = 0; j < N; ++j) {
            if (board[j][i] == p) {
                ++topdown;
            } else {
                topdown = 0;
            }
            if (topdown == K) {
                return true;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int rightdiag = 0;
            for (int h = 0; h < min(N - i, M - j); ++h) {
                if (board[i + h][j + h] == p) {
                    ++rightdiag;
                } else {
                    rightdiag = 0;
                }
                if (rightdiag == K) {
                    return true;
                }
            }
            int leftdiag = 0;
            for (int h = 0; h <= min(N - i - 1, j); ++h) {
                if (board[i + h][j - h] == p) {
                    ++leftdiag;
                } else {
                    leftdiag = 0;
                }
                if (leftdiag == K) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    int L;
    int H = 0;
    int G = 0;
    scanf("%d\n", &L);
    for (int _ = 0; _ < L; ++_) {
        int M, N, K;
        scanf("%d %d %d\n", &M, &N, &K);
        vector<vector<char>> board(N, vector<char>(M));
        for (int i = 0; i < N; ++i) {
            char row[202];
            fgets(row, 202, stdin);
            for (int j = 0; j < M; ++j) {
                board[i][j] = row[j];
            }
        }
        if (hasKInRow(board, N, M, K, 'x')) {
            ++H;
        } else if (hasKInRow(board, N, M, K, 'o')) {
            ++G;
        }
    }
    printf("%d:%d\n", H, G);
}
