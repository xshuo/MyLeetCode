#ifdef __76__
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

//refer the discuss board...:(:(:( O(n) is not easy.
class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, end = 0, count = t.size();
        int diff[128] = {0};
        for (int i = 0; i < count; ++i)
            diff[t[i]]++;
        int minLen = INT_MAX, retStart = 0;
        while (end < s.size()) {
            if (diff[s[end++]]-- > 0) count--;
            while (count == 0) {
                if (end - start < minLen) {
                    retStart = start;
                    minLen = end - start;
                }
                if (diff[s[start++]]++ == 0)
                    count++;
            }
        }
        if (minLen == INT_MAX)
            return "";
        else return s.substr(retStart, minLen);
    }
};

int main(int argc, char** args) {
    std::cout << (new Solution())->minWindow("ADOBECODEBANC", "ABC") << std::endl;
    return 0;
}

#endif