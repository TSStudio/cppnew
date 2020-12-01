#include<bits/stdc++.h>

using namespace std;

bool h[55][55];
int dis[55];
int T,N,d;

queue<int> q;

void init(){
	for(int i=0;i<55;i++){
		dis[i]=10000005;
	}
}
void SPFA(){
	while(q.size()){
		int n=q.front();
		q.pop();
		for(int i=1;i<=N;i++){
			if(!h[n][i]) continue;
			if(dis[i]>dis[n]+1){
				dis[i]=dis[n]+1;
				q.push(i);
			}
		}
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("bridge.in","r",stdin);
	freopen("bridge.out","w",stdout);
	scanf("%d",&T);
	register char c;
	for(int i=0;i<T;i++){
		scanf("%d%d",&N,&d);
		for(int j1=1;j1<=N;j1++){
			for(int j2=1;j2<=N;j2++){
				scanf(" %c",&c);
				if(c=='Y') h[j1][j2]=true;
				else h[j1][j2]=false;
			}
		}
		q.push(1);
		init();
		dis[1]=0;
		SPFA();
		bool flg=false;
		for(int j=1;j<=N;j++){
			if(dis[j]==10000005){
				printf("-1\n");
				flg=1;
				break;
			}
		}
		if(flg) continue;
		sort(dis+2,dis+N+1,cmp);
		printf("%d\n",dis[2]*d);
	}
	return 0;
}
