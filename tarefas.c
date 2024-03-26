#include "tarefas.h"
#include <stdio.h>
#include <string.h>

Erro Criar_tarefa(Tarefa tarefas[], int *posicao){
    if(*posicao >= TOTAL){
        return MAX_TAREFAS;
    }

    printf("Entre com a prioridade: ");
    scanf("%d", &tarefas[*posicao].prioridade);
    Clear_buffer();
    
    printf("Entre com a categoria: ");
    fgets(tarefas[*posicao].categoria, 100, stdin);

    printf("Entre com a descricao: ");
    fgets(tarefas[*posicao].descricao, 300, stdin);

    *posicao = *posicao + 1;

    return Ok;
};

Erro Deletar_tarefa(Tarefa tarefas[], int *posicao){
    if(*posicao == 0){
        return SEM_TAREFAS;
    }

    int pos_d;
    printf("Entre com a posicao da tarefa: ");
    scanf("%d", &pos_d);

    pos_d--;

    if(pos_d >= *posicao){
        return NAO_EXISTE;
    }
    int i = pos_d;

    for(i; i<*posicao; i++){
        tarefas[i].prioridade = tarefas[i+1].prioridade;
        strcpy(tarefas[i].categoria, tarefas[i+1].categoria);
        strcpy(tarefas[i].descricao, tarefas[i+1].descricao);
    }

    *posicao = *posicao - 1;

    return Ok;
};

Erro Listar_tarefa(Tarefa tarefas[], int posicao){
    if (posicao == 0){
        return SEM_TAREFAS;
    }

    int i = 0;

    for(i; i < posicao; i++){
        printf("Posicao: %d", i+1);
        printf("\t Prioridades: %d", tarefas[i].prioridade);
        printf("\t Categoria: %s", tarefas[i].categoria);
        printf("\t Descricao: %s", tarefas[i].descricao);
    }

    return Ok;
};

Erro Salvar(Tarefa tarefas[], int total, int posicao){
    FILE *f = fopen("tarefas", "wb");

    if(f == NULL){
        return ABRIR;
    }

    int e = fwrite(tarefas, total, sizeof(Tarefa), f);

    if(e <= 0){
        return ESCREVER;
    }

    e = fwrite(&posicao, 1, sizeof(int), f);

    if(e <= 0){
        return ESCREVER;
    }

    e = fclose(f);
    if(e != 0){
        return FECHAR;
    }

    return Ok;
};

Erro Carregar_tarefa(Tarefa tarefas[], int total, int *posicao){
    FILE *f = fopen("tarefas", "rb");

    if(f == NULL){
        return ABRIR;
    }

    int e = fread(tarefas, total, sizeof(Tarefa), f);
    if(e <= 0){
        return LER;
    }

    e = fread(posicao, 1, sizeof(int), f);
    if(e <= 0){
        return LER;
    }

    e = fclose(f);
    if(e != 0){
        return FECHAR;
    }

    return Ok;
};

void Clear_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { } //Faz a leitura de tudo que for digitado até que c seja diferente de \n ou EOF(Final do arquivo).
}