#include <stdio.h>

int main( ) {

int a[ 2 ][ 3 ] = { { 5, 6, 7 }, { 10, 20, 30 } };
int b[ 2 ][ 3 ] = { { 1, 2, 3 }, { 3, 2, 1 } };
int sum[ 2 ][ 3 ], row, column;

/* First the addition */

for( row = 0; row < 2; row++ )
for( column = 0; column < 3; column++ )
sum[ row ][ column ] =
a[ row ][ column ] + b[ row ][ column ];

/* Then print the results */

printf( "The sum is: \n\n" );

for( row = 0; row < 2; row++ ) {
for( column = 0; column < 3; column++ )
printf( "\t%d",sum[ row ][ column ] );
printf("\n"); /* at end of each row */
}

return 0;
}