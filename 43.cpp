#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<char> value(num1.length()+num2.length(),0);
        for(int i = num1.length()-1 ;i>=0;i--){
            for(int j=num2.length()-1;j>=0;j--){
                value[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        int carry = 0;
        for(int i = value.size() -1;i>=0;i--){
            value[i] += carry;
            carry = value[i]/10;
            value[i] %= 10;
            cout<<(int)value[i]<<endl;
        }
        cout<<"#############"<<endl;
        unsigned int begin_index = 0;
        while(begin_index < value.size() -1 && value[begin_index] == 0){
            begin_index++;
        }
        string res;
        for(unsigned int i = begin_index;i<value.size();i++){
            //value[i] += 48;
            // res.push_back(char(value[i]));
            cout<<(int) value[i]<<endl;
        }
        return res;
    }
};

int main(int argc,char** argv){
    Solution s;
    cout<<argv[1]<<endl;
    cout<<s.multiply(argv[1],argv[2])<<endl;
}
