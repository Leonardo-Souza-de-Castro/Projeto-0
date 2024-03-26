#include <stdio.h>
#include "tarefas.h"

void main(){
    int pos = 0;
    Tarefa tarefa[TOTAL];

    Erro e = Carregar_tarefa(tarefa, TOTAL, &pos);
    if (e == ABRIR)
    {
        printf("Nao foi possivel abrir o arquivo\n");
    }
    if (e == LER)
    {
        printf("Nao foi possivel ler as tarefas no arquivo\n");
    }
    if (e == FECHAR)
    {
        printf("Nao foi possivel fechar o arquivo\n");
    }

    int resp;
    if (e != Ok){
        pos = 0;
    }

    do
    {
        printf("\nMenu Principal: \n");
        printf("1 - Criar Tarefa \n");
        printf("2 - Deletar Tarefa \n");
        printf("3 - Listar Tarefas \n");
        printf("0 - Sair \n");

        printf("Entre com uma opcao: ");

        scanf("%d", &resp);
        printf("Opcao selecionado: %d \n", resp);

        switch (resp)
        {
        case 1:
            e = Criar_tarefa(tarefa, &pos);
            if (e == MAX_TAREFAS)
            {
                printf("Maximo de tarefas alcancado\n");
            }
            break;
        case 2:
            e = Deletar_tarefa(tarefa, &pos);
            if (e == SEM_TAREFAS)
            {
                printf("Nao existem tarefas para deletar\n");
            }
            else if(e == NAO_EXISTE){
                printf("Nao existe tarefas nesta posicao\n");
            }
            
            break;
        case 3:
            e = Listar_tarefa(tarefa, pos);
            if (e == SEM_TAREFAS)
            {
                printf("Nao existem tarefas para listar\n");
            }
            break;
        case 0:
            printf("Sair\n");
            e = Salvar(tarefa, TOTAL, pos);
            if (e == ABRIR)
            {
                printf("Nao foi possivel abrir o arquivo\n");
            }
            else if (e == ESCREVER)
            {
                printf("Nao foi possivel escrever as tarefas no arquivo.\n");
            }
            else if (e == FECHAR)
            {
                printf("Nao foi possivel fechar o arquivo\n");
            }
            break;

        default:
            printf("Opcao invalida! \n");
            break;
        }
    } while (resp != 0);
    
}