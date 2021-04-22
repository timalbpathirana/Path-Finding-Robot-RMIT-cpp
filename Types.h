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



// Added symbol defines for M3
#define SYMBOL_RIGHT    '>'
#define SYMBOL_LEFT     '<'
#define SYMBOL_TOP      '^'
#define SYMBOL_BOTTOM   'v'



// Changes for M4
//typedef char** Env;

#endif // COSC_ASSIGN_ONE_TYPES