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
const int N=1000006;
int a[N];
bool exist[N];
vector<int> p;
vector<int> tmp;
ll ans;
void dfs(int x,int pre){
	if(x>=int(p.size())){
		ll _ans=0;
		for(int i=0;i<int(tmp.size());++i){
			_ans+=tmp[i];
		}
		ans=max(ans,_ans);
		return;
	}
	for(int i=x+1;i<=int(p.size());++i){
		if(i==int(p.size())){
			dfs(i,0);
			continue;
		}
		if(abs(p[i]-p[x])<pre) continue;
		tmp.pb(a[p[i]]);
		dfs(i,abs(p[i]-p[x]));
		tmp.pop_back();
	}
}
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i){
		int x,y;scanf("%d%d",&x,&y);
		p.push_back(x);
		a[x]=y;
		exist[x]=1;
	}
	sort(p.begin(),p.end());
	//left to right
	 for(int i=0;i<int(p.size());++i){
	 	tmp.push_back(a[p[i]]);
	 	dfs(i,0);
	 	tmp.pop_back();
	 }
	 reverse(p.begin(),p.end());
	 //right to left
	 for(int i=0;i<int(p.size());++i){
	 	tmp.push_back(a[p[i]]);
	 	dfs(i,0);
	 	tmp.pop_back();
	 }
	 printf("%lld\n",ans);
	return 0;
}
