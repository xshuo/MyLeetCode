#ifdef __30__
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>

using std::string;
using std::vector;
using std::set;
using std::multiset;
using std::unordered_multiset;
using std::unordered_map;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        int wlen = words[0].size();
        int wcnt = words.size();
        unordered_map<string, int> dict;
        for (int i = 0; i < wcnt; ++i) {
            dict[words[i]]++;
        }
        for (int i = 0; i + wlen <= s.size(); ++i) {
            unordered_map<string, int> check;
            int j;
            for (j = 0; j < wcnt; ++j) {
                string sub = s.substr(i + j * wlen, wlen);
                if (dict.find(sub) != dict.end()) {
                    check[sub]++;
                    if (check[sub] > dict[sub])
                        break;
                } else break;
            }
            if (j == wcnt)
                ret.push_back(i);
        }
        return ret;
    }

    vector<int> findSubstring2(string s, vector<string>& words) {
        set<int> ans;
        int visit[10];
        memset(visit, 0, sizeof(visit));
        findSubstringImpl2(ans, s, words, visit, "", 0);
        return vector<int>(ans.begin(), ans.end());
    }

    void findSubstringImpl2(set<int>& ans, string s, vector<string>& words, int visit[], string sub, int cnt) {
        if (cnt == words.size()) {
            int index = s.find(sub, 0);
            while (index != std::string::npos) {
                ans.insert(index);

                index = s.find(sub, index + 1);
            }
            return;
        }
        for (int i = 0; i < words.size(); i++) {
            if (!visit[i]) {
                visit[i] = 1;               
                findSubstringImpl2(ans, s, words, visit, sub + words[i], cnt + 1);
                visit[i] = 0;
            }
        }
    }
};

int main(int argc, char** args) {
    vector<string> w;
    w.push_back("word");
    w.push_back("good");
    w.push_back("best");
    w.push_back("good");
    vector<int> ans = (new Solution())->findSubstring("wordgoodgoodgoodbestword", w);
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 1;
}

#endif