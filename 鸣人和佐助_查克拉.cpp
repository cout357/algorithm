#include<iostream>
#include<cstdio>
#define N 105
using namespace std;

char map[N][N];
struct node{
	int i,j;
	int c;	//查克拉 
	int f;	//父位置
	int t;
};
struct queue{
	node d[N*N*N];
	int front;
	int rear;
}que;
void push(int i,int j,int c,int f,int t){
	node tmp;
	tmp.i=i;tmp.j=j;tmp.c=c;tmp.f=f;tmp.t=t;
	que.d[que.rear++] = tmp;
}
void pop(){
	que.front++;
}
int seen[N][N][N] = {0};
char fmap[N][N];
int main(){
	int row,col,c;
	node begin,end;
	bool find = false;		//找到佐助
	int ccg;		//需要使用查克拉 
	cin >> row >> col >> c;
	//接收地图与找鸣人和佐助的坐标 
	cin.get();
	for(int i = 1;i <=row;i++){
		for(int j = 1;j<=col;j++){
			map[i][j] = cin.get();
			fmap[i][j] = '#';
			if(map[i][j]=='@'){begin.i=i;begin.j=j;}
			else if(map[i][j]=='+'){end.i=i;end.j=j;}
		}
		cin.get();
	}
	//bfs
	que.front = -1;
	que.rear = 0;
	push(begin.i,begin.j,c,-2,0);
	seen[begin.i][begin.j][c] = 1;
	while(que.front!=que.rear){
		node t = que.d[que.front+1];
		if(t.i==end.i&&t.j==end.j){find = true;break;}
		for(int ra = -1;ra<=1;ra++)
			for(int ca = -1;ca<=1;ca++)
				if((ra||ca)&&(ra==0||ca==0))
					if(t.i+ra>0&&t.i+ra<=row&&t.j+ca>0&&t.j+ca<=col){		//首先确保不出界 
						ccg = 0;
						if(map[t.i+ra][t.j+ca]=='#'){		//需要使用查克拉 
							ccg = -1;
						}
						if(t.c+ccg>=0&&seen[t.i+ra][t.j+ca][t.c+ccg]==0){					//走过后查克拉要不为负 
							push(t.i+ra,t.j+ca,t.c+ccg,t.f=que.front,t.t+1);
							seen[t.i+ra][t.j+ca][t.c+ccg] = 1;
						}
					}
		pop();
	}
	
	if(find){
		cout << "time = " << que.d[que.front+1].t << endl;
		while(que.front!=-2){
			fmap[que.d[que.front+1].i][que.d[que.front+1].j] = ' ';
			que.front = que.d[que.front+1].f;
		}
		for(int i = 1;i <=row;i++){
			for(int j = 1;j<=col;j++)
				cout << fmap[i][j];
			cout << endl;
		}
	}
	else cout << "can't go on." << endl;
	
	return 0;	
}

/*测试数据

4 4 1
#@##
**##
###*
****
	
6 6 2
#@##*#
**#**+
***#**
******
******
****** 
*/
