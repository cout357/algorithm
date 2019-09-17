#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 105

using namespace std;

int main(){
	int n;
	int nums[maxn][maxn] = {0};
	
	cin >> n;
	int *sum = nums[n];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= i;j++)
			cin >> nums[i][j];
	
	for(int i = n-1;i;i--)
		for(int j = 1;j <= i;j++)
			sum[j] = max(sum[j],sum[j+1]) + nums[i][j];
	cout << sum[1] << endl;
	
	return 0;
}
