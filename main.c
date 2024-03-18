#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_FILEPATH perror("[ERROR] :: wrong filepath !"),exit(1)

long file_size(char* filepath, int print){
    FILE* fp = fopen(filepath,"r");
    if (fp == NULL)
        ERROR_FILEPATH;

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    fclose(fp);

    if(print)
        printf("FILE SIZE :: %ld\n", file_size);

    return file_size;
}

char* ltrim(char* str){
    if(str == NULL) return NULL;

    int i = 0;
    while(isspace(str[i]))
        i++;

    strcpy(str,str+i);

    return str;
}

void write_to_file(char* filepath, char* str){
    FILE* fp = fopen(filepath,"w");
    if (fp == NULL)
        ERROR_FILEPATH;
    fprintf(fp,"%s",str);
    fclose(fp);
}

char* read_from_file(char* filepath){
    FILE* fp = fopen(filepath, "r");
    if (fp == NULL)
        ERROR_FILEPATH;

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    char* str = (char*)malloc(file_size * sizeof(char));

    fread(str, sizeof(char), file_size, fp);
    str[file_size] = '\0';

    fclose(fp);
    return str;
}

int main(){

    write_to_file("oldu.txt","          Selam");
    char* text = read_from_file("oldu.txt");
    
    printf("FILE :: %s\n",text);
    printf("TRIMMED FILE :: %s\n",ltrim(text));
    file_size("oldu.txt",1);
    
    return 0;
}
