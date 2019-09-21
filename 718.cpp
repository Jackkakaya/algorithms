#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        unordered_map<int,vector<int> > record;
        for(int i:A)
            record[i] = vector<int>();
        for(unsigned int i=0;i<A.size();i++)
            record[A[i]].push_back(i);

        int max_size = -1;
        for(int i=0;i<(int)B.size();i++){
            int tmp_idx = i,size=0;
            for(int idx:record[B[i]]){
                while(idx<(int)A.size() && tmp_idx <(int)B.size() ){
                    if(A[idx]==B[tmp_idx]){
                        idx++;
                        tmp_idx++;
                        size++;
                    }
                }
                max_size = size>max_size?size:max_size;
            }
        }
        return max_size;
    }
};
