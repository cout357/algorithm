#include<iostream>
#include<cstdio>

using namespace std;

//�ٰ������ź������������ų�һ���µ��ź�������� 
void func2(int a[],int begin,int m,int end,int tmp[]){
	int p = 0;		//����Ž�tmpʱ���±� 
	int p1 = begin,p2 = m+1;		//�ֱ����ÿ��������±�
	//ֻҪ������һ�������ߵ�ͷ�ˣ������� 
	while(p1<=m&&p2<=end){
		if(a[p1]<a[p2]) tmp[p++] = a[p1++];
		else			tmp[p++] = a[p2++];
	}
	//Ȼ������İ���ʣ�࣬�Ͱ��İ�����װ��tmp���� 
	while(p1<=m)
		tmp[p++] = a[p1++];
	while(p2<=end)
		tmp[p++] = a[p2++];
	//����tmp����Ԫ�ؿ�����ԭ����a
	for(int i = 0;i < (end-begin+1);i++)
		a[begin+i] = tmp[i];
}

//�Ȱ�Ҫ��������������� 
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
	int b[10];		//�������� 
	func1(a,0,9,b);
	for(int i = 0;i < 10;i++)
		printf("%d ",a[i]);
	printf("\n");
	
	return 0;
}
