class RandomizedSet {
public:
	vector<int> vc;  // ���浱ǰ���ڵ�Ԫ�� 
	unordered_map <int,int> hash; //����Ԫ���Լ�����Ӧ��λ�� 
	
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    	    
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
    	if(hash.count(val)) 
			return false;
    	hash[val] = vc.size();
    	vc.push_back(val);
    		return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
    	if(hash.count(val) == 0) return false;
    	int pos = hash[val];
    	int num = vc.back();
    	hash[num] = pos;
    	swap(vc[pos],vc[vc.size()-1]);  // ɾ��Ԫ�ص�ʱ�������ṹ����Ҫ���� 
    	vc.pop_back();
    	hash.erase(val);
    	return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vc[rand()%vc.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
