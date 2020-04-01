#include<stdio.h>
#include <iostream>
#include<string.h>
#include<cmath>
#include<queue>
#define maxV 1000
#define weightType int
#include <vector>
using namespace std;


typedef struct GEdge
{
    weightType w;
    int v1;
    int v2;
    GEdge()
    {
        w = 0;
        v1 = 0;
        v2 = 0;
    }
}GEdge, * ptrGEdge;

vector<ptrGEdge> ss;   
queue<ptrGEdge> ee;
int len;

bool calcuDis(ptrGEdge a,ptrGEdge b)
{
    int x = abs(a->v1-b->v1);
    int y = abs(a->v2-b->v2);
    bool re = sqrt(x*x+y*y) <= len;
 //   cout<<re << " "<<a->v1 << " "<<a->v2 << " "<<b->v1<< " "<<b->v2<<endl;
    return re;
}

bool reach(ptrGEdge a)
{
    return 50-abs(a->v1) <= len || 50 - abs(a->v2) <=len;  
}

bool bps(ptrGEdge e)
{
    for(vector<ptrGEdge>::iterator it = ss.begin(); it!=ss.end();it++)
    {
        (*it)->w = 0;
    }
    e->w=1;
    ee.push(e);
    while(!ee.empty())
    {
        ptrGEdge tmp = ee.front();
        ee.pop();
    //    cout<< endl <<tmp->v1<< " "<<tmp->v2<<endl;
        if(reach(tmp))
        {
            return true;
        }
        for(vector<ptrGEdge>::iterator it = ss.begin(); it!=ss.end();it++)
        {
            if((*it)->w == 0 && calcuDis(*it,tmp))
            {
                (*it)->w = 1;
                ee.push(*it);
            }
        }
    }
    return false;    
}

int main()
{  
    int n;
    cin>>n>>len;
    for(int i = 0; i < n ; i++)
    {
        ptrGEdge e = new GEdge;
        cin>>e->v1>>e->v2;
        e->w = 0;
        ss.push_back(e);
    }

    //模拟小岛岸边的坐标
    for(int v1 = 0;v1 <= 15; v1++)
    {
        int v2 = floor(sqrt(15 * 15 - v1 * v1));
        GEdge a,b,c,d;
        a.v1 = v1; 
        a.v2 = v2;
        b.v1 = -v1; 
        b.v2 = v2;
        c.v1 = v1; 
        c.v2 = -v2;
        d.v1 = -v1; 
        d.v2 = -v2;                        
        if(bps(&a) || bps(&b) || bps(&c)||bps(&d))
        {
            cout<<"Yes";
            return 0;
        }
    }

    cout<<"No";

    return 0;
}