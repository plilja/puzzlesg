#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

const int INF = 20001;

int maxStarsForRank(int rank) {
    if (rank >= 21 && rank <= 25) {
        return 2;
    } else if (rank >= 16 && rank <= 20) {
        return 3;
    } else if (rank >= 11 && rank <= 15) {
        return 4;
    } else if (rank >= 1 && rank <= 10) {
        return 5;
    } else {
        assert(rank == 0); // legend
        return INF;
    }
}

int main()
{
    char s[10005];
    scanf("%s", s);
    int n = strlen(s);
    int rank = 25;
    int stars = 0;
    int winStreak = 0;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c == 'W') {
            int starsGained = 1;
            winStreak++;
            if (winStreak >= 3 && rank >= 6 && rank <=25) {
                starsGained++;
            }
            for (int i = 0; i < starsGained; ++i) {
                if (stars == maxStarsForRank(rank)) {
                    rank--;
                    stars = 1;
                } else {
                    stars++;
                }
            }
        } else {
            assert(c == 'L');
            winStreak = 0;
            if (rank <= 20) {
                stars = stars - 1;
                if (stars < 0 && rank != 20 && rank != 0) {
                    rank++;
                    stars = maxStarsForRank(rank) - 1;
                }
                stars = max(stars, 0);
            }
        }
    }
    if (rank == 0) {
        puts("Legend");
    } else {
        printf("%d\n", rank);
    }
}
