// 逆时针方向90度 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        
        
        for(int i = 0; i < n/2; i++){
        	
        	int be = i, en = n - 1 - i;
        	
        	for(int j = be; j < en; j++){
        		int tmp1 = matrix[n - 1 - j][i];
        		int tmp2 = matrix[n - 1 - i][n - 1 - j];
        		int tmp3 = matrix[j][n - 1 - i];
        		
				matrix[n - 1 - j][i] = matrix[i][j];
        		matrix[n - 1 - i][n - 1 - j] = tmp1;
				matrix[j][n - 1 -i] = tmp2;
				matrix[i][j] = tmp3;	
			}
			
		}
		
		return ;
    }
};


// 顺时针方向90度 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        
        
        for(int i = 0; i < n/2; i++){
        	
        	int be = i, en = n - 1 - i;
        	for(int j = be; j < en; j++){
	        		cout << "matrix[i][j]= " << matrix[i][j] << " ";
					int tmp1 = matrix[j][n-1-i];
					int tmp2 = matrix[n-1-i][n-1-j];
					int tmp3 = matrix[n-1-j][i];
					
					matrix[j][n-1-i] = matrix[i][j];
					matrix[n-1-i][n-1-j] = tmp1;
					matrix[n-1-j][i] = tmp2;
					matrix[i][j] = tmp3;
					 
				}
				cout << endl;	
		
		}
		
		return ;
    }
};
