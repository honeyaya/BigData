#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class Solution {
public:
	bool iszero(double x){
		if(abs(x) <= 0.0000001)
			return true;
		else 
			return false;
	}
	
	double power(double x, long long n){
		if(n == 1) return x;
		double tmp = power(x , n / 2);
		if(n % 2)
			return x * tmp * tmp;
		else 
			return tmp * tmp;
	}
	
    double myPow(double x, int n) {
    	n = (long long) n;
        if(n == 0) 
        	return 1;
        if(iszero(x)) 
        	return 0;
        else{
        	if(n > 0)
        		return power(x,n);
        	else
        		return 1/power(x,-n);
		}
    }
};

int main(){
	Solution s;
	cout << s.myPow(2,4) << endl;
	return 0;
}
