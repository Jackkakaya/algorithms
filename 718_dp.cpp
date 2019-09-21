#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int> > dp(A.size()+1,vector<int>(B.size()+1,0));
        int max = 0;
        for(int i=1;i<=(int)A.size();i++){
            for(int j=1;j<=(int)B.size();j++){
                dp[i][j] = A[i-1]==B[j-1]?dp[i-1][j-1]+1:0;
                max = dp[i][j] > max?dp[i][j]:max;
            }
        }
        return max;
    }
};
