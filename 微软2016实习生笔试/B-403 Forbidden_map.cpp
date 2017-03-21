#include <iostream>
#include <string.h>
#include <string.h>
#include <map>
#include <math.h>
using namespace std;

map<unsigned int,int> mp[33];

int main(){
	int n,m;
	int a,b,c,d;
	while(cin >> n >> m){
		
		int i;
		for(i = 1; i <= n; i++){
			char cmd[20];
			scanf("%s",cmd);
			
			scanf("%d.%d.%d.%d",&a,&b,&c,&d);
			unsigned ip = (a<<24)+(b<<16)+(c<<8)+(d);
			
			char t;
			scanf("%c",&t);
			int mask = 32;
			if(t == '/')
				scanf("%d",&mask);
			
			ip >>= (32-mask);
			if(mask==0) ip = 0;
			
			if(cmd[0]=='a') {
				if(mp[mask][ip]==0) {
					mp[mask][ip] = i;
				}
			} else {
				if(mp[mask][ip]==0){
					mp[mask][ip]=-i;
				}
			}	
		}
		
		for(int j = 0; j < m; j++){
			scanf("%d.%d.%d.%d",&a,&b,&c,&d);
			int rule = n + 1;
			unsigned tmip = (a<<24) + (b<<16) + (c<<8) + d;
			
			for(int k = 0; k <= 32;k++){
				unsigned tmpip = tmip >> (32-k);
				
				if(k == 0) tmpip = 0;
				if(mp[k].find(tmpip)!=mp[k].end()){
					
					if(abs(rule) > abs(mp[k][tmpip])){
						//cout << mp[k][tmpip] << "---" <<endl;
						rule = mp[k][tmpip];
					}
				}
				
			}
			
			//cout << "rule=" <<rule<<endl;
			if(rule>0) cout << "YES" << endl;
			else cout << "NO" <<endl;
			
		}
		
		
	}
	return 0;
}
