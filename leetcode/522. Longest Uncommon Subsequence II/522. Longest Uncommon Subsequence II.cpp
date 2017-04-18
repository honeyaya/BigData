class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int len = strs.size();
        if(len == 0) return -1;
        
        map<string,int> mp;
        map<string,int> :: iterator iter;
        
        int maxlen = -1;
        for(int i = 0; i < len; i++){
        	int ll = (int) strs[i].size();
        	if(ll > maxlen) {
        		maxlen = ll;
			}
        	iter = mp.find(strs[i]);
			if(iter != mp.end()){
				mp[strs[i]]++;
			} else{
				mp[strs[i]] = 1;
			}
		}
		
		cout << "maxlen=" << maxlen << endl;
		
		for(iter=mp.begin(); iter!=mp.end(); iter++){
			if(iter->first.size() == maxlen && iter->second > 1) 
				return -1;
			//cout << iter->first << " " << iter->second << endl;	
		}
		
		return maxlen;
		
    }
};





