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
const int N=300005;
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
node operator -(const node&a,const node&b){
	return node(a.x-b.x,a.y-b.y);
}
ll v_toLeft(const node&a,const node&b,const node&c){
	return (ll)a.x*b.y-(ll)a.y*b.x
		 + (ll)b.x*c.y-(ll)b.y*c.x
		 + (ll)c.x*a.y-(ll)c.y*a.x;
}
bool to_Left(const node&a,const node&b,const node&c){
	return 0>v_toLeft(a,b,c);
}
ll dist(const node& a){
	ll x=(a.x-points[0].x);
	ll y=(a.y-points[0].y);
	return x*x+y*y;
}
ll cross(node p0,node p1,node p2) 
{
    return (ll)(p1.x-p0.x)*(p2.y-p0.y)-(ll)(p1.y-p0.y)*(p2.x-p0.x);
}    
bool cmp(node p1,node p2) 
{
    ll tmp=cross(points[0],p1,p2);  
    if(tmp>0) return true;
    else if(tmp==0&&dist(p1)<dist(p2)) return true;//three points on one line
    else return false;
}    
int st[N];
int getAns(node points[],int n){	
	sort(points+1,points+n,cmp);
	int i=0,m=0;
	while(i<n){
		while(m>1&&to_Left(points[st[m-2]],points[st[m-1]],points[i])){
			--m;
		}
		st[m++]=i++;
	}
	ll ans=m;
	for(int i=0;i<m;++i){ 
		ans=(ans*(points[st[i]].id))%(n+1);
	}
	return ans;
}
int main(){
	int n;scanf("%d",&n);
	int index=0;
	for(int i=0;i<n;++i){
		scanf("%d%d",&points[i].x,&points[i].y);
		points[i].id=i+1;
		if(points[i]<points[index]){
			index=i;
		}
	}
	node tmp=points[index];
	points[index]=points[0];
	points[0]=tmp;//LTL points[0]
	printf("%d\n",getAns(points,n));
	return 0;
}
