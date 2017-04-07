#include <iostream>
#include <stdio.h>
using namespace std;

#define maxn 101

char grid[maxn][maxn];
int dp[maxn][maxn][2];

int main(){
	int n,m;
	while(cin >> n >> m){
		
		for(int i = 0; i < n; i++){
			for(int j = 0;  j < m; j++){
				cin >> grid[i][j];
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				dp[i][j][0]=0;
				dp[i][j][1]=0;
			}
		}
		
		//init
		dp[0][0][0]=(grid[0][0]=='b');
		dp[0][0][1]=(grid[0][0]=='b')+(1<m && grid[0][1]!='b');
		
		for(int i = 1; i < m; i++){
			dp[0][i][0]=min(dp[0][i-1][1] + (1<n && grid[1][i-1] != 'b'),dp[0][i-1][0])+ (grid[0][i]=='b');
			dp[0][i][1]=dp[0][i][0] + (i+1<m && grid[0][i+1]!='b');
		}
		
		for(int i = 1; i < n; i++){
			dp[i][0][1]=min(dp[i-1][0][0]+(1<m && grid[i-1][1]!='b'),dp[i-1][0][1])+(grid[i][0]=='b');
			dp[i][0][0]=dp[i][0][1]+(i+1<n && grid[i+1][0]!='b'); 
		}
		//iterator
		for(int i = 1; i < n; i++){
			for(int j = 1; j < m; j++){
				dp[i][j][0] = min(dp[i][j-1][0],dp[i-1][j][1]+(i+1<n && grid[i+1][j]!='b')) + (grid[i][j]=='b') ;
				dp[i][j][1] = min(dp[i-1][j][1],dp[i][j-1][0]+(j+1<m && grid[i][j+1]!='b')) + (grid[i][j]=='b');
			}
		}
		
		cout << max(dp[n-1][m-1][0],dp[n-1][m-1][1]) << endl;
	}
	return 0;
}
