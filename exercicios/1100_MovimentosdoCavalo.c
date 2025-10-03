#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 8
#define MAX_QUEUE_SIZE 1000

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, Position p) {
    q->data[q->rear++] = p;
}

Position dequeue(Queue *q) {
    return q->data[q->front++];
}

bool isValid(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

int bfs(Position start, Position end) {
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
    bool visited[SIZE][SIZE];
    int distance[SIZE][SIZE];
    
    memset(visited, false, sizeof(visited));
    memset(distance, -1, sizeof(distance));
    
    Queue q;
    initQueue(&q);
    
    enqueue(&q, start);
    visited[start.x][start.y] = true;
    distance[start.x][start.y] = 0;
    
    while (!isEmpty(&q)) {
        Position cur = dequeue(&q);
        
        if (cur.x == end.x && cur.y == end.y) {
            return distance[cur.x][cur.y];
        }
        
        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if (isValid(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                distance[nx][ny] = distance[cur.x][cur.y] + 1;
                enqueue(&q, (Position){nx, ny});
            }
        }
    }
    
    return -1;
}

Position toPosition(const char *s) {
    return (Position){s[0] - 'a', s[1] - '1'};
}

int main() {
    char start[3], end[3];
    
    while (scanf("%s %s", start, end) != EOF) {
        Position startPos = toPosition(start);
        Position endPos = toPosition(end);
        
        int moves = bfs(startPos, endPos);
        
        printf("To get from %s to %s takes %d knight moves.\n", start, end, moves);
    }
    
    return 0;
}
