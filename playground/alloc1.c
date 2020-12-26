#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
    int32_t a[9][9] = {0};

    for( size_t i = 0 ; i < 9 ; i++ )
    {
        for( size_t j = 0 ; j < 9 ; j++ )
        {
            a[i][j] = ( i + 1 ) * ( j + 1 );
        }
    }

    /*for( size_t i = 0 ; i < 9 ; i++ )
    {
        for( size_t j = 0 ; j < 9 ; j++ )
        {
        printf( "%02d ", a[i][j] );
        }

        printf( "\n" );
    }*/

    for( size_t i = 0 ; i < 9 ; i++ )
    {
        printf("The address of row %ld is %p\n",i,&a[i]);
        printf("The value of row %ld is %p\n",i,a[i]);
        for( size_t j = 0 ; j < 9 ; j++ )
        {
            printf( "   The address of column %ld is %p\n",j,&a[i][j]);
        }
    }

    return 0;
}