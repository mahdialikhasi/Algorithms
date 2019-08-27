#include <iostream>
#include <math.h>
#include <vector>
#include <stdio.h>
using namespace std;

double nvp(int cf[], int size,double irr){
	double nvp = 0;
	for (int i = 0; i < size; ++i){
		nvp += cf[i] / (pow(1 + irr, i));
	}
	return nvp;
}

#define PRECISION_REQ 0.00001
double computeIRR(int cf[], int numOfFlows, double lowRate, double highRate){
	int i = 0,j = 0;
	double m = 0.0;
	double old = 0.00;
	double newx = 0.00;
	double oldguessRate = lowRate;
	double newguessRate = lowRate;
	double guessRate = lowRate;
	double lowGuessRate = lowRate;
	double highGuessRate = highRate;
	double npv = 0.0;
	double denom = 0.0;
	for(i=0; i< 10000; i++){
		npv = 0.00;
		for(j = 0; j < numOfFlows; j++){
			denom = pow((1 + guessRate),j);
			npv = npv + (cf[j] / denom);
		}
		if((npv > 0) && (npv < PRECISION_REQ)){
			break;
		}
		if(old == 0)
			old = npv;
		else
			old = newx;
		newx = npv;
		if(i > 0){
			if(old < newx){
				if(old < 0 && newx < 0)
					highGuessRate = newguessRate;
				else
					lowGuessRate = newguessRate;
			}
			else
			{
				if(old > 0 && newx > 0)
					lowGuessRate = newguessRate;
				else
					highGuessRate = newguessRate;
			}
		}
		oldguessRate = guessRate;
		guessRate = (lowGuessRate + highGuessRate) / 2;
		newguessRate = guessRate;
	}
	return guessRate;
}
int main(){
	double max = 100;
	double min = -1 + 0.01;
	int count = 0;
	double nvps[100];
	int t;
	cin >> t;
	int cf[t + 1];
	for (int i = 0; i < t + 1; ++i){
		cin >> cf[i];
	}
	int sign = 0;
	int pos = 0;
	if(nvp(cf, t + 1, min) < 0)
		sign = 1;
	for (int i = 0; i < 100; ++i){
		nvps[i] = nvp(cf, t + 1, min + i);
		if((nvps[i] > 0 && sign == 1) || (nvps[i] < 0 && sign == 0)){
			if(sign == 1){
				sign = 0;
			}else{
				sign = 1;
			}
			pos = i;
			count ++;
		}
		if(count > 1){
			cout << "Too many";
			return 0;
		}
	}
	int first = 0;
	if(count == 0){
		cout << "No";
		return 0;
	}else{
		
		for (int i = 0; i < pos; ++i){
			if((sign == 0 && nvps[i] < 0) || (sign == 1 && nvps[i] > 0)){
				first = i;
			}
		}
	}
	double irr = computeIRR(cf, t + 1, first + min, pos + min);
	double rnd = irr * 1000;
	double rnd2 = round(rnd / 10);
	//cout << rnd2 / 100 << endl;
	printf("%0.2lf", rnd2 / 100);

	return 0;
}