#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
#include <map>
 
using namespace std;

int main(){
	int n,m;
	while(cin >> n >> m){
		int mindex = 0;
		int left = 1, right = n;
		int low = 1, high = n;
		
		while(left < right || low < high){
			 for(int i=left; i<=right; i++){
	            //cout<<a[low][i]<<" ";
	            mindex++;
	            if(mindex == m){
	            	cout << low << " "<<i << endl;
	            	break;
				}
	         }
	        low++;
	        
	        for(int i=low; i<=high; i++){
	            //cout<<a[i][right]<<" ";
	            mindex++;
	            if(mindex == m){
	            	cout << i << " "<<right << endl;
	            	break;
				}
	        }
	        right--;
	        
	        for(int i=right; i>=left; i--){
	            //cout<<a[high][i]<<" ";
	            mindex++;
	            if(mindex == m){
	            	cout << high <<" "<< i << endl;
	            	break;
				}
	        }
	        high--;
	        
	        for(int i=high; i>=low; i--){
	            //cout<<a[i][left]<<" ";
	            mindex++;
	            if(mindex == m){
	            	cout << i << " "<< left << endl;
	            	break;
				}
	        }
	        left++;        
		}
	}	
	return 0;
}

