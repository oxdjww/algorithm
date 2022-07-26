/*
BOJ 17298 오큰수
https://www.acmicpc.net/problem/17298 
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<int> stk;
	int n;
	cin >> n;
	vector<int> vc(n);
	for(int i = 0 ; i < n ; i++)
	{
		int s;
		cin >> s;
		stk.push(s);
	}
	int cnt = 0;
	while(!stk.empty())	//시간복잡도 n 
	{
		int ans = -1;
		for(int i = 0 ; i < vc.size() ; i++) //시간복잡도 n 
		{
			if(stk.top() < vc[i])
				ans = vc[i];
		}
		vc.push_back(stk.top());
		stk.pop();
		vc[n-cnt-1] = ans;
		cnt++;
	}
	for(int i =0  ; i < n ; i++)
	{
		if(i != vc.size()-1)
			cout << vc[i] << " ";
		else
			cout << vc[i] << "\n";
	}
} 
/*
2중포문에서 시간초과가 많이 떴다고 하던 문제이다
나는 while문과 for문을 겹쳐 썼는데 시간초과가 자꾸만 떠서 코드를 결국 새로 짰다.. 
*/
