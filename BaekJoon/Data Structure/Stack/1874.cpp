#include <bits/stdc++.h>
using namespace std;
int main()
{
	stack<int> stk;
	int n;
	string s;
	scanf("%d",&n);
	int* checkArr = new int[n];
	for(int i = 0 ; i < n ; i++)
	{
		checkArr[i] = i+1;
	}
	int cur = 1;
	for(int i = 0 ; i < n ; i++)
	{
		int ipt;
		scanf("%d",&ipt);
		while(cur < ipt+1)
		{
			stk.push(cur++);
			if(checkArr[stk.top()-1])
				s += "+";
		}
		checkArr[stk.top()-1] = 0;
		stk.pop();
		s += "-";
		cur--;
	}
	for(int i = 0 ; i < n ; i++)
	{
		if(!checkArr[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	for(auto a : s) printf("%c\n",a);
}
