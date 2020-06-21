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
#define maxn 5005
#define maxv 5000
int n,v[maxn],w[maxn];
int pre[maxn][maxn],back[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d",v+i,w+i);
	}
	// pre[i][j] 考虑1~i种物品 容量为j的价值
	for(int i=0;i<n;++i){
		for(int j=maxv;j>=0;--j){
			if(j>=v[i])
			pre[i+1][j]=max(pre[i][j],pre[i][j-v[i]]+w[i]);
			else 
			pre[i+1][j]=pre[i][j];
		}
	} 
	// back[i][j] 考虑i~n种物品 容量为j的价值 
	for(int i=n-1;i>=0;--i){
		for(int j=5000;j>=0;--j){
			if(j>=v[i])
			back[i+1][j]=max(back[i+2][j],back[i+2][j-v[i]]+w[i]);
			else
			back[i+1][j]=back[i+2][j];
		}
	} 
	int q;
	scanf("%d",&q);
	while(q--){
		int V,x;
		scanf("%d%d",&V,&x);
		int ans=0;
		for(int j=0;j<=V;++j){
			ans=max(ans,pre[x-1][j]+back[x+1][V-j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
