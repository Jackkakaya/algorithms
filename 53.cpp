#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = 0;
        int pre_max_sum = 0;
        for(int i:nums){
            pre_max_sum = max(pre_max_sum+i,i);
            max_sum = max(max_sum,pre_max_sum);
        }
        return nums.size()==0?0:max_sum;
    }
};

int main(){
    int a[] = {-1,2,-5,2,2,5};
    vector<int> s(a,a+6);
    Solution s1;
    cout<<s1.maxSubArray(s)<<endl;
}
