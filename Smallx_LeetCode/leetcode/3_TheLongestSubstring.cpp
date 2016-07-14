#ifdef __3__
#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_l = 0;
        int visit[128];        
        memset(visit, 0xffff, sizeof(visit));
        int cnt = 0;

        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (visit[s[i]] == -1) {
                cnt++;
                visit[s[i]] = i;
            } else {
                if (cnt > max_l)
                    max_l = cnt;
                i = visit[s[i]] - 1;
                cnt = 0;
                memset(visit, 0xffff, sizeof(visit));
            }
        }
        if (cnt > max_l)
            max_l = cnt;
        return max_l;
    }
};

int lengthOfLongestSubstring(char* s) {
    int max_l = 0;
    int cnt = 0;

    int visit[128];        
    memset(visit, 0xffff, sizeof(visit));

    int size = strlen(s);
    for (int i = 0; i < size; i++) {
        if (visit[s[i]] == -1) {
            cnt++;
            visit[s[i]] = i;
        } else {
            if (cnt > max_l)
                max_l = cnt;
            i = visit[s[i]];
            cnt = 0;
            memset(visit, 0xffff, sizeof(visit));
        }
    }
    if (cnt > max_l)
        max_l = cnt;
    return max_l;    
}

int main(int argc, char** args) {
    string s = "c";
    
    int res = (new Solution())->lengthOfLongestSubstring(s);
    printf("%d\n", res);
    return 1;
}
#endif