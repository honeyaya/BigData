// backstracking 
// one number can be used many times

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> oneans;
	
public:
	void dfs(int current, int n, int tmpsum,int target,vector<int> candidates){
		
		if(tmpsum == target) {
			ans.push_back(oneans);
			return ;
		}
		else if(tmpsum > target) 
			return ;
			
		for(int i = current; i < n; i++){
			if(i!=current && candidates[i] == candidates[i-1]) continue;
			oneans.push_back(candidates[i]);
			dfs(i + 1, n, tmpsum + candidates[i], target, candidates);  // 下一次搜索的时候怎么修改层数 
			oneans.pop_back();	
		}
	}
	
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	int len = candidates.size();
		
		if(len == 0) return ans;
		
		sort(candidates.begin(), candidates.end());
		
		dfs(0, len, 0,target,candidates);
		
		return ans;    
    }
};
