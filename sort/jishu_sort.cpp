#include<iostream>
#include<map>
#include<vector>
using namespace std;
#define N 10002
#define N_p 7
int Score[N_p];
typedef struct in{
    int isShow;
    int id;
    int score[N_p];
    int tot;
    in(){
        isShow = 0;
        id = 0;
        tot  = 0 ;
        for(int i = 0 ; i < N_p; i++)
        {
            score[i] = -2;
        }
    }

    int getS()
    {
        tot = 0;
        for(int i = 0 ; i < N_p; i++)
        {
            if( score[i] > 0)
            {
                tot+=score[i];
            }
        }
        return tot;
    }
}in;

in t_id[N];

map<int ,vector<in>> t_all_right;


int main()
{
    int s_t;
    int p_t;
    int in_t;
    cin>>s_t>>p_t>>in_t;
    int all = 0;
    for(int i = 0; i < p_t; i++)
    {
        cin>>Score[i];
        all+=Score[i];
    }
    for(int i = 0 ;i < in_t; i++)
    {
        int id;
        int n;
        int s;
        cin>>id>>n>>s;
        if(s > t_id[id].score[n - 1])
        {
            if(s>=0)
            {
                t_id[id].isShow = 1;
            }
            if(s == -1)
            {
                s = 0;
            }
            t_id[id].score[n - 1] = s;
            t_id[id].id=id;
        }
    }

    for(int i = 0 ; i < N; i++)
    {
        int total = 0;
        for(int j = 0; j < p_t;j++)
        {
            if(t_id[i].score[j] == Score[j])
            {
                total++;
            }
        }
        t_id[i].getS();
        if(total>=0&& t_id[i].isShow == 1)
            t_all_right[total].push_back(t_id[i]);
    }

    map<int ,vector<in>> t_score;
    for(auto it = t_all_right.rbegin(); it != t_all_right.rend(); it++)
    {
        vector<in>& tmp = it->second;
        for(uint i = 0; i<tmp.size(); i++)
        {
            int s = tmp[i].tot;
            t_score[s].push_back(tmp[i]);
            //cout<<s<<endl;
        }
    }

    int key  = 0 ;
    int i = 0 ;
    for(auto it = t_score.rbegin();it!=t_score.rend();it++)
    {
        for(auto x = (it->second).begin();x!=(it->second).end();x++)
        {
            if(key != x->tot)
            {
                key = x->tot;
                i++;
            }            
            char c[30] = {0};
            sprintf(c,"%d %05d %d",i,x->id,x->tot);
            string tmp(c);
            for(int i = 0 ; i < p_t;i++)
            {
                if(x->score[i] == -2)
                {
                    tmp+=" -";
                }
                else
                {
                    tmp+=" "+to_string(x->score[i]);
                }
            }
            cout<<tmp<<endl;
 
        }
    }



    return 0;
}