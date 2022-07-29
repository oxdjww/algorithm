/*
BOJ 5430 AC
https://www.acmicpc.net/problem/5430
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int testcase;
	scanf("%d",&testcase);
	string command;
	while(testcase--)
	{
		deque<int> dq;
		bool reverse = false;
		bool errorFlag = false;	//에러 발생시 출력하지 않게끔  
		cin >> command;
		int n;
		scanf("%d",&n);
		string elem;
		cin >> elem;
		string str = "";	//[숫자,숫자,숫자..] 식 구성인데 숫자가 두자리수 일 경우 고려 
		for(int i = 0 ; i < elem.length() ; i++)
		{
			if(elem[i] == '[')
				continue;
			else if('0' <= elem[i] && elem[i] <= '9')	//숫자면 우선 저장 
				str += elem[i];
			else if(elem[i] == ',' || elem[i] == ']')	//,나 ]가 오면 저장한 것 deque에 push 
			{
				if(!str.empty())
				{
					dq.push_back(stoi(str));
					str.clear();
				}
			}
		}
		for(int i = 0 ; i < command.length() ; i++)
		{
			if(command[i] == 'R')	//뒤집힐 경우 reverse변수 이용해서 front,back 선택  
			{
				if(reverse)
					reverse = false;
				else reverse = true;
			}
			else
			{
				if(dq.empty())
				{
					cout << "error\n"; 
					errorFlag = true;
					break;
				}
				if(reverse)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}
		
		if(!errorFlag)
		{	//reverse 변수 이용하여 출력해준다 비어있을 경우 [] 출력되게끔 dq.empty()활용 
			printf("[");
			if(!reverse && !dq.empty())
			{	
				for(int i = 0 ; i < dq.size() ; i++)
				{
					if(i != dq.size()-1)
						printf("%d,",dq[i]);
					else
						printf("%d",dq[i]);
				}
			}
			else if(reverse&&!dq.empty())
			{			
				for(int i = dq.size()-1 ; i >= 0 ; i--)
				{	
					if(i != 0)
						printf("%d,",dq[i]);
					else
						printf("%d",dq[i]);
				}
			}
		if(!errorFlag)
			printf("]\n");
		}
	}
}
