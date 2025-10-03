#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1030

char image[MAX][MAX];
int dimensionX;
int dimensionY;

bool isPixelInImage(int xAxis, int yAxis) {
    return (xAxis >= 0 && xAxis < dimensionX && yAxis >= 0 && yAxis < dimensionY);
}

bool isVisited(int xAxis, int yAxis) {
    return (image[xAxis][yAxis] == 'o');
}

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct Node {
    Coordinate coord;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, Coordinate coord) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coord = coord;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

Coordinate dequeue(Queue* q) {
    Node* temp = q->front;
    Coordinate coord = temp->coord;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return coord;
}

void BFS(int xAxis, int yAxis) {
    int possibleNeighborsInX[] = {1, -1, 0, 0};
    int possibleNeighborsInY[] = {0, 0, -1, 1};

    Queue toBeVisited;
    initQueue(&toBeVisited);
    Coordinate startCoord = {xAxis, yAxis};

    enqueue(&toBeVisited, startCoord);

    while (!isEmpty(&toBeVisited)) {
        Coordinate visited_coord = dequeue(&toBeVisited);
        for (int i = 0; i < 4; i++) {
            int x = visited_coord.x + possibleNeighborsInX[i];
            int y = visited_coord.y + possibleNeighborsInY[i];

            if (isPixelInImage(x, y) && !isVisited(x, y)) {
                Coordinate new_coord = {x, y};
                enqueue(&toBeVisited, new_coord);
                image[x][y] = 'o';
            }
        }
    }
}

int main() {
    int clicks = 0;
    
    scanf("%d %d", &dimensionX, &dimensionY);

    for (int x = 0; x < dimensionX; x++)
        scanf("%s", image[x]);

    for (int x = 0; x < dimensionX; x++)
        for (int y = 0; y < dimensionY; y++)
            if (!isVisited(x, y)) {
                clicks++;
                BFS(x, y);
            }

    printf("%d\n", clicks);

    return 0;
}
