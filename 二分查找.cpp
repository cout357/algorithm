#include<iostream>
#include<cstdio>

using namespace std;
//在size范围内查找p，如果找到了就返回它在数组arr中的下标，找不到就返回-1 
void func(int size,int p){
	int min = 0;
	int max = size;
	int mid;
	bool find = 0;
	do{
		mid = (max+min)/2;
		if(mid>p)max = mid;
		else if(mid < p)min = mid;
		else {find = 1;break;};
	}while(1);
	if(find)printf("p = %d\n",mid);
	else printf("no find.\n");
}
int main(){
	int num = 37;
	int x;
	func(1000,num);
	
	return 0;
}
