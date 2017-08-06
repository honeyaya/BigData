#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main(){
	int n[4];
	int k,d;
	while(cin >> n[0] >> n[1] >> n[2] >> n[3]){
		cin >> k >> d;
		
		int ans = 0;
		for(int x = 1; x <= 6; x++){
			for(int y = x; y <= 6; y++){
				int c = (x + y) % 4;
				int s = min(x , y) + 1;
				
				int loop = 0;
				while(loop < 3){
					if(c == (k - 1) && (s == d)){
						ans++;
						break;
					} else{
						for(int i = 0; i < 4; i++){
							if(n[c] > 2){
								s += 2;
								n[c] -= 2;	
							} else if(n[c] == 2){
								s = 2;
								n[c] = 0;
								c--;
							} 
						}	
					}	
				}
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}
