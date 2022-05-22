// #define trigger = 1;

// int main(int argc, char **argv) {


//     #ifdef trigger
//     int mynum;
//     mynum = int(trigger);
//     printf("My number is %d", mynum);
//     #endif


//     int mynum = 1;
//     printf("My number is %d", mynum);
    
// }

/* Example using #ifdef directive for inserting platform specific source code by TechOnTheNet.com */

#include <stdio.h>

// #define UNIX 1

int main()
{
    // #define UNIX 1

   #ifdef UNIX
   printf("UNIX specific function calls go here.\n");
   #endif

   printf("TechOnTheNet is over 10 years old.\n");

   return 0;
}