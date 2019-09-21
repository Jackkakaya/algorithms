#include <iostream>
using namespace std;

class Solution {
public:
    int clumsy(int N) {
       if(N>4) {
            switch(N%4){
                case 0: return N+1;
                case 1: return N+2;
                case 2: return N+2;
                case 3: return N-1;
                default break;
            }
       }
       switch(N)
       {
            case 0:return 0;
            case 1:return 1;
            case 2:return 2;
            case 3:return 3;
            case 4:return 7;
       }
       return 0;
    }
};

int main(){

}
