// 5 最长回文子串

// 未完：本题用动态规划的做法我尚未熟练
// 目前采用中心扩展法，即寻找回文“核”，寻找核两端相同的字符。
// 回文核是指相同的字符组成的字符串
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        int same_l = 0;
        int same_r = 0;
        int ans_l = 0;
        int ans_r = 0;
        int max_len = 1;
        int max_l = 0;
        int max_r = 0;
        int find_same_p = 0;
        for (int i = 1 ; i < length ; ++i)
        {
            find_same_p = i;
            while (find_same_p > 0 && s[find_same_p] == s[find_same_p - 1])
            {
                find_same_p -= 1;
            }
            same_l = find_same_p;
            find_same_p = i;
            while (find_same_p < length - 1 && s[find_same_p] == s[find_same_p + 1])
            {
                find_same_p += 1;
            }
            same_r = find_same_p;
            ans_l = same_l;
            ans_r = same_r;
            while ( ans_l > 0 && ans_r < length - 1 && s[ans_l - 1] == s[ans_r + 1])
            {
                ans_l -= 1;
                ans_r += 1;
            }
            if (ans_r - ans_l + 1 >= max_len)
            {
                max_len = ans_r - ans_l + 1;
                max_l = ans_l;
                max_r = ans_r;
            }
        }
        return s.substr(max_l,max_r - max_l + 1);
    }
};

int main(int argc, const char * argv[]) {

    Solution s1;
    string str = "bb";
    cout<<s1.longestPalindrome(str)<<endl;

}
