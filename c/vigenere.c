#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void vigenerize(string k, string str);
int vigenerize_char(char c);

int main(int argc, string argv[]){

    if (argc == 2){
        string k = argv[1];
        int check = 1;

        for (int i = 0, n = strlen(k); i < n; ++i){
            if (!(k[i] >= 'A' && k[i] <= 'z')){
                check = 0;
            }
        }

        if (check == 0){
            printf("The keyword should consist of alphabetical letters.\n");
            return 1;
        } else {
            printf("plaintext: ");
            string str = get_string();
            printf("ciphertext: ");
            vigenerize(k, str);
            printf("\n");
        }
    } else if (argc > 2){
        printf("Usage: ./vigenere k\n");
        return 1;
    } else {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
}

int vigenerize_char(char c){
    return toupper(c) - 65;
}

void vigenerize(string k, string str){
    int k_length = strlen(k);
    int str_length = strlen(str);

    /* turn the key to a vigenerizable array */
    int arr[k_length];
    for (int i = 0; i < k_length; ++i){
        arr[i] = vigenerize_char(k[i]);
    }

    for (int i = 0, j = 0; i < str_length; ++i, ++j){
        if (j == k_length){
            j = 0;
        }

        if (str[i] >= 'a' && str[i] <= 'z'){
            printf("%c", ((((str[i] - 'a') + arr[j]) % 26) + 'a'));
        } else if (str[i] >= 'A' && str[i] <= 'Z'){
            printf("%c", ((((str[i] - 'A') + arr[j]) % 26) + 'A'));
        } else {
            printf("%c", str[i]);
            --j;
        }
    }
}
