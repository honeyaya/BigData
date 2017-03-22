class Solution {
public:
	bool dfs(int x, int y, vector<vector<char>> board,int depth, string word,vector<vector<int>>& vis){
		
		if(depth == word.size()-1) {
			return true;
		}
		
		vis[x][y] = 1;
		int row = board.size();
		int col = board[0].size();
		
		
		if((y-1>=0) && (!vis[x][y-1]) && (board[x][y-1] == word[depth+1])){
			if(dfs(x,y-1,board,depth+1,word,vis))
				return true;
		}
		
		if((y+1<col) && (!vis[x][y+1]) && (board[x][y+1] == word[depth+1])){
			if(dfs(x,y+1,board,depth+1,word,vis))
				return true;
		}
		
		if((x-1>=0) && (!vis[x-1][y]) && (board[x-1][y] == word[depth+1])){
			if(dfs(x-1,y,board,depth+1,word,vis))
				return true;
			
		}
		
		if((x+1<row) && (!vis[x+1][y]) && (board[x+1][y] == word[depth+1])){
			if(dfs(x+1,y,board,depth+1,word,vis))
				return true;
		}
		vis[x][y] = 0;
		return false;
	}
	
    bool exist(vector<vector<char>>& board, string word) {
    	if(word.size() == 0) return true;
        int row = board.size();
        int col = board[0].size();
        
        vector<vector<int>> vis(row,vector<int>(col,0));
        
        if(row == 0 || col == 0) return false;
	
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(board[i][j] == word[0]){
					if(dfs(i,j,board,0,word,vis)) 
					return true;
				}
			}
		}
		
		return false;
    }
};
