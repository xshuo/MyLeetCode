#ifdef __9__
#include <iostream>
#include <string>
#include <climits>
using std::string;
using std::cout;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        return isPalindromes(x, 10);
    }

    void myitoa(long long num, char buf[], int b) {
        int t_buf[65];
        int cnt = 0;
        int i, j;
        while (1) {
            if (num == 0)
                break;
            t_buf[cnt++] = num % b;
            num = num / b;
        }
        for (i = cnt - 1, j = 0; i >= 0; i--, j++) {
           if (t_buf[i] > 9)
               buf[j] = (t_buf[i] - 10) + 'A';
           else
               buf[j] = (t_buf[i] - 0) + '0';
        }
        buf[j] = '\0';
        //cout << num << " " << buf << endl;
    }

    bool isPalindromes(long long num, int base) {
        char buffer[50];
        myitoa(num, buffer, base);
        int len = strlen(buffer);
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            if (buffer[i] != buffer[j])
                return false;
        }
        return true;
    }
};

int main(int argc, char** args) {
    cout << ((new Solution())->isPalindrome(-2147447412)) << std::endl;
    return 0;
}
#endif