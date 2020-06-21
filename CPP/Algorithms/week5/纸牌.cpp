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
const int N=50005;
int a[N],b[N];
bool vis[N*2];

int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		vis[a[i]]=1;
	}
	int cnt=0;
	for(int i=1;i<=2*n;++i){
		if(!vis[i]) b[++cnt]=i;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	int ans=0;
	for(int j=1,i=1;j<=n;++j){
		if(a[i]<b[j]) {
			ans++;i++;
		}
	}	
	printf("%d\n",ans);
	return 0;
}
