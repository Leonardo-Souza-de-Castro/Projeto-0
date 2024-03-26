#define TOTAL 100 //Define um variavel que pode ser utilizado pelos arquivos que incluem o pacote

typedef struct {
    int prioridade;
    char descricao[300];
    char categoria[100];
} Tarefa;

typedef enum Erros{Ok, MAX_TAREFAS, SEM_TAREFAS, NAO_EXISTE, ABRIR, FECHAR, ESCREVER, LER} Erro;

Erro Criar_tarefa(Tarefa tarefas[], int *posicao);

Erro Deletar_tarefa(Tarefa tarefas[], int *posicao);
Erro Listar_tarefa(Tarefa tarefas[], int posicao);
Erro Salvar(Tarefa tarefas[], int total, int posicao);
Erro Carregar_tarefa(Tarefa tarefas[], int total, int *posicao);

void Clear_buffer();

