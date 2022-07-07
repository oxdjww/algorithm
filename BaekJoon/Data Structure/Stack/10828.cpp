#include <bits/stdc++.h>

using namespace std;

int main()
{
	stack<int> stk;
	int n;
	scanf("%d",&n);
	
	for(int i = 0 ; i < n ; i++)
	{
		string input;
		cin >> input;

		if(input == "push")
		{
			int x;
			cin >> x;
			stk.push(x);
		}
		else if(input == "pop")
		{
			if(stk.empty())
			{
				printf("-1\n");
			}
			else{
			printf("%d\n",stk.top());
			stk.pop();
		}
		}
		else if(input == "size")
		{
			printf("%d\n",stk.size());
		}
		else if(input == "empty")
		{
			if(stk.empty())
			{
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
		else
		{
			if(!stk.empty())
			{
				printf("%d\n",stk.top());
			}
			else
			{
				printf("-1\n");
			}
		}
	}
}
