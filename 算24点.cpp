#include<iostream>
#include<cstdio>
#define EXC 1e-6
using namespace std;

//���������ж��Ƿ���ȵķ���
bool isZero(double num){
	return num<EXC;
} 

bool func(double arr[],int n){
	int m = 0;
	double b[5];
	if(n==1){
		if(isZero(24-arr[0]))return true;
		else return false;
	}
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			m = 0;		//ʣ���������ĸ��� 
			for(int k = 0;k < n;k++){
				if(k!=i&&k!=j){
					b[m++] = arr[k];
				}
			}
			//�������� 
					//�� 
					b[m] = arr[i]+arr[j];
					if(func(b,m+1))return true;
					//���ּ�������һ�� 
					b[m] = arr[i]-arr[j];
					if(func(b,m+1))return true;
					b[m] = arr[j]-arr[i];
					if(func(b,m+1))return true;
					//�� 
					b[m] = arr[i]*arr[j];
					if(func(b,m+1))return true;
					//���ֳ�,ע���������Ϊ0 
					if(arr[i]){
						b[m] = arr[j]/arr[i];
						if(func(b,m+1))return true; 
					}
					if(arr[j]){
						b[m] = arr[i]/arr[j];
						if(func(b,m+1))return true;
					} 
		}
	}
	return false;
}

int main(){
	double arr[4];
	while(1){
		for(int i = 0;i < 4;i++)
			cin >> arr[i];
		if(!arr[0]&&!arr[1]&&!arr[2]&&!arr[3])break;		//���� 
		if(func(arr,4))cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
} 
