#include<stdlib.h> 
#include<stdio.h> 
#include<string.h> 
#define max_size 5
#include "C:\Users\My PC\OneDrive\Desktop\3rd sem\dsa\lab code\heddesplay.h"
int stack[max_size],top = -1; 
void push(); 
void pop(); 
void display(); 

int main() 
{ 
int choice = 1; 
while(choice) 
{ 
printf("\n\n--------STACK OPERATIONS-----------\n"); 
printf("1.Push\n"); 
printf("2.Pop\n"); 
printf("3.Display\n"); 
printf("4.Exit\n"); 
printf("-----------------------"); 
printf("\nEnter your choice:\t"); 
scanf("%d",&choice); 
switch(choice) 
{ 
case 1: 
push(); 
break; 
case 2: 
pop(); 
break; 
case 3: 
display(); 
break; 
case 4: 
exit(0); 
break; 
default: 
printf("\nInvalid choice:\n"); 
break; 
} 
} 
return 0; 
} 
void push() //Inserting element into the stack 
{ 
int item,n; 
if(top==(max_size-1)) 
{ 
printf("\nStack Overflow:"); 
} 


else 
{ 
printf("Enter the element to be inserted:\t"); 
scanf("%d",&item); 
top=top+1; 
stack[top]=item; 
} 
} 
void pop() //deleting an element from the stack 
{ 
int item; 
if(top==-1) 
{ 
printf("Stack Underflow:"); 
} 
else 
{ 
item=stack[top]; 
top=top-1; 
printf("\nThe poped element: %d\t",item); 
} 
}