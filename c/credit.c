#include <stdio.h>
#include <cs50.h>

int length(long long n);
int last_digit(long long n);
int first_sum(long long n);
int second_last_digit(long long n);
int second_sum(long long n);
long long clean_last_two_digits(long long n);

int main(void){
    printf("Number: ");
    long long n = get_long_long();
    if (last_digit(first_sum(n) + second_sum(n)) == 0){
        char str[length(n) + 1];
        sprintf(str, "%lld", n);
        if ((str[0] == '3') && (str[1] == '4' || str[1] == '7')){
            printf("AMEX\n");
        } else if (str[0] == '4'){
            printf("VISA\n");
        } else if ((str[0] == '5') && (str[1] == '1' || str[1] == '2' || str[1] == '3' || str[1] == '4' || str[1] == '5')){
            printf("MASTERCARD\n");
        }
    } else {
        printf("INVALID\n");
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
    while (n > 0){
        int digit_multiplied = second_last_digit(n) * 2;
        int digit_multiplied_digits = digit_multiplied;
        if (digit_multiplied > 9){
            digit_multiplied_digits = second_last_digit(digit_multiplied) + last_digit(digit_multiplied);
        }
        count += digit_multiplied_digits;
        n = clean_last_two_digits(n)
    }
    return count;
}

int second_sum(long long n){
    int count = 0;
    while (n > 0){
        count += last_digit(n);
        n = clean_last_two_digits(n)
    }
    return count;
}

int last_digit(long long n){
    return n % 10;
}

long long clean_last_two_digits(long long n){
    n = n - (second_last_digit(n) * 10) - last_digit(n);
    n /= 100;
    return n
}

int second_last_digit(long long n){
    return (n / 10) % 10;
}