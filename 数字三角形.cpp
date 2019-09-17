#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 105

using namespace std;

int nums[maxn][maxn];	//存放数字三角形 
int maxc[maxn][maxn];	//自底向上存放左右中较大的数字累加和 
int n;

int func(int i,int j){
	//如果知道从底到该行该列的最大值 ,就直接返回该最大值,不用重复计算 
	if(maxc[i][j]!=-1)return maxc[i][j];
	//如果是最低行,那么该行该列的最大值就是自己本身 
	if(i==n)  maxc[i][j] = nums[i][j];
	else{
		int x = func(i+1,j);
		int y = func(i+1,j+1);
		maxc[i][j] = max(x,y)+nums[i][j];
	}
	return maxc[i][j];
} 
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= i;j++){
			cin >> nums[i][j];		//接收数字三角形 
			maxc[i][j] = -1;		//初始化 
		}
	cout << func(1,1) << endl;
	
	return 0;
}
