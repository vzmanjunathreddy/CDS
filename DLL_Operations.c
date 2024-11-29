#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
   struct Node *prev;
 
};

// create a newNode

struct Node* createNode(int data){
  struct Node* newNode= (struct Node*)malloc(sizeof(struct  Node));
  newNode->data=data;
  newNode->next=NULL;
  newNode->prev=NULL;
  return newNode;
}


void insertNodeatBegeninig(struct Node **head, int data){

    struct Node *newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
    }
    newNode->next=*head;
    (*head)->prev=newNode;
    *head=newNode; 
}

void insertNodeatEnd(struct Node **head, int data){

    struct Node *newNode=createNode(data);

    if(*head==NULL){
        *head=newNode;
         return;
    }
    struct Node* temp =*head;
    while (temp->next!=NULL)
    {
        temp= temp->next; 
    }
    
    temp->next=newNode;
    newNode->prev=temp;

}

void insertNodeatPostion(struct Node **head, int data,int position){

    struct Node *newNode=createNode(data);

    if(position==0){
        insertNodeatBegeninig(head,data);
        return;

    }
     
    struct Node* temp =*head;

    for(int i=0;temp!=NULL && i<position-1;i++){
         temp= temp->next;
    }

    newNode->next=temp->next;
    newNode->prev=temp;

    if(temp->next!=NULL){
        temp->next->prev=newNode;

    }

    temp->next=newNode;
   }

  void deleteatheBegening(struct Node **head)
   {
          if(*head==NULL){
            printf("List is empty");
            return;
          }
          struct Node *temp =*head;
          *head=temp->next;
          free(temp);
       
   }
   void deleteathEnd(struct Node **head)
   {
          if(*head==NULL){
            printf("List is empty");
            return;
          }

          struct Node *temp =*head;  

           //there is only one node
          if(temp->next==NULL){
            free(temp);// this guy is deleting memory address reffered by head
            // *head --> Dangling pointer --> a pointer whose memory address is already released 
             *head=NULL;// Null Pointer
          }
         
          while (temp->next->next!=NULL)
          {
            temp=temp->next;
          }
          
          free(temp->next);
          temp->next=NULL;
     
   }

   
      void deleteNodeatPosition(struct Node **head,int position)
     {
        if(*head==NULL){
            printf("List is empty");
            return;
          }

          struct Node *temp =*head;  

        if(position==0){
            deleteatheBegening(head);
        }

        for(int i=0;i<position-1 && temp!=NULL;i++){
           temp=temp->next;
        }
       
        if(temp->next==NULL || temp==NULL){
            printf("Position is out of range.. \n");
        }

        // to check if a node is existing in front 
        if(temp->next!=NULL){

            temp->next->prev=temp->prev;
        }

        // to check if node is existing behind

        if(temp->prev!=NULL)
        {
            temp->prev->next=temp->next;
        }

         free(temp);         
     
   }

        void ForwardTraversalofNodes(struct Node* head){

        struct Node *temp=head;

        while(temp!=NULL){
            printf("Node data is %d \n", temp->data);
            temp=temp->next;
        }
   
     }

     void BackwardTraversalofNodes(struct Node* head){

        struct Node *temp=head;

        if(temp==NULL){
          printf("List is empty");
        }

        while (temp->next!=NULL)
        {
            temp=temp->next;
        }

        while (temp!=NULL)
        {
        printf("Backward data is %d \n",temp->data);
        temp=temp->prev;
        }
        
     }

   int main(){

     struct Node *head=NULL;
     insertNodeatBegeninig(&head,10);
     insertNodeatEnd(&head,12);
     insertNodeatBegeninig(&head,5);
     insertNodeatPostion(&head,7,1);
     ForwardTraversalofNodes(head);
     BackwardTraversalofNodes(head);
     //deleteathEnd(&head);
     //printf("After deleting the end node traversed data is \n");
    // TraversetheNodes(head);
   }