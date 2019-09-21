#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> hash(128,0);
        vector<bool> visited(128,false);
        for(char i:s)
            hash[i]++;

        string res = "0";
        for(char i:s){
            hash[i]--;
            if(visited[i])
                continue;

            while(i < res.back() && hash[res.back()] ){
                visited[res.back()] = false;
                res.pop_back();
            }
            res += i;
            visited[i] = true;
        }
        return res.substr(1);
    }
};


int main(int argc,char** argv){
    Solution s;
    cout<<s.removeDuplicateLetters(argv[1])<<endl;
}
