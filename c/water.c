#include <stdio.h>
#include <cs50.h>

int minutes_to_bottles(int minutes);

int main(void){
    printf("Minutes: ");
    int minutes = get_int();
    printf("Bottles: %i\n", minutes_to_bottles(minutes));
}

int minutes_to_bottles(int minutes){
    return minutes * 12;
}