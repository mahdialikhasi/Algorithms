#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int m , n;
	cin >> m >> n;
	vector<vector<int>> data; 
	for (int i = 0; i < m; ++i)
	{
		vector<int> t(n + 1);
		data.push_back(t);
		for (int j = 0; j < n; ++j)
		{
			char a;
			cin >> a;
			if(a == 'l'){
				if(j != 0)
					data[i][j] = data[i][j - 1] + 1;
				else
					data[i][j] = 1;
			}else{
				data[i][n] = 1;
			}
		}

	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = n - 2; j >= 0; --j)
		{
			if(data[i][j + 1] != 0 && data[i][j] != 0)
				data[i][j] = data[i][j + 1];
		}
	}
	for (int i = 0; i < m; ++i){
		if(data[i][n] == 1)
			data[i][n] = data[i][n-1];
		int first = data[i][0];
		if(data[i][n] != 0){
			for (int j = 0; i < n; ++j)
			{
				if(data[i][j] == 0)
					break;
				data[i][j] += data[i][n];
			}
			for (int j = n - 1; i >= 0; --j)
			{
				if(data[i][j] == 0)
					break;
				data[i][j] += first;
			}
		}
		
	}
	
	return 0;
}