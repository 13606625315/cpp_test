#include<iostream>
#include<queue>
#include<string.h>
#define MAX 1001
using namespace std;

typedef struct Node
{
    int v;
    int data;
    Node* next;
}Node, *ptrNode;

typedef struct list
{
    ptrNode first;
}list,*ptrList;

typedef struct Graph
{
    int v;
    int e;
    list l[MAX];
    Graph()
    {
        v=0;
        e=0;
        memset(l,0,sizeof(l));
    }
}Graph, *ptrG;


ptrG creatGraph()
{
    ptrG g = new Graph;
    cin>>g->v>>g->e;
    return g;
}
int visited[MAX];
void buildGraph(ptrG g)
{
    for(int i = 0; i < g->e;i++)
    {
        int v1 = 0;
        int v2 = 0;
        cin>>v1>>v2;

        ptrNode ptrN = new Node;
        ptrN->v = v2;
        ptrN->next = g->l[v1].first;
        g->l[v1].first = ptrN;

        ptrNode ptrN1 = new Node;
        ptrN1->v = v1;
        ptrN1->next = g->l[v2].first;
        g->l[v2].first = ptrN1;
    }
}

int bps(ptrG g ,int v , int level)
{
    int i = 0;
    queue<ptrNode> q;
    ptrNode p = new Node;
    p->v = v;
    p->data = 0;
    q.push(p);
    visited[v] = 1;

    while(!q.empty())
    {
       ptrNode p = q.front();  
       q.pop();
       if(p->data > level)
       {
           break;
       }
       i++;
       int num = p->v;
       ptrNode f = g->l[num].first;
       while(f != NULL)
       {
           if(visited[f->v] == 0)
           {
               f->data = p->data + 1;
                q.push(f);
                visited[f->v] = 1;
           }
            f=f->next;
       }
    }
    return i;
}
int main()
{
    ptrG g = creatGraph();
    buildGraph(g);

    for(int i = 1; i < g->v + 1; i++)
    {
        memset(visited, 0, sizeof(visited));
        int x = bps(g,i,6);
        printf("%d: %.2f%%\n",i,double(x) / g->v * 100);
    }
    
    return 0;
}