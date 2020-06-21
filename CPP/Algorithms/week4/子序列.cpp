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
const int N=500005;
const int mo=23333;
char s[N];
int dp[N];
int pre[N][26];
int getAns(int len){
	for(int i=0;i<26;++i) pre[1][i]=0;
	for(int i=1;i<=len;++i){
		for(int j=0;j<26;++j){
			pre[i+1][j]=pre[i][j];
		}
		pre[i+1][s[i]-'a']=i;
	}
	for(int i=1;i<=len;++i){
		int k=pre[i][s[i]-'a'];
		if(k!=0){
			dp[i]=dp[i-1]+dp[i-1]-dp[k-1];
		}
		else{
			dp[i]=dp[i-1]+dp[i-1]+1;
		}
		dp[i]=(dp[i]%mo+mo)%mo; 
	}
	return dp[len];
}

int main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	printf("%d\n",getAns(len));
	return 0;
}
