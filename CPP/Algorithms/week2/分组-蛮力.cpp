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
typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
#define mp make_pair
#define pb push_back
#define sz size() 
#define fi first
#define se second
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
#define maxn 300005
#define inf 1000005
int n,m,a[maxn];
int sum[maxn];
int dp[100][100][100];
int dfs(int l,int r,int m){
	if(~dp[l][r][m]) return dp[l][r][m];
	if(m==1) return sum[r]-sum[l-1];
	int ans=inf;
	for(int i=l;i<=r;++i){
		for(int j=1;j<m;++j){
			int linshi;
			if(i-l+1>=j&&r-i>=m-j)
			linshi=max(dfs(l,i,j),dfs(i+1,r,m-j));
			ans=min(ans,linshi);
		}
	}
	return dp[l][r][m]=ans;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
	scanf("%d",a+i);
	for(int i=0;i<n;++i)
	sum[i+1]=a[i]+sum[i];
	memset(dp,-1,sizeof(dp));
	int ans=dfs(1,n,m);
	printf("%d\n",ans);
	return 0;
}
