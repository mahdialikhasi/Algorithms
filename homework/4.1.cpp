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
	while(vertex_i[vertex_i.size() - 1] != n - 1 || vertex_j[vertex_j.size() - 1] != m - 1){
		int min = 1000;
		int k;
		int j;
		for (int i = 0; i < vertex_i.size(); ++i){
			if(vertex_i[i] == 0){
				if(vertex_j[i] == 0){
					if(check[0][1] == 0 && l[i] + data[0][1] < min){
						k = 0;
						j = 1;
						min = l[i] + data[0][1];
					}else if(check[1][0] == 0 && l[i] + data[1][0] < min){
						k = 1;
						j = 0;
						min = l[i] + data[1][0];
					}
				}else if(vertex_j[i] == m - 1){
					if(check[0][m - 2] == 0 && l[i] + data[0][m - 2] < min){
						k = 0;
						j = m - 2;
						min = l[i] + data[0][m - 2];
					}else if(check[1][m - 1] == 0 && l[i] + data[1][m - 1] < min){
						k = 1;
						j = m - 1;
						min = l[i] + data[1][m - 1];
					}
				}else{
					if(check[0][vertex_j[i] + 1] == 0 && l[i] + data[0][vertex_j[i] + 1] < min){
						k = 0;
						j = vertex_j[i] + 1;
						min = l[i] + data[0][vertex_j[i] + 1];
					}else if(check[1][vertex_j[i]] == 0 && l[i] + data[1][vertex_j[i]] < min){
						k = 1;
						j = vertex_j[i];
						min = l[i] + data[1][vertex_j[i]];
					}else if(check[0][vertex_j[i] - 1] == 0 && l[i] + data[0][vertex_j[i] - 1] < min){
						k = 0;
						j = vertex_j[i] - 1;
						min = l[i] + data[1][vertex_j[i] - 1];
					}
				}
			}else if(vertex_i[i] == n - 1){
				if(vertex_j[i] == 0){
					if(check[n - 1][1] == 0 && l[i] + data[n - 1][1] < min){
						k = n - 1;
						j = 1;
						min = l[i] + data[n - 1][1];
					}else if(check[n - 2][0] == 0 && l[i] + data[n - 2][0] < min){
						k = n - 2;
						j = 0;
						min = l[i] + data[n - 2][0];
					}
				}else if(vertex_j[i] == m - 1){
					if(check[n - 1][m - 2] == 0 && l[i] + data[n - 1][m - 2] < min){
						k = n - 1;
						j = m - 2;
						min = l[i] + data[n - 1][m - 2];
					}else if(check[n - 2][m - 1] == 0 && l[i] + data[n - 2][m - 1] < min){
						k = n - 2;
						j = m - 1;
						min = l[i] + data[n - 2][m - 1];
					}
				}else{
					if(check[n - 1][vertex_j[i] + 1] == 0 && l[i] + data[n - 1][vertex_j[i] + 1] < min){
						k = n - 1;
						j = vertex_j[i] + 1;
						min = l[i] + data[n - 1][vertex_j[i] + 1];
					}else if(check[n - 2][vertex_j[i]] == 0 && l[i] + data[n - 2][vertex_j[i]] < min){
						k = n - 2;
						j = vertex_j[i];
						min = l[i] + data[n - 2][vertex_j[i]];
					}else if(check[n - 1][vertex_j[i] - 1] == 0 && l[i] + data[n - 1][vertex_j[i] - 1] < min){
						k = n - 1;
						j = vertex_j[i] - 1;
						min = l[i] + data[n - 1][vertex_j[i] - 1];
					}
				}
			}else{
				if(vertex_j[i] == 0){
					if(check[vertex_i[i]][1] == 0 && l[i] + data[vertex_i[i]][1] < min){
						k = vertex_i[i];
						j = 1;
						min = l[i] + data[vertex_i[i]][1];
					}else if(check[vertex_i[i] + 1][0] == 0 && l[i] + data[vertex_i[i] + 1][0] < min){
						k = vertex_i[i] + 1;
						j = 0;
						min = l[i] + data[vertex_i[i] + 1][0];
					}else if(check[vertex_i[i] - 1][0] == 0 && l[i] + data[vertex_i[i] - 1][0] < min){
						k = vertex_i[i] - 1;
						j = 0;
						min = l[i] + data[vertex_i[i] - 1][0];
					}
				}else if(vertex_j[i] == m - 1){
					if(check[vertex_i[i]][m - 2] == 0 && l[i] + data[vertex_i[i]][m - 2] < min){
						k = vertex_i[i];
						j = m - 2;
						min = l[i] + data[vertex_i[i]][m - 2];
					}else if(check[vertex_i[i] + 1][m - 1] == 0 && l[i] + data[vertex_i[i] + 1][m - 1] < min){
						k = vertex_i[i] + 1;
						j = m - 1;
						min = l[i] + data[vertex_i[i] + 1][m - 1];
					}else if(check[vertex_i[i] - 1][m - 1] == 0 && l[i] + data[vertex_i[i] - 1][m - 1] < min){
						k = vertex_i[i] - 1;
						j = m - 1;
						min = l[i] + data[vertex_i[i] - 1][m - 1];
					}
				}else{
					if(check[vertex_i[i]][vertex_j[i] + 1] == 0 && l[i] + data[vertex_i[i]][vertex_j[i] + 1] < min){
						k = vertex_i[i];
						j = vertex_j[i] + 1;
						min = l[i] + data[vertex_i[i]][vertex_j[i] + 1];
					}else if(check[vertex_i[i]][vertex_j[i] - 1] == 0 && l[i] + data[vertex_i[i]][vertex_j[i] - 1] < min){
						k = vertex_i[i];
						j = vertex_j[i] - 1;
						min = l[i] + data[vertex_i[i]][vertex_j[i] - 1];
					}else if(check[vertex_i[i] - 1][vertex_j[i]] == 0 && l[i] + data[vertex_i[i] - 1][vertex_j[i]] < min){
						k = vertex_i[i] - 1;
						j = vertex_j[i];
						min = l[i] + data[vertex_i[i] - 1][vertex_j[i]];
					}else if(check[vertex_i[i] + 1][vertex_j[i]] == 0 && l[i] + data[vertex_i[i] + 1][vertex_j[i]] < min){
						k = vertex_i[i] + 1;
						j = vertex_j[i];
						min = l[i] + data[vertex_i[i] + 1][vertex_j[i]];
					}
				}
			}			
		}
		cout << "k:" << k << " j:" << j << " l:" << min << endl; 
		vertex_i.push_back(k);
		vertex_j.push_back(j);
		l.push_back(min);
		check[k][j] = 1;
	}
	return 0;
}