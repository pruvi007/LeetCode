// solution by @pruvi007

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.length();
        int low=0,high=l;
        int ans=1;
        if(l==0)
            return 0;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int f[256]={0};
            for(int i=0;i<mid;i++)
                f[s[i]%255]++;
            int flag=0;
            for(int i=0;i<256;i++)
            {
                if(f[i]>1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                
                for(int i=mid;i<l;i++)
                {
                    flag=0;
                    f[s[i-mid]%255]--;
                    f[s[i]%255]++;
                    for(int j=0;j<256;j++)
                    {
                        if(f[j]>1)
                        {
                            flag=1;
                        }
                    }
                    if(flag==0)
                        break;
                }
            }
            if(flag==0)
            {
                ans = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return ans;
    }
};