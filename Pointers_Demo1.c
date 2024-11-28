#include<stdio.h>


int main(){

    int var=10;
    //Declaration
    int *ptr;

    // Initialization
    ptr=&var;

   // Dereferencing the pointer --> accessing value stored in the memoy address
  // *ptr  will give you the value stored at the address

    printf("Value of Var is  %d \n", var);
    printf("Address of Var is  %p \n", &var);
    printf("Memory address referred by the pointer  %p \n", ptr);
    printf("Value stored the memory address referred by the pointer  %d \n", *ptr);

}