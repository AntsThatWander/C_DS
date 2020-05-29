#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    struct node* prev;
    struct node* next;
    int info;
}node;

typedef struct list{
    node* header;
    node* trailer;
    int size;
}list;

node* new_node(int info_){
    node* Nnode = (node*)malloc(sizeof(node));
    Nnode -> prev = NULL;
    Nnode -> next = NULL;
    Nnode -> info = info_;
}

list* initialize(){
    list* new_list= (list*)malloc(sizeof(list));
    new_list -> header = new_node(NULL);
    new_list -> trailer = new_node(NULL);
    new_list -> size = 0;
    new_list -> header -> next = new_list -> trailer;
    new_list -> trailer -> prev = new_list -> header;
    return new_list;
}

int is_Empty(list* in_list){
    if(in_list->header == NULL || in_list->trailer == NULL) return 1;
    return 0;
}

int HeaderInfo(list* in_list){
    if(is_Empty(in_list)) return NULL;
    return in_list->header->next->info;
}

int TrailerInfo(list* in_list){
    if(is_Empty(in_list)) return NULL;
    return in_list->trailer->prev->info;
}

void addLast(list* in_list, int ininfo){
    node* Nnode = new_node(ininfo);
    if(is_Empty(in_list)){
        in_list->header->next = Nnode;
        in_list->trailer->prev = Nnode;
        Nnode->next = in_list->trailer;
        Nnode->prev = in_list->header;
        in_list->size++;
    }
    Nnode->next = in_list->trailer;
    Nnode->prev = in_list->trailer->prev;
    in_list->trailer->prev->next = Nnode;
    in_list->trailer->prev = Nnode;
}

void reversePrint(list* in_list){
    node* cur = in_list->trailer->prev;
    printf("Printing the data in reverse: ");
    while(cur->prev != NULL){
        printf("%d ",cur->info);
        cur = cur->prev;
    }
}

int main(){
    int N;
    list* my_list = initialize();
    printf("Enter the number of data inputs : ");
    scanf("%d",&N);
    printf("\n");
    for(int i=0; i<N; i++){
        int M;
        printf("Enter the data of Node #%d: ",i+1);
        scanf("%d",&M);
        addLast(my_list, M);
    }
    printf("\n");
    reversePrint(my_list);
    return 0;
}
