#include "tarefas.h"
#include <stdio.h>
#include <string.h>

int Criar_tarefa(Tarefa tarefas[], int *posicao){
    if(*posicao >= TOTAL){
        return 1;
    }

    printf("Entre com a prioridade: ");
    scanf("%d", &tarefas[*posicao].prioridade);
    Clear_buffer();
    
    printf("Entre com a categoria: ");
    fgets(tarefas[*posicao].categoria, 100, stdin);

    printf("Entre com a descricao: ");
    fgets(tarefas[*posicao].descricao, 300, stdin);

    *posicao = *posicao + 1;

    return 0;
};

int Deletar_tarefa(Tarefa tarefas[], int *posicao){
    if(*posicao == 0){
        return 1;
    }

    int pos_d;
    printf("Entre com a posicao da tarefa: ");
    scanf("%d", &pos_d);

    pos_d--;

    if(pos_d >= *posicao){
        return 2;
    }
    int i = pos_d;

    for(i; i<*posicao; i++){
        tarefas[i].prioridade = tarefas[i+1].prioridade;
        strcpy(tarefas[i].categoria, tarefas[i+1].categoria);
        strcpy(tarefas[i].descricao, tarefas[i+1].descricao);
    }

    *posicao = *posicao - 1;

    return 0;
};

int Listar_tarefa(Tarefa tarefas[], int posicao){
    if (posicao == 0){
        return 1;
    }

    int i = 0;

    for(i; i < posicao; i++){
        printf("Posicao: %d", i+1);
        printf("\t Prioridades: %d", tarefas[i].prioridade);
        printf("\t Categoria: %s", tarefas[i].categoria);
        printf("\t Descricao: %s", tarefas[i].descricao);
    }

    return 0;
};

int Salvar(Tarefa tarefas[], int total, int posicao){
    FILE *f = fopen("tarefas", "wb");

    if(f == NULL){
        return 1;
    }

    int e = fwrite(tarefas, total, sizeof(Tarefa), f);

    if(e <= 0){
        return 2;
    }

    e = fwrite(&posicao, 1, sizeof(int), f);

    if(e <= 0){
        return 2;
    }

    e = fclose(f);
    if(e != 0){
        return 3;
    }

    return 0;
};

int Carregar_tarefa(Tarefa tarefas[], int total, int *posicao){
    FILE *f = fopen("tarefas", "rb");

    if(f == NULL){
        return 1;
    }

    int e = fread(tarefas, total, sizeof(Tarefa), f);
    if(e <= 0){
        return 2;
    }

    e = fread(posicao, 1, sizeof(int), f);
    if(e <= 0){
        return 2;
    }

    e = fclose(f);
    if(e != 0){
        return 3;
    }

    return 0;
};

void Clear_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { } //Faz a leitura de tudo que for digitado até que c seja diferente de \n ou EOF(Final do arquivo).
}