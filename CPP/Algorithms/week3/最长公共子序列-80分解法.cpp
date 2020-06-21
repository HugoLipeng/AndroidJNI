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
int a[maxn],b[maxn];
int dp[maxn][maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",a+i);
	}
	for(int i=0;i<n;++i){
		scanf("%d",b+i);
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(a[i]==b[j]){
				dp[i+1][j+1]=dp[i][j]+1;
			}
			else{
				dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
			}
		}
	}
	printf("%d\n",dp[n][n]);
	return 0;
}
