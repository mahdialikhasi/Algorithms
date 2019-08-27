#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>

int main(){
	int n;
	int m;
	cin >> n;
	cin >> m;
	vector<vector<int> > data;
	vector<vector<int> > check;
	for (int i = 0; i < n; ++i)
	{
		vector<int> tmp(m);
		data.push_back(tmp);
		check.push_back(tmp);
		for (int j = 0; j < m; ++j)
		{
			cin >> data[i][j];
		}
	}
	int max = m;
	if(n > m)
		max = n;
	vector<int> vertex_i;
	vector<int> vertex_j;
	vector<int> l;
	l.push_back(data[0][0]);
	vertex_i.push_back(0);
	vertex_j.push_back(0);
	check[0][0] = 1;
	while(vertex_i[vertex_i.size() - 1] != n - 1 || vertex_j[vertex_j.size() - 1] != m - 1){
		int min = 1000000;
		int k = -1;
		int j = -1;
		for (int i = 0; i < vertex_i.size(); ++i){
			//vertex_i[i], vertex_j[i]
			//check right
			if(vertex_j[i] + 1 <= m - 1 && check[vertex_i[i]][vertex_j[i] + 1] == 0 && l[i] + data[vertex_i[i]][vertex_j[i] + 1] < min){
				k = vertex_i[i];
				j = vertex_j[i] + 1;
				min = l[i] + data[vertex_i[i]][vertex_j[i] + 1];
			}
			//check left
			if(vertex_j[i] - 1 >= 0 && check[vertex_i[i]][vertex_j[i] - 1] == 0 && l[i] + data[vertex_i[i]][vertex_j[i] - 1] < min){
				k = vertex_i[i];
				j = vertex_j[i] - 1;
				min = l[i] + data[vertex_i[i]][vertex_j[i] - 1];
			}
			//check top
			if(vertex_i[i] - 1 >= 0 && check[vertex_i[i] - 1][vertex_j[i]] == 0 && l[i] + data[vertex_i[i] - 1][vertex_j[i]] < min){
				k = vertex_i[i] - 1;
				j = vertex_j[i];
				min = l[i] + data[vertex_i[i] - 1][vertex_j[i]];
			}
			//check bottom
			if(vertex_i[i] + 1 <= n - 1 && check[vertex_i[i] + 1][vertex_j[i]] == 0 && l[i] + data[vertex_i[i] + 1][vertex_j[i]] < min){
				k = vertex_i[i] + 1;
				j = vertex_j[i];
				min = l[i] + data[vertex_i[i] + 1][vertex_j[i]];
			}
		}
		//cout << "k:" << k << " j:" << j << " l:" << min << endl; 
		vertex_i.push_back(k);
		vertex_j.push_back(j);
		l.push_back(min);
		check[k][j] = 1;
	}
	cout << l[l.size() - 1] << endl;
	return 0;
}