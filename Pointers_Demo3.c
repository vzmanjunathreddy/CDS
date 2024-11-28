#include<stdio.h>

void swapNumbers(int *num1, int *num2);
void  swaptwoNumbers(int number1,int number2);
int main(){

    int number1=10, number2=20;

    // number1 is stored in one memory address =10
   // swapNumbers(&number1,&number2);
  
    swaptwoNumbers(number1,number2);
    printf("Number1 value is %d \n",number1);
    printf("Number2 value is %d \n",number2);

    }

void swapNumbers(int *num1, int *num2){

//we are changing vales in the address 
    int temp;
    temp =*num1;
    *num1=*num2;
    *num2=temp;

}

void swaptwoNumbers(int num1, int num2){

// change num1=20 and change num2=10

    int temp;
    temp =num1;
    num1=num2;
    num2=temp;


}

