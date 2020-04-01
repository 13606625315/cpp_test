#include<stdio.h>
#include <iostream>
#include<string.h>
#define maxV 11
#define weightType int
#include <queue>
using namespace std;

queue<int> ss;
int visited[maxV];

typedef struct Graph
{
    int gV;
    int gE;
    weightType w[maxV][maxV];
}Graph,* ptrGraph;

typedef struct GEdge
{
    weightType w;
    int v1;
    int v2;
}GEdge, * ptrGEdge;

ptrGraph createG(int n1,int n2)
{
    ptrGraph g = new Graph;
    g->gV = n1;
    g->gE = n2;
    memset(g->w, 0,sizeof(weightType) * maxV * maxV);
    return g;
}

void insertE(ptrGraph g,ptrGEdge e)
{
    g->w[e->v1][e->v2] = e->w;
    g->w[e->v2][e->v1] = e->w;
}

void buildG(ptrGraph g)
{
    ptrGEdge e = new GEdge;    
    e->w = 1;    
    for(int i = 0; i < g->gE; i++)
    {
        cin>>e->v1>>e->v2;
        insertE(g, e);
    }  
    delete e;  
}
void dfs(ptrGraph g, int v)
{

    visited[v] = 1;
    printf(" %d",v);

    for(int i = 0; i< g->gV;i++)
    {
        if(g->w[v][i] == 1 && visited[i] == 0)
        {
            dfs(g,i);
        }
    }
}
void bfs(ptrGraph g, int v)
{
    ss.push(v);
    visited[v] = 1;
    while(!ss.empty())
    {
        int tmp = ss.front();
        ss.pop();
        printf(" %d",tmp);
        for(int i = 0 ; i < g->gV; i++)
        {
            if(g->w[tmp][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                ss.push(i);
            }
        }
    }

}

void listComponent(ptrGraph g)
{

    for(int i = 0; i < g->gV; i++)
    {
        if(visited[i] == 0)
        {
            printf("{");
            dfs(g,i);
            printf(" }\n");
        }
    }

    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < g->gV; i++)
    {
        if(visited[i] == 0)
        {
            printf("{");
            bfs(g,i);
            printf(" }\n");
        }
    }

}

 
int main()
{
    int n_v = 0;
    int n_e = 0;
    cin>>n_v>>n_e;
    ptrGraph g = createG(n_v,n_e);
    buildG(g);
    listComponent(g);
    return 0;
}