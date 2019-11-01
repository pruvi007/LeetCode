/*
    MAX SUBARRAY SUM
    find the max subArray Sum.
*/

// this is the O(n) approach
// can we do it in O(lgn) using divide and conquer
class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n = a.size();
        if(n==0)
            return 0;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>=0)
                flag=1;
        }
        if(flag==0)
        {
            sort(a.begin(),a.end());
            return a[n-1];
        }
        int cur_sum = 0,max_sum = INT_MIN;
        for(int i=0;i<n;i++)
        {
            cur_sum += a[i];
            
            if(cur_sum<0)
            {
                cur_sum = 0;
            }
            if(cur_sum > max_sum)
                max_sum = cur_sum;
        }
        return max_sum;
    }
};