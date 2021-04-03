#ifndef COSC_ASSIGN_ONE_TYPES
#define COSC_ASSIGN_ONE_TYPES

#include <math.h> 

#define ENV_DIM                     20
#define NODE_LIST_ARRAY_MAX_SIZE    4*(ENV_DIM * ENV_DIM)

// A 2D array to represent the environment or observations
// REMEMBER: in a environment, the location (x,y) is found by maze[y][x]!

// first element is the actuall type and 2nd one is the type that we want to call 
// Which means, now when we use Env[ENV_DIM][ENV_DIM], it means a char
typedef char Env[ENV_DIM][ENV_DIM];
typedef int Integer;

#define SYMBOL_WALL             '='
#define SYMBOL_EMPTY            '.'
#define SYMBOL_GOAL             'G'
#define SYMBOL_START            'S'
#define SYMBOL_EXPOSED_RIGHT    '>'
#define SYMBOL_EXPOSED_LEFT     '<'
#define SYMBOL_EXPOSED_TOP      '^'
#define SYMBOL_EXPOSED_BOTTOM   '$'

#endif // COSC_ASSIGN_ONE_TYPES


// Lec notes importand to the assignment 1
// making a single array 
//int array[1//0] = {0};
// when it comes to 2D array, we first look the row and then check the col,
 //int array[x][y] = {0,0};
// first its making the Y rows from top to bottom
// and then go left to right for columns which is y 

//but in a cartisian plane, which is normally horizontal line is y and vertical is x, 
// we would look up the ARRAY using [y][x] because in array search starts from Y axis or rows and then columns
// P[row][col] = P(y,x)


// ARRAYS ARE POINTERS 
// So when we want to move from one memeory address of an array element to another mwemory address of element, we have to add 4 to the memory address as one array element is //4 byte  long. 
// If you get the memory address of the array in a whole, you will get the MA of the 1st element. 

// So we can create arrays as two different ways, 
/* 
1. int array[10] - this actually allocate memory for the whole array
2. int* array - this is also an array BUT this only allocate memory for a single pointer and this pointer form always uses inside a function 

ARRAYS ARE POINTERS so we can pass the arrays to functions in 2 ways, 
1. void func(int array[])
2. void func(int* array)

These both do the same thing which is changing the original array values as we are directly de-referecing the array and access the values. 

When we making 2D arrays, we need to have 2 pointers which is going be like,
int** ptr = array2D
here , (int*)* ptr >> *ptr is basically says we have an array of pointers to the integers ,,,, and (int*) says inside of that pointer is another array with actualy integraers. So by dereferecing once, you can get to 1st element and by deref again, you can go inside of that array and get the firat element of second array. 
 

IMPORTANT___ 
When you checking the length of a character array, it contains the elements and \0 BOTH. 

*/

/*

CLASSES---------

class Example {
    public:   
        Example(int value);
        void publicMethod();
        
    protected:
        int protectedVariable;
        int protectedMethod(double param);
        private:double privateArray[LENGTH];
        void privateMethod(int* ptr, double& ref);
    };

     This is how to define a class method
     int Example::protextedMethod(double param){
         return 0;
     }

     TO INIT THE CLASS
     Example ex(10); , here ex is the object 

    
*/

// QUESTIONS?
// 1. What is the type of Env[ENV_DIM][ENV_DIM] and how it works in main.cpp?
// 2. As one memory addres is 4 byte, to move from one to another, do we have to add 4?
// 3. How pointers are working in 2D array
// 4. Test?