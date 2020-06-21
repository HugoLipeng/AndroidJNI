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
const int N = 10005;


int n, m, in[N];
vector<int> e[N];


bool getAnswer(int n) {
	int x=0;
	for(int i=1;i<=n;++i){
		if(in[i]==0){
			if(x!=0) return 0;
			x=i;
		}
	}
	for(int k=0;k<n;++k){
		int z=0;
		for(int i=0;i<int(e[x].size());++i){
			int y=e[x][i];
			if(--in[y]==0){
				if(z!=0) return 0;
				z=y;
			}
		}
		x=z;
	}
	return 1;
}



int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            in[i] = 0;
            e[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            e[x].push_back(y);
            ++in[y];
        }
        printf("%d\n", getAnswer(n));
    }
    return 0;
}

