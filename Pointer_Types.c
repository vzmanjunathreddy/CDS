#include<stdio.h>

 struct student{

 };

 void getStudentdata(int id ,int age){

 };



int main(){


    int var=10;
    char c='G';
    struct student std;
    
    //Declaration
    int *int_ptr;
    char *char_ptr;
    struct student* stuct_ptr;
    void (*func_ptr)(int,int)=&getStudentdata;
    void *ptr_voidNull=NULL;

    // Initialization
    int_ptr=&var;
    char_ptr=&c;
    stuct_ptr=&std;

   // Dereferencing the pointer --> accessing value stored in the memoy address
  // *ptr  will give you the value stored at the address

    printf("Size of the Integer pointer %d \n", sizeof(int_ptr));
    printf("Sizze of the Char pointer %d \n", sizeof(char_ptr));
    printf("Size of the Struct pointer %d \n", sizeof(stuct_ptr));
    printf("Size of the Null pointer %d", sizeof(ptr_voidNull));

}