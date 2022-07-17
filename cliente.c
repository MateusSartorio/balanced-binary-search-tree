#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./src/h/bst.h"

int main(int argc, char** argv) {
    FILE* f = fopen("./saida.txt", "a");

    if(f == NULL) {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    bst* t = bst_init(1);

    int N = 1E6;
    srand(time(NULL));
    for(int i = 0; i < N; i++)
        bst_put(t, rand());

    // bst_print(t);
    // printf("A altura da arvore eh: %d\n", bst_height(t));
    fprintf(f, "%d", bst_height(t));


    bst_delete(t);
    fclose(f);

    return 0;
}