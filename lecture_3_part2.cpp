#include <iostream>
#include <stdlib.h>
#include <cassert>
#define ASSERT_OK()     if(!StackOk(stack)) {StackDump(stack);assert(0);}

using namespace std;
///////////////////////////////////////////////////////////////
//lesson 1
typedef double stackElemen_t; // now stackElemen_t == double, it's good because we can change this as we need

struct stack_t{
    stackElemen_t* data;  //double is bad, because we need more types
    int count;
    int max_count;
};
//example for c++ if we use typedef in struct(no global typedef)
// stack_d::stackElemen_t elem = 0; //new value, only in c++

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
//end code of lesson 1
//////////////////////////////////////////////////////////////////////////////////
int main() {
    return 0;
}

//operations in strings, but we change it to int:
//push int  ->  1 5
//mul       ->  1 5
//sub       ->  2
//sqrt      ->  3
//add       ->  4
//dib       ->  5
//pow       ->  6
//end       ->  -1
//out       ->
//we need many time to strcmp, but we can association command with their number
//it use in java, c#

//enum for convert

//we can make another program!!! that convert string_operations to int_operations
//It's the compiler(asm compiler in our case)
//We can make also dis asm

//So now we need asm, dis asm, and CPU

class CPU_t {
private:
    stack_t stack;
    double regs[4]; //magic number
    double RAM[100];    //we can not to include 
public:
    bool CPU_OK(){return StackOk(&stack);};
    void CPU_run();
};

//asm
//out       ->  bring last number in stack and print it
//setpixel  ->  print pixel with (x,y,z) that we bring in stack
//in        ->  bring number in stdin and put it to stack
//sqrt      ->  bring number and put sqrt(number) to stack
//sin(cos)  ->  bring number and put sin(number) to stack
//we make 4 register, f.e. in massive
//pop ax    ->  bring number in stack and put it to ax      -> 10 1(we can associated register with number)
//pop bx    ->  bring number in stack and put it to ax      -> 10 2
//push cx   ->  push number in register                     -> 1 1 3
//we can change push f.e. that  push 5 == 1 0 5;    push dx == 1 1 4
