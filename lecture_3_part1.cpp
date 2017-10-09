#include <iostream>

//hack
struct HackStruct_t
{
    int count;
    double* data;
};

struct StackTov_t
{
private:
    int count;
    double* data;
public:
    void Stackconstruct(double* _d, int _c){
        data = _d;
        count = _c;
    }
};
typedef StackTov_t st_t;



int main() {
    st_t s1 = {};
    st_t::Stackconstruct(%s1, 100);
//first way
    HackStruct_t* hack = (HackStruct_t*) &s1;
    hack -> count = -1;

//second way
    *(int*)&s1 = -1;

//third way
    *(int*)&s1 = -1;
    ((int*)&s1)[1] = 0; //from &s1 to int*, and then we can change it
// forth way
    *(int*)&s1 = 1;//1 < 100
    *(int *)&s1 = 10000;//10000 > 100
    //fifth way
    ((int *)&s1)[1] = 7;    //data = 7(pointer)
//sixth way
    ((double)((int*)&s1)[1])[2] = 0;    //hmmm
    hack -> data [2] =0;    //another way


    return 0;
}


// how prevent hack???

//first check
//canary secure we need put in canary not 1 or 0 else we can skip attack
struct StackTov_new         //more secure
{
private:
    int canary1;    //in verification we need first check canary
    int count;
    double* data;
    int canary2;    //in verification we need check canary
public:
    void Stackconstruct(double* _d, int _c){
        data = _d;
        count = _c;
    }
};
typedef StackTov_t st_n;

//also we may have canary in dynamic massive

//second way(expensive way)
//we can copy all data
//It's expensive but we can continue work even if someone hack one of our server

//RAID, need to google it
//third way
//it's expensive in time
//we can make some function that do control sum, for example control_sum = count + data + sum(data[i])
//I think this some kind of  <hash sum>
// if we need our data sort, we can do control_sum = count + data + sum(2^i*data[i])
//sometimes we need sum bytes(we need to convert double* to char*)

//c++ part
//template
Guard<stack> s; //we can write
template <typename Data_T>
    class Guard
    {
        unsigned canary1;
        Data_t data;
        ...
        int hash_sum;
        operator const Data_t&(){...}
        unsigned canary_i;
    };