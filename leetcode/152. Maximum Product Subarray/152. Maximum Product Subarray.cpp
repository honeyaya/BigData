// find the bigest product of the subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
  		int len = nums.size();
		  
		if(len == 0) return 0;
		
		vector<int> postive(len,0);
		vector<int> negtive(len,0);
		
		postive[0] = nums[0];
		negtive[0] = nums[0];
		
		for(int i = 1; i < len; i++){
			postive[i] = max(postive[i - 1] * nums[i] , max(negtive[i - 1] * nums[i] , nums[i]));
			negtive[i] = min(postive[i - 1] * nums[i] , min(negtive[i - 1] * nums[i] , nums[i]));
		}
		
		int ans = postive[0];
		
		for(int i = 0; i < len; i++){
		    ans = max(ans,postive[i]);
		    //cout << postive[i] << " " << negtive[i] << endl;
		}
		return ans;       
    }
};
