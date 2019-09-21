#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int push_idx=0,pop_idx=0;
        while(push_idx < (int)pushed.size()){
            while(!st.empty() && st.top()==popped[pop_idx]){
                st.pop();
                pop_idx++;
            }
            st.push(pushed[push_idx]);
            push_idx++;
        }
        return st.size() == 0;
    }
};
