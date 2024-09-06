#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <windows.h>

// DP
#if 0

// DP ������ȹ�� (Dynamic Programming)
// �޸������̼� (memoization)
int cache[50][50];

using namespace std;

int combination(int n, int r)
{
	if (r == 0 || n == r )
		return 1;

	// �̹� ���� ������ ������ �ٷ� ��ȯ
	int& ret = cache[n][r];
	if (ret != -1)
		return ret;

	ret= combination(n - 1, r) + combination(n - 1, r - 1);
	return ret;
}

int main()
{
	::memset(cache, -1, sizeof(cache)); //��� ���Ҹ� -1�� �о������ ȿ������ ����
	long start = GetTickCount64();
	int lotto = combination(45, 6);
	long end = GetTickCount64();

	cout << end - start << endl;
}

#endif

// ENCHANT
// ���ӿ��� +0�� ����˿� ��þƮ�� �ϴ� ��Ȳ�̶�� �����غ���.
// ���� ��ȭ �ֹ����� + 1, +2, +3 �� �ϳ��� ��ȭ�� �ȴ�. +9�� ������� �ߴ� ����� ���� ���ض�.
#if 0
using namespace std;

int N = 9;
int cache[100];

// [+num��]���� �����ؼ� [+N��]���� ���� ����� ���� ��� ������ ���̴�.
int Enchant(int num)
{
	// ���� ���
	if (num > N)
		return 0;
	if (num == N) // 9���� ������ ���
		return 1;

	// ĳ��
	int& ret = cache[num];
	if (ret != -1)
		return ret;

	// ���� 
	// �� ������ ���ҵǴ� ����� ���� ��� ���ϸ� �ڱ� �ڽ��� ����� ���� ���´�.
	return ret = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3); 
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int ret = Enchant(8);
	cout << ret << endl;
}
#endif