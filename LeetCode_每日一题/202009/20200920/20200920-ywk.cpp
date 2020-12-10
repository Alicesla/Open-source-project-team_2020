#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string::size_type strLength = s.size();
        string::size_type count = 0;
        if (strLength == 0) return 0;
        int breakFlag = 0;
        int result = 1;
        int jFlag = 0;
        for (int i = 0; i < strLength ; ++i)
        {
            for (int j = jFlag+1; j < strLength;++j)
            {
                breakFlag = 0;
                count = s.substr(i,j-i).find(s[j]);
                if(count != string::npos)
                {
                    if (result < j-i)
                    {
                        result = j-i;
                    }
                    i += count;
                    breakFlag = 1;
                    jFlag = j;
                    break;
                }
            }
            if (breakFlag == 0)
            {
                result = result < (strLength-i) ? (strLength-i) : result;
                break;
            }
        }
        return result;
    }
};


            
       
int main(int argc, const char * argv[]) {
    Solution s1;
    string s = "yfsrsrpzuya";
    cout<<s1.lengthOfLongestSubstring(s)<<endl;

    return 0;
}
