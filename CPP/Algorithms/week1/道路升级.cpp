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
#define PIII pair<pair<int, int>, int>
#define mp make_pair
#define pb push_back
#define sz size()
#define fi first
#define se second
typedef unsigned int ui;
int n, m;
int fa[200005];
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
bool cmp(const PIII &a, const PIII &b)
{
	return a.se > b.se;
}
vector<PIII> edge;
vector<int> ans;
int main()
{
	scanf("%d%d", &n, &m);
	int u, v;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &u, &v);
		edge.pb(mp(mp(u, v), i + 1));
	}
	sort(edge.begin(), edge.end(), cmp);
	int cnt = 0;
	init(n);
	for (auto &tmp : edge)
	{
		if (!_same(tmp.fi.fi, tmp.fi.se))
		{
			_union(tmp.fi.fi, tmp.fi.se);
			cnt++;
			ans.pb(tmp.se);
		}
		if (cnt == n - 1)
			break;
	}
	printf("%u\n", ans.sz);
	sort(ans.begin(), ans.end());
	for (ui i = 0; i < ans.sz; ++i)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}
