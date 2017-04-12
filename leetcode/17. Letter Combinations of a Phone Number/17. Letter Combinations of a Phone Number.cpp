class Solution {
protected:
	vector<string> ans;
	string one;
public:
	void dfs(int pos, string digits,vector<string> vc){
		if(pos == digits.size()){
			if(one.size() == pos)
				ans.push_back(one);
			return ; 
		}
		
		for(int i = pos; i < (int)digits.size(); i++){
			
			if(digits[i] == '1' || digits[i] == '0')
				continue;
			int num = (int)digits[i] - '0'; 
			//cout << "num= " << num <<" str:" << vc[num - 2] << endl;
			for(int j = 0; j < (int)vc[num - 2].size();j++){
				one += vc[num-2][j];
				dfs(i + 1, digits,vc);
				one = one.substr(0,one.length() - 1);
			}
		}
	}
    vector<string> letterCombinations(string digits) {
  		int len = digits.size();
  		ans.clear();
  		if(len == 0) return ans;
		vector<string> vc;
		vc.push_back("abc");
		vc.push_back("def");
		vc.push_back("ghi");
		vc.push_back("jkl");
		vc.push_back("mno");
		vc.push_back("pqrs");
		vc.push_back("tuv");
		vc.push_back("wxyz");
		
		one.clear();
		dfs(0,digits,vc);
		
		return ans;     
    }
};
