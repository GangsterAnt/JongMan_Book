//https://algospot.com/judge/problem/read/DICTIONARY

#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

vector<int> seen, order;
vector< vector <int> > adj;


vector<int> topologicalSort();
void dfs(int here);
void makeGraph(const vector<string>& words);



int main()
{
	int n, c;
	cin >> c;

	for (int i = 0; i < c; ++i)
	{
		cin >> n;
		vector< string> words;
		for (int j = 0; j < n; ++j)
		{
			string temp;
			cin >> temp;
			words.push_back(temp);
		}

		makeGraph(words);
		vector<int> result = topologicalSort();

		if (result.size() == 0)
			cout << "INVALID HYPOTHESIS\n";
		else
		{
			for (int i = 0; i < result.size(); ++i)
				cout << (char)(result[i] + 'a');
			cout << '\n';
		}


	}
	
	return 0;
}

vector<int> topologicalSort()
{
	order.clear();
	int size = adj.size();
	seen = vector< int>(size, 0);

	for (int i = 0; i < size; ++i)
	{
		if (!seen[i])
			dfs(i);
	}

	reverse(order.begin(), order.end());

	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (adj[order[j]][order[i]])
				return vector<int>();
		}
	}

	return order;
	
}

void dfs(int here)
{
	if (!seen[here])
	{
		seen[here] = 1;
		for (int there = 0; there < adj.size(); ++there)
		{
			if (adj[here][there] && !seen[there])
				dfs(there);
		}
	}

	order.push_back(here);
}

void makeGraph(const vector<string>& words)
{
	adj = vector< vector<int> >(26, vector<int>(26, 0));	//초기화

	for (int j = 1; j < words.size(); j++)
	{
		int i = j - 1, len = min( words[i].size(), words[j].size());

		for (int k = 0; k < len; ++k)
		{
			if (words[i][k] != words[j][k])
			{
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
		}
	}

	
}
