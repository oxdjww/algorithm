/*
BOJ 1918 후위표기식
https://www.acmicpc.net/problem/1918
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	stack<pair<char,int>> st;	//<연산자,우선순위> 넣어줄 stack  
	vector<pair<char,int>> vc;	//입력받은 <string 값,우선순위> 로 쪼개서 넣어줄 vector 
	string s;
	cin >> s;	//계산식 입력받기  
	for(int i = 0 ; i < s.length() ; i++)	//string의 인덱스 하나하나 우선순위 생각해서 vector에 넣어주기  
	{
		char c = s[i];
		if(c >= 'A' && c <= 'Z')
		{
			vc.push_back(make_pair(c,0));
		}
		else if(c == '+' || c == '-')
		{
			vc.push_back(make_pair(c,1));
		}
		else if(c == '*' || c == '/')
		{
			vc.push_back(make_pair(c,2));
		}
		else	// '(' or ')'
		{
			vc.push_back(make_pair(c,3));
		}
	}
	
	for(int i = 0 ; i < s.length() ; i++)
	{
		if(vc[i].second == 0) // 'A' ~ 'Z'면 그냥 출력 
			printf("%c",s[i]);
		else
		{
			if(vc[i].first == ')') //')'만 고려해준다 
			{
				while(st.top().first != '(')	//괄호가 닫힐 때 까지 
				{
					printf("%c",st.top().first);	//연산자들 몰아서 출력 
					st.pop();
				}
				st.pop();	//남은 '(' 출력 
				if(i != s.length()-1)	//마지막 인덱스까지 왔을 때에는 74행의 스택을 다 비워내는 코드로 가야하므로 continue 해주지 않는다 
				{
					continue;	//마지막 인덱스가 아닐 경우엔 ( ) 안의 것들 다 처리 했으므로 바로 다음 인덱스로 넘어가게끔 continue;  
				}
			}
			if(st.empty())	//연산자 스택이 비어있으면 꺼낼 것도 없으므로 그냥 넣어줌 
			{
				st.push(vc[i]);
			}
			else
			{
				while(!st.empty() && st.top().second >= vc[i].second)	//스택에 넣을 연산자랑 top이랑 비교 
				{
					if(st.top().second != 3) //'(',')' 만 아니면 다 출력 
					{
						printf("%c",st.top());
						st.pop();
					}
					else break;
				}
				st.push(vc[i]);
			}
		}
		if(i == s.length()-1)	//계산식 인덱스 마지막까지 왔을 때 남은 연산자 다 출력 
		{
			while(!st.empty())
			{
				if(st.top().second != 3) //'(',')' 만 아니면 다 출력 
					printf("%c",st.top().first);
				st.pop();
			}
		}
	}
} 
