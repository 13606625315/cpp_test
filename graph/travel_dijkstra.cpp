#include <iostream>

using namespace std;

#define MAX 500
#define weightType CWeight
#define infinity 1000
class CWeight
{
public:
    int len = infinity;
    int cost = infinity;
    bool compare(CWeight w)
    {
        if(len != w.len)
        {
            return len > w.len;
        }
        else
        {
            return cost > w.cost;
        }
    }

    CWeight& operator=(const CWeight& cls)
    {
        len = cls.len;
        cost = cls.cost;
        return *this;
    }

    CWeight operator+(const CWeight& cls)
    {
        CWeight data;
        data.len = len + cls.len;
        data.cost = cost + cls.cost;
        return data;
    }    
    
};


typedef struct Graph
{
    int v;
    int e;
    int start;
    int end;
    weightType data[MAX][MAX];
}Graph,*ptrGraph;

typedef struct Edge
{
    int v1 = 0;
    int v2 = 0; 
    weightType data;
}Edge,*ptrEdge;

weightType dist[MAX];
bool isCollect[MAX];

ptrGraph createGraph()
{
    ptrGraph g = new Graph;
    cin>>g->v>>g->e>>g->start>>g->end;
    for(int i=0;i<MAX;i++)
        for(int j = 0; j< MAX;j++)
        {
            if(i != j)
            {
                g->data[i][j].len = infinity;
                g->data[i][j].cost = infinity;
            }
            else
            {
                g->data[i][j].len = 0;
                g->data[i][j].cost = 0;
            }
        }
    return g;
}
void buildGraph(ptrGraph g)
{
    for(int i = 0; i < g->e; i++)
    {
        ptrEdge e = new Edge;
        cin>>e->v1>>e->v2>>e->data.len>>e->data.cost;
        g->data[e->v1][e->v2] = e->data;
        g->data[e->v2][e->v1] = e->data;

    }
}

int findMin(ptrGraph g)
{
    weightType data ;
    int k = -1;
    for(int i = 0;i < g->v; i++)
    {
        if(isCollect[i] == true )
            continue;
        if(data.compare(dist[i]))
        {
            data = dist[i];
            k = i;
        }
    }
    return k;
}

void dijkstra(ptrGraph g)
{
    int v = g->start;
    for(int i = 0; i < g->v;i++)
    {
      //  dist[i] = g->data[v][i];
        if(i == v)
        {
            dist[i].len = 0;
            dist[i].cost = 0;
        }
        else
        {
            dist[i].len = infinity;
            dist[i].cost = infinity;
        }
    }
    while(1)
    {
        int v = findMin(g);
        if(v == -1)
        {
            break;
        }
        isCollect[v] = 1;
        for(int i = 0; i < g->v; i++)
        {
            if(isCollect[i] == 1)
            {
                continue;
            }
            if(dist[i].compare(dist[v] + g->data[v][i]))
            {
                dist[i] = dist[v]+g->data[v][i];
            }
        }
    }
}

int main()
{
    ptrGraph g = createGraph();
    buildGraph(g);
    dijkstra(g);
    cout<<dist[g->end].len<<" "<<dist[g->end].cost;
    return 0;
}