#ifdef __15__
#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());

        int target = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (target == -nums[i])
                continue;
            target = -nums[i];

            int targetj = INT_MAX, targetk = INT_MAX;
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                int tt = nums[j] + nums[k];
                if (tt == target) {
                    if (targetj == nums[j] && targetk == nums[k]) {
                        k--, j++;
                        continue;
                    }
                    targetj = nums[j];
                    targetk = nums[k];
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    ret.push_back(v);
                    v.clear();
                    k--;
                    j++;
                } else if (tt > target) {
                    k--;
                } else if (tt < target) {
                    j++;
                }
            }
        }
        return ret;
    }
};

int main (int argc, char** args) {
    vector<int> v;
    v.push_back(3);
    v.push_back(0);
    v.push_back(-2);
    v.push_back(-1);
    v.push_back(1);
    v.push_back(2);

    vector<vector<int>> vv = (new Solution())->threeSum(v);

    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            printf("%d ", vv[i][j]);
        }
        printf("\n");
    }
    return 1;
}
#endif