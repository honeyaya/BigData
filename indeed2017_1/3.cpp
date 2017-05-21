# include<iostream>
# include<cstdio>
# include<cstring>
# include<vector>
# include<set>
# include<vector>
# include<algorithm>
using namespace std;

#define maxn 1010
int grid[maxn][maxn];
int vis[maxn];

int ans,n;

void dfs(int current){
	if(vis[current]) {
		cout << "--------current:" << current << endl;
		int s = 0;
		for(int i = 1; i <= n; i++){
			if(vis[i]) s++;
		}	
		if(s ==  n) ans++;
		return ;
	}
	vis[current] = true;
	for(int i = 1; i <= n; i++){
		if(grid[current][i] && vis[i]==false){
			vis[i] = true;
			dfs(i);
			vis[i] = false;
		}
	}
	
}
int main(){
	int m;
	while(cin >> n >> m){
		for(int i = 1; i < n; i++){
			for(int j = 1; j <= n; j++){
				
				grid[i][j] = 1;
				grid[j][i] = 1;
			}
		}
		
		while(m--){
			int a,b;
			cin >> a >> b;
			grid[a][b] = 0;
			grid[b][a] = 0;
		}
		
		int ans = 0;
		
		for(int i = 1; i <= n; i++){
			vis[i] = false;
		}
		dfs(1);
		cout << ans << endl;
	}
	return 0;
} 
