#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
void dfs(vector<vector<int> > &graph, vector<int> &visited, int s){
	visited[s] = 1;
	if(s == visited.size() - 1){
		cout << "winnable";
		exit(0);
	}
	for (int i = 0; i < graph[s].size(); ++i)
	{
		if(visited[graph[s][i]] == 0)
			dfs(graph,visited,graph[s][i]);
	}
}
void dfs_loop(vector<vector<int> > graph, vector<int> vertex){
	for (int i = 0; i < vertex.size(); ++i){
		if(vertex[i] == 2){
			vector<int> visited(vertex.size());
			dfs(graph,visited,vertex[i]);
			// cout << "winnable";
			// exit(0);
		}
	}
}
int main(){
	int n;
	cin >> n;
	vector<int> energy(n);
	vector<vector<int> > doors(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> energy[i];
		int doorway;
		cin >> doorway;
		for (int j = 0; j < doorway; ++j){
			int door;
			cin >> door;
			if(door > 0 && door <= n)
				doors[i].push_back(door - 1);
		}
	}
	vector<int> health(n,-1);
	health[0] = 100;
	vector<int> seen;
	seen.push_back(0);
	vector<int> visited(n);
	visited[0] = 1;
	for (int x = 0; x < 2 * n; ++x){
		int max = -1;
		int index = -1;
		for (int i = 0; i < seen.size(); ++i){
			for (int j = 0; j < doors[seen[i]].size(); ++j){
				//seen[i] -> doors[seen[i]][j]
				if(health[seen[i]] + energy[doors[seen[i]][j]] > 0 && health[doors[seen[i]][j]] < 0){
					if(health[seen[i]] + energy[doors[seen[i]][j]] > max){
						max = health[seen[i]] + energy[doors[seen[i]][j]];
						index = doors[seen[i]][j];
					}
				}else if(health[seen[i]] + energy[doors[seen[i]][j]] > 0 && health[seen[i]] + energy[doors[seen[i]][j]] > health[doors[seen[i]][j]]){
					//index = doors[seen[i]][j];
					visited[doors[seen[i]][j]] = 2;
				} 
			}
		}
		if(max > 0){
			health[index] = max;
			seen.push_back(index);
			visited[index] = 1;
		}else{
			break;
		}
	}
	if(health[n-1] > 0){
		cout << "winnable";
		return 0;
	}else{
		dfs_loop(doors, visited);
	}
	cout << "hopeless";
	return 0;
}