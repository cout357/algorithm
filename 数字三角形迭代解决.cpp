#include<algorithm>
#include<iostream>
#include<cstdio>
#define maxn 105

using namespace std;

int nums[maxn][maxn];	//存放数字三角形 
int maxc[maxn][maxn] = {0};	//自底向上存放左右中较大的数字累加和
int n;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= i;j++)
			nums[i][j] = j;		//接收数字三角形 
	//核心计算部分 
	for(int i = n;i;i--)
		for(int j = 1;j <= i;j++)
			maxc[i][j] = max(maxc[i+1][j],maxc[i+1][j+1])+nums[i][j];
	
	cout << maxc[1][1] << endl;
	
	return 0;
}
