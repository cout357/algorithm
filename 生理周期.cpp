#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

 int main(){
 	int a,b,c,d;		//23 28 33
 	while(cin >> a >> b >> c >> d&&a!=-1){
 		//�������Ƕ���ɵ�һ��С��d�ĸ߷��� 
		a%=23;b%=28;c%=33;
		for(;c<=d;c+=33);
		for(;(c-b)%28;c+=33);
		for(;(c-a)%23;c+=28*33);
		cout << c-d << endl;
    }
    
 	return 0;
 }
