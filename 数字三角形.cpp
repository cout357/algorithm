#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 105

using namespace std;

int nums[maxn][maxn];	//������������� 
int maxc[maxn][maxn];	//�Ե����ϴ�������нϴ�������ۼӺ� 
int n;

int func(int i,int j){
	//���֪���ӵ׵����и��е����ֵ ,��ֱ�ӷ��ظ����ֵ,�����ظ����� 
	if(maxc[i][j]!=-1)return maxc[i][j];
	//����������,��ô���и��е����ֵ�����Լ����� 
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
			cin >> nums[i][j];		//�������������� 
			maxc[i][j] = -1;		//��ʼ�� 
		}
	cout << func(1,1) << endl;
	
	return 0;
}
