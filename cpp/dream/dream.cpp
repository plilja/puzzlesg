#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cassert>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<string, int> events_to_order;
    vector<string> events;
    int head = 0;
    while (n--) {
        char c[5];
        scanf("%s", c);
        switch (c[0]) {
            case 'E': {
                char e[25];
                scanf("%s", e);
                events_to_order[e] = head;
                events.push_back(e);
                head++;
                break;
            }
            case 'D': {
                int r;
                scanf("%d", &r);
                while (r--) {
                    head--;
                    string &e = events[head];
                    events_to_order.erase(e);
                    events.pop_back();
                }
                break;
            }
            case 'S': {
                int k;
                scanf("%d", &k);
                int right = head;
                int left = -1;
                bool plot_error = false;
                while (k--) {
                    char e_[25];
                    scanf("%s", e_);
                    string e = e_;
                    if (e[0] == '!') {
                        string event = e.substr(1, e.size() - 1);
                        auto h = events_to_order.find(event);
                        if (h != events_to_order.end()) {
                            right = min(right, h->second);
                        }
                    } else {
                        auto h = events_to_order.find(e);
                        if (h == events_to_order.end()) {
                            plot_error = true;
                        } else {
                            left = max(left, h->second);
                        }
                    }
                }
                if (plot_error || left >= right) {
                    printf("Plot Error\n");
                } else {
                    if (right == head) {
                        printf("Yes\n");
                    } else {
                        printf("%d Just A Dream\n", head - right);
                    }
                }
                break;
            }
            default: {
                assert(false); // Unknown type of command
                break;
            }
        }
    }
}
