#include<iostream>
#include<cstdio>
//2.3+5.3*2.2-(13.5-2/0.4)-1.2*0.3+8.9
using namespace std;

double biao();
double xiang();
double yinzi();
double fl();
double biao(){
	double result = xiang();		//��ȡ�����ֵ 
	bool more = true;			//�Ƿ����� 
	while(more){
		char eign = cin.peek();		//�鿴���Ų�ȡ��
		if(eign=='+'||eign=='-'){
			cin.get();		//ȷ�����ַ���ǵö��� 
			if(eign=='+')  result+=xiang();
			else 	result-=xiang();
		}
		else more = false;		
	} 
	return result;
}

double xiang(){
	double result = yinzi();		//���ֵ����Ϊ�����ӵ�ֵ 
	bool more = true;			//�����Ƿ������� 
	while(more){
		char eign = cin.peek();		//�鿴���Ų�ȡ��
		if(eign=='*'||eign=='/'){
			cin.get(); 
			if(eign=='*')result*=yinzi();
			else result/=yinzi();
		}
		else more=false;		//Ϊʲô���ǳ˳�������žͲ���������Ϊ������ſ�����+-,���ʽ������Ҫ�鿴	
	} 
	return result;
}

double yinzi(){
	double result = 0;		//�Ȱ�ֵ��ʼ��Ϊ��
	char ch = cin.peek(); 
	if(ch=='('){		//���Ϊ������ 
		cin.get();		//�ȶ������������ 
		result = biao();		//������ӵ�ֵ��Ϊ�����ڱ��ʽ��ֵ
		cin.get();				//���������� 
	} 
	else{
		while(ch>='0'&&ch<='9'||ch=='.'){
			cin.get();
			if(ch=='.'){ result+=fl();break;}
			result = 10*result+ch-'0';
			ch = cin.peek();
		}
	}
	return result;
}

double fl(){
	int n = 0;		//λ��
	double result = 0;		//С��λ��ֵ 
	char ch = cin.peek();
	while(ch>='0'&&ch<='9'){
		n++;
		cin.get();
		result = 10*result+ch-'0';
		ch = cin.peek();
	} 
	while(n--){
		result/=10;
	}
	return  result;		//�ڱ��ʽ�Ϸ�������£�С�����϶������֣�����n��Ȼ����0
}

int main(){
	cout << biao() << endl;
	return 0;
} 
