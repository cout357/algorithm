#include<iostream>
#include<cstdio>

using namespace std;
//4 7 1 9 6 0 5 3 2 8
//2 7 1 9 6 0 5 3 4 8
void func(int arr[],int begin,int end){
	if(begin >= end)return;
	int k = arr[begin];
	int t;
	int n = 0;		//交换次数 
	int *i = arr+begin,*j = arr+end;
	while(i!=j){
		//奇次交换 
		if(n%2){
			if(*i>k){
				t = *i;
				*i = *j;
				*j = t;
				n++;
				j--;
			}
			else i++;
		}
		else{
			if(*j<k){
				t = *j;
				*j = *i;
				*i = t;
				n++;
				i++;
			}
			else j--;	
		}
	}
	cout << begin << i-arr << end << endl;
	func(arr,begin,i-arr-1);
	func(arr,i-arr+1,end);
}
int main(){
	int arr[10] = {4,7,1,9,6,0,5,3,2,8};
	func(arr,0,9);
	for(int i = 0;i < 10;i++)
		printf("%d ",arr[i]);
	cout << endl;
	
	return 0;
}
