#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define M 3

bool dfs(int Node, int ver, bool Visited_paths[], int Edge[][M]) {
    int next;
    Visited_paths[Node] = true;
    for (next = 0; next < ver; next++) {
        if  (Edge[Node][next] && !Visited_paths[next]) {
            dfs(next, ver, Visited_paths, Edge);
        }
    }
    return true;
}

bool Path(int ver, int ed[][M], int new) {
    bool Visited_paths[ver];
    int i, j, Edge[ver][ver];
    for (i = 0; i < ver; i++) {
        Visited_paths[i] = false;
        for (j = 0; j < ver; j++) {
         Edge[i][j] = 0;
        }
    }
    for (i = 0; i < new; i++) {
        int v1 = ed[i][0];
        int v2 = ed[i][1];
     Edge[v1][v2] = 1;
     Edge[v2][v1] = 1;
    }
    int start = 0;
    dfs(start, ver, Visited_paths, Edge);
    for (i = 0; i < ver; i++) {
        if (Visited_paths[i] !=0) {
            return false;
        }
    }
    return true;
}

int main() {
    int i, vertex, edges;
    scanf("%d %d", &vertex, &edges);
    int (*ED)[M] = malloc(edges * sizeof(*ED));
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &ED[i][0], &ED[i][1]);
    }
    bool res = Path(vertex, ED, edges);
    printf(res ? "true\n" : "false\n");
    free(ED);
    return 0;
}
