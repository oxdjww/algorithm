#include <bits/stdc++.h>
using namespace std;

int main()
{
	queue<int> que;
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
	{
		string s;
		cin >> s;
		if(s == "push")
		{
			int j;
			scanf("%d",&j);
			que.push(j);
		}
		else if(s == "pop")
		{
			if(!que.empty())
			{
				printf("%d\n",que.front());
				que.pop();
			}
			else
			{
				printf("-1\n");
			}
		}
		else if(s == "size")
		{
			printf("%d\n",que.size());
		}
		else if(s == "empty")
		{
			if(que.empty())
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else if(s == "front")
		{
			if(!que.empty())
			{
				printf("%d\n",que.front());
			}
			else
			{
				printf("-1\n");
			}
		}
		else if(s == "back")
		{
			if(!que.empty())
			{
				printf("%d\n",que.back());
			}
			else
			{
				printf("-1\n");
			}
		}
	}
}
