#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
int main(){
	int t;
	cin >> t;
	vector<vector <int> > data(t);
	for (int i = 0; i < t; ++i){
		for (int j = 0; j < t; ++j){
			int x;
			cin >> x;
			data[i].push_back(x);
		}
	}
	vector<int> max(t);
	for (int i = 0; i < t; ++i){
		max[i] = -200;
	}
	vector<int> cal(t);
	int maximum = -200;
	for (int i = 0; i < t; ++i){
		cal = data[i];
		for (int j = i; j < t; ++j){
			if(j == i){
				// calculate
				max[0] = cal[0];
				if(max[0] > maximum)
					maximum = max[0];
				for (int c = 1; c < t; ++c){
					if(max[c - 1] +  cal[c] > cal[c]){
						max[c] = max[c - 1] +  cal[c];
					}else{
						max[c] = cal[c];
					}
					if(max[c] > maximum)
						maximum = max[c];
				}
			}else{
				for (int a = 0; a < t; ++a){
					cal[a] += data[j][a];
				}
				// calculate
				max[0] = cal[0];
				if(max[0] > maximum)
					maximum = max[0];
				for (int c = 1; c < t; ++c){
					if(max[c - 1] +  cal[c] > cal[c]){
						max[c] = max[c - 1] +  cal[c];
					}else{
						max[c] = cal[c];
					}
					if(max[c] > maximum)
						maximum = max[c];
				}
			}
		}
	}
	cout << maximum << endl;
	return 0;
}