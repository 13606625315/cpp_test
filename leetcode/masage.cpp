#include<stdio.h>
#include<vector>
using namespace std;

class Solution {
public:
    int Max(int a, int b)
    {
        return a>b?a:b;
    }
    int massage(vector<int>& nums) {
       int size = nums.size();
        if(size == 0) return 0; 
        if(size == 1) return nums[0];

        vector<int> dp(size, 0);
        dp[0] = nums[0]; //dp[i] 表示nums[0...i] 能得到的最长时间
        dp[1] = max(nums[0],nums[1]);

        for(int i = 2; i < size; i++)
        {
            //遍历迄今为止的最大值，两种情况取较大：
            //1：预约本次，则上一次不预约（dp[i-2] + nums[i]）
            //2：本次不预约，则值为预约到上一次的最大值
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        return dp[size -1];
    }


};

int main()
{
    int cc[37] = {183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
    vector<int> a(cc,cc+37);
    Solution bb;
    printf("ma = %d\n",bb.massage(a));
    return 0;
}