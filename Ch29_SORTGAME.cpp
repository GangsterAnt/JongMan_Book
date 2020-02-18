//https://algospot.com/judge/problem/read/SORTGAME

#include <map>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

map< vector<int>, int> tosort[9]; //전처리를 위한 tosort 해쉬맵 
void precal(int n);
int solve(const vector<int> & perm);

int main()
{
	int c;
	cin >> c;
	for (int i = 1; i < 9; ++i) //각 input size case (n) 에 대해 tosort 그래프를 미리 생성해주었다
		precal(i);
	while (c--)
	{
		int n;
		cin >> n;       //각 입력에 대한 tosort를 참조한다. 새로 생성하지 않는다. 이를 통해 각 testcase 마다 새로 graph를 생성하지 않아도 된다.
		vector<int> perm(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> perm[i];
		
		cout << solve(perm)<<'\n';
	}
	return 0;
}

void precal(int n)
{
	tosort[n].clear();

	vector<int> temp(n);
	for (int i = 0; i < n; ++i)		//시작점 
		temp[i] = i;
	queue <vector<int>> q;	q.push(temp);
	tosort[n][temp] = 0;

	while (!q.empty())
	{
		vector<int> here = q.front();	q.pop();
		int cost = tosort[n][here];
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 2; j <= n; ++j)
			{
				reverse(here.begin() + i, here.begin() + j);
				if (tosort[n].count(here) == 0)	//tosort[here] ==0 으로 한다면 입력값이 1 2 3 과 같이 정렬되어 들어온경우 ( 시작점과 도착점이 같은경우) 오류가 발생한다.
				{								//이 구문은 발견되지 않은 정점을 발견하는것이 목표인데 시작점의 거리가 0이기 떄문에 미발견 정점으로 오해하기때문이다.
					tosort[n][here] += cost + 1;
					q.push(here);
				}
				reverse(here.begin() + i, here.begin() + j);
			}
		}
	}
}

int solve(const vector<int> & perm)
{
	int n = perm.size();
	vector<int> fixed(n);
	for (int i = 0; i < n; ++i)
	{
		int smaller = 0;
		for (int j = 0; j < n; ++j)
		{
			if (perm[j] < perm[i])
			{
				++smaller;
			}
		}
		fixed[i] = smaller;
	}

	return tosort[n][fixed];
}
