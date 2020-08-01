#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void func(vector<int>& ve)
{
    //**************************************************************************************************不能用前缀，用动态规划；
}

int main()
{
    vector<int> ve;// = {-2,1,-3,4,-1,2,1,-5,4};
    
    int i = 0;
    do
    {
        cin>>i;
        ve.push_back(i);
    }
    while(cin.get()!='\n');
    func(ve);
    return 0;
}

//-2 1 -3 4 -1 2 1 -5 4
// 4 -1 2 1