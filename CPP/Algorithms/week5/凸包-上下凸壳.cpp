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
struct node{
	int x,y,id;
	node(int x,int y):x(x),y(y){
	}
	node(){
	}
}points[N];
bool operator < (const node& a,const node& b) {
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
ll operator ^(const node& a,const node& b){ //be careful to int overflow
	return (ll)a.x*b.y-(ll)b.x*a.y;
}
node operator -(const node&a,const node&b){
	return node(a.x-b.x,a.y-b.y);
}
int st[N];
int getAns(node points[],int n){
	sort(points,points+n);
	int m=0;
	for(int i=0;i<n;++i){
		for(;m>1&&((points[st[m-1]]-points[st[m-2]])^(points[i]-points[st[m-2]]))<0;--m);
		st[m++]=i;
	}
	int t=m;// i start from n-2
	for(int i=n-2;i>=0;--i){
		for(;m>t&&((points[st[m-1]]-points[st[m-2]])^(points[i]-points[st[m-2]]))<0;--m);
		st[m++]=i;
	}
	ll ans=1;
	for(int i=0;i<m-1;++i){ // index endwith m-1
		ans=(ans*(points[st[i]].id))%(n+1);
	}
	return (ans*(m-1))%(n+1);
}
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d",&points[i].x,&points[i].y);
		points[i].id=i+1;
	}
	printf("%d\n",getAns(points,n));
	return 0;
}
