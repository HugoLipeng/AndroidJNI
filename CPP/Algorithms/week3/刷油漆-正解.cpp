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
const int N=21;
const int mod=23333;
int dp[N][N][N][N][N][6];
int a[21],b[6];
int dfs(int a,int b,int c,int d,int e,int last){
	if(~dp[a][b][c][d][e][last]) return dp[a][b][c][d][e][last];
	if(a==0&&b==0&&c==0&&d==0&&e==0) return dp[a][b][c][d][e][last]=1;
	ll ans=0;
	if(a&&a-(last==2)>0) ans+=(a-(last==2))*dfs(a-1,b,c,d,e,1);
	if(b&&b-(last==3)>0) ans+=(b-(last==3))*dfs(a+1,b-1,c,d,e,2);
	if(c&&c-(last==4)>0) ans+=(c-(last==4))*dfs(a,b+1,c-1,d,e,3);
	if(d&&d-(last==5)>0) ans+=(d-(last==5))*dfs(a,b,c+1,d-1,e,4);
	if(e) ans+=e*dfs(a,b,c,d+1,e-1,5);
	return dp[a][b][c][d][e][last]=ans%mod;
}
int main(){
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;++i) scanf("%d",a+i);
	for(int i=0;i<m;++i){
		b[a[i]]++;
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",dfs(b[1],b[2],b[3],b[4],b[5],0));
	return 0;
}
