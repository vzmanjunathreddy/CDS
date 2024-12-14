 #include<stdio.h>
 #include<stdlib.h>

 #define MAX 10

struct CircularQueue{

    int arr[MAX];
    int rear;
    int front;
};

void initializetheQueue(struct CircularQueue *q){

     q->front=q->rear=-1;
}

int IsEmpty(struct CircularQueue *q)
{
    if(q->front==q->rear==-1){
        return 1;
    }
}

int IsFull(struct CircularQueue *q)
{
    if(q->front== (q->rear+1)%MAX ){
        return 1;
    }
}


void enqueue(struct CircularQueue *q,int data){

   if(q->front!= (q->rear+1)%MAX ){ // IsCQueuue is Full
    
  if( q->front==-1){ // IS CQueue is empty

     q->front=0;
     q->rear=0;
   }
   else{
    q->rear=(q->rear+1)%MAX; // Insertion
   }
    q->arr[q->rear]=data;
    }
}
 
 
void dequeue(struct CircularQueue *q){

  
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
        q->front=(q->front+1)%MAX;
    }
    
   }
}
    void displayQueue(struct CircularQueue *q){

    if(q->front==-1){
           printf("Queue is Empty \n");
    }
    else{

        for(int i=q->front;i<=(q->front+1)%MAX;i++){
            printf("%d \n",q->arr[i]);
        }
    }
 }
  int main(){

   struct CircularQueue q;
    initializetheQueue(&q);
    enqueue(&q,10);
    enqueue(&q,12);
    enqueue(&q,14);
    dequeue(&q);
    displayQueue(&q);
   
 }

  // printf("Vallue is inserted into the queue %d", data);




