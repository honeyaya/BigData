class Solution {
public:
	struct TrieNode{
		TrieNode* next[2];
		TrieNode(){
			next[0] = next[1] = NULL;
		}
	};
	
	void buildTrie(TrieNode* &root, vector<int> nums){
		
		
		for(int num:nums){
			TrieNode* tmp = root;
			for(int i = 31; i >= 0; i--){
				int tag = (num & (1<<i)) > 0 ? 1 : 0;
				if(tmp->next[tag] == NULL){
					tmp->next[tag] = new TrieNode();
				}
				tmp = tmp->next[tag];
			}
		}
	}
	int maxxor(TrieNode* root, int num){
		TrieNode* tmp = root;
		int ans = 0;
		for(int i = 31; i >= 0; i--){
			int tag = (num & (1<<i))>0 ? 0 : 1;
			
			if(tmp->next[tag]!=NULL){
				ans = ans | (1 << i);
				tmp = tmp->next[tag];
			} else {
				tmp = tmp->next[1-tag];
			}
		}
		//cout << "num=" << num << " ans=" << ans <<endl;
		return ans;
	}
public:
    int findMaximumXOR(vector<int>& nums) {
    	TrieNode* root = new TrieNode();
		
		buildTrie(root,nums);
		
		int ans = -1;
		
		for(int num:nums){
			ans = max(ans,maxxor(root,num));
		}    
		
		return ans;
    }
};
