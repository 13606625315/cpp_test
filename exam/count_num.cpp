
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int m = 0;
    cin>>m;

    if(m>=100 || m <= 1)
    {
        cout<<"ERROR!";
        return 0;
    }

    vector<int> que;
    vector<int> tmp;

    for(int i  = 1; i <=100;i++)
    {
        que.push_back(i);

    }

    int k = 1 ;
//    cout<<m<<" "<<que.size()<<endl;
    while(que.size()>=m)
    {
        for(int i = 0 ;i < que.size();i++,  k++)
        {
            if(k % m ==0)
            {
        //        cout<<que[i]<<" ";
            }
            else
            {
                tmp.push_back(que[i]);
            }
        
        }
        que = tmp;
        tmp.clear();
     //   cout<<"size = "<<que.size()<<endl;
    }

    for(int i = 0 ;i < que.size();i++)
    {
        if(i == que.size() - 1)
        {
            cout<<que[i];
        }
        else
        {
            cout<< que[i] <<",";
        }
    }
    return 0;
}
