#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int t = 0;
int max_no = 0;
void dfs(vector<vector<int> >g, vector<int> &v, int s){
	v[s] = 1;
	t++;
	for (int i = 0; i < g[s].size(); ++i)
	{
		if(v[g[s][i]] != 1){
			dfs(g, v, g[s][i]);
		}
	}
}
void dfs_loop(vector<vector<int> >g, vector<int> &v){
	for (int i = 0; i < g.size(); ++i)
	{
		if(v[i] != 1){
			t = 0;
			dfs(g,v,i);
			if(t > max_no)
				max_no = t;
		}
	}
}
int main(){
	int m , n;
	cin >> m >> n;
	vector<vector<char> > prdata;
	vector<vector<int> > data(m*n);
	vector<int> visited(m*n); 
	for (int i = 0; i < m; ++i)
	{
		vector<char> t(n);
		prdata.push_back(t);
		for (int j = 0; j < n; ++j)
		{
			char a;
			cin >> a;
			prdata[i][j] = a;
		}
	}
	int first, last;
	cin >> first >> last;
	char exact = prdata[first][last];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(prdata[i][j] == exact){
				//etesale in b bahgie
				if(i != 0)
					data[(i - 1) * n + j].push_back(i * n + j);
				if(i != m - 1)
					data[(i + 1) * n + j].push_back(i * n + j);
				if(j != 0)
					data[i * n + j - 1].push_back(i * n + j);
				else
					data[i * n + n - 1].push_back(i * n + j);
				if(j != n -1)
					data[i * n + j + 1].push_back(i * n + j);
				else
					data[i * n + 0].push_back(i * n + j);
			}else{
				visited[i * n + j] = 1;
			}
		}
	}
	dfs(data,visited,first * n + last);
	dfs_loop(data,visited);
	cout << max_no << endl;
	return 0;
}