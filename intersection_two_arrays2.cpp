/*
	Find intersection of 2 arrays
	two methods
	1. using multisets
	2. using merge concpet (beats 99%)
*/

// solution by @pruvi007
// 1
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        if(nums1.size() ==0 || nums2.size()==0)
            return a;
        
        multiset<int> s(nums2.begin(),nums2.end());
      
        vector<int> ans;
       
        
        for(int i=0;i<nums1.size();i++)
        {
            int x = nums1[i];
            if(s.find(x) != s.end())
            {
                ans.push_back(x);
                s.erase(s.lower_bound(x));
            }
        }
        return ans;
    }
};

// 2
