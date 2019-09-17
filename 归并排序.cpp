#include<iostream>
#include<cstdio>

using namespace std;

//再把两半排好序的数组组合排成一个新的排好序的数组 
void func2(int a[],int begin,int m,int end,int tmp[]){
	int p = 0;		//做存放进tmp时的下标 
	int p1 = begin,p2 = m+1;		//分别代表每半数组的下标
	//只要有其中一半数组走到头了，就跳出 
	while(p1<=m&&p2<=end){
		if(a[p1]<a[p2]) tmp[p++] = a[p1++];
		else			tmp[p++] = a[p2++];
	}
	//然后如果哪半有剩余，就把哪半依次装进tmp数组 
	while(p1<=m)
		tmp[p++] = a[p1++];
	while(p2<=end)
		tmp[p++] = a[p2++];
	//最后把tmp数组元素拷贝进原数组a
	for(int i = 0;i < (end-begin+1);i++)
		a[begin+i] = tmp[i];
}

//先把要排序的数组两两拆开 
void func1(int a[],int begin,int end,int tmp[]){
	if(begin<end){
		int m = begin+(end-begin)/2;
		func1(a,begin,m,tmp);
		func1(a,m+1,end,tmp);
		func2(a,begin,m,end,tmp);
	}
}

int main(){
	int a[10] = {3,7,1,6,9,0,8,2,5,4};
	int b[10];		//备用数组 
	func1(a,0,9,b);
	for(int i = 0;i < 10;i++)
		printf("%d ",a[i]);
	printf("\n");
	
	return 0;
}
