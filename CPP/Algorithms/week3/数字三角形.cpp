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
#define PI3 pair<pair<int,int>,int> 
#define mp make_pair
#define pb push_back
#define sz size() 
#define fi first
#define se second
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
int n;
vector<int> p[1005];
int dp[1005];
int main(){
	int x;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		for(int j=0;j<i+1;++j){
			scanf("%d",&x);
			p[i].push_back(x);
		}
	}
	for(int i=0;i<n;++i){
		dp[i]=p[n-1][i];
	}
	for(int i=n-2;i>=0;--i){
		for(int j=0;j<i+1;++j){
			dp[j]=p[i][j]+max(dp[j],dp[j+1]);
		}
	}
	printf("%d\n",dp[0]);
	return 0;
}
