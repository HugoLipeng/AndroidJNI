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
#define PII pair<int, int>
#define mp make_pair
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef unsigned int ui;
int n, m;
int fa[500005];
vector<PII> p1, p2;
void init(int n)
{
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
}
int getfa(int v)
{
	return v == fa[v] ? v : fa[v] = getfa(fa[v]);
}
inline bool _same(int x, int y)
{
	int fx = getfa(x), fy = getfa(y);
	return fx == fy;
}
void _union(int x, int y)
{
	int fx = getfa(x), fy = getfa(y);
	if (fx != fy)
		fa[fx] = fy;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		p1.clear();
		p2.clear();
		scanf("%d%d", &n, &m);
		init(n);
		int a, b, e;
		bool wrong = 0;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d%d", &a, &b, &e);
			if (e)
				p1.pb(mp(a, b));
			else
				p2.pb(mp(a, b));
		}
		for (ui i = 0; i < p1.sz; ++i)
		{
			_union(p1[i].fi, p1[i].se);
		}
		for (ui i = 0; i < p2.sz; ++i)
		{
			if (_same(p2[i].fi, p2[i].se))
				wrong = 1;
		}
		if (wrong)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
