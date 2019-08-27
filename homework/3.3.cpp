#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
void dfs(vector<vector<int> >g,vector<int> &grev, vector<int> &printed, int s,vector<string> names){
	printed[s] = 1;
	cout << " " << names[s];
	for (int i = 0; i < g[s].size(); ++i){
		grev[g[s][i]]--;
	}
}
void dfs_loop(vector<vector<int> >g, vector<int > &grev, vector<int> &visited,vector<string> names,vector<int> f){
	cout << "Dilbert should drink beverages in this order:";
	for(int j = 0; j < g.size();j++)
		for (int i = 0; i < g.size();i++)
		{
			if(grev[i] == 0 && visited[i] == 0){		
				dfs(g,grev,visited,i,names);
				break;
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
	vector<vector<int> > data(n);
	vector<int > datarev(n);
	vector<int> f(n);
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
		datarev[y]++;
	}
	vector<int> printed(n);
	dfs_loop(data,datarev,printed,names,f);
	return 0;
}