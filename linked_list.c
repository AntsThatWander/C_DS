#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int num;
    struct node* next;
}node;

typedef struct list{
    node* head;
    node* tail;
    int size;
}list;

list* initialize(){
    list* new_list = (list*)malloc(sizeof(list));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

int is_Empty(list* in_list){
    if(in_list->head == NULL||in_list->tail==NULL) return 1;
    return 0;
}

node* new_Node(int num){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->num = num;
    new_node->next = NULL;
    return new_node;
}

int headNum(list* in_list){
    return in_list->head->num;
}

int tailNum(list* in_list){
    return in_list->tail->num;
}

void addFirst(int num, list* in_list){
    node* new_node = new_Node(num);
    in_list->size++;
    if(is_Empty(in_list)) {
        in_list->head = new_node;
        in_list->tail = new_node;
        return;
    }
    node* tmp = in_list->head;
    in_list->head = new_node;
    new_node->next = tmp;
}

void addLast(int num, list* in_list){
    node* new_node = new_Node(num);
    in_list->size++;
    if(is_Empty(in_list)) {
        in_list->head = new_node;
        in_list->tail = new_node;
        return;
    }
    node* tmp = in_list->tail;
    in_list->tail = new_node;
    tmp->next = new_node;
}

void addNext(int num, list* in_list, node* in_node){
    if(in_node == NULL) return;
    node* new_node = new_Node(num);
    node* tmp = in_node->next;
    in_node->next = new_node;
    new_node->next = tmp;
    in_list->size++;
}

void removeFirst(list* in_list){
    if(is_Empty(in_list)) return;
    node* tmp = in_list->head;
    in_list->head = tmp->next;
    free(tmp);
}

void removeLast(int num, list* in_list){
    if(is_Empty(in_list)) return;
    node* cur = in_list->head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    in_list->tail = cur;
    free(cur->next);
}

void printData(list* in_list){
    node* cur = in_list->head;
    printf("생성된 연결 리스트: ");
    for(int i=1; cur != NULL; i++){
        printf("%d",cur->num);
        if(cur->next != NULL) printf("->");
        cur = cur->next;
    }
    printf("\n");
}

int main(){
    int cnt; 
    printf("노드의 개수 : ");
    scanf("%d",&cnt);
    list* my_list = initialize();
    for(int i=0; i<cnt; i++){
        int num;
        printf("노드 #%d 데이터 : ",i);
        scanf("%d",&num);
        addLast(num, my_list);
    }
    printData(my_list);

    free(my_list);

    return 0;
}