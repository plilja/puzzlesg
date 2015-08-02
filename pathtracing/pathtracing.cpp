#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<vector<char>> initMap(int height, int width)
{
    vector<vector<char>> map(height, vector<char>(width, ' '));
    for (int i = 0; i < (int)map.size(); ++i) {
        map[i][0] = '#';
        map[i][map[i].size() - 1] = '#';
    }
    for (int i = 0; i < (int)map[0].size(); ++i) {
        map[0][i] = '#';
        map[map.size() - 1][i] = '#';
    }
    return map;
}

int main()
{
    vector<char> moves;
    char move[10];
    while (1 == scanf("%s", move)) {
        moves.push_back(move[0]);
    }
    int top = 0, bottom = 0, leftmost = 0, righmost = 0;
    int vertical = 0, horizontal = 0;
    for (char m : moves) {
        if (m == 'd') {
            vertical++;
        } else if (m == 'u') {
            vertical--;
        } else if (m == 'l') {
            horizontal--;
        } else {
            assert(m == 'r');
            horizontal++;
        }
        leftmost = min(leftmost, horizontal);
        righmost = max(righmost, horizontal);
        top = min(top, vertical);
        bottom = max(bottom, vertical);
    }
    vector<vector<char>> map = initMap(bottom - top + 3, righmost - leftmost + 3);
    int x = -leftmost + 1;
    int y = -top + 1;
    map[y][x] = 'S';
    for (char m : moves) {
        if (m == 'd') {
            y++;
        } else if (m == 'u') {
            y--;
        } else if (m == 'l') {
            x--;
        } else {
            assert(m == 'r');
            x++;
        }
        map[y][x] = '*';
    }
    map[y][x] = 'E';
    for (int i = 0; i < (int)map.size(); ++i) {
        for (int j = 0; j < (int)map[i].size(); ++j) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
