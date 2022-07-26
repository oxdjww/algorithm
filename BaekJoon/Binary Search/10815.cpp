/*
BOJ 10815 숫자카드
https://www.acmicpc.net/problem/10815 
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	vector<int> x;
	int n;
	cin >> n;
	
	for(int i = 0 ; i < n ; i++) 
	{
		int ipt;
		cin >> ipt;
		x.push_back(ipt);
	}
	vector<int> y;
	int k;
	cin>> k;
	for(int i = 0 ; i < k ; i++)
	{
		int ipt;
		cin >> ipt;
		y.push_back(ipt);
	}
	vector<int> answer(k,0);
	sort(x.begin(),x.end());
	
	int start=0,end=x.size()-1;

	for(int i = 0 ; i < k ; i++)	//간단한 이분탐색 
	{
		start = 0, end = x.size()-1;
		while(start<=end)
		{
			int mid = (start+end)/2;
			if(y[i] > x[mid])
			{
				start = mid +1;
			}
			else if(y[i] < x[mid])
			{
				end = mid - 1;
			}
			else
			{
				answer[i] = 1;
				break;
			}
		}
	}
	for(auto i : answer)
	{
		cout << i << " ";
	}
}
