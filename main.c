#include<stdio.h>

void main(){
    int resp;
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
    } while (resp != 0);
    
}