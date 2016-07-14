#ifdef __1__
#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::multimap;
using std::pair;

class Solution {
public:
    typedef multimap<int, int>::iterator map_pointer;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        multimap<int, int> nums_map;
        for (int i = 0; i < nums.size(); ++i) {
            nums_map.insert(pair<int, int>(nums[i], i));
        }
        for (int i = 0; i < nums.size(); ++i) {
            int second = target - nums[i];
            pair<map_pointer, map_pointer> equal_range;
            equal_range = nums_map.equal_range(nums[i]);
            for (map_pointer p = equal_range.first; p != equal_range.second; ++p) {
                if (p->second == i) {
                    nums_map.erase(p);
                    break;
                }
            }
            multimap<int, int>::iterator it = nums_map.find(second);
            if (it != nums_map.end()) {
                result.push_back(i);
                result.push_back(it->second);
                break;
            }
        }
        return result;
    }
};

int main(int argc, char** args) {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(3);
    
    vector<int> res = (new Solution())->twoSum(nums, 6);
    for (int i = 0; i < 2; i++) {
        printf("%d\n", res[i]);
    }
}
#endif