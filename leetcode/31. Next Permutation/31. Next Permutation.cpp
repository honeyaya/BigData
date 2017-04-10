class Solution {
public:
    void nextPermutation(vector<int>& nums) {
  		int len = nums.size();
		  
		if(len < 2) return ;
		
		int i = len - 2, j = len - 1;
		while(i >= 0 && nums[i]>=nums[i+1]) i--;
		
		while(j >= 0 && nums[j]<=nums[i]) j--;
		
		swap(nums[i],nums[j]);
		
		reverse(nums.begin() + i + 1, nums.end());      
    }
};
