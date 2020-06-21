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
const int N=100005;
char s[N*5],t[N];
vector<int> match(int n,int m,char *s,char *t){
	vector<int> ans;
	for(int i=0,j=0;i<n;){
		if(s[i]==t[j]) {
			i++;j++;
		}
		else {
			i=i-j+1;
			j=0;
		}
		if(j>=m) ans.push_back(i-m);
	}
	return ans;
}
int main(){
	//when you use the strlen(s) in function(char *s) the error will be happen 
	int n,m;
	scanf("%d",&n);
	scanf("%s",s);
	scanf("%d",&m);
	scanf("%s",t);
	vector<int> ans=match(n,m,s,t);
	for(int i=0;i<int(ans.size());++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}
