// solution by @pruvi007

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int x = target - nums[i];
            if(m.find(x)!=m.end())
            {
                if(m[x]!=i)
                {
                    ans.push_back(i);
                    ans.push_back(m[x]);
                    return ans;
                }
            }
        }
        return ans;
        
    }
};