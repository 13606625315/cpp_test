#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

#define N 1000

typedef struct Exp{
    int key;
    int value;
}Exp;

int s[N];
vector<Exp> que;
int degree[N];
vector<vector<int>> a(N,vector<int>(N,0));
int hash1(int i ,int n)
{
  return i%n;
}

void print(vector<vector<int>> a,int n)
{
    for(int i = 0;i<n;i++)
    {
      for(int j = 0; j < n; j++) 
      {
          cout<<a[i][j]<<" ";
      }
      cout<<endl;
    }
}

int main()
{

  int n = 0 ;
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    cin>>s[i];

    if(s[i] < 0)
    {
        continue;
    }

    int pos = hash1(s[i],n);

    while(pos != i)
    {   
        a[pos][i]++;        
        pos = (pos+1)%n;
        degree[i]++;
    }

  }
  
 // print(a,n);

    

  while(1)
  {

    for(int i = 0;i<n;i++)
    {
        // int total = 0;
        // for(int j = 0; j < n; j++)
        // {
        //     total += a[j][i];
        // }
        if(degree[i] == 0 && s[i] >=0)
        {
            Exp x;
            x.key = i;
            x.value = s[i];
           que.push_back(x);
           
        }
    }

    if(que.empty())
    {
        break;
    }

    static bool xxx = false;

    if(xxx)
    {
        cout<<" ";
    }
    else
    {
        xxx = true;
    }
    Exp tmp = que[0];
    for(auto &it:que)
    {
       if( it.value < tmp.value)
       {
           tmp = it;
       }
    }

    cout<<tmp.value;

    s[tmp.key] = -1;

    for(int i = 0 ; i < n; i++)
    {
        if(a[tmp.key][i] == 1)
            degree[i] --;
    }
   
    que.clear();


 //   print(a,n);

    // cout<<endl<<"***********"<<endl;
  }

  
  return 0;
}