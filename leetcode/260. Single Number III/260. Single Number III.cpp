class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int len = nums.size();
        int nxor = 0;
        vector<int> vc;
        for(int num:nums){
        	nxor ^= num;
		}
		
		int pos = 0;
		for(int i = 0; i < 32; i++){
			int st = 1 << i;
			if(nxor & st) {
				pos = i;
				break;
			}
		}
		
		int na = 0,nb = 0;
		for(int num:nums){
			int st = 1 << pos;
			if(num & st) {
				na ^= num;
			} else {
				nb ^= num;
			}
		}
		
		vc.push_back(na);
		vc.push_back(nb);
		
		return vc;
    }
};
