#include<iostream>
#include<vector>
#include<deque>
using namespace std;
typedef struct ww{
    pair<int,int> zb;
    int num;
}ww;

int main()
{
    deque<string> cmd;

    deque<ww> she;
    do
    {
        string a;
        cin>>a;
        cmd.push_back(a);
    } while (cin.get()!='\n');
    

    int x = 0;
    int y = 0;

    cin>> x >> y;

    vector<vector<string>> g(x,vector<string>(y,"a"));
    for(int i=0 ;i<x;i++)
    {
        for(int j = 0 ;j<y;j++)
        {
            cin>> g[i][j];
        }
    }


    // for(auto it:cmd)
    // {
    //     cout<<it<<",";
    // }
    // cout<<endl<<x<<" ,," <<y<<endl;

    //  for(int i=0 ;i<x;i++)
    // {
    //     for(int j = 0 ;j<y;j++)
    //     {
    //         cout<< g[i][j];
    //     }
    //     cout<<endl;
    // }
   
    ww key ;
    ww next ;
     for(int i=0 ;i<x;i++)
    {
        for(int j = 0 ;j<y;j++)
        {
            if(g[i][j] == "H")
            {
                key.zb.first = i;
                key.zb.second = j;
            }
        }
    }

    she.push_back(key);
//    cout<< key.first<<","<<key.second<<endl;
    int len = 1;
    string dirction = "L";
    for(auto it: cmd)
    {
       
        if(it == "L"
        || it == "R"
        || it == "U"
        || it == "D"
        )
        {
            dirction = it;
            continue;
        }
        next = key;
        if(it =="G")
        {
            if(dirction == "L")
            {
                next.zb.second--;
            }
            else if(dirction == "R")
            {
                next.zb.second++;
            }
            else if(dirction == "U")
            {
                next.zb.first--;
            }
            else if(dirction == "D")
            {
                next.zb.first++;
            }    
        }
        int a = next.zb.first;
        int b = next.zb.second;

        if(a<0||a>=x
        || b<0||b>=y
            )
        {
            cout<<"chen1"<<endl;
            break;
        }

        cout<<dirction<<endl;
        if(g[a][b] == "F")
        {
        //    cout<<a<<"xxxxx"<<b<<endl;
            len++;
            for(auto it:she)
            {
                it.num++;
            }
            next.num = 0;
            she.push_front(next);
            g[a][b] = "E";
  
        }
        else if(g[a][b] == "E")
        {
            she.pop_back();
            for(auto it:she)
            {
                it.num++;
            }
            next.num = 0;
            she.push_front(next);
            pair<int,int> tmp = she.begin()->zb;
            int num = she.begin()->num;
            bool f = true;
            for(int i = 1;i<she.size();i++)
            {
                cout<<she[i].zb.first<<","<<she[i].zb.second<<she[i].num<<endl;
                cout<<tmp.first<<","<<tmp.second<<num<<endl;
                if(she[i].zb == tmp)
                {
                    f = false;
                    break;
                }
            }
            if(f == false)
            {
                cout<<"chen2"<<endl;
                break;
            }
        }

        for(auto it:she)
        {
            cout<<it.zb.first<<" "<<it.zb.second<<endl;
        }
        cout<<endl;
        key = next;
    }
        for(auto it:she)
        {
            cout<<it.zb.first<<" "<<it.zb.second<<endl;
        }    
   cout<<len;
    return 0;
}

   
// G U G R G D G
// 3 3
// F F F
// F F H
// E F E