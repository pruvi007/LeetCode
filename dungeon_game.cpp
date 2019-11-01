/*
	DUNGEON GAME
	idea: go in bottom manner (from last cell)
	and remember not to fall below 1.
	bottom-up DP
*/
// solution by @pruvi007

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int dp[n+1][m+1];
        
        // min HP reqd at last cell
        dp[n-1][m-1] = max(1,1 - a[n-1][m-1]);
        cout << dp[n-1][m-1] ;
        for(int i=m-2;i>=0;i--)
        {
            dp[n-1][i] = max(1,dp[n-1][i+1] - a[n-1][i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            dp[i][m-1] = max(1,dp[i+1][m-1] - a[i][m-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                dp[i][j] = max(1,min(dp[i+1][j],dp[i][j+1])-a[i][j]);
            }
        }
        return dp[0][0];
    }
};