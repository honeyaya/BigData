// �������Ӵ������uncommon�ִ� 
class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b) return 0;
        else return max(a.size(),b.size());
    }
};
