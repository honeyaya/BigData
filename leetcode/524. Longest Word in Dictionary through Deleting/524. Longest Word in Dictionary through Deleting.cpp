class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end(),[](string a,string b){
        	if(a.length() == b.length()) return a < b;
        	return a.length() > b.length();
		});
        
        for(string str:d){
        	if(str.length() > s.length()) continue;
        	int index = 0;
        	for(char c:s){
        		if(c == str[index]) index++;
			}
			if(index==str.length()) return str;
		}
		return "";
    }
};
