// find the number which appear just once
// 1th wa: the number maybe negtive
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        
        int ans = 0;
        for(int i = 0; i < 32; i++){
    		int st = 1 << i;
			int cnt = 0; 
        	for(int j = 0; j < len; j++){
        		if(nums[j] & st) cnt++;
			}
			if(cnt%3==1) ans |= st;
        }
        return ans;
    }
};
