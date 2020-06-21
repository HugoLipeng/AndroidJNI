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
typedef unsigned char uc;
template <typename value_type>
struct __Item
{
	typedef unsigned char uc;
	value_type x, y;
	int id, sum;
	__Item() {}
	__Item(uc _x, uc _y) : x(_x), y(_y) {}
	bool operator<(const __Item &rhs) const
	{
		if (sum != rhs.sum)
			return sum < rhs.sum;
		else if (x != rhs.x)
			return x < rhs.x;
		return y < rhs.y;
	}
	void prt()
	{
		printf("%hhu %hhu\n", x, y);
	}
};
int n;
__Item<int> stu[5005];
__Item<int> cache[5005];
int c_sz;
void __merge(int l, int r, int &rec)
{
	int mid = (l + r) >> 1;
	int Itr1 = l, Itr2 = mid;
	c_sz = 0;
	while (Itr1 < mid || Itr2 < r)
	{
		if (Itr1 >= mid)
			cache[c_sz++] = stu[Itr2++];
		else if (Itr2 >= r)
			cache[c_sz++] = stu[Itr1++];
		else
		{
			if (stu[Itr1] < stu[Itr2])
			{
				rec += mid - Itr1;
				cache[c_sz++] = stu[Itr2++];
			}
			else
			{
				cache[c_sz++] = stu[Itr1++];
			}
		}
	}
	Itr1 = l;
	for (int i = 0; i < c_sz; ++i)
	{
		stu[Itr1++] = cache[i];
	}
}
void solve(int l, int r, int &rec)
{
	if (r - l <= 1)
		return;
	int mid = (l + r) >> 1;
	solve(l, mid, rec);
	solve(mid, r, rec);
	__merge(l, r, rec);
}
bool cmp(const __Item<int> &a, const __Item<int> &b)
{
	if (a.sum != b.sum)
		return a.sum > b.sum;
	else if (a.x != b.x)
		return a.x > b.x;
	return a.y > b.y;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &stu[i].x, &stu[i].y);
		stu[i].sum = stu[i].x + stu[i].y;
		stu[i].id = i + 1;
	}
	int ans = 0;
	solve(0, n, ans);
	for (int i = 0; i < n; ++i)
	{
		__Item<int> &node = stu[i];
		printf("%d %d %d %d\n", node.id, node.x + node.y, node.x, node.y);
	}
	printf("%d\n", ans);
	return 0;
}
