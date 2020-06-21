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
const int N=2e5+5;
bool notPrime[N],notDeng[N];
vector<int> getAns(int n,int k){
	notDeng[1]=notDeng[2]=1;
	notPrime[1]=1;
	for(int i=2;i<=n;++i){
		if(!notPrime[i]){
			notDeng[i]=1;
			for(int j=2*i;j<=n;j+=i){
				notPrime[j]=1;
			}	
		}
		else{
			for(int j=2*i;j<=n;j+=i){
				notDeng[j]=1;
			}
		}
	}
	vector<int> ans;
	for(int i=1;i<=n;++i){
		if(k==0) {
			if(!notPrime[i]) ans.push_back(i);
		}
		else if(!notDeng[i]) ans.push_back(i);
	}
	return ans;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	vector<int> ans=getAns(n,k);
	for(int i=0;i<int(ans.size());++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}
