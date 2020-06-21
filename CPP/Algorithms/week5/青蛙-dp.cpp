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
const int N=1000006;
const int maxn=1005;
int a[N];
vector<int> p;
ll dp[maxn][maxn];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i){
		int x,y;scanf("%d%d",&x,&y);
		p.push_back(x);
		a[x]=y;
	}
	ll ans=0;
	for(int rd=0;rd<2;++rd){
		sort(p.begin(),p.end());
		for(int i=0;i<int(p.size());++i){
			dp[i][i]=a[(p[i]<0)?-p[i]:p[i]];
			for(int j=0;j<i;++j){
				dp[i][j]=0;
				for(int k=j;k>=0&&p[i]-p[j]>=p[j]-p[k];--k){
					dp[i][j]=max(dp[i][j],dp[j][k]);
				}
				ans=max(ans,(dp[i][j]+=a[(p[i]<0)?-p[i]:p[i]]));
			}
		}
		for(int i=0;i<int(p.size());++i){
			p[i]=-p[i];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
