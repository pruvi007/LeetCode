// solution by @pruvi007

class Solution {
public:
    #define ll long long int
    
    string longestPalindrome(string s) {
        int l = s.length();
        int s1=-1,e1=-1;
            int s2=-1,e2=-1;
        if(l==1)
            return s;
        else if(l==2)
        {
            if(s[0]==s[1])
                return s;
            else 
            {
                string ans ="";
                ans += s[0];
                return ans;
            }
        }
        else
        {
            ll m1=1,m2=0;
            
            for(int i=0;i<l;i++)
            {

                
                //considering single center (odd length palindrome)
                if((i-1)>=0 && (i+1)<l)
                {
                    int l1 = i-1;
                    int r1 = i+1;
                    while(l1>=0 && r1<l && s[l1] == s[r1])
                    {
                         if((r1-l1+1)>m1)
                         {
                            //  cout<<s1<<" "<<e1<<endl;
                             s1 = l1;
                             e1 = r1;
                              m1=r1-l1+1;
                         }
                           
                        l1--;
                        if(l1<0)
                            break;
                        r1++;
                        if(r1>=l)
                            break;

                    }
                }


                
                //considering double center (even length palindrome)
                if(s[i] == s[i+1])
                {
                    if(2>m2)
                    {
                        s2=i;
                        e2=i+1; 
                        m2 = 2;
                    }
                        
                    if((i-1)>=0 && (i+2)<l)
                    {
                        int l2 = i-1;
                        int r2 = i+2;
                        while(l2>=0 && r2<l && s[l2] == s[r2])
                        {
                            if((r2-l2+1)>m2)
                            {
                                // cout<<s2<<" "<<e2<<endl;
                                s2 = l2;
                                e2 = r2;
                                m2 = r2-l2+1;
                            }
                                
                            l2--;
                            if(l2<0)
                                break;
                            r2++;
                            if(r2>=l)
                                break;

                        }
                    }

                }
                
            }
            string ans ="";
                ll d = m1>m2?m1:m2;
                // cout<<d<<endl;
                if(d == m1)
                {
                    // cout<<s1<<" "<<e1<<endl;
                    for(int i=s1;i<=e1;i++)
                        ans += s[i];
                }
                else
                {
                    // cout<<s2<<" "<<e2<<endl;
                    for(int i=s2;i<=e2;i++)
                        ans += s[i];
                }
                return ans;
        }
        
    }
};