/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
 NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor. 
*/
vector<int> aux_v1, v1;
MinStack::MinStack() {
    aux_v1.clear();
    v1.clear();
}

void MinStack::push(int x) {
    v1.push_back(x);
    if(aux_v1.empty() || aux_v1.back() > x)
        aux_v1.push_back(x);
}

void MinStack::pop() {
    if(!v1.empty())
    {
        if(v1.back() == aux_v1.back())
        {
            aux_v1.pop_back();
        }
        v1.pop_back();
    }
}

int MinStack::top() {
    if(v1.empty())
        return -1;
    return v1.back();
}

int MinStack::getMin() {
    if(aux_v1.empty())
        return -1;
    int top = aux_v1.back();
    return top;
}

