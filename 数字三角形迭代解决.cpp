#include<algorithm>
#include<iostream>
#include<cstdio>
#define maxn 105

using namespace std;

int nums[maxn][maxn];	//������������� 
int maxc[maxn][maxn] = {0};	//�Ե����ϴ�������нϴ�������ۼӺ�
int n;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= i;j++)
			nums[i][j] = j;		//�������������� 
	//���ļ��㲿�� 
	for(int i = n;i;i--)
		for(int j = 1;j <= i;j++)
			maxc[i][j] = max(maxc[i+1][j],maxc[i+1][j+1])+nums[i][j];
	
	cout << maxc[1][1] << endl;
	
	return 0;
}
