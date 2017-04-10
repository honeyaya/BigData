class Solution {
public:
    int maxSubArray(vector<int>& nums) {
  		int len = nums.size();
		
		if(len == 0) return 0;
		
		int sum = nums[0], tmp = nums[0];
		
		for(int i = 1; i < len; i++){
			if(tmp >= 0) {
				tmp += nums[i];
			} else{
				tmp = nums[i];
			}
			
			if(sum < tmp){
				sum = tmp;
			}
		}
		
		return sum;      
    }
};
