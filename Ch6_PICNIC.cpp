//https://algospot.com/judge/problem/read/PICNIC
//
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//bool friends[10][10];
//int makepair(int n);
//bool paired[10];
//
//int main()
//{
//	int c, n, m;
//	int tempX, tempY;
//
//	cin >> c;
//	
//
//	for (int i = 0; i < c; i++)
//	{
//		cin >> n >> m;
//		for (int j = 0; j < m; ++j) 
//		{
//			cin >> tempY >> tempX;
//			friends[tempY][tempX] = friends[tempX][tempY] = 1;
//		}
//		cout<<makepair(n)<<'\n';
//		for(int i=0; i<10;++i)
//			memset(friends[i], false, sizeof(bool) * 10);
//
//	}
//	return 0;
//}
// 
//int makepair(int n)
//{
//	int first= -1;
//	for (int i = 0; i < n; ++i)
//	{
//		if (!paired[i])
//		{
//			first = i;
//			break;
//		}
//	}
//	if (first ==-1)
//		return 1;
//
//	int ret = 0;
//	
//		for (int j = first+1; j < n; ++j)
//		{
//			if (!paired[j] && friends[first][j])
//			{
//				paired[j] = paired[ first] = true;
//				ret += makepair(n);
//				paired[j] = paired[ first] = false;
//			}
//		}
//	
//	return ret;
//
//}
