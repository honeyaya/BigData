//  normal method
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
  		 int row = matrix.size();
  		 if(row == 0) return false;
		 int col = matrix[0].size();
		 
		 if(col == 0)
		 	return false;
		
		 if(target < matrix[0][0] || target > matrix[row-1][col-1])
		 	return false;
		
		int i = 0, j = col - 1;
		while(i < row){
			if(matrix[i][j] < target) {
				i++;
			} else {
				for(int k = 0; k <= j; k++){
					if(matrix[i][k] == target) {
						return true;
					}
				}
				return false;
			}
		}  
    }
};

// ÓÅ»¯
 
