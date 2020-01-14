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

���� ���� :
�ߺ� ���
01 23
02 13
03 12 ���� ���� ���� ��.. i++ �Ǹ鼭 paired[i], j�� false �� �����..
	  i �� 1 �� ++ ������.. paired[0] == false �� �Ǹ鼭.. �ߺ����� ���� ����.
12 03
13 02
23 01

������.. 2�� for ���� ���� �ʱ� ������ �̷� ������ �߻����� �ʴ´�.
�� 2�� for ���� �������ν� i �� j���� �ݺ����� ������ �ٽ� ������� �ʰ� �ϰ�, i�� ������Ű�� �ȴ�.
*/