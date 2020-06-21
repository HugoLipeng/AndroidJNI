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
int n,V,_type[5005];
int val[5005],vol[5005],dp[5005];
int main(){
	scanf("%d%d",&n,&V);
	for(int i=0;i<n;++i){
		scanf("%d%d%d",_type+i,val+i,vol+i);
	}
	for(int i=0;i<n;++i){
		if(_type[i]){
			for(int j=vol[i];j<=V;++j){
				dp[j]=max(dp[j],dp[j-vol[i]]+val[i]);
			}
		}
		else{
			for(int j=V;j>=vol[i];--j){
				dp[j]=max(dp[j],dp[j-vol[i]]+val[i]);
			}
		}
	}
	printf("%d\n",dp[V]);
	return 0;
}
