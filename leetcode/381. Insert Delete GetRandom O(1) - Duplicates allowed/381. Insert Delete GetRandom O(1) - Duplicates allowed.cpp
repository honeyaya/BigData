// 删除时候，位置的确定  

class RandomizedCollection {
public:
	vector<int> vc;
    map<int, priority_queue<int>> hash;

	
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
    	
		vc.push_back(val);
		hash[val].push(vc.size() - 1);
		return hash[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(hash.find(val) == hash.end()) return false;
        if(hash[val].empty()) return false;
        
        int idx = hash[val].top();
        
        hash[val].pop();
        
        if(vc.size() - 1 != idx){
        	int t = vc.back();
        	vc[idx] = t;
        	
        	hash[t].pop();
        	hash[t].push(idx);
		}
        vc.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
    	
        return vc[rand()%vc.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
