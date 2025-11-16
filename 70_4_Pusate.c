// 4. Two Queues using single array
// Roll Number: 70

#include<stdio.h>
#define MAX 20
int q[MAX],front1=-1,front2=MAX,rear1=-1,r2=MAX;

void enQ1(int x){
    if(rear1+1==r2){
        printf("Queue overflow");
    }
    if(front1 == -1)
        front1 = 0;

    rear1++;
    q[rear1] = x;
}

void enQ2(int x){
    if(r2-1==rear1){
        printf("Queue overflow");
    }
    if(front2 == MAX)
        front2 = MAX-1;

    r2--;
    q[r2] = x;
}


void deQ1(){
    if(front1 == -1 || front1 > rear1){
        printf("Queue underflow");
    }
    else{
        
        front1++;
        if(front1 > rear1){
        front1 = rear1 = -1; 
    }
    
    }
}

void deQ2(){
    if(front2 == MAX || front2 < r2){
        printf("Queue underflow");
    }
    else{
        front2--;
        if(front2 < r2){
        front2 = r2 = MAX;
    }
    }
}

void disp1(){
    for(int i=front1;i<=rear1;i++){
        printf("%d ",q[i]);
    }
    printf("\n");
}

void disp2(){
    for(int i=front2;i>=r2;i--){
        printf("%d ",q[i]);
    }
    printf("\n");
}

int main(){
    int res;
do{
    printf("\n1.enQ1\n2.enQ2\n3.deQ1\n4.deQ2\n5.Display1\n6.Display2\n7.Exit\n");
    scanf("%d",&res);
    int value;
    switch (res)
    {
    case 1:
        printf("\nEnter value:");
        scanf("%d",&value);
        enQ1(value);
        break;
    case 2:
        printf("\nEnter value:");
        scanf("%d",&value);
        enQ2(value);
        break;    
    case 3:
        deQ1();
        break;
    case 4:
        deQ2();
        break;
    case 5:
        disp1();
        break;
    case 6:
        disp2();
        break;
    default:
        break;
    }
}while(res!=7);
return 0;
}