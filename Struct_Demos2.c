// Struct is userdefined datatype used to group simillar items 
//Pointer to Stuct
// Normal struct variable can be accessed using dot operator 
// Struct pointer variables can be access using --> arrow operator

#include<stdio.h>
#include<string.h>

struct Person{

    int age;
    char name[10];

};
int main(){

struct Person p={10,"ShriShri"};
struct Person *sptr;

sptr=&p;

printf("Age of the Person is %d \n",sptr->age);
printf("Name of the Person is %s \n",sptr->name);

}



