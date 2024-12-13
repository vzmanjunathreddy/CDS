 #include<stdio.h>
 #include<stdlib.h>

 typedef struct Queue{

    int *arr;
    int rear;
    int front;
    int size;
}Queue;

void initializetheQueue(Queue *q,int size){

     q->arr=(int *)malloc(size *sizeof(int));
     q->front=q->rear=-1;
     q->size=size;
}

void isEmpty(Queue *q){
    if(q->front==-1){
        printf("Queue is Emepty \n");
    }
}

int isFull(Queue *q){

    if(q->rear==q->size-1){
        printf("queue is full");
        return -1;
    }
    else{
        return 0;
    }

}

void enqueue(Queue *q,int data){

    if(isFull(q))
      printf("Queue is full ");
   if( q->front==-1){
      q->front=0;
   }
   q->rear++;
   q->arr[q->rear]=data;

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
    int size;
    initializetheQueue(&q,10);
    enqueue(&q,10);
    enqueue(&q,12);
    enqueue(&q,14);
    dequeue(&q);
    displayQueue(&q);
   
 }
 



