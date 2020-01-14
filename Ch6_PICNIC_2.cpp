//https://algospot.com/judge/problem/read/PICNIC

#include <iostream>
#include <string.h>
using namespace std;

bool friends[10][10];
int makepair(int n);
bool paired[10];

int main()
{
	int c, n, m;
	int tempX, tempY;

	cin >> c;


	for (int i = 0; i < c; i++)
	{
		cin >> n >> m;
		for (int j = 0; j < m; ++j)
		{
			cin >> tempY >> tempX;
			friends[tempY][tempX] = friends[tempX][tempY] = 1;
		}
		cout << makepair(n) << '\n';
		for (int i = 0; i<10; ++i)
			memset(friends[i], false, sizeof(bool) * 10);

	}
	return 0;
}

int makepair(int n)
{
	bool fin = true;

	for (int i = 0; i < n; ++i)
	{
		if (!paired[i])
		{
			fin = false;
			break;
		}
	}
	if (fin)
		return 1;

	int ret = 0;
	int i = 0;
	for (i; i < n; ++i) 
	{
		if (!paired[i])
		{
			break;
		}
	}

	for (int j = i + 1; j < n; ++j)
	{
		if (!paired[j] && friends[i][j])
		{
			paired[j] = paired[i] = true;
			ret += makepair(n);
			paired[j] = paired[i] = false;
		}
	}

	return ret;

}

/*


int makepair(int n)
{
bool fin = true;

for (int i = 0; i < n; ++i)
{
if (!paired[i])
{
fin = false;
break;
}
}
if (fin)
return 1;

int ret = 0;

for (int i = 0; i < n; ++i)
{
if (!paired[i])
{
for (int j = i + 1; j < n; ++j)
{
if (!paired[j] && friends[i][j])
{
paired[j] = paired[i] = true;
ret += makepair(n);
//cout << i << " " << j << '\n';
paired[j] = paired[i] = false;
}
}
}
}

return ret;

}

오답 이유 :
중복 계산
01 23
02 13
03 12 까지 정상 수행 후.. i++ 되면서 paired[i], j가 false 로 변경됨..
	  i 가 1 로 ++ 되지만.. paired[0] == false 가 되면서.. 중복으로 수를 센다.
12 03
13 02
23 01

정답은.. 2중 for 문을 돌지 않기 때문에 이런 문제가 발생하지 않는다.
즉 2중 for 문을 뜯음으로써 i 가 j조건 반복문이 끝나도 다시 시행되지 않게 하고, i를 고정시키면 된다.
*/