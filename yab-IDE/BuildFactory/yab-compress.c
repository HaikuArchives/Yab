#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>

unsigned long file_size(char *filename)
{
    FILE *pFile = fopen(filename, "rb");
    fseek (pFile, 0, SEEK_END);
    unsigned long size = ftell(pFile);
    fclose (pFile);
    return size;
}

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("Usage: yab-compress <file.yab>\n\n");
        return 1;
    }
	unsigned long filesize;
    filesize = file_size(argv[1]);
    char *buffer = (char*)malloc(filesize);

    FILE *fi, *fo;

    // read source file into buffer
    fi = fopen(argv[1], "r");
    fread(buffer, sizeof(char), filesize, fi);
    fclose(fi);

    // compress buffer
    char *dest;
    unsigned long destlen;
    compress(dest, &destlen, buffer, filesize);

    // write compressed buffer to output
    unsigned long i;
    fo = fopen("program.h", "w");
    fprintf(fo, "const char myProg[] = {");
    for(i=0; i < destlen; i++)
        fprintf(fo, "%i,", dest[i]);
    fprintf(fo, "' ' };\n");
    fclose(fo);

    return 0;
}

