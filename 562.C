#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
struct node*prev;
int data;
struct node*next;
};
struct node*START;
void creation();
void insertion();
void deletion();
void display();
void searching();
void main()
{
int c,choice;
clrscr();
printf("\n--------*MENU*---------");
printf("\n enter:");
printf ("\n 1.insertion");
printf("\n 2.deletion");
printf("\n 3.display");
printf("\n4.searching");
printf("\n 5.exit");
creation();
while(c>3)
{
printf("\n ______________________");
printf("\n enter your choice from the above menu:");
scanf("%d",&choice);
switch(choice)
{
case 1:insertion();
break;
case 2:deletion();
break;
case 3:display();
break;
case 4:searching();
break;
case 5:exit(0);
break;
default:printf("\n invalid choice");
break;
}
c++;
}
getch();
}
void creation()
{
START=NULL;
}
void insertion ()
{
struct node*temp,*p,*q;
int info,pos,loc,i;
printf("\n enter the element to be inserted:");
scanf("%d",&info);
temp=(struct node*)malloc(1*sizeof(struct node));
temp->data=info;
if(START==NULL)
{
printf("\n the list is empty so the inserted element will becomes the first element");
temp->prev=NULL;
temp->next=NULL;
START=temp;
}
else
{
printf("\n enter 1/2/3 to insert element at begining/ending/specified postion:");
scanf("%d",&loc);
if(loc==1)
{
temp->prev=NULL;
temp->next=START;
START=temp;
printf("\n successfully %d inserted at ending postion",info);
}
else if(loc==2)
{
p=START;
while(p->next!=NULL)
{
p=p->next;
}
p->next=temp;
temp->prev=p;
temp->next=NULL;
printf("\n successfully %d inserted at ending position",info);
}
else if(loc==3)
{
printf("\n enter the position where to insert:");
scanf("%",&pos);
p=START;
q=START->next;
for(i=0;i<pos-2;i++)
{
p=p->next;
q=q->next;
}
p->next=temp;
q->prev=temp;
temp->prev=p;
temp->next=q;
printf("\n successfully %d inseeted at %d position",info,pos);
}
}
}
void deletion()
{
struct node*p,*q;
int pos,loc,i;
if(START==NULL)
printf("\n list is empty......");
else
{
if(START->next==NULL)
{
p=START	;
printf("\n %d is deleted from the list",p->data);
free(p);
START=NULL;
}
else
{
printf("\n enter 1/2/3/\ to deleted element from begining/ending/position:");
scanf("%d", &loc);
if(loc==1)
{
p=START;
START->next->prev=NULL;
START=START->next;
printf("\n %d is deleted from begining of the list",p->data);
free(p);
}
else if(loc==2)
{
p=START;
q=START->next;
while(q->next!=NULL)
{
p=p->next;
q=q->next;
}
p->next=NULL;
printf("\n %d is deleted from the ending of the list",q->data);
free(q);
}
else if(loc==3)
{
printf("\n enter the position from where to delete:");
scanf("%d",&pos);
p=START;
q=START->next;
for(i=0;i<pos-2;i++)
{
p=p->next;
q=q->next;
}
p->next=q->next;
q->next->prev=p;
printf("\n %d is deleted form the %d position",q->data,pos);
free(q);
}
}
}
}
void display()
{
struct node*p;
p= START;
if(START==NULL)
printf("\n list is empty.........");
else
{
printf("\n elements present in list are:\n");
while(p!=NULL)
{
printf("%d\t",p->data);
p=p->next;
}
}
}
void searching()
{
struct node*p;
int key,i=1,flag;
p=START;
printf("\n enter the element to be serched:");
scanf("%d",key);
if(START==NULL)
printf("\n list is empty......");
else
{
while(p!=NULL)
{
if(p->data==key)
{
flag=1;
break;
}
p=p->next;
i++;
}
}
if(flag==1)
printf("\n%d found at the position %d ",key,i);
else
printf("\n the element %d is not found in the list",key);
}

