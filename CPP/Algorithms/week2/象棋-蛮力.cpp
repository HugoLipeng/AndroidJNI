#include <cstdio>
#include <time.h>  
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
#define maxn 505
int n;
int st,ed;
int mat[maxn][maxn];int ans;
int rec[maxn];
bool row[maxn],col[maxn];
void dfs(int now){
//	if(double(clock()-st)/CLOCKS_PER_SEC>=2.9) return;
	if(now==n) {
		int tmp=0;
		for(int i=0;i<now;++i){
			tmp+=rec[i];
		}
		ans=max(ans,tmp);
		return;
	}
	int sum=0;
	for(int i=0;i<n;++i){
		if(mat[now][i]&&!row[now]&&!col[i]){
			row[now]=col[i]=rec[now]=1;
			sum++;
//			if(double(clock()-st)/CLOCKS_PER_SEC>=2.9) return;
			dfs(now+1);
			row[now]=col[i]=rec[now]=0;
		}
	}
	if(sum==0||row[now]){
		rec[now]=0;
//		if(double(clock()-st)/CLOCKS_PER_SEC>=2.9) return;
		dfs(now+1);
		return ;
	}
}
int main(){
	st=clock();
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			scanf("%d",*(mat+i)+j);
		}
	}
	dfs(0);
	printf("%d\n",ans);
	return 0;
}
