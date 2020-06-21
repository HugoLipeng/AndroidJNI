#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <cstdlib>  
#include <algorithm>  
#include <queue>  
#include <stack>  
#include <map>  
#include <set>  
#include <vector>  
#include <iostream>
#include <utility>
using namespace std;
#define pii pair<int,int> 
#define piii pair<pair<int,int>,int> 
#define mp make_pair
#define pb push_back
#define sz size() 
#define fi first
#define se second
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
const int N=2005;
int n,m,t,d;int ans=0;
pii get(pii p,int type,int n,int m){
	switch(type){
		case 0:return mp(n,p.se);
		case 1:return mp(p.fi,m);
		case 2:return mp(0,p.se);
		case 3:return mp(p.fi,0);
		case 4:return mp(max(0,p.fi+p.se-m),min(p.fi+p.se,m));
		case 5:return mp(min(p.fi+p.se,n),max(0,p.fi+p.se-n));
	}
}
int mind[N][N];
void bfs(int n,int m,int t,int d){
	queue<pii> que;
	memset(mind,-1,sizeof(mind));
	que.push(mp(0,0));mind[0][0]=0;
	while(!que.empty()){
		pii tmp=que.front();que.pop();
		int u=tmp.fi,v=tmp.se;
		if(mind[u][v]==t) break;
		for(int i=0;i<6;++i){
			pii nxt=get(tmp,i,n,m);
			int x=nxt.fi,y=nxt.se;
			if(!(~mind[x][y])){
				que.push(nxt);
				mind[x][y]=mind[u][v]+1;
			}
		}
	}
	ans=-1;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			if(~mind[i][j]&&mind[i][j]<=t){
				ans=(ans==-1)?abs(i+j-d):min(ans,abs(i+j-d));
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&t,&d);
	bfs(n,m,t,d);
	printf("%d\n",ans);
	return 0;
}
