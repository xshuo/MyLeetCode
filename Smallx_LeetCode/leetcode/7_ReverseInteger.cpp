#ifdef __7__

#include <iostream>
#include <string>
#include <climits>
using std::string;
using std::cout;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return x;
        int flag = x < 0 ? true : false;
        long long tempx = x;
        if (flag) tempx = -tempx;
        int num[15], len = 0;
        while (tempx) {
            num[len++] = tempx % 10;
            tempx = tempx / 10;
        }
        long long ret = 0;
        for (int i = 0; i < len - 1; i++) {
            ret = (ret + num[i]) * 10;
        }
        ret += num[len - 1];
        if (ret > INT_MAX)
            return 0;
        return flag ? -ret : ret;
    }
};

//best solution
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};

int main(int argc, char** args) {
    cout << ((new Solution())->reverse(-2147483648)) << std::endl;
    return 0;
}
#endif