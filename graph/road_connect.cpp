#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#define MAX 1001
#define infinity 65535
using namespace std;
typedef struct Graph
{
    int v;
    int e;
    int data[MAX][MAX];
    Graph()
    {
        v = 0;
        e = 0;
        for(int i = 0 ; i < MAX ; i++)
        {
            for(int j = 0; j < MAX; j++)
            {
                if(i == j)
                {
                    data[i][j] = 0;
                }
                else
                {
                    data[i][j] = infinity;
                }
            }
        }
    }
}Graph,* ptrGraph;

typedef struct Edge
{
    int v1;
    int v2;
    int data;
    Edge()
    {
        v1 = 0;
        v2 = 0;
        data = 0;
    }
}Edge,*ptrEdge;

ptrGraph createGraph()
{
    ptrGraph g = new Graph;
    cin>>g->v>>g->e;
    return g;
}

struct cmp
{
    bool operator()(const ptrEdge &a,const ptrEdge &b)
    {
        return a->data > b->data;
    }
};

vector<ptrEdge> ve;
priority_queue<ptrEdge,vector<ptrEdge>,cmp> que;

void buildGraph(ptrGraph g)
{
    for(int i = 0; i < g->e;i++)
    {
        ptrEdge e = new Edge;
        cin>>e->v1>>e->v2>>e->data;
        g->data[e->v1][e->v2] = e->data;
        g->data[e->v2][e->v1] = e->data;
        que.push(e);
    }
}

int dist[MAX];
int parent[MAX];
bool collect[MAX];

int findMin(ptrGraph g)
{
    int min = infinity;
    int k = 0;
    for(int i = 1; i <= g->v; i++)
    {
        if(collect[i] == 1)
        {
            continue;
        }
        if(dist[i] < min)
        {
            min = dist[i];
            k = i;
        }
    }
    return k;
}


void prim(ptrGraph g)
{
    int x = 1;
    for(int i = 1 ; i <= g->v;i++)
    {
        if(i == x)
        {
            dist[i] = 0;
        }
        else
        {
            dist[i] = infinity;
        }

    }
    while(1)
    {
        int v = findMin(g);
      
        if(v == 0)
        {
            break;
        }
        dist[v] = 0;   
        collect[v] = 1;  
        for(int i = 1;i <= g->v; i++)
        {
            if(collect[i] == 1)
            {
                continue;
            }

            if(g->data[v][i] < dist[i])
            {
                dist[i] = g->data[v][i];
                parent[i] = v;
            }
        }
    }

    int num = 0;
    for(int i = 1; i <= g->v; i++)
    {
        if(dist[i] == 0)
        {
            num++;
        }
    }

    if(num == g->v)
    {
        int money = 0;
        for(int i = 1;i<=g->v; i++)
        {
            if(parent[i] != 0)
            {
                money += g->data[parent[i]][i];
            }
        }
        cout<<money;
    }
    else
    {
        cout<<-1;
    }

}

ptrEdge findMin()
{
    ptrEdge e = que.top();
    que.pop();
    return e;
}


int find(int e)
{
    int k = e;
    while(parent[k] > 0)
    {
        k = parent[k];
    }
    return k;
}

void Union(int v1,int v2)
{
    v1 = find(v1);
    v2 = find(v2);

    if(parent[v1] < parent[v2])
    {
        parent[v2] = v1;
        parent[v1]--;
    }
    else
    {
        parent[v1] = v2;
        parent[v2]--;
    }
}

bool isSameT(ptrEdge e)
{
    if(find(e->v1) == find(e->v2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void kruskal(ptrGraph g)
{
    while(ve.size() < g->v && que.size() > 0)
    {
       ptrEdge e = findMin();
       if(!isSameT(e))
        {
            ve.push_back(e);
            Union(e->v1,e->v2);
        }
    }

    if(ve.size() == g->v - 1)
    {
        int value = 0;
        for(vector<ptrEdge>::iterator it = ve.begin();it != ve.end() ; it++ )
        {
            value += (*it)->data;
          //  cout<<"123="<< (*it)->data <<endl;
        }
        cout<<value;
    }
    else
    {
        cout<<-1;
    }
}

int main()
{

    ptrGraph g = createGraph();

    buildGraph(g);
    
    //prim(g);

    memset(parent, 0, sizeof(parent));  
    kruskal(g);
    return 0;
}