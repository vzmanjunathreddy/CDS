 #include<stdio.h>
 #include<stdlib.h>

struct Node {

    int data;
    struct Node *next;
    
 };

struct Queue{

    struct Node *front, *rear;
};

//Initialize
//Memory Allocation
//Assign data 
//Link the nodes

//enqueue -->to add an elements inside the queue
//dequeue --> to remove an element from the Queue

struct Node* CreateNode (int data){
 struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
 newnode->data=data;
 newnode->next=NULL;
 return newnode;
}

struct Queue* CreateQueue(){

 struct Queue* q =(struct Queue*)malloc(sizeof(struct Queue));
 q->front=q->rear=NULL;

}

int isEmpty(struct Queue *q){

    if(q->front==NULL) return 1;
}

void enqueue(struct Queue *q, int data){

    struct Node *newNode=CreateNode(data);

    if(q->front==NULL && q->rear==NULL)
    {
        q->front=q->rear=newNode;
    }
    
     q->rear->next=newNode;
     q->rear=newNode;

}

void dequeue(struct Queue *q){

    if(q->front!=NULL){

    struct  Node *temp =q->front;
    int data= temp->data;
    q->front=q->front->next;  

    if(q->front==NULL){
        q->rear=NULL;
    }
    free(temp);
    printf("Element dequeued is %d \n",data);
    }
    

}

 void displaythedata(struct Queue *q){

  struct Node *temp =q->front;

  while(temp){

    printf("Queue data is %d \n",temp->data);
    temp=temp->next;
  }
 }

  int main(){

    struct Queue *q= CreateQueue();
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    displaythedata(q);
    dequeue(q);
    displaythedata(q);
  }

 