#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 12
using namespace std;

void func(int arr[],int begin,int end){
	if(begin >= end)return;
	int k = arr[begin],i = begin,j = end;
	while(i!=j){
		while(i<j&&arr[j]>=k)j--;	//注意是>=,不然如果有相同的元素会出错 
		swap(arr[i],arr[j]);
		while(i<j&&arr[i]<=k)i++;
		swap(arr[i],arr[j]);
	}
	func(arr,begin,i-1);
	func(arr,i+1,end);
}
int main(){
	int arr[maxn] = {2,6,5,10,9,1,4,7,3,8,0,10};
	func(arr,0,maxn-1);
	for(int i = 0;i < maxn;i++)
		printf("%d ",arr[i]);
	cout << endl;
	
	return 0;
} 
