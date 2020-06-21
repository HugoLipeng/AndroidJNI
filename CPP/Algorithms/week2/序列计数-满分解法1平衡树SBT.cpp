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
namespace SBT{
	#define MAXN 303000
	typedef struct sbtnod
	{
	    int key,left,right,size;
	} sbtnode;
	int sbttail,sbt;
	
	sbtnode tree[MAXN];
	
	void rrotate(int& t)
	{
	    int k=tree[t].left;
	    if (!k) return ;
	    tree[t].left=tree[k].right;
	    tree[k].right=t;
	    tree[k].size=tree[t].size;
	    tree[t].size=tree[tree[t].left].size+tree[tree[t].right].size+1;
	    t=k;
	}
	
	void lrotate(int& t)
	{
	    int k=tree[t].right;
	    if (!k) return ;
	    tree[t].right=tree[k].left;
	    tree[k].left=t;
	    tree[k].size=tree[t].size;
	    tree[t].size=tree[tree[t].left].size+tree[tree[t].right].size+1;
	    t=k;
	}
	
	void maintain(int& t,bool flag)
	{
	    if (!t) return ;
	    if (!flag)
	        if (tree[tree[tree[t].left].left].size>tree[tree[t].right].size) rrotate(t);
	        else if (tree[tree[tree[t].left].right].size>tree[tree[t].right].size) 
	        {
	            lrotate(tree[t].left);
	            rrotate(t);
	        } else return ;
	    else
	        if (tree[tree[tree[t].right].right].size>tree[tree[t].left].size) lrotate(t);
	        else if (tree[tree[tree[t].right].left].size>tree[tree[t].left].size)
	        {
	            rrotate(tree[t].right);
	            lrotate(t);
	        } else return ;
	    
	    maintain(tree[t].left,false);
	    maintain(tree[t].right,true);
	    maintain(t,false);
	    maintain(t,true);
	}
	
	void insert(int& t,int v)
	{
	    if (!t)
	    {
	        sbttail++;
	        tree[sbttail].key=v;
	        tree[sbttail].size=1;
	        t=sbttail;
	    } else 
	    {
	        tree[t].size++;
	        if (v<tree[t].key) insert(tree[t].left,v);
	        else insert(tree[t].right,v);
	        maintain(t,v>=tree[t].key);
	    }
	}
	
	int del(int& t,int v)
	{
	    int ret;
	    tree[t].size--;
	    if (v==tree[t].key||(v<tree[t].key&&tree[t].left==0)||(v>tree[t].key&&tree[t].right==0))
	    {
	        ret=tree[t].key;
	        if (tree[t].left==0||tree[t].right==0) t=tree[t].left+tree[t].right;//
	        else tree[t].key=del(tree[t].left,tree[t].key+1);
	    } else 
	    {
	        if (v<tree[t].key) ret=del(tree[t].left,v);
	        else ret=del(tree[t].right,v);
	    }
	    return ret;
	}
	
	int select(int t,int k)
	{
	    if (k==tree[tree[t].left].size+1) return t;
	    if (k<=tree[tree[t].left].size) return select(tree[t].left,k);
	    else return select(tree[t].right,k-1-tree[tree[t].left].size);
	}
	
	int search(int t,int x)
	{
	    if (t==0||x==tree[t].key) return t;
	    if (x<tree[t].key) return search(tree[t].left,x);
	    else return search(tree[t].right,x);
	}
	
	int getmin(int t)
	{
	    int i=t;
	    while(tree[i].left)
	    {
	        i=tree[i].left;
	    }
	    return tree[i].key;
	}
	
	int getmax(int t)
	{
	    int i=t;
	    while(tree[i].right)
	    {
	        i=tree[i].right;
	    }
	    return tree[i].key;
	}
	
	int pred(int& t,int y,int v)
	{
	    if (!t) return y;
	    if (tree[t].key<v) return pred(tree[t].right,t,v);
	    else return pred(tree[t].left,y,v);
	}
	
	int succ(int& t,int y,int v)
	{
	    if (!t) return y;
	    if (tree[t].key>=v) return succ(tree[t].left,t,v);
	    else return succ(tree[t].right,y,v);
	}
	
	void deb_out()
	{
	    printf("-------\n");
	    printf("sbttail=%d sbt=%d\n",sbttail,sbt);
	    for    (int i=1;i<=sbttail;i++)
	    printf("%2d: key=%2d size=%2d left=%2d right=%2d\n",i,tree[i].key,tree[i].size,tree[i].left,tree[i].right);
	    printf("-------\n");
	}
	void sbt_init(){
		memset(tree,0,sizeof(tree));
	    sbttail=0;
	    sbt=0;
	}
	bool empty(){
		if(tree[sbt].size==0) return true;
		return false;
	}
}
void insert(int v){
	SBT::insert(SBT::sbt,v);
}
int getMax(){
	return	SBT::getmax(SBT::sbt);
}
int getMin(){
	return  SBT::getmin(SBT::sbt);
}
void erase(int v){
	SBT::del(SBT::sbt,v);
}
void db(){
	SBT::deb_out();
}
bool empty(){
	return SBT::empty();
}
ll getAnswer(int n,int d,vector<int> a){
	SBT::sbt_init();
	ll ans=0;
	insert(a[0]);
	for(int i=0,j=0;i<int(a.size());++i){
		while(j+1<int(a.size())&&
		(max(getMax(),a[j+1])-min(getMin(),a[j+1])<=d||empty())){
			++j;
			insert(a[j]);
		}
		erase(a[i]);
		ans+=j-i;
	}
	return ans;
}
int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	vector<int> a;
	a.resize(n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	printf("%lld\n",getAnswer(n,d,a));
	return 0;
}
