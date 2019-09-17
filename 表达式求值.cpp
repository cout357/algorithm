#include<iostream>
#include<cstdio>
//2.3+5.3*2.2-(13.5-2/0.4)-1.2*0.3+8.9
using namespace std;

double biao();
double xiang();
double yinzi();
double fl();
double biao(){
	double result = xiang();		//获取左项的值 
	bool more = true;			//是否还有项 
	while(more){
		char eign = cin.peek();		//查看符号不取出
		if(eign=='+'||eign=='-'){
			cin.get();		//确定该字符后记得丢弃 
			if(eign=='+')  result+=xiang();
			else 	result-=xiang();
		}
		else more = false;		
	} 
	return result;
}

double xiang(){
	double result = yinzi();		//项的值首先为左因子的值 
	bool more = true;			//该项是否还有因子 
	while(more){
		char eign = cin.peek();		//查看符号不取出
		if(eign=='*'||eign=='/'){
			cin.get(); 
			if(eign=='*')result*=yinzi();
			else result/=yinzi();
		}
		else more=false;		//为什么不是乘除这个符号就不丢弃？因为这个符号可能是+-,表达式函数需要查看	
	} 
	return result;
}

double yinzi(){
	double result = 0;		//先把值初始化为零
	char ch = cin.peek(); 
	if(ch=='('){		//如果为左括号 
		cin.get();		//先丢弃这个左括号 
		result = biao();		//则该因子的值就为括号内表达式的值
		cin.get();				//丢弃右括号 
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
	int n = 0;		//位数
	double result = 0;		//小数位总值 
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
	return  result;		//在表达式合法的情况下，小数点后肯定有数字，所以n必然大于0
}

int main(){
	cout << biao() << endl;
	return 0;
} 
