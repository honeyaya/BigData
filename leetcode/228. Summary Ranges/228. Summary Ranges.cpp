class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vc;
        int len = nums.size();
        if(len == 0) return vc;
        
        int first = nums[0];
        string tmp;
        
        for(int i = 0; i < len ; i++){
			if(i == len - 1 || nums[i+1]-nums[i] != 1 ){
				int end = nums[i];
				if(first != end)
					tmp = to_string(first) + "->" + to_string(end);
				else 
					tmp = to_string(first);
				vc.push_back(tmp);
				if(i!=(len - 1))
					first = nums[i + 1];
			}
			
		}
		
		return vc;
    }
};
