#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 12
#define INF 999999999

int bitcount(int tmp)
{
	if (tmp != 0)
		return tmp % 2 + bitcount(tmp / 2);
	else
		return 0;
}

int graduate(int semester_index, int taken);

int semester[10];

int pre[ MAXN ]; //과목 i의 선수과목 목록

int cache[10][ ( 1<< (MAXN+1) ) ]; //메모제이션

int n, k, m, l;

// n 은 전공과목의 수 , k 는 들어야하는 과목의 수, 남은 학기수 m, 학기당 최대 수강 과목수 l

int main()
{
	//cache 초기화
	for (int a = 0; a < 10; ++a)
	{
		for (int b = 0; b < (1 << MAXN); ++b)
			cache[a][b] = -1;
	}



	int c;

	cin >> c;

	for (int i = 0; i < c; ++i)
	{

		cin >> n>>k>>m>>l;

		for (int j = 0; j < n; ++j)		//j 는 수업의 인덱스
		{
			int temp;
			cin >> temp; //선수과목의 갯수

			for (int a = 0; a < temp; ++a)	// j 의 선수과목을 입력받는다.
			{
				int temp2;
				cin >> temp2;
				pre[j] = pre[j] | (1 << temp2);
			}
		}

		for (int b = 0; b < m; ++b)	//b는 학기의 index
		{
			int temp;
			cin >> temp;		//temp는 해당 학기의 개설 과목수
			for (int c = 0; c < temp; ++c)
			{
				int temp2;
				cin >> temp2;
				semester[b] = semester[b] | (1 << temp2);
			}
		}

		int finally =  graduate(0, 0);
		if (finally > m)
			cout << "IMPOSSIBLE \n";
		else
			cout << finally << '\n';



		/*for (int a = 0; a < n; ++a)
		{
			for (int b = 0; b < (1 << MAXN); ++b)
				cache[a][b] = -1;
		}*/
	}

	return 0;
}


int graduate(int semester_index, int taken)
{
	int& ret = cache[semester_index][taken];

	if (ret != -1)
		return ret;
	ret = INF;

	//기저 1 졸업 성공... 수강한 과목이 k개 이상
	if (bitcount(taken) >= k)
		return 0;

	//기저 2 졸업 불가능
	if ( semester_index == m )
		return ret;

	//선수 다 들은거 체크
		//canTake 는 개설 학기중에 안들은것 모음
	int canTake = (semester[semester_index] & (~taken));
	

	for (int i = 0; i < n; ++i)// 모든 과목에대하여
	{		// 선수를 다 안들은것 && 수강 가능한것은  ,,,,, 뺀다 ( &= ~ )
		if ((taken & pre[i]) != pre[i]  && ( canTake & ( 1<<i) ) )
			canTake &= ~(1 << i);
	}
	

	// Full Search 이번학기에 들을수 있는 수업들의 brute force
	for (int take = canTake; take > 0; take = (take - 1) &canTake)
	{
		// 만약 수강과목 take 의 갯수가 한도치 l 초과라면.... 다음 경우의 수로 continue;
		if( bitcount(take) > l)
			continue;
		// 현재 ret 과 비교... 다음 semester 와 내가 이번학기 수강한것 (take) | 기존 수강 taken ... 이번 학기 수강한것이므로 +1;
		ret = min(ret, graduate(semester_index + 1, (taken | take)) + 1);
	}
	
	//이번학기 수강을 전혀 하지 않은경우 ( l 이 0이라거나... canTake 가 없다거나 ( 왜냐 pre[i] & taken  != pre[i]... for all 개설과목 in semseter_index)
	ret = min(ret, graduate(semester_index + 1, taken));
	

	

	return ret;

}
