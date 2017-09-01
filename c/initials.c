#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void){
	string name = get_string();

	if (name[0] != ' '){
		printf("%c", toupper(name[0]));
	}

	for (int i = 0, n = strlen(name); i < n; ++i){
		if (name[i] == ' ' && name[i + 1] != ' '){
			if (name[i + 1] >= 'A' && name [i + 1] <= 'z'){
				printf("%c", toupper(name[i + 1]));
			}
		}
	}
	printf("\n");
}