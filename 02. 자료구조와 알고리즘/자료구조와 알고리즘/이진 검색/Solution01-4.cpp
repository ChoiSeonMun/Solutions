#ifdef SOLUTION_01_4
#include <stdio.h>

using ll = long long;

ll N, M, H;
ll wood[1'000'000];

ll SumHeight(ll v)
{
	ll result = 0;

	for (int i = 0; i < N; ++i)
	{
		ll r = wood[i] - v;
		result += (r < 0) ? 0 : r;
	}

	return result;
}

ll ps()
{
	ll s = 0, e = H + 1;

	ll result = 0;

	while (s < e)
	{
		ll m = (s + e) / 2;
		ll sh = SumHeight(m);

		if (sh < M)
			e = m;
		else
		{
			result = (result < m) ? m : result;

			s = m + 1;
		}
	}

	return result;
}

int main()
{
	scanf("%lld %lld", &N, &M);
	for (ll i = 0; i < N; ++i)
	{
		scanf("%lld", &wood[i]);

		H = (H < wood[i]) ? wood[i] : H;
	}

	printf("%d", ps());
}
#endif