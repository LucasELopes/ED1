#include <stdio.h>
int main ( ) {
    int x , y , *p ;
    y = 0 ; 
    p = &y ; // *p = 0;
    x = *p ; // x = 0;
    x = 4 ; // x = 4, *p = 0, 
    (*p)++; // *p = 1
    --x; // x = 3
    (*p ) += x ; // *p = 8, y = 8;
    return 0 ;
 }