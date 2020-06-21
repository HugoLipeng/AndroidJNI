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
#define maxn 300005
int n,a[maxn];
int erfen(int l,int r,int x){
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]>=x) r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	scanf("%d",a+i);
	sort(a,a+n);
	int q;scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		int index=erfen(0,n-1,x);
		if(index>=n) {
			printf("-1\n");
			continue;
		}
		printf("%d\n",a[index]);
	}	
	return 0;
}
