#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Data {
public:
    void change_word(string &s, int delta) {
        int freq = 0;
        if (wordToFreq.count(s) > 0) {
            freq = wordToFreq[s];
            wordToFreq.erase(s);
            freqToWord[freq].erase(s);
        }
        freq += delta;
        wordToFreq[s] = freq;
        freqToWord[freq].insert(s);
    }

    void add_word(string &s) {
        change_word(s, 1);
    }

    void delete_word(string &s) {
        change_word(s, -1);
    }

    vector<pair<string, int>> top(int n) {
        vector<pair<string, int>> r;
        for (auto it = freqToWord.rbegin(); r.size() < n && it != freqToWord.rend() && it->first > 0; ++it) {
            for (auto &d : it->second) {
                r.push_back({d, it->first});
            }
        }
        return r;
    }

    map<string, int> wordToFreq;
    map<int, set<string>> freqToWord;
};

int main() {
    string s;
    int day = 0;
    Data data;
    map<int, vector<string>> days;
    while (cin >> s) {
        if (s == "<text>") {
            day++;
            if (day >= 7) {
                for (auto &w : days[day - 7]) {
                    data.delete_word(w);
                }
            }
            days[day - 7].clear();
        } else if (s == "<top") {
            int n;
            cin >> n;
            cout << "<top " << n << ">" << endl;
            auto r = data.top(n);
            for (auto &p : r) {
                cout << p.first << " " << p.second << endl;
            }
            cout << "</top>" << endl;
        } else if (s.size() >= 4 && s != "</text>" && s != "/>") {
            data.add_word(s);
            days[day].push_back(s);
        }
    }
}
