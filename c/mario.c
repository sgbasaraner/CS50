#include <stdio.h>
#include <cs50.h>

void build_pyramid(int height);

int main(void){
    printf("Height: ");
    int height = get_int();
    build_pyramid(height);
}

void build_pyramid(int height){
    for(int i = 1; i < height + 1; i++){
        for ( size_t ii = 0; ii < height - i; ++ii )
            putchar(' ');
        for ( size_t ii = 0; ii < i; ++ii )
            putchar('#');
        putchar(' ');
        for ( size_t ii = 0; ii < i; ++ii )
            putchar('#');
        for ( size_t ii = 0; ii < height - i; ++ii )
            putchar(' ');
        printf("\n");
   }
}