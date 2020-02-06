//https://algospot.com/judge/problem/read/PALINDROMIZE

#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> getPartialMatch(const string & N);
int palindromize(const string& N);


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int c;
	cin >> c;

	for (int i = 0; i < c; ++i)
	{
		string n;
		cin >> n;
		cout << palindromize(n) << '\n';
	}
	return 0;

}


vector<int> getPartialMatch(const string & N)
{
	int size = N.size();
	vector<int> pi(size, 0);
	int begin = 1, matched = 0;

	while (begin + matched < size)
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



int palindromize(const string& N)
{
	int begin = 0 , match = 0 ,size = N.size();
	string reverse;
	
	for (int i = size -1 ; i >=0  ; --i)
	{
		reverse += N[i];
	}

	vector<int> pi = getPartialMatch(N);


	while (begin < size)
	{
		if ((N[begin + match] == reverse[match]) && (match < size))
		{
			++match;
			if (match+begin == size)
				return size*2 -match;
		}

		else
		{
			if (match == 0)
				begin++;
			else
			{
				begin += begin + pi[match -1];
				match = pi[match - 1];
			}
		}
	}

	return 0;
}
