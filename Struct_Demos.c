// Struct is userdefined datatype used to group simillar items 

#include<stdio.h>
#include<string.h>

struct Person{

    int age;
    char name[10];

};
int main(){

struct Person p={10,"ShriShri"};
printf("Age of the Person is %d \n",p.age);
printf("Name of the Person is %s \n",p.name);

}



