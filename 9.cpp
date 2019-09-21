#include <iostream>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int reverse_num = 0,tmp = x;
        while(x){
            reverse_num = reverse_num*10+x%10;
            x/=10;
        }
        return reverse_num==tmp;
    }
};
int main(int argc,char** argv){
    Solution s;
    cout<<s.isPalindrome(atoi(argv[1]))<<endl;
}
