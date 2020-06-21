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
int n,ans;
bool row[20],dig[80],_dig[80];
void solve(int now){
	if(now==n+1){
		ans++;
		return;
	}
	// row:now
	// col:i
	for(int i=1;i<=n;++i){
		if(!row[i]&&!dig[2*n+now-i]&&!_dig[now+i]){
			row[i]=dig[2*n+now-i]=_dig[now+i]=1;
			solve(now+1);
			row[i]=dig[2*n+now-i]=_dig[now+i]=0;
		}		
	}
}
int main(){
	scanf("%d",&n);
	solve(1);
	printf("%d\n",ans);
	return 0;
}
