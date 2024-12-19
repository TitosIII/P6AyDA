#include<stdio.h>
#include<stdlib.h>

#define MAX 999

int getText(char*, const char*);
void prepareArray(int*);
int compare(char*, char*);

FILE* stream;

int main(){
    char str1[MAX];
    int n = getText(str1, "test.txt");
    char str2[MAX];
    int m = getText(str1, "copy.txt");
    
    char table[MAX][MAX];
    prepareArray((int*)&table[0]);
    
    return 0;
}

int getText(char* str, const char* fileName){
    stream = fopen(fileName, "r");
    if(stream == NULL){
        printf("Error al cargar el archivo...\n");
        return -1;
    }
    int i;
    char aux;
    for(i = 0; i < MAX; i++){
        aux = fgetc(stream);
        if(aux != EOF){
            *(str + i);
            continue;
        }
        break;
    }
    return i;
}

void prepareArray(int* array){
    int i, j;
    for(i = 0 ; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            *(array + i * MAX + j) = -1;
        }
    }
}