//2*3-4*5
/* 
	1 2 3
	
   (2 * 3) - 4 * 5 = -14   -- 1 3 2 
   ((2 * 3) - 4) * 5 = 10  -- 1 2 3
   (2 * (3 - 4)) * 5 = -10 -- 2 1 3
   2 * ((3 - 4) * 5) = -10 -- 2 3 1
   2 * (3 - (4 * 5)) = -34 -- 3 2 1
   
    (2*(3-(4*5))) = -34
	((2*3)-(4*5)) = -14
	((2*(3-4))*5) = -10
	(2*((3-4)*5)) = -10
	(((2*3)-4)*5) = 10
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

using namespace std;

class Solution {
	
public:
	bool isoperator(char c){
		if(c == '+' || c == '*' || c =='-')
			return true;
		return false;
	}
	
	vector<int> diffWaysToCompute(string input) {
  		vector<int> ans;
		if(input.size() == 0){
			return ans;
		} else{
			for(int i = 0; i < input.length(); i++){
				if(isoperator(input[i])){
					vector<int> l = diffWaysToCompute(input.substr(0,i));
					vector<int> r = diffWaysToCompute(input.substr(i+1));
					
					for(int j = 0; j < l.size(); j++){
						for(int k = 0; k < r.size(); k++){
							int a = l[j];
							int b = r[k];
							switch(input[i]){
								case '+':{
									ans.push_back(a+b);
									break;
								} 
								case '-':{
									ans.push_back(a-b);
									break;
								}
								case '*':{
									ans.push_back(a*b);
									break;
								}
							}
						}
					}
				}
			}
			if(ans.empty()){
				ans.push_back(atoi(input.c_str()));
			}
			return ans;
		}
    }
    
};

int main(){
	Solution so;
	string s;
	vector<int> vc;
	while(cin >> s){
		vc = so.diffWaysToCompute(s);
		for(int i = 0; i < vc.size(); i++){
			cout << vc[i] << " ";
		}
		cout << endl;
	}
}
