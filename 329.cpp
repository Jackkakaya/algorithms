#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix.front().empty())
            return 0;
        vector<vector<int> > record(matrix.size(),vector<int>(matrix.front().size(),0));
        int step = 1;
        int pre_val = INT_MIN;
        for(unsigned int row=0;row < matrix.size();row++){
            for(unsigned int col=0; col<matrix.front().size();col++){
                step = max(step,dfs(matrix,pre_val,row,col,record));
            }
        }
        return step;
    }
    int dfs(vector<vector<int> >& matrix,int pre_val,int row,int col,vector<vector<int> >& record){
        int nrows = matrix.size();
        int ncols = matrix.front().size();
        if(row<0||row>=nrows||col<0||col>=ncols||matrix[row][col] <= pre_val)
            return 0;
        if(record[row][col])
            return record[row][col];
        int up = dfs(matrix,matrix[row][col],row+1,col,record);
        int down = dfs(matrix,matrix[row][col],row-1,col,record);
        int left = dfs(matrix,matrix[row][col],row,col-1,record);
        int right = dfs(matrix,matrix[row][col],row,col+1,record);
        int elm[] = {up,down,left,right};
        record[row][col] = *max_element(elm,elm+4) + 1;
        return record[row][col];
    }
};

int main(){
    int nums[][3] = {
        {9,9,4},
        {6,6,8},
        {2,1,1}
    };
    vector<vector<int> > vec;
    for (int i = 0;i<3;i++){
        vector<int> tmp(nums[i],nums[i]+3);
        vec.push_back(tmp);
    }
    for(unsigned int i=0;i<vec.size();i++){
        for(unsigned int j=0;j<vec.front().size();j++){
            cout<<vec[i][j];
        }
        cout<<endl;
    }
    Solution s;
    cout<<s.longestIncreasingPath(vec)<<endl;
}
