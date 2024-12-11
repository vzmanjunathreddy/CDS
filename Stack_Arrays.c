
 #include<stdio.h>
 #include<stdlib.h>

 struct Stack {

    int *arr;
    int  top ;
    int capcity;

 };

void CreateStack(struct Stack *stack,int capacity)
{
   stack->capcity=capacity;
   stack->top=-1;
   stack->arr=(int*)malloc(capacity*sizeof(int));
}

void IsStackEmpty(struct Stack *stack){

    if(stack->top==-1){
        printf("Stack is Empty \n");
    }
    else{
         printf("Stack is Not Empty \n");
    }
}

void IsStackisFull(struct Stack *stack){

    if(stack->top==stack->capcity-1){
        printf("Stack is Full \n");
    }
    else{
         printf("Stack is Not Full \n");
    }
}

void PushElementintoStack(struct Stack *stack,int data){

    if(stack->top!=stack->capcity-1){
        
      stack->arr[++stack->top]=data;

      printf("Pushed an element inside the stack is %d \n",data);
    }
}

void PopElementFromStack(struct Stack *stack){

    if(stack->top!=-1){
    
     printf("Poped an element inside the stack is %d \n",stack->arr[stack->top]);

      stack->arr[stack->top--];

    }
}

void PeekElementFromStack(struct Stack *stack){

    if(stack->top!=-1){
    
     printf("Element Peeked from Stack is %d \n",stack->arr[stack->top]);

    }
}


void displayStackElements(struct Stack *stack){

     if(stack->top!=-1){
    
        for(int i=stack->top; i>=0;i--)
        {
            printf("Elements of stack are  %d \n", stack->arr[i]);
        }
     }
     else{
        printf("Stack is Empty \n");
     }
}


int main(){

    struct Stack stack;
    int capacity=5;
    CreateStack(&stack,capacity);
    PushElementintoStack(&stack,10);
    PushElementintoStack(&stack,20);
    displayStackElements(&stack);
    PopElementFromStack(&stack);
    PopElementFromStack(&stack);
    PeekElementFromStack(&stack);
    displayStackElements(&stack);
    IsStackEmpty(&stack);
    IsStackisFull(&stack);


    
}
