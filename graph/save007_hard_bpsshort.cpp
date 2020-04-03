#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;
#define MAX 100


typedef struct Edge
{
    int v1;
    int v2;
    int data;
    struct Edge* path;
    Edge()
    {
        v1=0;
        v2=0;
        data=0;
        path=NULL;
    }
}Edge,*ptrEdge;

int N;
int len;
vector<ptrEdge> graph;


bool calcuDis(ptrEdge a,ptrEdge b)
{
    int x = abs(a->v1-b->v1);
    int y = abs(a->v2-b->v2);
    bool re = sqrt(x*x+y*y) <= len;
    
    return re;
}

bool reach(ptrEdge a)
{
    return 50-abs(a->v1) <= len || 50 - abs(a->v2) <=len;  
}


void createGraph()
{
    for(int i = 0 ; i < N; i++)
    {
        ptrEdge e = new Edge;
        cin>>e->v1>>e->v2;
        graph.push_back(e);
    }
}

void reset()
{
    for(auto& it:graph)
    {
        it->data = 0;
        it->path = NULL;
    }
}
bool bps(Edge e,ptrEdge& key)
{
    reset();
    queue<ptrEdge> que;    
    que.push(&e);
    while(!que.empty())
    {
        ptrEdge f = que.front();
        que.pop();
        if(reach(f))
        {
            key = f;
            return true;
        }
        for(auto& it:graph)
        {
            if(it->data == 0 && calcuDis(f,it))
            {

                it->data = f->data + 1;
                if(f == &e)
                {
                    it->path = NULL;
                }
                else
                {
                    it->path = f;
                }
            //    printf("%p(%d,%d)->%p(%d,%d)\n",it->path,f->v1,f->v2,it,it->v1,it->v2);                
                que.push(it);
            }
        }
    }
    return false;
}

int main()
{
    cin>>N>>len;

    createGraph();

    int min = 1000;
    vector<Edge> out;
    for(int v1 = 0;v1 <= 7.5; v1++)
    {
        int v2 = floor(sqrt(7.5 * 7.5 - v1 * v1));
        Edge a,b,c,d;
        a.v1 = v1; 
        a.v2 = v2;
        b.v1 = -v1; 
        b.v2 = v2;
        c.v1 = v1; 
        c.v2 = -v2;
        d.v1 = -v1; 
        d.v2 = -v2;  
        vector<Edge> q;
        q.push_back(a);q.push_back(b);q.push_back(c);q.push_back(d);
        for(auto &it:q)
        {
            if(reach(&it))
            {
                cout<<1;
                return 0;
            }
            ptrEdge key;
            if(bps(it,key))
            {
              //  cout<<"v="<<it.v1<<","<<it.v2<<endl;
             //   cout<<min<<"nim="<<key->data<<",v1="<<key->v1<<",v2="<<key->v2<<endl;
                if(min>key->data)
                {
                    min=key->data;
                    out.clear();
                    ptrEdge tmp = key;
                    stack<ptrEdge> ss;
                    while(tmp)
                    {
                      //  printf("(%d, %d) ",tmp->v1,tmp->v2);
                        ss.push(tmp);
                        tmp = tmp->path;
                    }
                   // printf("\n");
                    while(!ss.empty())
                    {
                        ptrEdge x = ss.top();
                        ss.pop();
                        out.push_back(*x);
                    }
                }
            }
        }                      
    }

    if(min == 1000)
    {
        cout<<0;
    }
    else
    {
        cout<<min+1<<endl;
        for(auto &x:out)
        {
            cout<<x.v1<<" "<<x.v2<<endl;
        }
    }

    return 0;
}