#include <stdio.h>
#include <cs50.h>

void build_pyramid(int height);
int get_proper_int(void);

int main(void){
    printf("Height: ");
    int height = get_proper_int();
    if (height > -1){
        build_pyramid(height);
    } else {
        return 1;
    }
}

void build_pyramid(int height){
    for(int i = 1; i < height + 1; i++){
        for ( size_t ii = 0; ii < height - i; ++ii )
            putchar(' ');
        for ( size_t ii = 0; ii < i; ++ii )
            putchar('#');
        putchar(' ');
        putchar(' ');
        for ( size_t ii = 0; ii < i; ++ii )
            putchar('#');
        printf("\n");
   }
}

int get_proper_int(void){
    int i = -1;
    while (i < 0 || i > 23){
        printf("Height: ");
        i = get_int();
    }
    return i;
}
