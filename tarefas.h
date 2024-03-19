#define TOTAL 100 //Define um variavel que pode ser utilizado pelos arquivos que incluem o pacote

typedef struct {
    int prioridade;
    char descricao[300];
    char categoria[100];
} Tarefa;

int Criar_tarefa(Tarefa tarefas[], int *posicao);

int Deletar_tarefa(Tarefa tarefas[], int *posicao);
int Listar_tarefa(Tarefa tarefas[], int posicao);
int Salvar(Tarefa tarefas[], int total, int posicao);
int Carregar_tarefa(Tarefa tarefas[], int total, int posicao);

