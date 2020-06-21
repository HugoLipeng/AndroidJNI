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
int ans,allOne;
int twoPow(int x){
	return 1<<x;
}
void dfs(int pos,int left,int right){
	if(pos==allOne){
		ans++;return;
	}
	for(int i=allOne&(~(pos|left|right));i>0;){
		int t=i&-i;
		dfs(pos|t,(left|t)<<1,(right|t)>>1);
		i^=t; 
	}
}
int main(){
	int n;scanf("%d",&n);
	allOne=twoPow(n)-1;
	dfs(0,0,0);
	printf("%d\n",ans);
	return 0;
}
