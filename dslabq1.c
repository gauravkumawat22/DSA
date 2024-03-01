#include<stdio.h> 
#include<stdlib.h> 
int a[20]; 
int n,val,i,pos; 
/*Function Prototype*/ 
void create(); 
void display(); 
int main() 
{ 
    int choice=1; 
    while(choice) 
    { 
        printf("\n\n--------MENU-----------\n"); 
        printf("1.CREATE\n"); 
        printf("2.DISPLAY\n"); 
        printf("3.EXIT\n");
        printf("Enter Your Choice\n");
        scanf("%d",&choice);
        switch(choice) 
        { 
            case 1: 
                create(); 
                break; 
            case 2: 
                display(); 
                break; 
            case 3: 
                exit(0); 
                break;
            default: 
            printf("\nInvalid choice:\n"); 
        } 
    } 
return 0; 
} 

void create() 
{ 
    printf("\nEnter the size of the array elements:\t"); 
    scanf("%d",&n); 
    printf("\nEnter the elements for the array:\n"); 
    for(i=0;i<n;i++) 
    { 
        scanf("%d",&a[i]); 
    } 
} 
//displaying an array elements 
void display() 
{ 
    int i; 
    printf("\nThe array elements are:\n"); 
    for(i=0;i<n;i++) 
    { 
        printf("%d\t",a[i]); 
    } 
} 
