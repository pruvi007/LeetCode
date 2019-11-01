#include<bits/stdc++.h>
using namespace std;

bool notPresent(string a,vector<string> &curList)
{
	int n =curList.size();
	for(int i=0;i<n;i++)
	{
		if(curList[i] == a)
			return false;
	}
	return true;
}
bool valid(string a,string b)
{
	int c = 0;
	int n = a.length();
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
			c++;
	}
	return c==1;
}

vector< vector<string> > all;
void wordLadder(string begin,string end,vector<string> &words)
{
	int n = words.size();
	queue< pair<string,vector<string> > > q;
	vector<string> temp{begin};
	q.push({begin,temp});
	while(!q.empty())
	{
		pair<string,vector<string> > x = q.front();
		q.pop();
		// cout << x.first << endl;
		if(x.first == end)
		{
			vector<string> l = x.second;
			// for(int i=0;i<l.size();i++)
			// 	cout << l[i] << " ";
			// cout << endl;
			all.push_back(l);
		}
		for(int i=0;i<n;i++)
		{
			if( valid(x.first,words[i]) and notPresent(words[i],x.second) )
			{
				// cout << "valid";
				vector<string> t2 = x.second;
				t2.push_back(words[i]);
				q.push( {words[i],t2} );
			}

		}

	}
}

int main()
{
	string b,e;
	cin >> b >> e;
	int n;
	cin >> n;
	vector<string> words;
	for(int i=0;i<n;i++)
	{
		string x;
		cin >> x;
		words.push_back(x);
	}

	wordLadder(b,e,words);
	int minLen = INT_MAX;
	for(int i=0;i<all.size();i++)
	{
		if(all[i].size() < minLen)
			minLen = all[i].size();
	}
	vector< vector<string> > ans;
	for(int i=0;i<all.size();i++)
	{
		if(all[i].size() == minLen)
			ans.push_back(all[i]);
	}
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}

}