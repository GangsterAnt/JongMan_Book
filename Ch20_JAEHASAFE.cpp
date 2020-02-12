//https://algospot.com/judge/problem/read/JAEHASAFE
//Time out 

#include<iostream>
#include<vector>
#include <string>
using namespace std;

vector<int> getPartialMatch(const string & N);
int KMPsearch(const string& H, const string& N);
int howManyShift();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	cin >> c;
	for (int i = 0; i < c; ++c)
	{
		cout<<howManyShift()<<'\n';
	}
	return 0;
}

vector<int> getPartialMatch(const string& N)
{
	int n_size = N.size();
	vector<int> pi(n_size, 0);
	int begin = 1 , matched = 0;

	while ( begin + matched < n_size )
	{
		if (N[matched] == N[begin + matched])
		{
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
			
		}
	}

	return pi;
}

int KMPsearch(const string& H, const string& N)
{
	int begin = 0, matched = 0;
	int n = N.size() ,h = H.size();
	vector<int> pi = getPartialMatch(N);
	while (begin + n <= h)
	{
		if (H[begin + matched] == N[matched] && matched < n)
		{
			++matched;
			if (matched == n)
			{
				return begin;
			}
		}
		else
		{
			if (matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}

		}
	}
	return begin;
}


int howManyShift()
{
	int n =0 , result =0;
	cin >> n;

	string original;
	cin >> original;

	for(int i=1; i<n+1; ++i)
	{
		string temp;
		cin >> temp;
	
		if (i % 2 == 0)	//반시계
		{

			result += KMPsearch(original+ original, temp);
			original = temp;
		}
		else //if (i % 2 == 1)	//시계
		{
			result += KMPsearch(temp + temp, original);
			original = temp;
		}
	}

	return result;
}
