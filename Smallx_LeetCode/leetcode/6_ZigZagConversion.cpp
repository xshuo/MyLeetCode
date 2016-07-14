#ifdef __6__
#include <iostream>
#include <string>
using std::string;
using std::cout;

class Solution {
private:
    static const int N = 1000;
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string temp[N];
        int row = 0;
        int flag;
        for (int i = 0; i < s.size(); i++) {
            if (row == 0)
                flag = 1;
            else if (row == numRows - 1)
                flag = -1;            
            temp[row] += s[i];
            row = row + flag;
        }
        string ret;
        for (int i = 0; i < numRows; i++)
            ret += temp[i];
        return ret;
    }
};

int main(int argc, char** args) {
}
#endif