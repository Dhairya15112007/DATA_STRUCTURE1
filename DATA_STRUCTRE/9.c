#include <stdio.h>

#define MAX_VERTICES 20

static int graph[MAX_VERTICES][MAX_VERTICES];
static int visited[MAX_VERTICES];
static int vertex_count;

static void dfs(int vertex)
{
    int neighbor;

    visited[vertex] = 1;
    printf("%d ", vertex);

    /* Visit neighbors in ascending vertex order. */
    for (neighbor = 0; neighbor < vertex_count; ++neighbor) {
        if (graph[vertex][neighbor] && !visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

static void bfs(int start)
{
    int queue[MAX_VERTICES];
    int front = 0;
    int rear = 0;
    int neighbor;

    for (neighbor = 0; neighbor < vertex_count; ++neighbor) {
        visited[neighbor] = 0;
    }

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (neighbor = 0; neighbor < vertex_count; ++neighbor) {
            if (graph[vertex][neighbor] && !visited[neighbor]) {
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }
        }
    }
}

int main(void)
{
    int start;
    int i;

    /* Sample undirected graph with six vertices, numbered 0 through 5. */
    vertex_count = 6;
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[3][5] = graph[5][3] = 1;
    graph[4][5] = graph[5][4] = 1;

    printf("Graph traversal demonstration (vertices 0-%d)\n", vertex_count - 1);
    printf("Enter the starting vertex: ");
    if (scanf("%d", &start) != 1 || start < 0 || start >= vertex_count) {
        fprintf(stderr, "Invalid starting vertex. Enter a number from 0 to %d.\n",
                vertex_count - 1);
        return 1;
    }

    for (i = 0; i < vertex_count; ++i) {
        visited[i] = 0;
    }
    printf("DFS traversal: ");
    dfs(start);
    printf("\n");

    printf("BFS traversal: ");
    bfs(start);
    printf("\n");

    return 0;
}
