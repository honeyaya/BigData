/*
Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

//  1. one number can be used once  //vis array 
	2. the answer can't be repeated eg: 1.2.4 is ok and 2.4.1 not ok compare the current number to the one.back()
	
*/
/*
Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
*/
class Solution {
private:
	vector<vector<int>> vc;
	vector<int> one;
	int vis[9];
public:
    vector<vector<int>> combinationSum3(int k, int n) {
    	if(k > 10 || k < 1 ||  n > 55) 
			return vc;
			
		one.clear();
		vc.clear();
		for(int i = 0; i < 9; i++)
			vis[i] = 0;
			
		dfs(1, 9, k, 0, n);
		
		return vc;	    
    }
    
    void dfs(int current, int n, int k, int sum, int target){
    	//cout << "current=" << current << " sum=" << sum << endl; 
		if(sum == target){
    		if(one.size() == k)
    			vc.push_back(one);
    		return ;
		}
		
		if(sum > target){
			return ;
		}
		
		
		for(int i = current; i <= n; i++){
		    
			if(!vis[i] && (one.size() == 0|| i>one.back())){
				vis[i] = 1;
				one.push_back(i);
				//cout << "current= " << current << " i=" << i << endl;
				dfs(current + 1, n , k, sum + i, target);
				one.pop_back();	
				vis[i] = 0;
			}
		}
	}
};



//-------------------------------------------------------------------------------

/*
Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
*/

class Solution {
private:
	vector<vector<int>> vc;
	vector<int> one;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
    	if(k > 10 || k < 1 ||  n > 55) 
			return vc;
			
		one.clear();
		vc.clear();
			
		dfs(1, k, 0, n);
		
		return vc;	    
    }
    
    void dfs(int current,  int k, int sum, int target){
    	if(k==0 && sum == target) {
    		vc.push_back(one);
    		return ;
		} 
		if(k < 0 || sum > target) {
			return ;
		}
		
		for(int i = current; i <= 9; i++){
			one.push_back(i);
			dfs(i  + 1, k - 1, sum + i, target);
			one.pop_back();
		}
	}
};
