#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[]){

   if (argc == 2){
   		int k = atoi(argv[1]);
   		printf("plaintext: ");
   		string str = get_string();
   		printf("ciphertext: ");
   		for (int i = 0, n = strlen(str); i < n; i++){
    		if (str[i] >= 'a' && str[i] <= 'z'){
    			printf("%c", ((((str[i] - 'a') + k) % 26) + 'a'));
    		} else if (str[i] >= 'A' && str[i] <= 'Z'){
    			printf("%c", ((((str[i] - 'A') + k) % 26) + 'A'));
    		} else {
    			printf("%c", str[i]);
    		}
		}
		printf("\n");
    } else if (argc > 2){
   		printf("Usage: ./caesar k\n");
      	return 1;
    } else {
     	printf("Usage: ./caesar k\n");
      	return 1;
    }
}
