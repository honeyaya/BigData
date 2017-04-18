// 找两个子串的最大uncommon字串 
class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b) return 0;
        else return max(a.size(),b.size());
    }
};
