#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#define MAX 101
#define infinity 65535
using namespace std;

int g[MAX][MAX];
int N;
int V;
queue<int> que;
int indegree[MAX];
int early[MAX];
int late[MAX];
int main()
{
    cin>>N>>V;

    for(int i = 1 ; i <= N; i++)
    for(int j = 1 ; j <= N; j++)
    {
        g[i][j] = infinity;
    }

    for(int i = 0; i < V;i++)
    {
        int v1 , v2, data;
        cin>>v1>>v2>>data;
        g[v1][v2] = data;
        indegree[v2]++;
    }

    int tmp[MAX];
    memcpy(tmp, indegree, sizeof(tmp));

    for(int i = 1; i <= N; i++)
    {
        if(indegree[i] == 0)
        {
            que.push(i);
        }
    }

    //最早完成时间
    int num = 0;
    while(!que.empty())
    {
        
        int k = que.front();
 
        que.pop();
        num++;
        for(int i = 1; i <= N; i++)
        {
            if(g[k][i] < infinity)
            {
                early[i] = max(early[i], early[k] + g[k][i]);
                if(--indegree[i] == 0)
                {
                    que.push(i);
                }
            }
        }
    }

    int end = 0;
    int value = 0;
    if(num != N)
    {
        cout<<0;
        return 0;
    }
    else
    {

        for(int i = 1 ; i <= N; i++)
        {
            if(value < early[i])
            {
                value = early[i];
                end = i;
            }
        }
        cout<<value<<endl;
    }

    //最晚完成时间
    for(int i = 1 ; i <= N;i++)
    {
        late[i] = infinity;
    }
    late[end] = value;
    que.push(end);    
    while(!que.empty())
    {   
        int k = que.front();
        que.pop();
        for(int i = 1; i <= N; i++)
        {
            if(g[i][k] < infinity)
            {
                late[i] = min(late[i],late[k] - g[i][k]);
                que.push(i);
            }
        }
    }
    //关键路径
    for(int i = 1 ; i <= N; i++)
    {
        for(int j = N; j >= 1; j--)
        {
            if(g[i][j] < infinity)
            {
                if(late[j] - early[i] - g[i][j] == 0)
                {
                    cout<<i<<"->"<<j<<endl;
                }
            }
        }
    }
    return 0;
}