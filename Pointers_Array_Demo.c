#include<stdio.h>


int main(){

    int StudIds[3]={1,2,3};

    //Declaration
    int *ptr;
    // Initialization
    ptr=&StudIds[1];

   // Dereferencing the pointer --> accessing value stored in the memoy address
  // *ptr  will give you the value stored at the address

     printf("Value of Var is  %d \n", ptr[0]);
    printf("Value of Var is  %d \n", ptr[1]);
    printf("Value of Var is  %d \n", ptr[2]);
    printf("Value stored the memory address referred by the pointer  %d \n", StudIds[2]);
    printf("Address of Var is  %p \n", ptr);
    printf("Memory address referred by the pointer  %p \n", StudIds);
    printf("Value stored the memory address referred by the pointer  %d \n", StudIds[1]);

}