#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
double nvp(int cf[], int size,long double irr){
	long double nvp = 0;
	for (int i = 0; i < size; ++i){
		nvp += cf[i] / (pow(1 + irr, i));
	}
	return nvp;
}
int main(){
	int t;
	cin >> t;
	int cf[t + 1];
	int allZero = 1;
	for (int i = 0; i < t + 1; ++i){
		cin >> cf[i];
		if(cf[i]){
			allZero = 0;
		}
	}
	long double irr = -1 + 0.01;
	long double alpha = 50000;
	int no = 0;
	int change = 0;
	for (int i = 0; i < 50000; ++i){
		if(nvp(cf, t+ 1, irr) > 0.00001){
			irr += alpha;
			if(irr == -1){
				irr += 0.01;
			}
			alpha /= 2;
			
		}else if(nvp(cf, t+ 1, irr) < -0.00001){
			irr -= alpha;
			if(irr == -1){
				irr -= 0.01;
			}
			alpha /= 2;
			change = 1;
		}else{
			break;
		}
		
	}
	long double nvp_f = nvp(cf , t + 1, irr);
	if(allZero){
		cout << "Too many";
	}else if(irr <= -1){
		cout << "No";
	}else{
		//double rnd = irr * 1000;
		//double rnd2 = round(rnd / 10);
		printf("%0.2Lf", irr);
	}
	return 0;
}