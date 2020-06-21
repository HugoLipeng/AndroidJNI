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
const int N=300005;
int n,d,max_value[N],min_value[N];
vector<int> a;
ll solve(int l,int r){
	if(l>=r) return 0;
	int mid=(l+r)>>1;
	ll ans=solve(l,mid)+solve(mid+1,r);
	for(int i=mid+1;i<=r;++i){
		max_value[i]=(i==mid+1)?a[i]:max(max_value[i-1],a[i]);
		min_value[i]=(i==mid+1)?a[i]:min(min_value[i-1],a[i]);
	}
	int mi=0,mx=0;
	for(int i=mid,pos=r;i>=l;--i){
		mi=(i==mid)?a[i]:min(mi,a[i]);
		mx=(i==mid)?a[i]:max(mx,a[i]);
		for(;pos>mid&&max(mx,max_value[pos])-min(mi,min_value[pos])>d;pos--);
		ans+=pos-mid;
	}
	return ans;
}
ll getAnswer(int n,int d,vector<int> a){
	::n=n;
	::d=d;
	::a=a;
	return solve(0,n-1);
}
int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	vector<int> a;
	a.resize(n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	printf("%lld\n",getAnswer(n,d,a));
	return 0;
}
