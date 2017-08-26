#include <stdio.h>
#include <cs50.h>

int length(long long n);
int last_digit(long long n);
int first_sum(long long n);
int second_last_digit(long long n);
int second_sum(long long n);

int main(void){
    printf("Enter card number: ");
    long long n = get_long_long();
    if (last_digit(first_sum(n) + second_sum(n)) == 0){
        char str[256];
        sprintf(str, "%lld", n);
        if ((str[0] == '3') && (str[1] == '4' || str[1] == '7')){
            printf("AMEX\n");
        } else if (str[0] == '4'){
            printf("VISA\n");
        } else if ((str[0] == '5') && (str[1] == '1' || str[1] == '2' || str[1] == '3' || str[1] == '4' || str[1] == '5')){
            printf("MASTERCARD\n");
        } else {
            printf("LEGIT\n");
        }
    } else {
        printf("the result is %i, it should've been 0: NOT LEGIT\n",last_digit(first_sum(n) + second_sum(n)));
    }
}

int length(long long n){
    int count = 0;
    while(n != 0){
        n /= 10;
        ++count;
    }
    return count;
}

int first_sum(long long n){
    int count = 0;
    long long modified_n = n;
    while (modified_n > 0){
        int digit_multiplied = second_last_digit(modified_n) * 2;
        int digit_multiplied_digits = digit_multiplied;
        if (digit_multiplied > 9){
            digit_multiplied_digits = second_last_digit(digit_multiplied) + last_digit(digit_multiplied);
        }
        count += digit_multiplied_digits;
        modified_n = modified_n - (second_last_digit(modified_n) * 10) - last_digit(modified_n);
        modified_n /= 100;
    }
    return count;
}

int second_sum(long long n){
    int count = 0;
    long long modified_n = n;
    while (modified_n > 0){
        count += last_digit(modified_n);
        modified_n = modified_n - (second_last_digit(modified_n) * 10) - last_digit(modified_n);
        modified_n /= 100;
    }
    return count;
}

int last_digit(long long n){
    return n % 10;
}

int second_last_digit(long long n){
    return (n / 10) % 10;
}