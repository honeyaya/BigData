class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vc;
        map<string,vector<string>> mp;
        map<string,vector<string>>:: iterator iter;
		int len = strs.size();
        
        if(len == 0) return vc;
        
        string tmp;
        for(int i = 0; i < len; i++){
        	tmp = strs[i];
        	sort(tmp.begin(),tmp.end());
			//cout << "tmp=" << tmp << endl;
			iter = mp.find(tmp);
			if(iter == mp.end()){
				mp[tmp].push_back(strs[i]);
			}
			else{
				mp[tmp].push_back(strs[i]);
			}
		}
		
		for(iter = mp.begin(); iter != mp.end(); iter++){
			sort(iter->second.begin(),iter->second.end());
			vc.push_back(iter->second);
			/*for(int j = 0; j < iter->second.size(); j++){
				cout << iter->second[j] << " " ; 
			}
			cout << endl;
			*/
		}
		
		return vc;
    }
};
