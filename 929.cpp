#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ans;
        for(string s:emails){
            string tmp = "";
            int flag = 1;
            for(char i:s){
                if(i=='+')
                    flag = 0;
                else if(i=='@')
                    flag = 2;
                switch(flag){
                    case 1:
                        if(i!='.')
                            tmp += i;
                        break;
                    case 2:
                        tmp += i;
                        break;
                    case 0:
                        break;
                }
            }
            ans.insert(tmp);
        }
        return ans.size();
    }
};

int main(){
}
