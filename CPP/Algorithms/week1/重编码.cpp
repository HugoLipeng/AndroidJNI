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
int n;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> que;
int main()
{
	scanf("%d", &n);
	ll x;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &x);
		que.push(x);
	}
	ll ans = 0;
	while (!que.empty())
	{
		if (que.size() == 1)
			break;
		ll t1 = que.top();
		que.pop();
		ll t2 = que.top();
		que.pop();
		ans += t1 + t2;
		que.push(t1 + t2);
	}
	printf("%lld\n", ans);
	return 0;
}
