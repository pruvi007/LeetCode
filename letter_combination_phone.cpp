/*
    Input: "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

    idea: add the current char and move to next word.
*/


class Solution {
public:
    vector<string> ans;
    map<string,int> m;
    void gen_comb(vector<string> &s,int l,int k,string temp)
    {
        if(k>l)
            return;
        // when length of word is == l, combination is done
        if(temp.length()==l)
        {
            if(m.find(temp)==m.end())
            {
                ans.push_back(temp);
                m[temp]++;
            }
            
            
        }
        for(int i=k;i<l;i++)
        {
            for(int j=0;j<s[i].length();j++)
            {
                // current letter added to temp and moved to (i+1)th word.
                gen_comb(s,l,i+1,temp+s[k][j]);
            }
                
            
        }
        
    }
    vector<string> letterCombinations(string a) {
        vector<string> s;
        ans.clear();
        m.clear();
        int l = a.length();
        if(a.length()==0)
            return ans;
        for(int i=0;i<l;i++)
        {
            if(a[i]=='2')
                s.push_back("abc");
            else if(a[i]=='3')
                s.push_back("def");
            else if(a[i]=='4')
                s.push_back("ghi");
            else if(a[i]=='5')
                s.push_back("jkl");
            else if(a[i]=='6')
                s.push_back("mno");
            else if(a[i]=='7')
                s.push_back("pqrs");
            else if(a[i]=='8')
                s.push_back("tuv");
            else if(a[i]=='9')
                s.push_back("wxyz");
            
        }
        gen_comb(s,l,0,"");
        return ans;
        
    }
};