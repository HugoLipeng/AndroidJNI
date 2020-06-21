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
#define maxn 80000
int allOne,n;
bool vis[2][maxn];
string ans;
int twoPow(int x){
	return 1<<x;
}
void dfs(int u){
	for(int i=0;i<2;++i){
		if(!vis[i][u]){
				int nxt=((u<<1)|i)&allOne;
				vis[i][u]=1;
				dfs(nxt);
				ans.push_back('0'+i);
		}
	}
}
void getAnswer(int _n){
	_n=n;
	ans="";
	allOne=twoPow(_n-1)-1;
	dfs(0);
}
int main(){
	scanf("%d",&n);
	getAnswer(n);
	printf("%s\n",ans.c_str());
	return 0;
}
