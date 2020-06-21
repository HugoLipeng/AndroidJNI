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
int m,n,a[25];
int rec[25],type[105];
int dfs(int pre,int now){
	if(now==n+1) {
		return 1;
	}
	int ans=0;
	for(int i=0;i<m;++i){
		if(i+1!=pre&&rec[i]){
			rec[i]--;
			ans=(ans+dfs(i+1,now+1))%23333;
			rec[i]++;
		}
	}
	return ans;
}
int main(){
	scanf("%d",&m);
	for(int i=0;i<m;++i){
		scanf("%d",a+i);
		n+=a[i];
	}
	for(int i=0;i<m;++i){
		rec[i]=a[i];
	}
	printf("%d\n",dfs(-1,1));
	return 0;
}
