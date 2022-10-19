// Joao Pedro Moro Bolognini RA:792185
// Árvore DFS com grafos.
#include <stdio.h>
#include <stdlib.h>

struct node{
  int w;
  struct node *prox;
};
typedef struct node Node;
struct graph{
  int V;
  int E;
  Node **adj;
};
typedef struct graph Graph;

struct vertices{
  int v1, v2;
};
typedef struct vertices Vertices;

void inicializar(Graph *G, unsigned nvertices);
void destroi(Graph *G);
void adiciona_arco(Graph *G, unsigned v, unsigned w);
int dfs_privado_caminho(Graph *G, int vis[], unsigned v, int contador, int vetor[], Vertices vertices[]);
void dfs_caminho(Graph *G, int vetor[], Vertices vertices[]);
int dfs_privado_ciclo(Graph *G, int vis[], unsigned v, int vetor[], int vetorCiclo[]);
int dfs_ciclo(Graph *G, int vetor[], int vetorCiclo[]);

int main() {
  int nVertices, i, j;
  Graph G;
  scanf("%d", &nVertices);
  inicializar(&G, nVertices);
  while (1){
    scanf("%d,%d", &i, &j);
    if ((i == 0) && (j == 0)){
      break;
    }
    adiciona_arco(&G, i-1, j-1);
  }
  int vetor[nVertices], verCiclo[nVertices];
  for (int i=0; i<nVertices ;i++){
    vetor[i]=0;
  }
  Vertices vertices[nVertices];
  dfs_caminho(&G, vetor, vertices); // Essa funcao serve pra verificar o caminho do grafo.
  for (int i=0; i<nVertices ;i++){
    printf("%d [%d,%d]\n", vetor[i], vertices[i].v1, vertices[i].v2);
  }
  for (int i=0; i<nVertices ;i++){
    vetor[i]=0;
    verCiclo[i]=-1; // Vetor auxiliar que ajuda para saber se o grafo ja viu determinado vertice.
    // Se for -1, o vertice nao foi visitado ainda.
    // Se for 0, o vertice esta sendo visitado no momento, esta vendo os caminhos dele.
    // Se for 1, o vertice ja foi visto e seus caminhos tambem.
  }
  int resposta=dfs_ciclo(&G, vetor, verCiclo); // Essa funcao serve para ver se tem algum ciclo no grafo.
  if (resposta != 0) {
    printf("aciclico: nao\n");
  } else {
    printf("aciclico: sim\n");
  }
  return 0;
}

void inicializar(Graph *G, unsigned nvertices){
  G->V = nvertices;
  G->E=0;
  G->adj = (Node**)malloc(sizeof(Node*)*G->V);
  for (unsigned v=0; v<G->V ;v++){
    G->adj[v] = NULL;
  }
}

void destroi(Graph *G){
  for (unsigned v=0; v<G->V ;v++){
    while (G->adj[v]){
      Node *l = G->adj[v];
      G->adj[v] = G->adj[v]->prox;
      free(l);
    }
  }
  free(G->adj);
  G->V=G->E=0;
}

void adiciona_arco(Graph *G, unsigned v, unsigned w){
  Node *l = (Node*)malloc(sizeof(Node));
  l->w = w;
  l->prox = G->adj[v];
  G->adj[v] = l;
  G->E++;
}

int dfs_privado_caminho(Graph *G, int vis[], unsigned v, int contador, int vetor[], Vertices vertices[]){
  int i;
  vis[v] = 1;
  for (i=0; i<G->V ;i++){
    if (vetor[i]==0){
      vetor[i]=v+1;
      break;
    }
  }
  vertices[i].v1=contador; // Rotula o vertice baseado em timestamps.
  contador++;
  for (Node* n = G->adj[v]; n != NULL ;n = n->prox){
    if (vis[n->w] == 0){
      contador=dfs_privado_caminho(G, vis, n->w, contador, vetor, vertices);
    }
  }
  vertices[i].v2=contador; // Rotula o vertice baseado em timestamps.
  contador++;
  return contador; // Retorna o indice atual do timestamps.
}

void dfs_caminho(Graph *G, int vetor[], Vertices vertices[]){
  int contador;
  contador=1; // Rotulador em timestamps, comeca em 1.
  int vis[G->V];
  for (unsigned v=0; v<G->V ;v++){
    vis[v] = 0;
  }
  for (unsigned v=0; v<G->V ;v++){
    if (vis[v] == 0){
      contador=dfs_privado_caminho(G, vis, v, contador, vetor, vertices);
    }
  }
}

int dfs_privado_ciclo(Graph *G, int vis[], unsigned v, int vetor[], int vetorCiclo[]){
  int i, temCiclo=0;
  vis[v] = 1;
  for (i=0; i<G->V ;i++){
    if (vetor[i]==0){
      vetor[i]=v+1;
      break;
    }
  }
  vetorCiclo[v]=0; // O vertice atual esta analisando seus provaveis vertices ligados.
  for (Node* n = G->adj[v]; n != NULL ;n = n->prox){
    vetor[v]=0;
    if (vetorCiclo[n->w] == 0){ // Se o vertice encontrado esta analisando seus provaveis vertices ligados e foi encontrado, logo tem-se um ciclo.
      temCiclo=1;
    }
    if (vis[n->w] == 0){
      temCiclo+=dfs_privado_ciclo(G, vis, n->w, vetor, vetorCiclo);
    }
  }
  vetorCiclo[v]=1; // O vertice ja foi visto e todos seus provaveis vizinhos/ligacoes foram visitadas.
  return temCiclo;
}

int dfs_ciclo(Graph *G, int vetor[], int vetorCiclo[]){
  int contador;
  contador=0;
  int vis[G->V];
  for (unsigned v=0; v<G->V ;v++){
    vis[v] = 0;
  }
  for (unsigned v=0; v<G->V ;v++){
    if (vis[v] == 0){
      contador+=dfs_privado_ciclo(G, vis, v, vetor, vetorCiclo);
    }
  }
  return contador; // Cada unidade dessa variavel eh um ciclo que foi encontrado, se for 0, o grafo eh aciclico.
}