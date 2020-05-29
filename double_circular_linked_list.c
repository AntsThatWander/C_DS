#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Need to Edit.
typedef struct node{//doubly linked node
    struct node* prev;
    struct node* next;
    char pic; 
}node;

typedef struct list{//doubly circular linked list
    node* tail; 
    char* input_string; //first string
}list;

void add(list* in_list, char pic); //Because of the sequence of function...

node* newNode(char pic){//return new node. == private method!
    node* newN = (node*)malloc(sizeof(node));
    newN -> prev = NULL;
    newN -> next = NULL;
    newN -> pic = pic;
    return newN;
}

void String2Node(list* in_list, char in_string[]){//first input to node
    const int length = strlen(in_string);
    node* cur = in_list->tail;
    for(int i=0; i<length; i++){
        printf("%c",in_string[i]);
        add(in_list, in_string[i]);
    }
}

list* initialize(char* in_string){//return complete list
    list* newL = (list*)malloc(sizeof(list));
    newL -> tail = NULL;
    newL -> input_string = in_string;
    String2Node(newL, in_string);
    return newL;
}

int isEmpty(list* in_list){//return integer because of absence of boolean in C.
    if(in_list->tail == NULL) return 1;
    return 0;
}

void add(list* in_list, char pic){//add a new node to the list behind of tail node. 
    node* newN = newNode(pic);
    if(isEmpty(in_list)) {
        in_list->tail = newN;
        in_list->tail -> next = in_list->tail;
        return;
    }
    newN -> prev = in_list->tail;
    newN -> next = in_list->tail->next;
    in_list->tail->next->prev = newN;
    in_list->tail->next = newN;
    in_list->tail = in_list->tail->next;
}

char* Node2String(list* in_list){//list to string. 
    const int length = strlen(in_list->input_string);
    char* String = (char*)malloc(length);
    node* cur = in_list->tail->next;
    for(int i=0; i<length; i++){
        *(String + i) = cur->pic;
        cur = cur->next;
    }
    *(String + length) = '\0';
    return String;
}

void rotateLeft(list* in_list){
    in_list -> tail = in_list->tail->prev;
}

void rotateRight(list* in_list){
    in_list -> tail = in_list->tail->next;
}

int main(){
    printf("Enter the number of Test Case : ");
    int TC; scanf("%d",&TC);
    for(int i=0; i<TC; i++){ //50
        printf("Enter the number of States : ");
        int state; scanf("%d",&state);
        printf("Enter the string : ");
        char cur_string[10001]; scanf("%s",cur_string);
        list* new_list = initialize(cur_string); //10000
        int cnt = 0, limit = 1;//cnt : least case, limit : for wrong string.
        for(int j=0; j<state; j++){ //100
            printf("Enter the desired form of string : ");
            char add_string[10001]; 
            scanf("%s",add_string);
            while(strcmp(add_string,Node2String(new_list))!=0){ //10000 X 10000
                if(limit>strlen(cur_string)){//To prevent infinite loop
                    printf("Too many loop\n");
                    break;
                }
                if(j%0 == 0) rotateRight(new_list); 
                else rotateLeft(new_list);
                printf("cur : %s\n",Node2String(new_list));
                cnt++;
                limit++;
            }
             
            limit=1;
        }
        printf("%d\n",cnt);
    }
}


