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
using namespace std;
int rt, cnt;
int v[100005], lson[100005], rson[100005];
void _insert(int rt, int val)
{
	if (v[rt] == 0)
	{
		v[rt] = val;
		return;
	}
	if (val < v[rt])
	{
		if (lson[rt] == 0)
		{
			lson[rt] = ++cnt;
			v[cnt] = val;
		}
		else
		{
			_insert(lson[rt], val);
		}
	}
	else
	{
		if (rson[rt] == 0)
		{
			rson[rt] = ++cnt;
			v[cnt] = val;
		}
		else
		{
			_insert(rson[rt], val);
		}
	}
}
void pre(int rt)
{
	if (rt == 0)
		return;
	printf("%d ", v[rt]);
	pre(lson[rt]);
	pre(rson[rt]);
}
void back(int rt)
{
	if (rt == 0)
		return;
	back(lson[rt]);
	back(rson[rt]);
	printf("%d ", v[rt]);
}
int main()
{
	rt = 1;
	cnt = 1;
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		_insert(rt, x);
	}
	pre(rt);
	printf("\n");
	back(rt);
	printf("\n");
	return 0;
}
