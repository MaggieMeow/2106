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
	int ans = 0;
	while (x <= y) {
		ans += x;
		x += 1;
	}
	*z = ans;
    //*spellName = "lumos";
}

void aloho(int x, int y, int* z) {
	int i;
	int ans;
	for (i = 1; i <= x && i <=y; ++i) {
		if(x % i == 0 && y % i == 0) {
			ans = i;
		}
	}
	*z = ans;
    //*spellName = "aloho";
}

void expel(int x, int y, int* z) {
	while (x % y == 0) {
		x = x / y;	
	}	
       	*z = x;
    //*spellName = "expel";
}

void sono(int x, int y, int* z) {
	int ans = 1;
	while (y > 0) {
		ans = ans * x;
		y --;
	}
	*z = ans;
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
    char spellNames[4][13] = {"lumos", "alohomora", "expelliarmus", "sonorus"};

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
