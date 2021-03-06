#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

#define ALPHABETSIZE 26

using namespace std;

vector<string> dominant(vector<string> input) {
    // Sort input by length
    map<pair<int, int>, string> m;
    for (int i = 0; i < input.size(); i++) {
        m[{-input[i].size(), i}] = input[i];
    }
    vector<string> input_by_len;
    for (auto &kv : m) {
        input_by_len.push_back(kv.second);
    }

    // Determine character count in input
    int n = input_by_len.size();
    vector<vector<int>> char_count(n, vector<int>(ALPHABETSIZE, 0));
    for (int i = 0; i < n; i++) {
        for (char c : input_by_len[i]) {
            int remap = c - 'a';
            char_count[i][remap]++;
        }
    }

    // Determine which string dominates which
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        bool dominated = false;
        for (int j = 0; j < i; j++) {
            if (input_by_len[i].size() == input_by_len[j].size()) {
                continue;
            }
            dominated = true;
            for (char c : input_by_len[i]) {
                int count1 = char_count[i][(int)(c - 'a')];
                int count2 = char_count[j][(int)(c - 'a')];
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
            ans.push_back(input_by_len[i]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<string> input;
    char str[20];
    while (1 == scanf("%s\n", str)) {
        input.push_back(str);
    }
    auto ans = dominant(input);
    for (string& s : ans) {
        printf("%s\n", s.c_str());
    }
}
