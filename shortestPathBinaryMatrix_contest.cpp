class Solution {
public:
    
    int vis[1001][1001]={0};
    bool isSafe(vector<vector<int>>& grid,int i,int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i<n && j<m && i>=0 && j>=0 && grid[i][j]==0)
            return true;
        return false;
    }
    int bfs(vector<vector<int>>& grid,pair<int,int> source,pair<int,int> dest)
    {
        int x[] = {-1,-1,-1,0,0,1,1,1};
        int y[] = {-1,0,1,-1,1,-1,0,1};
        
        // we will push val,level in the queue
        queue< pair<int,pair<int,int> > > q;
        q.push({0,{source.first,source.second}});
        vis[0][0]=1;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                pair<int,pair<int,int> > p = q.front();
                q.pop();
                if(p.second.first == dest.first && p.second.second == dest.second)
                    return p.first+1;

                for(int j=0;j<8;j++)
                {
                    int a = p.second.first + x[j];
                    int b = p.second.second + y[j];
                    if(isSafe(grid,a,b) && vis[a][b]==0)
                    {
                        vis[a][b]=1;
                        q.push({p.first+1,{a,b}});
                    }
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        int ans = bfs(grid,{0,0},{n-1,n-1});
        return ans;
        
    }
};