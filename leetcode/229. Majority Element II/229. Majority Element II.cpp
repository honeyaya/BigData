// ����Ԫ�� ����[n/3]��Ԫ��
// ������2��
// ���ڲ�ȷ�������ǽ��м��� �����Ƿ񳬹�[len/3]
 
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

// ������[len/k] �Ĵ�����Ԫ��


