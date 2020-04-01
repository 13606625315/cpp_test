#include<stdio.h>
#include<vector>
#include<map>
int ccc(int a,int b)
{
    if(a==b)
        return a;
   	if(a>b)
        return ccc(a-b,b);
    if(a<b)
        return ccc(b-a,a);
}
using namespace std;
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {

        int size= deck.size();
        if(size <= 1)
        {
            return false;
        }
        vector<int> tmp(deck);  
        map<int ,int> Map;     
        while(tmp.size() > 0)
        {
            int key = tmp[0];
            int num = 0;
            for(vector<int>::iterator it = tmp.begin();it != tmp.end();)
            {
                if(key == *it)
                {
                   it = tmp.erase(it);
                   num++;
                }
               else
                {
                    it++; 
                }
            }
            printf("key = %d, num = %d\n",key, num);
            Map.insert(make_pair(key,num));
        }
        for(int i = 2;i<=size ;i++)
        {
            bool flag = true;
            for(map<int, int>::iterator it = Map.begin(); it != Map.end(); it++)
            {
                printf("it = %d\n",it->second);
                if(it->second%i != 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
            {
                return true;
            }
        }

        return false;

    }
};

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(1);

    Solution group;
    bool f = group.hasGroupsSizeX(a);
    printf("f = %d\n",f);
}