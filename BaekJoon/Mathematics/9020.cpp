/*
BOJ 9020 골드바흐의 추측
https://www.acmicpc.net/problem/9020 
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int sosu[10000] = {0};
	for(int i = 1 ; i < 10000 ; i++)
	{
		sosu[i] = 1;
	}
	for(int i = 2 ; i < sqrt(10000) ; i++)
	{
		if(sosu[i] == 0)
			continue;
		for(int j = i+i ; j < 10000 ; j += i)
		{
			sosu[j] = 0;
		}
	}//문제에서 설정한 최대 수인 10000까지의 소수들을 배열에 미리 표시해놓는다 
	int n;
	cin >> n;
	
	for(int testcase = 0 ; testcase < n ; testcase++)
	{
		vector<pair<int,int>> vc;
		int input;
		cin >> input;//수를 입력받고  
		for(int i = 2 ; i < input ; i++) //어떤 두 수를 더했을 때 input이 되어야 하고 소수인 조건까지 있으니 
		{		//input만큼 경우의 수를 뽑아 돌려주고 소수배열로 판단하여 두 수 모두 소수이면 pair로 push_back 
			if(sosu[i] == 1 && sosu[input-i] == 1)
				vc.push_back(make_pair(i,input-i));
		}	//합쳐서 input이 되고, 두 수 모두 소수인 경우의 순서쌍들을 vc에 넣어준 상태
		int mingap = 10000;	 //순서쌍의 최소 차이를 알기위해 mingap설정 
		pair<int,int> answer;
		for(int i = 0 ; i < vc.size() ; i++)
		{
			if(mingap > (vc[i].first - vc[i].second > 0 ? vc[i].first - vc[i].second : (-1)*(vc[i].first - vc[i].second ) ) )
			{	//차이가 최소일 경우에 answer에 들어갈 pair가 계속 갱신되게끔 설정 
				mingap = (vc[i].first - vc[i].second > 0 ? vc[i].first - vc[i].second : (-1)*(vc[i].first - vc[i].second ) );
				answer.first = vc[i].first;
				answer.second = vc[i].second;
			}
		}
		cout << answer.first <<" " << answer.second << "\n";
	}
}
