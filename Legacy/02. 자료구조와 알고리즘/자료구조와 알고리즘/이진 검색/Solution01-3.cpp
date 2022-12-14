#ifdef SOLUTION_01_3
#include <stdio.h>

using ll = long long;

ll K, N, M;
ll lan[10'000];

ll count(ll v)
{
	ll result = 0;

	for (int i = 0; i < K; ++i)
		result += lan[i] / v;

	return result;
}

ll ps()
{
	ll s = 1, e = M + 1;
	ll result = 0;

	while (s < e)
	{
		ll m = (s + e) / 2;
		ll c = count(m);

		if (c < N)
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
	scanf("%lld %lld", &K, &N);
	for (int i = 0; i < K; ++i)
	{
		scanf("%lld", &lan[i]);

		M = (M < lan[i]) ? lan[i] : M;
	}

	printf("%lld", ps());
}
#endif