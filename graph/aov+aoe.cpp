#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX 100

int N;
int V;
int g[MAX][MAX];

int early[MAX];
int indegree[MAX];
queue<int> que;

int main()
{
    cin>>N>>V;    
    for(int i = 0 ; i < N ;i++)
    for(int j = 0 ; j < N ; j++)
    {
        g[i][j] = -1;
    }

    for(int i = 0 ; i < V; i++)
    {
        int v1,v2,data;
        cin>>v1>>v2>>data;
        g[v1][v2] = data;
        indegree[v2]++;
    }
     for(int i = 0 ; i < N ;i++)
    {
        if(indegree[i] == 0)
        {
            que.push(i);
        }
    }
    int num = 0;

    while(!que.empty())
    {
        int k = que.front();
        que.pop();
        num++;
        for(int i = 0 ; i < N; i++)
        {
            if(g[k][i] != -1)
            {
                early[i] = max(early[i],early[k] + g[k][i]);
                if(--indegree[i] == 0)
                {
                    que.push(i);
                }
            }
        }
    }

    if(num == N)
    {
        int value = 0;
        for(int i = 0 ; i < N; i++)
        {
            value = max(value,early[i]);
        }
        cout<<value;
    }
    else
    {
        cout<<"Impossible";
    }

    return 0;
}