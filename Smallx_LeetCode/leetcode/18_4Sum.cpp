#ifdef __18__
#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            for (int ii = i + 1; ii < nums.size(); ii++) {
                int t = target - nums[i] - nums[ii];
                for (int j = ii + 1, k = nums.size() - 1; j < k;) {
                    int tt = nums[j] + nums[k];
                    if (tt == t) {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[ii]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        ret.push_back(v);
                        v.clear();
                        while (j + 1 < k && nums[j + 1] == nums[j]) j++;
                        while (j < k - 1 && nums[k - 1] == nums[k]) k--;  
                        k--;
                        j++;
                    } else if (tt > t) {
                        k--;
                    } else if (tt < t) {
                        j++;
                    }
                }
                while (ii + 1 < nums.size() && nums[ii + 1] == nums[ii]) ii++;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return ret;
    }
};

int main (int argc, char** args) {
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(-1);
    v.push_back(0);
    v.push_back(-2);
    v.push_back(2);

    vector<vector<int>> vv = (new Solution())->fourSum(v, 0);

    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            printf("%d ", vv[i][j]);
        }
        printf("\n");
    }
    return 1;
}
#endif