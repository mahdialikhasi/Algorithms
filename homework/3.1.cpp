#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
vector<int> l;
int dfsCycle(vector<int> g, int i, vector<int> &x){
	x[i] = 1;
	if(x[g[i]] == 0){
		int count = dfsCycle(g, g[i], x) + 1;
		return count;
	}else{
		if(l[g[i]] == -1){
			return 0;
		}
		else{
			return l[g[i]] + 1;
		}
	}
}
void dfsCycleUpdate(vector<int> g, int i, vector<int> &x, int y){
	x[i] = 1;
	l[i] = y;
	if(x[g[i]] == 0){
		dfsCycleUpdate(g, g[i], x, y);
	}else{
		return;
	}
}
void cycle(vector<int> g, int i){
	vector<int> tmp(g.size());
	int y = dfsCycle(g,i,tmp);
	vector<int> x(g.size());

	dfsCycleUpdate(g,i,x,y);
}
int dfs(vector<int> g, int i, vector<int> &x){
	x[i] = 1;
	if(x[g[i]] == 0){
		int count = dfs(g, g[i], x) + 1;
		if(l[i] == -1){
			l[i] = count;	
		}else{
			count = l[i];
		}
		
		return count;
	}else{
		if(l[g[i]] == -1){
			//cycle
			cycle(g,i);
			return l[i];
		}
		else{
			l[i] = l[g[i]] + 1;
			return l[g[i]] + 1;
		}
	}
}
int main(){
	int n;
	cin >> n;
	vector<int> data(n);
	
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		int y;
		cin >> y;
		data[x - 1] = y - 1;
		l.push_back(-1);
	}
	int max = 0;
	int index = 0;
	vector<int> tmp(n);
	for (int i = 0; i < n; ++i){
		if(tmp[i] == 0){
			int count = dfs(data, i, tmp);
			l[i] = count;
			if( count > max){
				max = count;
				index = i;
			}
		}
		
		//cout << l[i] << ";";
	}
	cout << index + 1 << endl;
	return 0;
}