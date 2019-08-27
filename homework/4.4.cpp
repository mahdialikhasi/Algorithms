#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int minimum = 100000;
vector<vector<int> > connection;
void dfs(vector<int> &visited, vector<vector<int> > &lenght, vector<int> &min, int s, int t){
	visited[s] = 1;
	if(s == t){
		minimum = min[s]; 
		return;
	}
	if(visited[t] == 1){
		return;
	}	
	for (int i = 0; i < connection[s].size() && visited[t] == 0; ++i){
		if(lenght[s][i] > 0 && visited[i] == 0){
			if(lenght[s][i] < min[s]){
				min[i] = lenght[s][i];
			}else{
				min[i] = min[s];
			}
			dfs(visited,lenght,min,i,t);
			if(minimum != 100000){
				lenght[s][i] -= minimum;
				lenght[i][s] += minimum;
			}
		}
	}
}
int main(){
	int n;
	cin >> n;
	int s, t , c;
	cin >> s >> t >> c;
	connection.resize(n + 1, vector<int>(n + 1));
	for (int i = 0; i < c; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		connection[x][y] += z;
		connection[y][x] += z;
	}
	vector<int> min(connection.size());
	vector<vector<int> > graph(connection.size(), vector<int>(connection.size()));
	for (int i = 0; i < connection.size(); ++i){
		for (int j = 0; j < connection[i].size(); ++j){
			graph[i][j] = connection[i][j];
		}
	}
	do{
		minimum = 100000;
		vector<int> visited(connection.size());	
		min[s] = 100000;
		dfs(visited,graph,min,s,t);
	}while(minimum != 100000);
	int bandwith = 0;
	for (int i = 0; i < graph[s].size(); ++i){
		bandwith += connection[s][i] - graph[s][i];
	}
	cout << "The bandwidth is " << bandwith << "." << endl;
	return 0;
}