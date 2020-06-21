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
vector<int> pos,a,b,f;
int getAns(int n,vector<int>a,vector<int>b){
	f.resize(n+1);pos.resize(n+1);
	for(int i=0;i<=n;++i) f[i]=n+2;
	for(int i=1;i<=n;++i){
		pos[b[i]]=i;
	}
	for(int i=1;i<=n;++i){
		a[i]=pos[a[i]];
	}
	f[0]=0;
	for(int i=1;i<=n;++i)
	*lower_bound(f.begin(),f.end(),a[i])=a[i];
	return int(lower_bound(f.begin(),f.end(),n+1)-f.begin())-1;
}
int main(){
	int n;scanf("%d",&n);
	a.resize(n+1);b.resize(n+1);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&b[i]);
	}
	printf("%d\n",getAns(n,a,b));
	return 0;
}
