#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

void topological_sort(int graph[][MAX_VERTICES], int n);

int main() {
    int n = 6; // 정점의 개수
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    printf("Topological Sort:\n");
    topological_sort(graph, n);

    return 0;
}

void topological_sort(int graph[][MAX_VERTICES], int n) {
    int in_degree[MAX_VERTICES] = {0};
    int i, j, k;

    // Step 1: 각 정점의 진입 차수 계산
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[j][i] == 1) {
                in_degree[i]++;
            }
        }
    }

    // Step 2: 위상 정렬 수행
    for (k = 0; k < n; k++) {
        // 진입 차수가 0인 정점을 찾음
        int v = -1;
        for (i = 0; i < n; i++) {
            if (in_degree[i] == 0) {
                v = i;
                break;
            }
        }

        // 진입 차수가 0인 정점이 없으면 사이클 발생
        if (v == -1) {
            fprintf(stderr, "Network has a cycle.\n");
            exit(1);
        }

        // 정점 출력 및 삭제
        printf("%d ", v);
        in_degree[v] = -1; // 삭제 표시

        // v에서 나가는 간선 제거
        for (j = 0; j < n; j++) {
            if (graph[v][j] == 1) {
                in_degree[j]--;
            }
        }
    }
    printf("\n");
}