#include <stdio.h>
#include <stdlib.h>

//백준 1991번
typedef struct node{ //a node of tree
    struct node* left; 
    struct node* right;
    char myname; //node's character
}node;

node* TreeArr[27]; // 거지 같은 백준 입력 순서 때문에 넣었습니다.

node* add_node(char myname){ // return a node with char tagging
    node* Nnode = (node*)malloc(sizeof(node));
    Nnode->left = NULL;
    Nnode->right = NULL;
    Nnode->myname = myname;
    return Nnode;
}

void add(){//computing each statement
    char current; //char for current node
    char left; //char for left node
    char right; //char for right node
    scanf("%c %c %c",&current,&left,&right); //input
    getchar(); //거지 같은 버퍼 ^^
    node* mynode; 
    if(current == 'A') { //root, for the first time.
        mynode = add_node(current);
        TreeArr[current-'A'] = mynode;
    }
    else //other node, for the rest of time.
        mynode = TreeArr[current-'A'];
    //if it have children, add it!
    if(left != '.') {
        mynode->left = add_node(left);
        TreeArr[left-'A'] = mynode->left; 
    }
    
    if(right != '.') {
        mynode->right = add_node(right);
        TreeArr[right-'A'] = mynode->right;
    }
}

void preorder(node* root){
    printf("%c",root->myname);
    if(root->left != NULL)
        preorder(root->left);
    if(root->right != NULL)
        preorder(root->right);
}

void inorder(node* root){
    if(root->left != NULL)
        inorder(root->left);
    printf("%c",root->myname);
    if(root->right != NULL)
        inorder(root->right);
}

void postorder(node* root){
    if(root->left != NULL)
        postorder(root->left);
    if(root->right != NULL)
        postorder(root->right);
    printf("%c",root->myname);
}

int main(){
    int TC; scanf("%d",&TC);//actually, the number of nodes.
    getchar();//진짜 vscode는 버퍼 처리도 못하는 레전드다.
    while(TC--){
        add();//giving statements.
    }
    preorder(TreeArr[0]);
    printf("\n");
    inorder(TreeArr[0]);
    printf("\n");
    postorder(TreeArr[0]);
    printf("\n");
}



