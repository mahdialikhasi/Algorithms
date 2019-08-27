#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

#define LOW_RATE -1 + 0.01
#define HIGH_RATE 100.5
#define MAX_ITERATION 10000
#define PRECISION_REQ 0.00001
double computeIRR(int cf[], int numOfFlows){
	int i = 0,j = 0;
	double m = 0.0;
	double old = 0.00;
	double newx = 0.00;
	double oldguessRate = LOW_RATE;
	double newguessRate = LOW_RATE;
	double guessRate = LOW_RATE;
	double lowGuessRate = LOW_RATE;
	double highGuessRate = HIGH_RATE;
	double npv = 0.0;
	double denom = 0.0;
	for(i=0; i< MAX_ITERATION; i++){
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

int main()
{
	int t;
	cin >> t;
	int cf[t + 1];
	double irr = 0.00;
	for (int i = 0; i < t + 1; ++i){
		cin >> cf[i];
	}
	irr = computeIRR(cf, t + 1);
	cout << irr << endl;
	double nvp = 0;
	for (int i = 0; i < t + 1; ++i){
		nvp += cf[i] / (pow(1 + irr, i));
	}
	cout << nvp;
}