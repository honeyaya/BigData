// save the small gap between sum and target

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        
        sort(nums.begin(),nums.end());
        
        int delta = 100000, sum = 0; 
        for(int i = 0; i < len - 1; i++){
        	int itarget = target - nums[i];
        	
        	int left = i + 1, right = len - 1;
        	while(left < right){
        		int tmpsum = nums[left] + nums[right];
        		int tmp = abs(tmpsum - itarget);
        		if(delta > tmp) {
        			delta = tmp;
        			sum = nums[left] + nums[right] + nums[i];
				}
        		
        		if(tmpsum > itarget) right--;
        		else left++;
			}
		}
		
		return sum;
    }
};

// -4 -1 1 2    target = 1





