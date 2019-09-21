#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int idx = 0;
        vector<string> res;
        while(idx < (int)nums.size()){
            int init_num = nums[idx];
            int cur_num = nums[idx];
            while(idx+1 <(int)nums.size() && nums[idx+1] - cur_num == 1)
                cur_num = nums[++idx];
            if(init_num == cur_num)
                res.push_back(to_string(init_num));
            else
                res.push_back(to_string(init_num) + "->" + to_string(cur_num));

            idx++;
        }
        return res;
    }
};

int main(){
    vector<string> res ;
    int arr[] = {0,1,2,4,5,7};
    vector<int> input(arr,arr+sizeof(arr)/sizeof(int));
    Solution s;
    res = s.summaryRanges(input);
    for(string i:res){
        cout<<i<<endl;
    }
}
