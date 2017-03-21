#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int n;
	while(cin >> n){
		vector<vector<int>> employee;
		vector<int> tmp; 
		for(int i = 0; i < n; i++){
			cin >> score >> managerId ;
			tmp.push_back(score);
			tmp.push_back(managerId);
			employee.push_back(tmp);		
		}
	
		
	}
	return 0;
}
