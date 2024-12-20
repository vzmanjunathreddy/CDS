
 #include<stdio.h>
 #include<stdlib.h>

 struct Node {

    int data;
    struct Node *left;
    struct Node *right;
    
 };

// create a newNode

struct Node* createNode(int data){
  struct Node* newNode= (struct Node*)malloc(sizeof(struct  Node));
  newNode->data=data;
  newNode->left= newNode->right=NULL;
  return newNode;
}

struct Node* inserttheNode(struct Node *root, int data){

    if(root==NULL){
        return createNode(data);
    }
    if(data<root->data){

        root->left=inserttheNode(root->left,data);

    }else{
         root->right=inserttheNode(root->right,data);
    }
      return root;
}

//InOrder Traversal of Nodes {  Left, Root, Right }

// Pre order Traversal of Nodes { Root , Left,Rigt}

// Post Order Traversal of Nodes { Left, Right , Root}

   void inOrderTraversal(struct Node* root){
     if(root!=NULL){
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
     }

   }

    void PreOrderTraversal(struct Node* root){
     if(root!=NULL){
        printf("%d ", root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
     }

   }

       void PostOrderTraversal(struct Node* root){
        if(root!=NULL){        
            PostOrderTraversal(root->left);
            PostOrderTraversal(root->right);
             printf("%d ", root->data);
        }

   }



int main(){

    struct Node* root= NULL;

    int values[]={50, 70, 60, 20, 90, 10, 40, 100};
   
   int n =sizeof(values)/sizeof(values[0]);


   for(int i=0; i<n ;i++){
    root=inserttheNode(root,values[i]);
   }
   
   inOrderTraversal(root);
   printf("\n");
   PreOrderTraversal(root);
   printf("\n");
  PostOrderTraversal(root);

}