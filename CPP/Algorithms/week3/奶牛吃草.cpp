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
#define maxn 1005
int n,k,x[maxn];
int dp[maxn][maxn][2];
int getAns(int n,int k,int x[],int dp[][maxn][2]){
	sort(x+1,x+n+1);
	for(int i=1;i<=n;++i)
		dp[i][i][0]=dp[i][i][1]=abs(k-x[i])*n;
	for(int len=2;len<=n;++len){
		for(int l=1,r;(r=l+len-1)<=n;++l){
			dp[l][r][0]=min(
				dp[l+1][r][0]+(n-r+l)*abs(x[l]-x[l+1]),
				dp[l+1][r][1]+(n-r+l)*abs(x[l]-x[r])
			);
			dp[l][r][1]=min(
				dp[l][r-1][0]+(n-r+l)*abs(x[r]-x[l]),
				dp[l][r-1][1]+(n-r+l)*abs(x[r]-x[r-1])
			);
		}
	}
	return min(dp[1][n][0],dp[1][n][1]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",x+i);
	}
	printf("%d\n",getAns(n,k,x,dp));
	return 0;
}
