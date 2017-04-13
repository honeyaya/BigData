// 状态更新
// 效率不高   
// 空间优化的方法  使用bit来表示状态  
class Solution {
public:
	int count(int x,int y,vector<vector<int>> board){
		
        int row = board.size();
		int col = board[0].size();
		
		int cnt = 0;
		
		int gapx[] = {-1,0,1};
		int gapy[] = {-1,0,1};
		
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
			    if(gapx[i] == 0 && gapy[j] == 0)
			        continue;
				int newx = x + gapx[i];
				int newy = y + gapy[j];
				if((0 <= newx && newx < row ) && (0 <= newy && newy < col) && (board[newx][newy])) cnt++;	
			}
		}
		return cnt;
		
	}
    void gameOfLife(vector<vector<int>>& board) {
        
        int row = board.size();
		int col = board[0].size();
		
		if(row == 0 || col == 0) return;
		
		vector<vector<int>> vc;
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				vector<int> tmp;
				tmp.clear();
				int numLiveNeighbor = count(i,j,board);
				//cout << "numLiveNeighbor= " << numLiveNeighbor << endl;
				int trow = -1, tcol = -1;
				if(board[i][j]) {
					if(numLiveNeighbor < 2 || numLiveNeighbor > 3) {
						trow = i, tcol = j;
					}
				}
				else {
					if(numLiveNeighbor == 3){
						trow = i, tcol = j;
					}
				}
				
				if(trow != -1){
					tmp.push_back(trow);
					tmp.push_back(tcol);
					vc.push_back(tmp);
				}
			}	
		} 
		
		if(vc.size()){
			for(int i = 0; i < (int)vc.size(); i++){
				board[vc[i][0]][vc[i][1]] = 1 - board[vc[i][0]][vc[i][1]]; 
			}
		}
    }
};

 
