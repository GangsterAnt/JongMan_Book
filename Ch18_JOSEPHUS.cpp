//https://algospot.com/judge/problem/read/JOSEPHUS

#include <iostream>
#include <list>

using namespace std;

int main()
{
	
	int c, k, n;

	

	cin >> c;

	for (int i = 0; i < c; ++i)
	{
		list<int> LL;

		cin >> n >> k;

		for (int j = 1; j <= n; ++j)
		{
			LL.push_back(j);
		}


	/*	for (list<int>::iterator temp = LL.begin(); temp != LL.end(); temp++)
			cout << *temp << " ";
		cout << '\n';*/
		 
		list<int>::iterator it = LL.begin();
	
		while (LL.size() != 2)
		{
			
			it = LL.erase(it);

			if (it == LL.end())
				it = LL.begin();
			
			for (int b = 0; b < k - 1; ++b)
			{
				++it;

				if (it == LL.end())		//end() 일경우 begin 으로 바꿔주눈데... 이때 한칸 jump 한거 아닌가?
				{						//아니다.. end() 함수같은경우 맨 마지막 원소 바로 다음 node를 리턴한다.. 즉 유효주소를 넘어간 iterator 를 검증하는것이지
										//마지막 원소를 리턴하는것이 아니다.
					it = LL.begin();
					
				}

				//++it;

				// 여기서 it ++ 하면 뻑남 size가 4 ->3 으로 될때... why?
				// it 가 원소 6 ( LL.end()) 인데 erase 해버리면... end의 끝을 넘어간 junk값이  it 에 들어간다
				// 이때 if 문이 end() it= LL.begin()이 되므로 잡아줄것 같지만...

				//it ==5 , if 문 false -> it++ it==6이 되어버림..

			}

		}

		cout << LL.front() << " " << LL.back() << '\n';

	}

	return 0;
}
