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
const int N=505;
struct node{
	int to,next;
}edge[N*N];int cnt;
int ans;
int ihead[N];bool vis[N*2];int mc[N*2];
void add(int u,int v){
	cnt++;
	edge[cnt].next=ihead[u];
	edge[cnt].to=v;
	ihead[u]=cnt;
}

bool dfs(int x){
	for(int v=ihead[x];v;v=edge[v].next){
		int y=edge[v].to;
		if(!vis[y]){
			vis[y]=true;
			if(mc[y]==0||dfs(mc[y])){
				mc[x]=y;
				mc[y]=x;
				return true;
			}
		}
	}
	return false;
}
int getAns(int n){
	ans=0;
	for(int i=1;i<=n;++i){
		memset(vis,0,sizeof(vis));
		if(dfs(i)){
			ans++;
		}
	}
	return ans;
}
int main(){
	int n,x;
	scanf("%d",&n);
	cnt=0;
	for(int i=1;i<=n;++i) ihead[i]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			scanf("%d",&x);
			if(x){
				add(i,j+n);
			}
		}	
	}
	printf("%d\n",getAns(n));
	return 0;
}
