#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int v;
    struct No * prox;
} no;

typedef struct Grafo {
    int nv;
    no ** lista;
} grafo;

typedef struct Fila {
    int inicio;
    int topo;
    int qtd;
    int * itens;
} fila;

// Queue = enfileirar
void enfileirar (fila *p, int elemento) {
    p -> itens[++(p -> topo)] = elemento;
    int n = p -> qtd;
    p -> qtd = n += 1;
}

// Verifica se a fila está vazia
int vazia (fila *p) {
    if (p -> qtd == 0) {
        return 1;
    }
    else{
        return 0;
    }
}

// Dequeue = desenfileirar
int desenfileirar (fila *p) {
    int n = p -> qtd;
    p -> qtd = n -= 1;
    return (p -> itens[p -> inicio++]);
    
}

// Printa a fila para o usuário
void printar_fila (fila *p) {
    fila *ptr = p;
    int n;
    printf("Fila\n");
    for (int i = p -> inicio; i <= p -> topo; i++){
        n = ptr -> itens[i];
        printf("%d->", n += 1);
    }
    printf ("//\n");
}

// Inicializa o grafo
void inicializar (grafo * g, int nv) {
    g -> lista = calloc (nv, sizeof(no*));
    g -> nv = nv;
}

// Desaloca o grafo da memória
void desalocar (grafo * g) {
    for (int i = 0; i < g -> nv; i++) {
    no* temp = g -> lista[i]; 
        while (temp) {
            no *r = temp;
            temp = temp -> prox;
            free (r);
        }
    }
    free (g -> lista);
}

// Adiciona aresta ao grafo
void add_aresta (grafo * g, int v1, int v2) {
    no **temp = &g -> lista[v1];
    while (*temp != NULL && (*temp) -> v > v2) {
        temp = &(*temp) -> prox;
    }
    if (*temp == NULL || (*temp) -> v != v2) {
        no * nv = malloc (sizeof(no));
        nv -> v = v2;
        nv -> prox = *temp;
        *temp = nv;
    }
}

void saida (char d[][4], int pi[], char cor[], fila * f, int qtd_v) {
    printf ("Noh");
    for (int i = 1; i <= qtd_v; i++) {
        printf (" %d", i);
    }
    printf ("\n");
    printf ("d[]");
    for (int i = 0; i < qtd_v; i++) {
        printf (" %s", d[i]);
    }
    printf ("\n");
    printf ("pi[]");
    for (int i = 0; i < qtd_v; i++) {
        printf (" %d", pi[i]);
    }
    printf ("\n");
    printf ("cor");
    for (int i = 0; i < qtd_v; i++) {
        printf (" %c", cor[i]);
    }
    printf ("\n");
    printar_fila (f);
}

// Algoritmo de busca em largura
void bfs (grafo * g, int origem) {
    fila f;
    f.topo = -1;
    f.inicio = 0;
    f.qtd = 0;
    f.itens = (int *) malloc(g -> nv * sizeof(int));

    int v1, pi[g -> nv], dn[g -> nv], n, dv;
    char d[g -> nv][4], cor[g -> nv], c;

    for (int i = 0; i < g -> nv; i++) {
        strcpy (d[i], "inf");
        pi[i] = -1;
        cor[i] = 'W';
    }

    saida (d, pi, cor, &f, g -> nv);
    cor[origem] = 'G';
    strcpy (d[origem], "0");
    enfileirar (&f, origem);
    printf ("\n");
    saida (d, pi, cor, &f, g -> nv);
    dn[origem] = 0;

    while (vazia (&f) != 1) {
        v1 = desenfileirar (&f);
        no *temp = g -> lista[v1];
        while (temp != NULL) {
            if (cor[temp -> v] == 'W') {
                cor[temp -> v] = 'G';
                dv = dn[v1] + 1;
                dn[temp -> v] = dv;
                c = dv + '0';
                d[temp -> v][0] = c;
                d[temp -> v][1] = '\0';
                n = v1;
                pi[temp -> v] = n += 1;
                enfileirar (&f, temp -> v);
            }
            temp = temp -> prox;
        }
        cor[v1] = 'B';
        printf ("\n");
        saida (d, pi, cor, &f, g -> nv);
    }
}

int main () {
    grafo g;
    int v1, v2, nv, na, direcionado, origem;
    scanf ("%d %d %d %d\n", &nv, &na, &direcionado, &origem);
    origem -= 1;
    inicializar (&g, nv);

    for (int i = 0; i < na; i++) {
        scanf ("%d %d\n", &v1, &v2);
        v1 -= 1;
        v2 -= 1;
        add_aresta (&g, v1, v2);
        if (direcionado == 0) {
            add_aresta (&g, v2, v1);
        }
    }

    bfs (&g, origem);
    desalocar (&g);

    return 0;
}