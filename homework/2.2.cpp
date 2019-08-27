#include <iostream>
using namespace std;
#include <vector>

int main(){
	int t;
	vector<int> data;
	while(cin >> t){
		data.push_back(t);
	}
	vector<int> myvect(data.size());
	//initialization
	myvect[0] = 1;
	for (int i = 1; i < data.size(); ++i){
		int max = 0;
		for (int j = 0; j < i; ++j){
			if(data[j] < data[i]){
				if(max < myvect[j]){
					max = myvect[j];
				}
			}
		}
		myvect[i] = max + 1;
	}
	int max = 1;	
	int last = 0;
	for (int i = 1; i < data.size(); ++i){
		if(myvect[i] >= max){
			max = myvect[i];
			last = i;
		}
	}
	cout << max << endl << "-" << endl;
	vector<int> subseq;
	for (int i = last; i >= 0; --i){
		if(myvect[i] == max){
			subseq.push_back(data[i]);
			max--;
		}
	}
	for (int i = subseq.size() - 1; i >= 0; --i){
		cout << subseq[i] << endl;
	}
	return 0;
}