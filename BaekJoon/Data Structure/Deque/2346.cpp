#include <iostream>
#include <deque>
#include <cstdio>
#include <vector>
using namespace std;
int flag = 1;

int main(void)
{
    vector<int> data;
    vector<int> ans;
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int ipt;
        scanf("%d", &ipt);
        data.push_back(ipt);
    }

    int idx = 0;
    int dist = 0;
    for (int i = 0; i < n; i++)
    {
        printf("dist : %d\n",dist);
        idx = idx + dist;
        if (idx > n-1)
            idx -= n;
        if (idx < 0)
            idx += n;
        printf("idx : %d\n",idx);
        dist = data[idx];
        data[idx] = 0;
        
        if (!dist)
        {   
            if (flag)
            {
                printf("visit\n");
                idx++;
                dist = data[idx];
                data[idx] = 0;
                if (idx < 0)
                {
                    idx += n;
                }
                if (idx > n-1)
                {
                    idx = idx % n;
                }
                printf("real idx : %d\n",idx);
                printf("real dist : %d\n",dist);
            }
            else
            {
                idx--;
                dist = data[idx];
                data[idx] = 0;
                if (idx < 0)
                {
                    idx += n;
                }
                if (idx > n-1)
                {
                    idx = idx % n;
                }
            }
        }
        ans.push_back(idx + 1);
        if (dist > 0)
                flag = 1;
        if (dist < 0)
                flag = 0;
        for(int t = 0 ; t < n ; t++)
        {
            printf("%d ",data[t]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}