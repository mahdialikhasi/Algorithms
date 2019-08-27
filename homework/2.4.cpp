#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <vector>
#define MIN 100000
int main(){
	int a;
	cin >> a;
	int x = a / 100;

	vector<vector <int> > wind(10);
	vector<vector <int> > array(10);
	for (int i = 9; i >= 0; --i){
		for (int j = 0; j < x; ++j){
			int t;
			cin >> t;
			wind[i].push_back(-1 * t);	
		}
	}
	
	//initialize
	for (int i = 0; i < 10; ++i){
		for (int j = 0; j < x; ++j){
			array[i].push_back(MIN);
		}
		
	}
	array[0][0] = 30 + wind[0][0];
	array[1][0] = 60 + wind[0][0];
	
	for (int j = 1; j < x; ++j){
		for (int i = 0; i < 10; ++i){
			if(i == 0){
				if(array[i][j - 1] + 30 + wind[i][j] < array[i + 1][j - 1] + 20 + wind[i + 1][j]){
					array[i][j] = array[i][j - 1] + 30 + wind[i][j];
				}else{
					array[i][j] = array[i + 1][j - 1] + 20 + wind[i + 1][j];
				}
					
			}else if(i == 9){
				if(array[i][j - 1] + 30 + wind[i][j] < array[i - 1][j - 1] + 60 + wind[i - 1][j]){
					array[i][j] = array[i][j - 1] + 30 + wind[i][j];	
				}else{
					array[i][j] = array[i - 1][j - 1] + 60 + wind[i - 1][j];
				}
			}else{
				int min = MIN;
				if(array[i][j - 1] + 30 + wind[i][j] < min){
					min = array[i][j - 1] + 30 + wind[i][j];	
				}
				if(array[i - 1][j - 1] + 60 + wind[i - 1][j] < min){
					min = array[i - 1][j - 1] + 60 + wind[i - 1][j];
				}
				if(array[i + 1][j - 1] + 20 + wind[i + 1][j] < min){
					min = array[i + 1][j - 1] + 20 + wind[i + 1][j];
				}
				array[i][j] = min;
			}
		}
	}
	
	for (int j = 0; j < x; ++j)
	{
		for (int i = 0; i < 10; ++i)
		{
			cout << array[i][j] << "(" << wind[i][j] << ")" << ",";
		}
		cout << endl;
	}
	cout << array[0][x - 1] << endl;

	return 0;
}