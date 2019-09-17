#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100000
using namespace std;

int nums[maxn];
int yus[maxn];
int main(){
	int n;			//数字个数 
	int findN;		//查找数字 
	bool find = 0;
	cin >> n >> findN;
	for(int i = 0;i < n;i++){
		cin >> nums[i];
		yus[i] = findN-nums[i];
	}
	sort(nums,nums+n);
	int i = 0,j = n-1;
	while(i!=j){
		if(nums[i]+nums[j]>findN)j--;
		else if(nums[i]+nums[j]<findN)i--;
		else {find = 1;break;}
	}
	if(find)printf("%d+%d=%d\n",nums[i],nums[j],findN);
	else printf("no find\n");
	
	return 0;
} 
