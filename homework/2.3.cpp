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
	
	vector<int> max(n);
	vector<int> bleft(n);
	vector<int> max2(n);
	//initilize
	if(price[0] <= m){
		max[0] = favor[0];
		bleft[0] = m - price[0];
	}else{
		max[0] = 0;
		bleft[0] = m;
	}
	int maximum = 0;
	for (int i = 1; i < n; ++i){
		int status = 0;
		for (int j = 0; j < i; ++j){
			//cout << favor[i] + max[j] << "ss" << i << "ss" << j << endl;
			if(bleft[j] - price[i] >= 0 && favor[i] + max[j] > max[i]){
				max[i] = favor[i] + max[j];
				bleft[i] = bleft[j] - price[i];
				status = 1;
			}
		}
		if(status == 0){
			if(price[i] <= m){
				max[i] = favor[i];
				bleft[i] = m - price[i];
			}else{
				max[i] = 0;
				bleft[i] = m; 
			}
		}
	}





	if(m >= 2000)
		m += 200;
	//initilize
	for (int i = 0; i < n; ++i)
	{
		favor[i] = 0;
		max2[i] = 0;
		bleft[i] = 0;
	}
	if(price[0] <= m){
		max2[0] = favor[0];
		bleft[0] = m - price[0];
	}else{
		max2[0] = 0;
		bleft[0] = m;
	}
	maximum = 0;
	for (int i = 1; i < n; ++i){
		int status = 0;
		for (int j = 0; j < i; ++j){
			//cout << favor[i] + max[j] << "ss" << i << "ss" << j << endl;
			if(bleft[j] - price[i] >= 0 && favor[i] + max2[j] > max[i]){
				max2[i] = favor[i] + max2[j];
				bleft[i] = bleft[j] - price[i];
				status = 1;
			}
		}
		if(status == 0){
			if(price[i] <= m){
				max2[i] = favor[i];
				bleft[i] = m - price[i];
			}else{
				max2[i] = 0;
				bleft[i] = m; 
			}
		}
	}
















	for (int i = 0; i < n; ++i){
		if(max[i] > maximum)
			maximum = max[i];
		if(max2[i] > maximum && m - 200 - bleft[i] > 2000)
			maximum = max[i];
	}
	/*for (int i = 0; i < n; ++i){
		cout << max[i] << ":" << bleft[i] << endl;
	}*/
	cout << maximum << endl;
	return 0;
}