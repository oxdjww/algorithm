/*
문제
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

길이가 짧은 것부터
길이가 같으면 사전 순으로
입력
첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.

출력
조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.

예제 입력 1 
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
예제 출력 1 
i
im
it
no
but
more
wait
wont
yours
cannot
hesitate
*/
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(const string& s1, const string& s2)
{
	if(s1.length() == s2.length())
	{
		return s1 < s2;
	}
	return s1.length() < s2.length();
}
int main()
{
	int N;
	cin >> N;
	vector<string> vc;
	
	for(int i = 0 ; i < N ; i++)
	{
		string s;
		cin >> s;
		if(find(vc.begin(),vc.end(),s)==vc.end())
			vc.push_back(s);
	}
	sort(vc.begin(),vc.end(),compare);
	for(int i = 0 ; i < vc.size() ; i++)
	{
		cout << vc[i] << endl;
	}
}
/*
find()로 중복체크 해주고, compare함수만 구현해주면 되는 간단한 정렬문 
*/
