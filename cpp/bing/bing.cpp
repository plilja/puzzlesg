#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int ALPH_SIZE = 'z' - 'a' + 1;

class Trie {
public:
    Trie() {
        transitions = new Trie *[ALPH_SIZE];
        for (int i = 0; i < ALPH_SIZE; ++i) {
            transitions[i] = 0;
        }
        count = 0;
    }

    Trie *addTransition(char to) {
        int idx = to - 'a';
        if (transitions[idx] == 0) {
            transitions[idx] = new Trie();
        }
        return transitions[idx];
    }

    Trie *getTransition(char to) {
        int idx = to - 'a';
        return transitions[idx];
    }

    ~Trie() {
        for (int i = 0; i < ALPH_SIZE; ++i) {
            if (transitions[i] != 0) {
                delete transitions[i];
            }
        }
        delete transitions;
    }

    Trie **transitions;
    int count;
};


int main() {
    int n;
    scanf("%d\n", &n);
    Trie trie;
    while (n--) {
        char s[35];
        scanf("%s\n", s);
        int l = strlen(s);
        Trie *t = &trie;
        for (int i = 0; i < l; ++i) {
            t->count++;
            t = t->addTransition(s[i]);
        }
        printf("%d\n", t->count);
        t->count++;
    }
}



