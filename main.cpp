#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 999

int getText(char*, const char*);
void prepareArray(int*, int, int);
int max(int, int);
int compare(char*, char*, int, int);

int main(){
    char str1[MAX];
    int n = getText(str1, "test.txt");
    char str2[MAX];
    int m = getText(str2, "copy.txt");

    if(n == -1 || m == -1){
        return -1;
    }

    int aux = compare(str1, str2, n, m);

    float result =(float) aux/m;

    printf("Porcentaje de copia: %.5f%%\n", (float) result*100);
    return 0;
}

int getText(char* str, const char* fileName){
    FILE* stream = fopen(fileName, "r");
    if(stream == NULL){
        printf("Error al cargar el archivo...\n");
        return -1;
    }
    int i;
    char aux;
    for(i = 0; i < MAX; i++){
        aux = fgetc(stream);
        if(aux != EOF){
            *(str + i) = aux;
            continue;
        }
        break;
    }
    fclose(stream);
    return i;
}

void prepareArray(int* array, int x, int y){
    int i = max(x, y) + 1;
    for(; i > 0; i--){
        *(array + i) = 0;
        *(array + i * MAX) = 0;
    }
}

int max(int x, int y){
    if(x>=y){
        return x;
    }
    return y;
}

int compare(char* str1, char* str2, int x, int y){
    FILE * priori = fopen("main.csv","a");
    int t = 0;
    int table[MAX][MAX];
    prepareArray((int *)&table[0], x, y);
    int i, j, aux;
    t += max(x,y) + 2;
    for(i = 0; i < x; i++){
        for(j = 0 ; j < y; j++){
            aux = max(table[i][j + 1], table[i + 1][j]);
            if(*(str1 + i) == *(str2 + j)){
                aux ++;
                t++;
            }
            table[i + 1][j + 1] = aux;
            t += 4;
        }
        t += 1;
    }
    t += 2;
    fprintf(priori, "%d, %d\n", x + y, t);
    fclose(priori);
    return table[i][j];
}