#ifdef __49__
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> v;
        unordered_map<int, int> hash;
        int k = 0;
        for (int i = 0; i < strs.size(); ++i) {
            int len = strs[i].size();
            string tmp = strs[i];
            std::sort(tmp.begin(), tmp.end());
            int h = 0;
            for (int j = 0; j < len; ++j) {
                h = 31 * h + tmp[j];
            }
            auto p = hash.find(h);
            if (p == hash.end()) {
                v.push_back(strs[i]);
                ans.push_back(v);
                v.clear();
                hash[h] = k++;
            } else {
                ans[p->second].push_back(strs[i]);
            }
        }
        return ans;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int primeA[26] = {
            3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 107};
        int primea[26] = {
            109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251};
        vector<vector<string>> ans;
        vector<string> v;
        unordered_map<int, int> hash;
        int k = 0;
        for (int i = 0; i < strs.size(); ++i) {
            int len = strs[i].size();
            unsigned int h = 1;
            for (int j = 0; j < len; ++j) {
                h *= primeA[strs[i][j] - 'a'];
            }
            auto p = hash.find(h);
            if (p == hash.end()) {
                v.push_back(strs[i]);
                ans.push_back(v);
                v.clear();
                hash[h] = k++;
            } else {
                ans[p->second].push_back(strs[i]);
            }
        }
        return ans;
    }
};

int main(int argc, char** args) {
    vector<string> s;
    s.push_back("duh");
    s.push_back("ill");
    s.push_back("eat");
    s.push_back("tea");
    s.push_back("tan");
    s.push_back("ate");
    s.push_back("nat");
    s.push_back("bat");

    vector<vector<string>> ret = (new Solution())->groupAnagrams(s);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            std::cout << ret[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
#endif