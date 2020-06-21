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
ll a[maxn],ans;int n,m;
bool check(ll d,int _m){
	ll sum=0;int cnt=1;
	for(int i=0;i<n;++i){
		if(a[i]>d) return false;
		sum+=a[i];
		if(sum>d) {
			sum=a[i];
			cnt++;
		}
	}
	if(cnt<=_m) return true;
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
	scanf("%lld",a+i);
	ll l=0,r=0,mid;
	for(int i=0;i<n;++i) r+=a[i];	
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid,m)) r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",r+1);
	return 0;
}
