#include<iostream>
#include<cstdio>
#include<queue>
#define maxn 100000
using namespace std;

struct node{
	int at;
	int time;
};
int main(){
	int farm,cow;
	queue<node> que;
	int seen[maxn] = {0};
	
	cin >> farm >> cow;
	que.push(node{farm,0});
	while(!que.empty()){
		if(que.front().at==cow){cout << que.front().time << endl;break;}
		node tmp = que.front();
		que.pop();
		if(tmp.at-1>=0&&seen[tmp.at-1]==0){que.push(node{tmp.at-1,tmp.time+1});seen[tmp.at-1]=1;};
		if(tmp.at+1<maxn&&seen[tmp.at+1]==0){que.push(node{tmp.at+1,tmp.time+1});seen[tmp.at+1]=1;};
		if(tmp.at*2<maxn&&seen[tmp.at*2]==0){que.push(node{tmp.at*2,tmp.time+1});seen[tmp.at*2]=1;};
	}
	
	return 0;
}
