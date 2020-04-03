#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
#define MAX 100
#define infinity 999
typedef struct Graph{
    int v;
    int e;
    int data[MAX][MAX];
}Graph,*ptrGraph;

typedef struct Node{
    int v1;
    int v2;
    int data;
}Node,*ptrNode;

ptrGraph createGraph()
{
    ptrGraph graph = new Graph;
    cin>>graph->v>>graph->e;
    for(int i = 0;i < MAX; i++)
    {
        for(int j = 0;j<MAX; j++)
        {
            if(i == j)
            {
                graph->data[i][j] = 0; 
            }
            else
            {
                graph->data[i][j] = infinity;
            }
        }
    }
    return graph;
}

void buildGraph(ptrGraph graph)
{
    for(int i = 0; i < graph->e ; i++)
    {
        int v1 = 0;
        int v2 = 0;
        int data = 0;
        cin>>v1>>v2>>data;
      //  cout<<"   "<<data;
        v1--;
        v2--;
        graph->data[v1][v2] = data;
        graph->data[v2][v1] = data;
    }
}

void floyd(ptrGraph graph)
{
    for(int k = 0;k < graph->v; k++)
    for(int i = 0;i < graph->v;i++)
    for(int j = 0; j < graph->v;j++)
    {
        if(graph->data[i][k] + graph->data[k][j] < graph->data[i][j])
        {
            graph->data[i][j] = graph->data[i][k]+graph->data[k][j];
        }
    }
}

void getAnimal(ptrGraph graph)
{
    vector<int> list;
    for(int i = 0;i < graph->v;i++)
    {
        int max = 0;
        for(int j = 0 ; j <graph->v;j++)
        {
            if(graph->data[i][j] > max)
            {
                max = graph->data[i][j];
            }
        }
        list.push_back(max);
    }   
    int min = 999;
    int minA = 0;
    int i = 0;
    for(auto &it:list)
    {
        cout<< it<<endl;
        if(min > it)
        {
            min = it;
            minA = i;
        }
        if(it == infinity)
        {
            cout<<0;
            return;
        }
        i++;
    }
    cout<<++minA<< " "<<min;
}

int main()
{
    ptrGraph graph = createGraph();
    buildGraph(graph);
    floyd(graph);
    getAnimal(graph);
    return 0;
}