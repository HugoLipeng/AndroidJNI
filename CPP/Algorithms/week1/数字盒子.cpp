#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<ll, int> mp;
bool check(int op, ll x)
{
	if (op == 1)
	{
		if (mp[x])
			return 0;
		mp[x] = 1;
		return 1;
	}
	else
	{
		if (mp[x])
		{
			mp[x] = 0;
			return 1;
		}
		return 0;
	}
}

int main()
{
	int Q, op;
	ll x;
	scanf("%d", &Q);
	while (Q--)
	{
		scanf("%d%lld", &op, &x);
		puts(check(op, x) ? "Succeeded" : "Failed");
	}
	return 0;
}
