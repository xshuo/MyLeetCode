#ifdef __8__
#include <iostream>
#include <string>
#include <climits>
using std::string;
using std::cout;

class Solution {
public:
    int myAtoi(string str) {
        string temp;
        int i, j, k;
        int flag = 1;
        i = 0;
        j = str.size() - 1;
        while (i < str.size() && str[i] == ' ') i++;
        while (j >= 0 && str[j] == ' ') j--;
        if (i < str.size() && str[i] == '+') i++;
        else if(i < str.size() && str[i] == '-') {
            flag = -1;
            i++;
        }

        for (k = i; k <= j; k++) {
            if (!('0' <= str[k] && str[k] <= '9'))
                break;
        }
        temp = str.substr(i, k - i);
        if (temp.size() == 0)
            return 0;

        long long ret = 0;
        i = 0;
        while (i < temp.size()) {
            ret = ret * 10 + (temp[i] - '0');
            if (flag * ret < INT_MIN)
                return INT_MIN;
            else if (flag * ret > INT_MAX)
                return INT_MAX;
            i++;
        }
        ret = flag * ret;
        return ret;
    }
};

int main(int argc, char** args) {
    cout << ((new Solution())->myAtoi("214748364892838992246666666666777")) << std::endl;
    cout << atoi("2147483648") << std::endl;
    return 0;
}
#endif