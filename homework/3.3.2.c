#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
int t = 0;
void dfs(vector<vector<int> >g, vector<int> &visited, int s, vector<int> &f){
	visited[s] = 1;
	for (int i = 0; i < g[s].size(); ++i)
	{
		if(visited[g[s][i]] == 0){
			dfs(g,visited,g[s][i],f);
			
		}
		if(f[g[s][i]] >= f[s])
			f[s] = f[g[s][i]] + 1;
	}
	if(f[s] == 0)
		f[s] = 1;
	t++;
}
void dfs_loop(vector<vector<int> >g, vector<int> &visited, vector<int> &f){
	for (int i = 0; i < g.size(); ++i)
	{
		if(visited[i] == 0){
			t = 0;
			dfs(g,visited,i,f);
		}
	}
}
void print_out(vector<vector<int> >g, vector<int> f,vector<int> svisited, int source, vector<string> names){
	cout << "Dilbert should drink beverages in this order:";
	svisited[source] = 1;
	cout << " " << names[source];
	int status = 1;
	while(status){
		status = 0;
		for (int i = 0; i < g[source].size(); ++i)
		{
			if(svisited[g[source][i]] == 0 && f[g[source][i]] == f[source] - 1){
				svisited[g[source][i]] = 1;
				source = g[source][i];
				status = 1;
				cout << " " << names[source];
				break;
			}
		}
	}
	cout << ".";
}
void print_vec(vector<int> vec){
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << ",";
	}
}
int main(){
	int n;
	cin >> n;
	vector<string> names;
	for (int i = 0; i < n; ++i)
	{
		string bev;
		cin >> bev;
		names.push_back(bev);
	}
	int m;
	cin >> m;
	vector<int> visited(n);
	vector<int> f(n);
	vector<vector<int> > data(n);
	for (int i = 0; i < m; ++i)
	{
		string b1,b2;
		cin >> b1 >> b2;
		int x;
		int y;
		for (int i = 0; i < n; ++i)
		{
			if(b1 == names[i]){
				x = i;
				break;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if(b2 == names[i]){
				y = i;
				break;
			}
		}
		data[x].push_back(y);
	}
	dfs_loop(data,visited,f);
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		if(f[i] > max){
			max = f[i];
		}
	}
	print_vec(f);
	cout << "Dilbert should drink beverages in this order:";
	for (int i = 0; i < n;)
	{
		for (int j = 0; j < n; ++j)
		{
			if(f[j] == max){
				cout << " " << names[j];
				i++;
			}
		}
		max --;
	}
	cout << ".";
	return 0;
}