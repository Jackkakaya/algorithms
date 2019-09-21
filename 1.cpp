#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> table;
        vector<int> ret;
        for(int i=0;i<nums.size();i++){
            if( table.count(target-nums[i]) ){
                ret.push_back(table[target-nums[i]]);
                ret.push_back(i);
                return ret;
            }
            table[nums[i]] = i;
        }
        return ret;
    }
};
