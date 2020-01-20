//https://algospot.com/judge/problem/read/CLOCKSYNC

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


int recursive(int* clock,int num);
void pushswitch( int* clock, int num); 

bool swtch[10][16] =
{
	{ 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0 },
	{ 0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1 },
	{ 1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0 },
	{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1 },
	{ 0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0 }
};

int main()
{
	int c;
	int clock[16];
	int temp;
	
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			cin >> clock[j];
		}
		temp = recursive(clock, 0);
		(temp == 999) ? temp = -1 : temp;
		cout <<temp<< '\n';
	}

	return 0;
}

int recursive(int* clock, int num)
{
	
	bool fin = true;

	for (int i = 0; i < 16; ++i)
	{
		if (clock[i] != 12)
		{
			fin = false;
			break;
		}
	}

	if (num == 10)
	{
		if (fin)
			return 0;
		else return 999;
	}

	int ret = 999;

	for (int i = 0; i < 4; ++i)
	{
		//cout << "Recursive!" << num << " " << i << '\n';
		ret = min(ret, i + recursive( clock, num+1));
		pushswitch(clock, num);
	}

	return ret;
}

void pushswitch( int* clock, int num)
{
	
	for (int i = 0; i < 16; ++i)
	{

		if (swtch[num][i])
		{
			if (clock[i] == 12)
				clock[i] = 3;
			else
				clock[i] += 3;
			
			
		}
		//cout << clock[i] << " ";
	}
	//cout << '\n';
}
