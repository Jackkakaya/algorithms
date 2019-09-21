#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> arr;
    stack<int> min;
    MinStack() {
    }

    void push(int x) {
        arr.push(x);
        if(min.empty() || min.top() < x){
            cout<<"insert min"<<endl;
            min.push(x);
        }
    }

    void pop() {
        if(arr.top() == min.top())
            min.pop();
        arr.pop();
    }

    int top() {
        return arr.top();
    }

    int getMin() {
        return min.top();
    }
};
int main(){
    MinStack* m = new MinStack();
    m->push(512);
    cout<<"1"<<endl;
    m->push(-1024);
    cout<<2<<endl;
    m->push(-1024);
    cout<<3<<endl;
    m->push(512);
    cout<<4<<endl;
    m->pop();
    cout<<5<<endl;
    cout<<m->getMin()<<endl;
    cout<<5.5<<endl;
    m->pop();
    cout<<6<<endl;
    cout<<m->getMin()<<endl;

    m->pop();
    cout<<m->getMin()<<endl;
}
