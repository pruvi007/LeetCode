
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
        
        // q to maintain the bfs state
        queue<int> q;
        q.push(n);
        // map to maintain visisted elements
        map<int,int> m;
        
        // d is the depth of bfs
        int d = 0;
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                int x = q.front();
                q.pop();
                cout << d << " " << x << endl;
                if(x == 0)
                    return d;
                if(m.find(x)==m.end())
                {
                    for(int i=0;i<sq.size();i++)
                    {
                        int p = x-sq[i];
                        if(p>=0)
                            q.push(p);
                    }
                    m[x] = 1;
                }
            }
            d++;
        }
        return d;
        
    }
};