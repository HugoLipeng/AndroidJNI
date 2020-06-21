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
#define maxn 500005
int n,a[maxn];
int partition(int l,int r){
	int pivot=a[l];
	while(l<r){
		while(l<r&&a[r]>=pivot) r--; a[l]=a[r];
		while(l<r&&a[l]<=pivot) l++; a[r]=a[l];
	}
	a[l]=pivot;
	return l;
}
void solve(int l,int r){
	if(r-l+1<=1) return;
	int mid=partition(l,r);
	solve(l,mid);
	solve(mid+1,r);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",a+i);
	}
	solve(0,n-1);
	for(int i=0;i<n;++i){
		printf("%d",a[i]);
		if(i!=n-1) printf(" ");
		else printf("\n");
	}
	return 0;
}
