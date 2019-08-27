#include <iostream>
#include <math.h>
using namespace std;

int k;
void f(int * a, int n , int l , int r){ //return 1 if moratab 0 if na moratab
	if(n == 1){
		return;
	}
	if(k > 1){
		k -= 2;
		int mid = floor((l + r) / 2);
		for (int i = 0; i < n / 2; ++i){
			int tmp = a[l + i];
			a[l + i] = a[mid + i];
			a[mid + i] = tmp;
		}/*
		int x[n/2];
		for (int i = 0; i < n/2; ++i){
			x[i] = a[l + i];
		}
		for(int i = 0; i < n - n/2; i++){
			a[l + i] = a[mid + i];
		}
		for (int i = 0; i < n / 2; ++i){
			a[mid + i] = x[i];
		}*/
		f(a, n/2 , l , mid);
		f(a, n - n/2, mid , r);
		
		
	}else{
		return;
	}
}
int main(){
	int n;

	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; ++i){
		a[i] = i + 1;
	}

	f(a, n, 0 , n);
	k--;
	//cout << k << endl;
	if(k == 0){
		for (int i = 0; i < n; ++i){
			cout << a[i] << ' ';
		}
	}else{
		cout << "-1";
	}
	return 0;
}