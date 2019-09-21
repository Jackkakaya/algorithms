#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string cur_name = "";
        deque<string> record;
        for(char i:path){
            if(i=='/'){
                if(cur_name==""){}
                else if(cur_name == ".."){
                    if(!record.empty())
                        record.pop_back();
                }
                else if(cur_name != "."){
                    record.push_back(cur_name);
                }
                cur_name = "";
            }else{
                cur_name.push_back(i);
            }
        }
        if(cur_name != ""){
            if (cur_name == ".."){
                if(!record.empty())
                    record.pop_back();
            }
            else if(cur_name != ".")
                record.push_back(cur_name);
        }
        string res = "";
        while(!record.empty()){
            res += "/" + record.front();
            record.pop_front();
        }
        return res==""?"/":res;
    }
};

int main(int argc,char** argv){
    Solution s;
    cout<<s.simplifyPath(argv[1])<<endl;
}
