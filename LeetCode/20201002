/*
   Author: litang
   Description: 
   Since: 2020/10/02
          09:23:21
*/
class Solution {
public:
    int count = 0;
    unordered_set<char> s;
    int numJewelsInStones(string J, string S) {
        s.insert(J.begin(), J.end());
        for( auto i : S)
            if(s.count(i))
                count++;
        return count;
    }   
};
