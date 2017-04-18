class Solution {
public:
    string reverseWords(string s) {
  		int len = s.length();
		if(len == 0) return s;
		
		string ans = "";
		string one = "";
		for(int i = 0; i < len; i++){
			if(s[i] ==  ' '){
				reverse(one.begin(),one.end());
				ans += one + " ";
				one.clear();
			} else {
				one += s[i];
			}
		}
		if(s[0] != ' '){
			reverse(one.begin(),one.end());
			ans += one;      	
		}
		
		return ans;
    }
};
