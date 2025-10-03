#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct dataNode {
    char name[30];
} DataNode;

typedef struct node {
    DataNode data;
    struct node *next;
} Node;

typedef struct list {
    int size;
    Node *head;
} List;

List *createList();

void push_front(List *list, DataNode data);

void insertionSort(List *list);

void printList(List *list, int pos);

bool isEmpty(List *list);

Node *atPos(List *list, int index);

List *createList() {
    List *list = (List *)malloc(sizeof(List));
    list->size = 0;
    list->head = NULL;
    return list;
}

void push_front(List *list, DataNode data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = list->head;
    list->head = node;
    list->size++;
}

void printList(List *list, int pos) {
    Node *pointer = atPos(list, pos);
    printf("%s\n", pointer->data.name);
}

bool isEmpty(List *list) {
    return (list->size == 0);
}

Node *atPos(List *list, int index) {
    if (index >= 0 && index < list->size) {
        Node *node = list->head;
        int i;
        for (i = 0; i < index; i++) {
            node = node->next;
        }
        return node;
    }
    return NULL;
}

void insertionSort(List *list) {
    Node *pointer = list->head;
    Node *i;
    Node *j;
    for (i = list->head; i->next != NULL; i = i->next) {
        Node *menor = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(j->data.name, menor->data.name) < 0) {
                menor = j;
            }
        }
        DataNode aux = i->data;
        i->data = menor->data;
        menor->data = aux;
    }
}

int main() {
    List *lista = createList();
    DataNode data;

    while (scanf("%s", data.name) != EOF) {
        push_front(lista, data);
    }

    insertionSort(lista);
    printList(lista, 0);

    return 0;
}
