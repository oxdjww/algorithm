/*
BOJ 2447 º° Âï±â 
https://www.acmicpc.net/problem/2447
*/
#include <bits/stdc++.h>
using namespace std;

int star(int i, int j, int n);

int main( ){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			star(i, j, n);
		printf("\n");
	}
}

int star(int i, int j, int n){
	if((i / n) % 3 == 1 && (j / n) % 3 == 1) 
		cout << " ";
	else if(n / 3 == 0)
		cout << "*";
	else
		star(i, j, n / 3);	//Àç±ÍÈ£Ãâ
	return 0;
}
