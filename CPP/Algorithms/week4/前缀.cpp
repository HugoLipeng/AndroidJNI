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
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
const int N=1000005;
int t[N][26];int cnt,root;int num[N];
char s[N];
void insert(char* s){
	int len=strlen(s),now=root;
	for(int i=0;i<len;++i){
		if(t[now][s[i]-'a']){
			num[t[now][s[i]-'a']]++;
			now=t[now][s[i]-'a'];
		}
		else{
			t[now][s[i]-'a']=++cnt;
			num[cnt]++;
			now=cnt;
		}
	}
}
int match(char *s){
	int len=strlen(s),now=root;
	for(int i=0;i<len;++i){
		if(t[now][s[i]-'a']){
			now=t[now][s[i]-'a'];
		}
		else return 0;
	}
	return num[now];
}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%s",s);
		insert(s);
	}
	for(int i=0;i<m;++i){
		scanf("%s",s);
		printf("%d\n",match(s));
	}	
	return 0;
}
