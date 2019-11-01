/*
    search for a word in  maze of characters.
    idea: backtracking approach 
*/

class Solution {
public:
    
    bool dfs(vector<vector<char> > &board,string &word,int i,int j,int r)
    {
        int n = board.size();
        int m = board[0].size();
        if(r>=word.length())
            return true;
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        char c = board[i][j];
        
        bool x = false;
        if(board[i][j] == word[r])
        {
            // mark the board
            board[i][j] = '#';
            // get or from al 4 directions if any of them is true then ans is true.
            x = dfs(board,word,i+1,j,r+1) || dfs(board,word,i-1,j,r+1) || 
                dfs(board,word,i,j+1,r+1) || dfs(board,word,i,j-1,r+1);
        } 
        
         // reset the board.
        board[i][j]=c;
        return x;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        if(word == "")
            return false;
        if(n==0 || m==0)
            return false;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                bool ans = dfs(board,word,i,j,0);
                // cout << endl;
                if(ans)
                    return true;
                
            }
        }
        return false;
        
    }
};