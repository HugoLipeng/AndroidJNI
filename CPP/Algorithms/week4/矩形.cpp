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
const int N=1005;
int a[N][N],b[N][N];
int n,m,p,q;
int base=2333;int mo1=1e9+7;int mo2=1e9+9;
ll h1[2][N][N],h2[2][N][N];
ll g1[N],g2[N];
vector<PII> getAns(){
	//line scanning
	ll t3=1,t4=1;
	for(int i=1;i<=q;++i) {
		t3=t3*base%mo1;
		t4=t4*base%mo2;
	}
	ll r1=(mo1-t3)%mo1;
	ll r2=(mo2-t4)%mo2;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(j>q){
				h1[0][i][j]=(h1[0][i][j-1]*base+a[i][j]+r1*a[i][j-q])%mo1;
				h2[0][i][j]=(h2[0][i][j-1]*base+a[i][j]+r2*a[i][j-q])%mo2;
			}
			else{
				h1[0][i][j]=(h1[0][i][j-1]*base+a[i][j])%mo1;
				h2[0][i][j]=(h2[0][i][j-1]*base+a[i][j])%mo2;
			}
		}
	}
	//forget to reset the -base^p (mod mo1 or mo2)
	t3=1,t4=1;
	for(int i=1;i<=p;++i) {
		t3=t3*base%mo1;
		t4=t4*base%mo2;
	}
	r1=(mo1-t3)%mo1;
	r2=(mo2-t4)%mo2;
	//col scanning
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			if(i>p){
				h1[1][i][j]=(h1[1][i-1][j]*base+h1[0][i][j]+r1*h1[0][i-p][j])%mo1;
				h2[1][i][j]=(h2[1][i-1][j]*base+h2[0][i][j]+r2*h2[0][i-p][j])%mo2;
			}
			else{
				h1[1][i][j]=(h1[1][i-1][j]*base+h1[0][i][j])%mo1;
				h2[1][i][j]=(h2[1][i-1][j]*base+h2[0][i][j])%mo2;
			}
		}
	}
	for(int i=1;i<=p;++i){
		for(int j=1;j<=q;++j){
			g1[i]=(g1[i]*base+b[i][j])%mo1;
			g2[i]=(g2[i]*base+b[i][j])%mo2;
		}
	}
	ll G1=0,G2=0;
	for(int i=1;i<=p;++i){
		G1=(G1*base+g1[i])%mo1;
		G2=(G2*base+g2[i])%mo2;
	}
	vector<PII> _a;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(h1[1][i][j]==G1&&h2[1][i][j]==G2&&i-p+1>=1&&j-q+1>=1){
				_a.push_back(mp(i-p+1,j-q+1));
			}
		}
	}
	return _a;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",*(a+i)+j);
		}
	}
	for(int i=1;i<=p;i++){
		for(int j=1;j<=q;++j){
			scanf("%d",*(b+i)+j);
		}
	}
	vector<PII> ans=getAns();
	for(int i=0;i<int(ans.size());++i){
		printf("%d %d\n",ans[i].fi,ans[i].se);
	}
	return 0;
}

