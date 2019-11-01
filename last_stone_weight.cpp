/*
    add two largest stones and push back their difference. Dont push if diff ==0
    find the final weight stone
*/
// solution by @pruvi007

class Solution {
public:
    int lastStoneWeight(vector<int>& a) {
        priority_queue<int> pq;
        int n = a.size();
        for(int i=0;i<n;i++)
            pq.push(a[i]);
        while(1)
        {
            if(pq.size()>=2)
            {
                int a = pq.top();
                pq.pop();
                int b = pq.top();
                pq.pop();

                if(a!=b)
                {
                    pq.push(abs(a-b));
                    if(pq.size()==1)
                        return pq.top();
                }
            }
            if(pq.size()==1)
                return pq.top();
            if(pq.size()==0)
                return 0;
        }
        
        
    }
};