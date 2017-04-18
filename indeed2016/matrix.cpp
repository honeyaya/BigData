#include <iostream>
using namespace std;

#define maxn 100
int m1[maxn][maxn];
int m2[maxn][maxn];
int ans[maxn][maxn];

int main(){
	int n,m,k;
	while(cin >> n >> m >> k){
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> m1[i][j] ;
			}
		}
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < k; j++){
				cin >> m2[i][j] ;
			}
		}
		
		for(int index1 = 0; index1 < n; index1++){
			for(int index2 = 0; index2 < k; index2++){
				int sum = 0;
				
				for(int index3 = 0; index3 < m; index3++){
					sum += m1[index1][index3] * m2[index3][index2];
				}
				
				ans[index1][index2] = sum;
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < k; j++){
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}		
		
	}
	return 0;
}
