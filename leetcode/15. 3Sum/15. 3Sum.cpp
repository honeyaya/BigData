// first sort then use two points methods 
// ps: the target can be duplicated

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int len = nums.size();
        
		vector<vector<int>> ans;
		vector<int> tmpans;
		
		
        if(len == 0) return ans;
        
		sort(nums.begin(),nums.end());
			
		for(int i = 0; i < len - 2 && nums[i] <= 0; i++){
		    if(i!=0 && nums[i] == nums[i - 1]) continue;    
			int target = -nums[i];
		
			int left = i + 1, right = len - 1;
			while(left < right){
				
					int tmp = nums[left] + nums[right];
					if(tmp < target) left++;
					else if(tmp > target) right--;
					else if(tmp == target) {
						tmpans.clear();
						tmpans.push_back(nums[left]);
						tmpans.push_back(nums[right]);
						tmpans.push_back(-target);
						ans.push_back(tmpans);
						while(left < len && nums[left] == nums[left + 1]) left++;
						while(right >=0  && nums[right] == nums[right - 1]) right--;
						left++;
						right--;
					}	 
			}
			
		}
		
		return ans;
    }
};
