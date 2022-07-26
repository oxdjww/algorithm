/*
문제
크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다. Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.

예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

출력
총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.

예제 입력 1 
4
3 5 2 7
예제 출력 1 
5 7 7 -1
예제 입력 2 
4
9 5 4 8
예제 출력 2 
-1 8 8 -1
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> input;
	vector<int> answer(n,-1);
	stack<int> stk;
	for(int i = 0 ; i < n ; i++)
	{
		int s;
		scanf("%d",&s);
		input.push_back(s);
	}
	
	for(int i = n-1 ; i >= 0 ; i--) //가장 늦게 들어온 원소부터 체크 
	{
		while(!stk.empty() && stk.top() <= input[i]) //체크한 원소들을 넣을 스택이 비어있다면 
		{	//비어있지 않고, i번째 원소의 오큰수를 찾을 때 까지 pop 
			stk.pop();
		}
		if(!stk.empty())
		{	//찾았다! 
			answer[i] = stk.top();
		}
		stk.push(input[i]);	//체크하고 있는 i번째 원소 넣어주기 
	}	//포문을 돌 때 마다 51행 덕분에 스택은 다음 원소의 오큰수를 찾을 때도
		//편리하게끔 예쁘게 정돈된 상태이다 
	
	
	for(int i = 0 ; i < n ; i++)
	{
		if(i != n-1)
			printf("%d ",answer[i]); 
		else
			printf("%d\n",answer[i]);	//마지막 인덱스 출력할때
	}
} 
