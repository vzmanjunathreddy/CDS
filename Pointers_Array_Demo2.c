#include<stdio.h>


int main(){

    int StudIds[3]={6,2,3};

    int *ptr=StudIds;

    for(int i=0;i<=2;i++){

      //  printf("Value inside ptr arris %d \n ",*ptr++);

       printf("Value inside ptr arris %d \n ",ptr[i]);
    }







}