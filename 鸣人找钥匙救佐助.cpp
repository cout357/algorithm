#include<iostream>
#include<cstdio>
#include<set> 
#define N 105
using namespace std;

struct node{
	int i,j;
	int f,key,t;
	set<char> keys;
};
struct queue{
	node d[N*N*N];
	int front,rear;
}que;

void push(int i,int j,int f,int key,int t,set<char> keys){
	node tmp;
	tmp.i = i;tmp.j = j;tmp.f = f;tmp.key = key;tmp.t = t;tmp.keys = keys;
	que.d[que.rear++] = tmp;
}

void pop(){
	que.front++;
}

int main(){
	int seen[N][N][N] = {0};
	char map[N][N];
	char fmap[N][N];
	bool find = 0;
	int row,col;
	node begin,end;
	int ka;
	begin.key = 0;end.key = 0;
	cin >> row >> col;
	//地图中,'#'代表墙,' '代表通路,'@'代表鸣人位置,'+'代表佐助位置,'数字'代表钥匙
	cin.get();
	for(int i = 1;i <= row;i++){
		for(int j = 1;j <= col;j++){
			if(cin.peek()=='*')end.key++;
			else if(cin.peek()=='@'){begin.i = i;begin.j = j;}
			else if(cin.peek()=='+'){end.i = i;end.j = j;}
			map[i][j] = cin.get();
			fmap[i][j] = '#';
		}
		cin.get();
	}
	//bfs
	que.front = -1;que.rear = 0;
	set<char> st;
	push(begin.i,begin.j,-2,begin.key,0,st);
	seen[begin.i][begin.j][begin.key] = 1;
	while(que.front != que.rear){
		node t = que.d[que.front+1];
		if(t.i==end.i&&t.j==end.j&&t.key==end.key){find = true;break;}
		for(int ra = -1;ra <= 1;ra++)
			for(int ca = -1;ca <= 1;ca++)
				if((ca||ra)&&(ca==0||ra==0))
					if(t.i+ra>0&&t.i+ra<=row&&t.j+ca>0&&t.j<=col&&map[t.i+ra][t.j+ca]!='#'){	//先确保不越界 与不撞墙 
						ka = 0;
						if(map[t.i+ra][t.j+ca]>='0'&&map[t.i+ra][t.j+ca]<='9'&&t.keys.find(map[t.i+ra][t.j+ca])==t.keys.end()){		//如果这里有钥匙且是没捡过的
							ka++;
							st = t.keys;
							st.insert(map[t.i+ra][t.j+ca]);
						}
						if(seen[t.i+ra][t.j+ca][t.key+ka]==0){
							push(t.i+ra,t.j+ca,que.front,t.key+ka,t.t+1,st);
							seen[t.i+ra][t.j+ca][t.key+ka];
						}
					}
		pop();
	}
	if(find){
		while(que.front!=-2){
			fmap[que.d[que.front+1].i][que.d[que.front+1].j] = ' ';
			que.front = que.d[que.front+1].f;
		}
		for(int i = 1;i <= row;i++){
			for(int j = 1;j <= col;j++)
				cout << fmap[i][j];
			cout << endl;
		}
	}
	else cout << "can't do it." << endl;
	
	return 0;
}
