/*
BOJ 1764 듣보잡
https://www.acmicpc.net/problem/1764 
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<string> deud;
	vector<string> bo;
	vector<string> answer;
	for(int i = 0 ; i < n ; i++)
	{
		string s;
		cin >> s;
		deud.push_back(s);
	}
	for(int i = 0 ; i < m ; i++)
	{
		string s;
		cin >> s;
		bo.push_back(s);
	}
	
	sort(deud.begin(),deud.end());	//이분탐색 전 정렬  
	
	for(int i = 0 ; i < m ; i++)
	{
		int start = 0,end = deud.size()-1;
		while(start <= end)
		{
			int mid = (start + end)/2;
			if(bo[i] == deud[mid])
			{
				answer.push_back(deud[mid]);
				break;
			}
			else if(bo[i] > deud[mid])
			{
				start = mid + 1;				
			}
			else
			{
				end = mid - 1;
			}
		}
	}
	sort(answer.begin(),answer.end());	//출력 전 정렬 
	cout << answer.size() << "\n";
	for(auto i : answer)
	{
		cout << i << "\n";
	}
}
