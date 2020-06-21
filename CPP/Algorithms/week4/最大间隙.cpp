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
#define pii pair<int,int> 
#define piii pair<pair<int,int>,int> 
#define mp make_pair
#define pb push_back
#define sz size() 
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u32;
const int N=67108869;
u32 a[N],l[N],r[N];
u32 nextInt(u32 x){
	x^=x<<13;
	x^=x>>17;
	x^=x<<5;
	return x;
}
void initData(u32 *a,int n,int k,u32 seed){
	for (int i=0;i<n;++i){
		seed=nextInt(seed);
		a[i]=seed>>(32-k);
	}
}
u32 maxGap(u32 *a,int n,int k){
	int m=1<<26;
	const int _k=max(k-26,0);
	memset(l,-1,sizeof(int)*m);
	memset(r,-1,sizeof(int)*m);
	for(int i=0;i<n;++i){
		int bl=a[i]>>_k;
		if(l[bl]==-1){
			l[bl]=r[bl]=a[i];
		}
		else if(a[i]<l[bl]){
			l[bl]=a[i];
		}
		else if(a[i]>r[bl]){
			r[bl]=a[i];
		}
	}
	u32 last=a[0],ans=0;
	for(int i=0;i<m;++i){
		if(l[i]!=-1){
			if(last>l[i]) last=l[i];
			if(l[i]-last>ans) ans=l[i]-last;
			last=r[i];
		}
	}
	return ans;
}
int main(){
	int n,k;u32 seed;
	scanf("%d%d%u",&n,&k,&seed);
	initData(a,n,k,seed);
	printf("%u\n",maxGap(a,n,k));
	return 0;
}
