#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>

#define ALPHABETSIZE 26

using namespace std;

void dominant(vector<string> &ans, char input[15010][12], int nr_of_words)
{
    vector<vector<int>> char_count(nr_of_words, vector<int>(ALPHABETSIZE, 0));
    vector<vector<int>> used_chars(nr_of_words, vector<int>());
    vector<int> len(nr_of_words, 0);
    for (int i = 0; i < nr_of_words; i++) {
        len[i] = strlen(input[i]);
        set<char> tmp;
        for (int j = 0; j < len[i]; ++j) {
            char c = input[i][j];
            int remap = c - 'a';
            char_count[i][remap]++;
            tmp.insert(remap);
        }
        copy(tmp.begin(), tmp.end(), back_inserter(used_chars[i]));
    }
    for (int i = 0; i < nr_of_words; i++) {
        bool dominated = false;
        for (int j = 0; j < nr_of_words; j++) {
            if (len[i] >= len[j]) {
                continue;
            }
            dominated = true;
            for (int c : used_chars[i]) {
                int count1 = char_count[i][c];
                int count2 = char_count[j][c];
                if (count2 < count1) {
                    dominated = false;
                    break;
                }
            }
            if (dominated) {
                break;
            }
        }
        if (!dominated) {
            ans.push_back(input[i]);
        }
    }
    sort(ans.begin(), ans.end());
}

int main()
{
    char input[15010][12];
    int i = 0;
    while (1 == scanf("%s\n", input[i])) {
        i++;
    }
    vector<string> ans;
    dominant(ans, input, i);
    for (string& s : ans) {
        printf("%s\n", s.c_str());
    }
}
