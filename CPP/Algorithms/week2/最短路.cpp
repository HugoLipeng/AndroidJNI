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
#define PII pair<int,int>
#define PIII pair<pair<int,int>,int> 
#define mp make_pair
#define pb push_back
#define sz size() 
#define fi first
#define se second
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
#define maxn 100005
int n,m,S,T;
vector<PII> edge[maxn];
int d[maxn];
bool vis[maxn];
class mycmp{
	public:
	bool operator ()(const PII& a,const PII& b)const{
		return a.se>b.se;
	}
};
priority_queue<PII,vector<PII>,mycmp> que;
int main(){
	scanf("%d%d%d%d",&n,&m,&S,&T);
	int u,v,w;
	for(int i=0;i<m;++i){
		scanf("%d%d%d",&u,&v,&w);
		edge[u].pb(mp(v,w));
		edge[v].pb(mp(u,w));
	}
	memset(d,0x3f,sizeof(d));
	d[S]=0;
	que.push(mp(S,d[S]));
	while(!que.empty()){
		PII tmp=que.top();que.pop();
		if(tmp.fi==T) break;
		vis[tmp.fi]=1;
		for(auto p:edge[tmp.fi]){
			if(!vis[p.fi]&&d[tmp.fi]+p.se<d[p.fi]){
				d[p.fi]=d[tmp.fi]+p.se;
				que.push(mp(p.fi,d[p.fi]));
			}
		}
	}
	printf("%d\n",d[T]);
	return 0;
}
