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
const int N=500005;
char s[N],t[3*N];
int radar[3*N];//radius of the center of the 
ll getAns(int len){
	//extend
	for(int i=0;i<len;++i){
		t[2*i+1]='#';
		t[2*i+2]=s[i];
	}
	t[0]='1';
	t[2*len+1]='#';
	t[2*len+2]='2';
	len=len*2+3;
	memset(radar,0,sizeof(radar));
	int cur=1,r=0;//current center
	for(int i=2;i<len;++i){
		if(2*cur-i>=cur-radar[cur]){
			r=(cur+radar[cur]>=i+radar[cur*2-i])?(radar[cur*2-i]):(cur+radar[cur]-i);
		}
		else{
			r=0;
		}
		r++;
		while(i-r>=0&&i+r<len&&t[i-r]==t[i+r]) r++;
		radar[i]=r-1;
		if(i+radar[i]>cur+radar[cur]) cur=i;
	}
	ll ans=0;
	for(int i=0;i<len;++i){
		ans+=(radar[i]+1)/2;
	}
	return ans;
}
int main(){
	scanf("%s",s);
	int len=strlen(s);
	printf("%lld\n",getAns(len));
	return 0;
}
