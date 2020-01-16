//https://algospot.com/judge/problem/read/BOGGLE

#include <iostream>
#include <string>
using namespace std;

int dx[8] =	{-1,-1,-1, 0, 0,	1,1,1 };
int dy[8] = {-1, 0, 1,-1, 1,  - 1,0,1 };
char board[5][5];

bool hasWord(int y, int x, string word);

int main()
{
	
	int c,n;
	string word[10];
	cin >> c;
	for (int i = 0; i < c; ++i)	// 테스트 케이스
	{

		for (int j = 0; j < 5; ++j)	// board 채우기
		{
			for (int k = 0; k < 5; ++k)
			{
				cin >> board[j][k];
			}


		}

		cin >> n;
		for (int j = 0; j < n; ++j)
		{
			cin >> word[j];
		}

		for (int j = 0; j < n; ++j)
		{
			bool fin = false;
			for (int a = 0; a < 5; ++a)	// board 채우기
			{
				for (int b = 0; b < 5; ++b)
				{
					fin += hasWord(a, b, word[j]);
				}


			}
			if (fin)
				cout << word[j] << " YES\n";
			else
				cout << word[j] << " NO\n";
		}


	}


	return 0;
}

bool hasWord(int y, int x, string word)
{
	if (x < 0 || y < 0 || 4 < x || 4 < y)
		return false;
	if (board[y][x] != word[0]) 
		return false;
	
	if (word.size() == 1)
		return true;
	else
	{
		for (int i = 0; i < 8; ++i)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if(hasWord(nextY, nextX, word.substr(1)))
				return true;
		}
	
	}
	return false;
}
