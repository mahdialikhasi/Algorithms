#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string>
int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int> > data(n, vector<int>(m));
	vector<vector<int> > data2(n + 1, vector<int>(m + 1));
	vector<vector<int> > sec(n + 1, vector<int>(m + 1, 10000));
	vector<vector<string> > faces(n + 1, vector<string>(m + 1));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> data[i][j];
			if(data[i][j] == 1){
				data2[i][j] = 1;
				data2[i][j + 1] = 1;
				data2[i + 1][j + 1] = 1;
				data2[i + 1][j] = 1;
			}
		}
	}
	for (int i = 0; i < n + 1; ++i)
	{
		data2[i][0] = data2[i][m] = 1; 
	}
	for (int i = 0; i < m + 1; ++i)
	{
		data2[0][i] = data2[n][i] = 1;
	}
	int source_n, source_m, t_n, t_m;
	cin >> source_n >> source_m >> t_n >> t_m;
	string face;
	cin >> face;
	sec[source_n][source_m] = 0;
	faces[source_n][source_m] = face;
	queue<int> ies;
	queue<int> jes;
	ies.push(source_n);
	jes.push(source_m);
	while(!ies.empty()){
		int now_i = ies.front();
		ies.pop();
		int now_j = jes.front();
		jes.pop();
		string face = faces[now_i][now_j];
		int no = sec[now_i][now_j];
		int up,down,right,left;
		if(face == "south"){
			down = 1;
			right = left = 2;
			up = 3;
		}else if(face == "north"){
			up = 1;
			left = right = 2;
			down = 3;
		}else if(face == "west"){
			up = down = 2;
			left = 1;
			right = 3;
		}else if(face == "east"){
			up = down = 2;
			left = 3;
			right = 1;
		}
		if(now_i + 1 < n + 1 && data2[now_i + 1][now_j] != 1){
			if(no + down < sec[now_i + 1][now_j]){
				sec[now_i + 1][now_j] = no + down;
				ies.push(now_i + 1);
				jes.push(now_j);
				faces[now_i + 1][now_j] = "south";
			}
			if(now_i + 2 < n + 1 && data2[now_i + 2][now_j] != 1){
				if(no + down < sec[now_i + 2][now_j]){
					sec[now_i + 2][now_j] = no + down;
					ies.push(now_i + 2);
					jes.push(now_j);
					faces[now_i + 2][now_j] = "south";
				}
				if(now_i + 3 < n + 1 && data2[now_i + 3][now_j] != 1){
					if(no + down < sec[now_i + 3][now_j]){
						sec[now_i + 3][now_j] = no + down;
						ies.push(now_i + 3);
						jes.push(now_j);
						faces[now_i + 3][now_j] = "south";
					}
				}
			}
		}
		if(now_i - 1 >= 0 && data2[now_i - 1][now_j] != 1){
			if(no + up < sec[now_i - 1][now_j]){
				sec[now_i - 1][now_j] = no + up;
				ies.push(now_i - 1);
				jes.push(now_j);
				faces[now_i - 1][now_j] = "north";
			}
			if(now_i - 2 >= 0 && data2[now_i - 2][now_j] != 1){
				if(no + up < sec[now_i - 2][now_j]){
					sec[now_i - 2][now_j] = no + up;
					ies.push(now_i - 2);
					jes.push(now_j);
					faces[now_i - 2][now_j] = "north";
				}
				if(now_i - 3 >= 0 && data2[now_i - 3][now_j] != 1){
					if(no + up < sec[now_i - 3][now_j]){
						sec[now_i - 3][now_j] = no + up;
						ies.push(now_i - 3);
						jes.push(now_j);
						faces[now_i - 3][now_j] = "north";
					}
				}
			}
		}

		if(now_j + 1 < m + 1 && data2[now_i][now_j + 1] != 1){
			if(no + right < sec[now_i][now_j + 1]){
				sec[now_i][now_j + 1] = no + right;
				ies.push(now_i);
				jes.push(now_j + 1);
				faces[now_i][now_j + 1] = "east";
			}
			if(now_j + 2 < m + 1 && data2[now_i][now_j + 2] != 1){
				if(no + right < sec[now_i][now_j + 2]){
					sec[now_i][now_j + 2] = no + right;
					ies.push(now_i);
					jes.push(now_j + 2);
					faces[now_i][now_j + 2] = "east";
				}
				if(now_j + 3 < m + 1 && data2[now_i][now_j + 3] != 1){
					if(no + right < sec[now_i][now_j + 3]){
						sec[now_i][now_j + 3] = no + right;
						ies.push(now_i);
						jes.push(now_j + 3);
						faces[now_i][now_j + 3] = "east";
					}
				}
			}
		}
		if(now_j - 1 >= 0 && data2[now_i][now_j - 1] != 1){
			if(no + left < sec[now_i][now_j - 1]){
				sec[now_i][now_j - 1] = no + left;
				ies.push(now_i);
				jes.push(now_j - 1);
				faces[now_i][now_j - 1] = "west";
			}
			if(now_j - 2 >= 0 && data2[now_i][now_j - 2] != 1){
				if(no + left < sec[now_i][now_j - 2]){
					sec[now_i][now_j - 2] = no + left;
					ies.push(now_i);
					jes.push(now_j - 2);
					faces[now_i][now_j - 2] = "west";
				}
				if(now_j - 3 >= 0 && data2[now_i][now_j - 3] != 1){
					if(no + left < sec[now_i][now_j - 3]){
						sec[now_i][now_j - 3] = no + left;
						ies.push(now_i);
						jes.push(now_j - 3);
						faces[now_i][now_j - 3] = "west";
					}
				}
			}
		}
	}
	if(sec[t_n][t_m] == 10000){
		cout << -1;
	}else{
		cout << sec[t_n][t_m];
	}
	// for (int i = 0; i < n + 1; ++i)
	// {
	// 	for (int j = 0; j < m + 1; ++j)
	// 	{
	// 		cout << sec[i][j] << "     ";
	// 	}
	// 	cout << endl;
	// }
	// for (int i = 0; i < n + 1; ++i)
	// {
	// 	for (int j = 0; j < m + 1; ++j)
	// 	{
	// 		cout << faces[i][j] << "     ";
	// 	}
	// 	cout << endl;
	// }
	return 0;
}