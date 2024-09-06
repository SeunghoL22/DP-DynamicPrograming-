#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <windows.h>

// DP
#if 0

// DP 동적계획법 (Dynamic Programming)
// 메모이제이션 (memoization)
int cache[50][50];

using namespace std;

int combination(int n, int r)
{
	if (r == 0 || n == r )
		return 1;

	// 이미 답을 구한적 있으면 바로 반환
	int& ret = cache[n][r];
	if (ret != -1)
		return ret;

	ret= combination(n - 1, r) + combination(n - 1, r - 1);
	return ret;
}

int main()
{
	::memset(cache, -1, sizeof(cache)); //모든 원소를 -1로 밀어버리는 효율적인 연산
	long start = GetTickCount64();
	int lotto = combination(45, 6);
	long end = GetTickCount64();

	cout << end - start << endl;
}

#endif

// ENCHANT
// 게임에서 +0강 집행검에 인첸트를 하는 상황이라고 가정해보자.
// 무기 강화 주문서는 + 1, +2, +3 중 하나로 강화가 된다. +9강 집행검이 뜨는 경우의 수를 구해라.
#if 0
using namespace std;

int N = 9;
int cache[100];

// [+num강]부터 시작해서 [+N강]까지 가는 경우의 수는 모두 동일할 것이다.
int Enchant(int num)
{
	// 기저 사례
	if (num > N)
		return 0;
	if (num == N) // 9강에 도달한 경우
		return 1;

	// 캐시
	int& ret = cache[num];
	if (ret != -1)
		return ret;

	// 적용 
	// 세 갈래로 분할되는 경우의 수를 모두 더하면 자기 자신의 경우의 수가 나온다.
	return ret = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3); 
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int ret = Enchant(8);
	cout << ret << endl;
}
#endif