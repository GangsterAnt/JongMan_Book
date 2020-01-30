#include < iostream >
#include <string>
using namespace std;

string reverse(string::iterator  & it);

int main()
{
	int C;
	cin >> C;

	for (int i = 0; i < C; ++i)
	{
		string compressed;
		cin >> compressed;

		string::iterator it;
		it = compressed.begin();

		cout << reverse(it)<<'\n';
	}

	return 0;
}


string reverse(string::iterator  & it)
{
	char temp = *it;
	it +=1;

	if (temp == 'b' || temp == 'w')
	{
		return string(1, temp);
	}
	else
	{
		string UL = reverse(it);
		string UR = reverse(it);
		string LL = reverse(it);
		string LR = reverse(it);

		return string(1, 'x') + LL + LR + UL + UR;
	}
	

}
