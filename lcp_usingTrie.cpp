// solution by @pruvi007
/*
    Longest Common Prefix using Tries
*/

class Solution {
public:
    struct TrieNode{
        map<char,TrieNode*> child;
        map<char,int> f;
        bool end;
    };
    TrieNode *getNode()
    {
        TrieNode *temp = new TrieNode;
        temp->end = false;
        return temp;
    }
    TrieNode *root = NULL;
    void insert(string x)
    {
        if(root==NULL)
            root = getNode();
        int l = x.length();
        TrieNode *cur = root;
        for(int i=0;i<l;i++)
        {
            char ch = x[i];
            TrieNode *n = cur->child[ch];
            if(n==NULL)
            {
                n = getNode();
                cur->child[ch] = n;
                cur->f[ch]=1;
            }
            else
                cur->f[ch]++;
            cur = n;
        }
        cur->end = true;
    }
    string getLCP(string s,int k)
    {
        int l = s.length();
        TrieNode *cur = root;
        string ans="";
        for(int i=0;i<l;i++)
        {
            char ch = s[i];
            TrieNode *N = cur->child[ch];
            
            if(N)
            {
                int n = cur->f[ch];
                if(n==k)
                    ans+=s[i];
                else if(n==1)
                    return ans;
                cur = N;
                    
            }
            
        }
        return ans;
        
    }
    string longestCommonPrefix(vector<string>& s) {
        root = NULL;
        int n = s.size();
        if(n<=0)
            return "";
        for(int i=0;i<n;i++)
            insert(s[i]);
        return getLCP(s[0],n);
        
        
    }
};