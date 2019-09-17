#include<iostream>
#include<cstdio>

using namespace std;

int func(int t){
	if(t < 0)return 0;
	if(t == 0)return 1;
	return func(t-1)+func(t-2);
}

int main(){
	int N;
	while(cin >> N)
		cout << func(N) << endl;
	
	return 0;
} 
