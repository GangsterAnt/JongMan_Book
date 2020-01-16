//https://algospot.com/judge/problem/read/BOARDCOVER
#include <iostream>
#include <vector>

using namespace std;

int covertype[4][3][2] = 
{
	{{0,0},{0,1},{1,0}},// Γ
	{{0,0},{1,0},{1,1}},// ㄴ
	{{0,0},{1,0},{1,-1}},// 」
	{{0,0},{0,1},{1,1}} // ㄱ

};

bool set(vector< vector<int>> &board, int y, int x,int type, int delta , int h , int w); //덮는다.

int cover(vector <vector<int>> &board, int h , int w); //재귀


int main()
{
	vector< vector<int>> board(20,vector<int>(20,0));
	//vector<vector<int>> board;
	int c, h, w;
	cin >> c;
	char temp;
	for (int testcase = 0; testcase < c; ++testcase)
	{
		cin >> h >> w;
		for (int row = 0; row < h; ++row) 
		{
			for (int colum = 0; colum < w; ++colum)
			{
				cin >>temp;
				if (temp == '#')
					//board.at(row).push_back(1);
					board[row][colum] = 1;
				else if (temp == '.')
					//board.at(row).push_back(0);
					board[row][colum] = 0;
			}
		}
		
		/*for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
				cout << board[i][j] << " ";
			cout << '\n';
		}*/

		cout<<cover(board,h,w)<<'\n';
	}

	return 0;
}


bool set(vector< vector<int>> &board, int y, int x,int type, int delta, int h ,int w) //덮는다.
{
	bool fin = true;
	int dy, dx;

	for (int i = 0; i < 3; ++i)
	{
		dy = y + covertype[type][i][0];
		dx = x + covertype[type][i][1];

		if (dy <0 || dx <0 || dy >= h || dx >=w)
			fin = false;

		if ( (board[dy][dx] += delta) > 1)
			fin = false;
	}
	return fin;
}

int cover(vector <vector<int>> &board, int h, int w)		//재귀
{
	int y, x;
	y = x = -1;

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (board[i][j] == 0)
			{
				y = i; x = j;
				break;
			}
		}
		if (y != -1) break;
	}


	if (y == -1)
		return 1;

	int ret = 0;
	for (int type = 0; type < 4; ++type)
	{
		if (set(board, y, x, type, 1,h,w))
		{
			ret += cover(board,h,w);
		}
		set(board, y, x, type, -1,h,w);
	}

	return ret;

}

