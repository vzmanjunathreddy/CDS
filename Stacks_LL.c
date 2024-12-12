
 #include<stdio.h>
 #include<stdlib.h>

 struct Node {
    int data;
   struct  Node *next;
 };


struct Stack{
    struct  Node* top;  // pointer to top of the node
};

void initializeStack(struct Stack* stack)
{
    stack->top=NULL;
};

int isEmtpty(struct Stack* stack){
    return stack->top==NULL ; // return 1 if stack->top ==NULL else -1
}
void push(struct Stack * stack ,int data)
{
   struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
   newNode->data=data;
   newNode->next=stack->top;
   stack->top=newNode;
   printf("Pushed an element inside the stack %d \n", data);
};

void pop(struct Stack * stack )
{
    if(stack->top!=NULL){
 
      struct  Node *temp= stack->top;
      stack->top= stack->top->next;
      int data=temp->data;
      free(temp);
      printf("Poped data is %d \n",data);
    }
    else{
        printf ('Stack is underflow there are no elements');
    }
};

 void TraversetheLinkedList(struct Stack * stack ){

    if(stack->top==NULL){
        printf('Stack  is Empty \n');
    }
    else{

        struct Node* temp= stack->top;

           while (temp!=NULL)
           {
             printf("Node data is %d \n",temp->data);
             temp=temp->next;
           }
    }
 }

int main(){

    struct Stack stack;
    initializeStack(&stack);
    push(&stack,25);
    push(&stack,35);
    push(&stack,45);
    push(&stack,55);
    TraversetheLinkedList(&stack);
    int isempty= isEmtpty(&stack);
    if(isempty==0){
        printf("Stack is not empty \n");
    }
    else{
          printf("Stack is empty \n");
    }
     pop(&stack);

    int isempty1= isEmtpty(&stack);
    if(isempty1==0){
        printf("Stack is not empty \n");
    }
    else{
          printf("Stack is empty \n");
    }
 
}
