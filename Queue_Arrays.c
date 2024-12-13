 #include<stdio.h>
 #include<stdlib.h>

 #define MAX 10

typedef struct Queue{

    int arr[MAX];
    int rear;
    int front;
}Queue;

void initializetheQueue(Queue *q){

     q->front=q->rear=-1;
}

void isEmpty(Queue *q){
    if(q->front==-1){
        printf("Queue is Emepty \n");
    }
}

void enqueue(Queue *q,int data){

   if(q->rear==MAX - 1){
      printf("Queue is full ");
   }
   if( q->front=-1){

     q->front=0;
   }
   q->rear++;
   q->arr[q->rear]=data;
  // printf("Vallue is inserted into the queue %d", data);

}

void dequeue(Queue *q){

  
   if( q->front==-1){

   printf("Queue is Empty \n");
   }
   else{
    int data= q->arr[q->front];
    printf("Removed data element from Queue is %d \n", data);
    if(q->rear==q->front){
        q->front=q->rear=-1;
    }
    else{
        q->front++;
    }
    
   }
}
 

 void displayQueue(Queue *q){

    if(q->front==-1){
           printf("Queue is Empty \n");
    }
    else{

        for(int i=q->front;i<=q->rear;i++){
            printf("%d \n",q->arr[i]);
        }
    }
 }

 int main(){

    Queue q;
    initializetheQueue(&q);
    enqueue(&q,10);
    enqueue(&q,12);
    enqueue(&q,14);
    dequeue(&q);
    displayQueue(&q);
   
 }
 



