//93,227,273,385,537,539,556

class Solution {
private:
	vector<string> ans;
	//vector<string> list;
	string ip;
	
public:
	bool valid(string s,int start,int end){
		string tmp = s.substr(start, end - start + 1);
		int num = atoi(tmp.c_str());
		if(s[start] == '0' && start != end) return false;
		if(num >= 0 && num < 256) return true;
		return false;
		
	}
	void dfs(int pos, int part, string s){
		if(pos == s.length() && part == 4) {
			ans.push_back(ip);
			return ;
		}
		
		for(int i = pos; i < s.length(); i++){
			if(part < 4 && i - pos < 3 && valid(s,pos,i)){
				ip += s.substr(pos, i - pos + 1);
				part++;
				if(part < 4)
					ip += ".";
				
				dfs(i + 1, part,s);
				
				if(part < 4) 
					ip.pop_back();
				part--;
				for(int j = 0; j < i - pos + 1; j++){
					ip.pop_back();
				}
			}
		}
	}
	
    vector<string> restoreIpAddresses(string s) {
    	int len = s.length();
		
		if(len < 4 || len > 12) return ans;
		
		dfs(0,0,s);
		
		return ans;    
    }
};
