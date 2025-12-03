#include <string.h>
#include <stdio.h>
#include <limits.h>

#define INF 500000000 
#define MAX_VERTICES 501

typedef int Vertices;

typedef struct {
    int v;
    int a;
    int rota[MAX_VERTICES][MAX_VERTICES];
} Grafo;

Grafo grafo;

void dijkstra (int origem, int destino)
{
    int w, w0; 
    int fr[MAX_VERTICES], parnt[MAX_VERTICES];
    int cst[MAX_VERTICES];
    
    memset (parnt, -1, sizeof(parnt));
    
    for (int i = 0; i < grafo.v; i++) {
        cst[i] = INF;
    }

    cst[origem] = 0;
    fr[origem] = origem;
    
    while(1){
        int mincst = INF;
        w0 = -1; 
        
        for(w = 1; w < grafo.v; w++){ 
            if(parnt[w] == -1 && cst[w] < mincst){
                mincst = cst[w];
                w0 = w;
            }
        }
        
        if(w0 == -1 || mincst == INF) break; 
        
        parnt[w0] = fr[w0]; 
        
        for(w = 1; w < grafo.v; w++){
            if (grafo.rota[w0][w] != INF && cst[w0] != INF) {
                if(cst[w] > cst[w0] + grafo.rota[w0][w]){
                    cst[w] = cst[w0] + grafo.rota[w0][w];
                    fr[w] = w0;
                }
            }
        }
    }
    
    if(cst[destino] < INF) {
        printf("%d\n", cst[destino]);
    } else {
        printf("Nao e possivel entregar a carta\n");
    }
}


int main()
{
	memset(&grafo, 0, sizeof(grafo));
	
	int n,e; 
    int k,o,d;
	int x,y,z;
    
    int i, j;
    
    while(scanf("%d %d", &n, &e) == 2){
        if(n == 0 && e == 0) break;

        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                grafo.rota[i][j] = INF;
            }
            grafo.rota[i][i] = 0;
        }

        for (i = 0; i < e; ++i){
            scanf("%d %d %d",&x, &y, &z);
            
            if(grafo.rota[y][x] != INF){
                grafo.rota[x][y] = 0;
                grafo.rota[y][x] = 0;
            } else {
                grafo.rota[x][y] = z;
            }
        }
        
        grafo.v = n + 1; 
        grafo.a = e;

        scanf("%d", &k);

        for (i = 0; i < k; ++i){
            scanf("%d %d",&o, &d);
            dijkstra(o, d);
        }

        printf("\n");
    }
	return 0;
}
