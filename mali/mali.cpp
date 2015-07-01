#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> nums1(101, 0);
    vector<int> nums2(101, 0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        nums1[a]++;
        nums2[b]++;

        vector<int> nums1_copy = nums1;
        vector<int> nums2_copy = nums2;
        int r = 0;
        int j = 1;
        int k = 100;
        while (j <= 100 && k > 0) {
            while (nums1_copy[j] == 0 && j <= 100) ++j;
            while (nums2_copy[k] == 0 && k > 0) --k;
            if (j <= 100 && k > 0) {
                int num = min(nums1_copy[j], nums2_copy[k]);
                nums1_copy[j] -= num;
                nums2_copy[k] -= num;
                r = max(r, j + k);
            }
        }
        printf("%d\n", r);
    }
}
