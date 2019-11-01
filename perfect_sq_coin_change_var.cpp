class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        int x = sqrt(n);
        if(n==0)
            return 0;
        for(int i=1;i<=x;i++)
        {
            sq.push_back(i*i);
        }
        int dp[n+1];
        for(int i=0;i<=n;i++)
            dp[i] = INT_MAX;
        dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<sq.size();j++)
            {
                if(sq[j]<=i)
                {
                    int x = dp[i-sq[j]];
                    dp[i] = min(dp[i],x+1);
                }
            }
        }
        return dp[n];
    }
};