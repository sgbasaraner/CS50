#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[]){

	// check for two arguments
    if (argc != 2){
    	fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // remember raw_file
    char *raw_file = argv[1];

    // open the file
    FILE *ptr = fopen(raw_file, "r");

    //check if file can be opened
    if (ptr == NULL){
        fprintf(stderr, "Could not open %s.\n", raw_file);
        return 2;
    }

    int count = 0;
    BYTE buffer[512];

    FILE *img;

    fseek(ptr, 0L, SEEK_END);
    long int size = ftell(ptr);
    printf("%lu\n", size);
    rewind(ptr);
    char filename[7];
    for (int i = 1; (i * 512) < size + 1; ++i){
    	fread(&buffer, 512, 1, ptr);

    	// check if it's the start of a new jpg file
    	if (buffer[0 == 0xff] &&
    	    buffer[1] == 0xd8 &&
    	    buffer[2] == 0xff &&
    	    (buffer[3] & 0xf0) == 0xe0){

    	    // check if another file was found before
    		if (count > 0){
    			fclose(img);
    			sprintf(filename, "%03i.jpg", count);
    			img = fopen(filename, "w");
    			fwrite(&buffer, 512, 1, img);
    			count++;
    		} else {
    		    sprintf(filename, "%03i.jpg", count);
    			img = fopen(filename, "w");
    			fwrite(&buffer, 512, 1, img);
    			count++;
    		}
    	} else {

    	    // if a previous file is present, write to it
    		if (count > 0){
    			fwrite(&buffer, 512, 1, img);
    		}
    	}
		fseek(ptr, 512*i, SEEK_SET);
    }
    return 0;
}