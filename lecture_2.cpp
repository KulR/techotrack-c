#include <iostream>
#include <stdlib.h>
#include <cassert>
#define ASSERT_OK()     if(!StackOk(stack)) {StackDump(stack);assert(0);}

using namespace std;

typedef double stackElemen_t; // now stackElemen_t == double, it's good because we can change this as we need

struct stack_t{
    stackElemen_t* data;  //double is bad, because we need more types
    int count;
    int max_count;
};
//example for c++ if we use typedef in struct(no global typedef)
// stack_d::stackElemen_t elem = 0; //new value, only in c++


int main() {
    stack_t s = {};
    s.data[s.count++] = 10; //it is bad, because not secure, if we have more than two stacks we can don't remind all stuff..
    s.data[s.count++] = 20;// that's why we need function( in c++ we need class, because we can)
    return 0;
}

bool StackOk(const stack_t* stack) //quiet verification
{
    return  stack &&
            stack -> count >= 0 &&
            stack -> max_count >= stack -> count &&
            stack -> data;
}
//we can write StackError and return error number

void StackDump(stack_t* stack){ //if stack not verified we need print log, for example in file
    //some code
}
//[] contain pointer in memory

void StackConstruct(stack_t* stack /*, ... it's some params we can use in our function*/)
{


    //stack -> data = calloc();
    //stack -> count = ...;
    stack -> count = 0;
}

void StackDestruct(stack_t* stack){

    free(stack -> data);

}

void StackPush (stack_t* stack, stackElemen_t value){   //the theory of two markers
    //assert(StackOk(stack)); we can use, but more  valiable
    if(!StackOk(stack)) {StackDump(stack); assert(0);} // we write ASSERT_OK() in define, so we can don't write this program
    stack -> data[stack -> count ++] = value;
    ASSERT_OK();
    //assert(StackOk(stack));
}