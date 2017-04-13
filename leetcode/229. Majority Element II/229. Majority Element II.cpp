// 找主元素 超过[n/3]的元素
// 最多出现2个
// 由于不确定，考虑进行检验 次数是否超过[len/3]
 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
  		int len = nums.size();
  		
  		
		if(len  == 0 || len == 1)
			return nums;
			
		vector<int> vc;
		int n = 0, m = 0;
		int cn = 0, cm = 0;
		
		for(int i  = 0; i < len; i++){
			if(nums[i] == m){
				m = nums[i];
				cm++;
			} else if(nums[i] == n){
				n = nums[i];
				cn++;
			} else {
				if(cm == 0) {
					m = nums[i];
					cm++;	
				} else if(cn == 0) {
					n = nums[i];
					cn++;	
				}else {
					cm--;
					cn--;	
				}
			}
		}
		
		cm = 0;
		cn = 0;
		for(int i = 0; i < len; i++){
			if(nums[i] == m) {
				cm++;
			}
			if(nums[i] == n){
				cn++;
			}
		}
		
		if(cm > (len/3)) {
			vc.push_back(m);
		}
		if(cn > (len/3) && n!=m){
			vc.push_back(n);
		}
		return vc;      
    }
};

//-----------------------------------------------------------------------

// 若出现[len/k] 的次数的元素


