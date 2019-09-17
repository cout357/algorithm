#include<iostream>
#include<cstdio>

using namespace std;

char *func(char ch,int light,char left[],char right[]){
	int leftSum = 0,rightSum = 0;
	for(int i = 0;i < 4;i++){
		if(left[i]==ch)leftSum+=light;
		else leftSum+=2;
	}
	for(int i = 0;i < 4;i++){
		if(right[i]==ch)rightSum+=light;
		else rightSum+=2;
	}
	if(leftSum == rightSum)return "even";
	else if(leftSum < rightSum)return "down";
	else return "up";
}

bool strc(char *p,char *q){
	if(*p == *q)return true;
	else return false;
}

int main(){
	char r1_left[4],r1_right[4];
	char r2_left[4],r2_right[4];
	char r3_left[4],r3_right[4];
	char result[3][10];
	char ch;
	while(1){
		cin >> r1_left >> r1_right >> result[0];
		cin >> r2_left >> r2_right >> result[1];
		cin >> r3_left >> r3_right >> result[2];
		for(ch = 'A';ch<='L';ch++){
			if(strc(func(ch,1,r1_left,r1_right),result[0])&&strc(func(ch,1,r2_left,r2_right),result[1])&&strc(func(ch,1,r3_left,r3_right),result[2])){
				cout << ch << ":qing" << endl;break;
			}
			if(strc(func(ch,3,r1_left,r1_right),result[0])&&strc(func(ch,3,r2_left,r2_right),result[1])&&strc(func(ch,3,r3_left,r3_right),result[2])){
				cout << ch << ":zhong" << endl;break;
			}
		}
	}
	
	return 0;
}
