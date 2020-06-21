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
#define maxn 200005
int n,a[maxn],d[maxn];
ll cnt;
void merge(int l,int r){
	int mid=(l+r)>>1,index=0;
	int p1=l,p2=mid;
	while(p1<mid||p2<r){
		if(p1>=mid) d[index++]=a[p2++];
		else if(p2>=r) d[index++]=a[p1++];
		else{
			if(a[p1]>a[p2]){
				d[index++]=a[p2++];
				cnt+=mid-p1;
			}
			else{
				d[index++]=a[p1++];
			}
		}
	}
	memcpy(a+l,d,index*sizeof(int));
}
void solve(int l,int r){
	if(r-l<=1) return;
	int mid=(l+r)>>1;
	solve(l,mid);
	solve(mid,r);
	merge(l,r);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",a+i);
	}
	solve(0,n);
	printf("%lld\n",cnt);
	return 0;
}
