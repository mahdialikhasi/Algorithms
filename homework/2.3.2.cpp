#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int m;
	cin >> m;
	int n;
	cin >> n;
	vector<int> favor;
	vector<int> price;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		price.push_back(t);
		cin >> t;
		favor.push_back(t);
	}	
	int maximum = 0;
	for(int x = 0; x < n; x++){
		//vector<int> tmp(n);
		//tmp = price;
		//vector<int> ft(n);
		//ft = favor;
		//int temper;
		//int temperf;
		
		if(x != 0){
			int temper = price[x - 1];
			int temperf = favor[x - 1];
			price[x - 1] = price[n-1];
			favor[x - 1] = favor[n-1];
			price[n-1] = temper;
			favor[n-1] = temperf;
		}
		vector<vector <int> > data;
		for (int i = 0; i < m + 1; ++i){
			vector<int> tmp(n);
			data.push_back(tmp);
		}
		for (int j = 1; j < n; ++j){
			for (int i = 0; i < m + 1; ++i)
			{
				int max = 0;
				if(i - price[j - 1] >= 0 && data[i - price[j - 1]][j - 1] + favor[j - 1] > max)
					max = data[i - price[j - 1]][j - 1] + favor[j - 1];
				if(data[i][j - 1] > max)
					max = data[i][j - 1];
				data[i][j] = max;
			}
		}
		if(maximum < data[m][n-1])
			maximum = data[m][n-1];
		int p = m - price[n-1];
		if(p >= 0 && p <= m && data[p][n-1] + favor[n-1] > maximum){
			maximum = data[p][n-1] + favor[n-1];
		}
		p = m + 200 - price[n-1];
		while(p <= m && p - 1 >=0 && data[p][n-1] == data[p - 1][n-1])
			p --;
		if(p >= 0 && p <= m && data[p][n-1] + favor[n-1] > maximum && p > 2000){
			maximum = data[p][n-1] + favor[n-1];
		}
		/*cout << price[n - 1];
		cout << ";;" << p << ";;" << data[p][n-1] << endl;*/
		
	}
	
	/*for (int i = 0; i < n; ++i){
		cout << max[i] << ":" << bleft[i] << endl;
	}*/
	cout << maximum << endl;
	return 0;
}