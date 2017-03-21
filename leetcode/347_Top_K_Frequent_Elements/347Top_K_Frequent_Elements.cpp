// unorder_map && priority_queue µÄÑ§Ï°
 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> vc;
        
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;    
        }
        
        priority_queue<pair<int,int>> pq;
        
        for(auto it = mp.begin(); it != mp.end();  it++) {
            pq.push(make_pair(it->second,it->first));
            if(pq.size() > ((int)mp.size() - k)){
                vc.push_back(pq.top().second);
                pq.pop();
            }
        }
        
        return vc;
    }
};
