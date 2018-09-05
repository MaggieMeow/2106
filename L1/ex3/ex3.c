/*************************************
* Lab 1 Exercise 3
* Name     :
* Matric No:
* Lab Group:
*************************************/

#include <stdio.h>

//Datatype Declarations
typedef void (*spellFuncPtr)(int, int, int*);

void lumos(int x, int y, int* z) {
    *z = 1;
    //*spellName = "lumos";
}

void aloho(int x, int y, int* z) {
    *z = 2;
    //*spellName = "aloho";
}

void expel(int x, int y, int* z) {
    *z = 3;
    //*spellName = "expel";
}

void sono(int x, int y, int* z) {
    *z = 4;
    //*spellName = "sono";
}
 

int main()
{
    //int a, b, optype, res;

    //The code below is to show the usage of a function pointer only
    //You can remove/comment them off 

    //arithFuncPtr is a function pointer datatype
    //   - it points to afunction that takes (int, int) as parameter
    //   - and returns int as return result

    //arithFuncPtr ptr;

    //ptr points to the function add
    //ptr = performSpell;

    //scanf("%i %i", &a, &b);

    //Defereference a function pointer === call the function
    //if you take (*ptr) as some function f
    // then below is the same as
    //   res = f(a, b);

    //res = (*ptr)(a, b);
    int X, Y, Z;
    int spellCode;
    char spellNames[4][13] = {"lumos", "aloha", "expelliarmus", "sono"};

    spellFuncPtr spellArr[4] = {&lumos, &aloho, &expel, &sono};
    while(scanf("%i %i %i", &spellCode, &X, &Y) == 3) {
        (*(spellArr[spellCode-1]))(X, Y, &Z);
	printf("%s %d\n", spellNames[spellCode-1], Z);
    }
   
    return 0;
}

int add(int x, int y)
{
    return x+y;
}
