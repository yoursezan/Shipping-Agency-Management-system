//Arafath Islam Sezan
//dept.CSE-213

// Shipping Agency Management system
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<conio.h>
struct Product
{
long int reg;
char
Batch_number[200],company_name[50],imported_country[200],pro_name[150];
int quantity_order,quantity_sup;
struct Product *next;
}* head;
void imported_countryed(long int reg, char* Batch_number, char*
company_name, char* imported_country, char* pro_name, int quantity_order,int
quantity_sup)
{
struct Product *Product=(struct Product *)malloc(sizeof(struct Product));
Product -> reg=reg;
strcpy(Product->Batch_number, Batch_number);
strcpy(Product-> company_name, company_name);
strcpy(Product->pro_name,pro_name);
Product-> quantity_order= quantity_order;
Product-> quantity_sup = quantity_sup;
Product-> next=NULL;
if(head==NULL)
{
head= Product;
}
else
{
struct Product* temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp-> next=Product;

}
printf("\n\n \t\tProduct Added Successfully IN The List at Registration No. %ld \n",reg);
}
int total_item(struct Product*temp)
{
int count=0;
struct Product*current=head;
while (current!=NULL)
{
count++;
current= current->next;
}
return count;
}
void display()
{
int count;
struct Product *temp=head;
if(temp==NULL)
{
printf("\n\n Information Of Registration No. List is Empty!!!\n");
}
else
{
printf("\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-Products Information List*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
printf("\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
while (temp!=NULL)
{
printf("\n\t\tEnter Product registration Number :%ld\n",temp->reg);

printf("\t\tEnter Product Batch Number :%s\n",temp->Batch_number);
printf("\t\tEnter Company Name :%s\n",temp->company_name);
printf("\t\tEnter Product Import Country Name:%s\n",temp->imported_country);
printf("\t\tProduct Name:%s\n",temp->pro_name);
printf("\t\tQuantity of Product (order) :%d\n",temp->quantity_order);
printf("\t\tQuantity of product (supplied) : %d\n",temp->quantity_sup);
temp = temp->next;
}
printf("\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
printf("\n\t\t\tTotal Registered Information of Product in the list is : %d",
total_item(head));
}
}
void search(long int reg)
{
struct Product* temp=head;
if (head==NULL)
{
printf("\n\n Information of Registration No. List is Empty !!!\n");
}
else
{
while(temp!=NULL)
{
if(temp!=NULL)
{
printf("\n\t\t\tInformation of Registration No. %ld Is Found !!!\n", reg);

printf("\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");

printf("\t\t\t Searching Product Information List");
printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");

printf("\n\t\t\tEnter Product registration Number :%ld\n",temp->reg);
printf("\t\t\tEnter Product Batch Number :%s\n",temp->Batch_number);
printf("\t\t\tEnter Company Name :%s\n",temp->company_name);
printf("\t\t\tEnter Product Import Country Name:%s\n",temp->imported_country);

printf("\t\t\tProduct Name :%s\n",temp->pro_name);
printf("\t\t\tQuantity of Product (order) :%d\n",temp->quantity_order);
printf("\t\t\tQuantity of Product (supplied): %d\n",temp->quantity_sup);
return;
}
temp=temp->next;
}
}
printf("\n\n Not Found the Product with %ld reg No. In the Information List!!!\n",reg);
}
void Delete(long int reg)
{
struct Product *temp1=head;
struct Product *temp2=head;
while(temp1!=NULL)
{
if(temp1->reg==reg)

{
printf("\n\t\t\tInformation of Registration No. %ld Is Found !!!\n", reg);
if(temp1==temp2)
{
head=head->next;
free(temp1);
}
else
{
temp2->next=temp1->next;
free(temp1);
}
printf("\n\t\t\tDeleting of the Registration No. Product Information Successfully !!!!\n");
return;
}
temp2=temp1;
temp1=temp1->next;
}
printf("\n\n\t\t\tNot Found the Product with %ld Reg No. In The Information List !!!!!\n",reg);
}
void update(long int reg)
{
struct Product * temp = head;
while(temp!=NULL)
{
if(temp->reg==reg)
{
printf("\n\t\t\tInformation of Registration No. %ld Is Found !!!\n\n\n", reg);
printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-Update Product-*-*-*-*-*-*-*-*-*-*-*");

printf("\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
printf("\n\t\t\tUpdate Product Registration Number :");
scanf("%ld",&temp->reg);
printf("\n\t\t\tUpdate Products Batch Number :");
fflush(stdin);
gets(temp->Batch_number);
printf("\n\t\t\tUpdate Company Name :");
fflush(stdin);
gets(temp->company_name);
printf("\n\t\t\tUpdate Product imported country Name :");
fflush(stdin);
gets(temp->imported_country);
fflush(stdin);
printf("\n\t\t\tUpdate Product Name :");
fflush(stdin);
gets(temp->pro_name);
printf("\n\t\t\tUpdate Quantity of Product (order) :");
fflush(stdin);
scanf("%d",&temp->quantity_order);
printf("\n\t\t\tUpdate Quantity of Product (Supplied) : ");
scanf("%d",&temp->quantity_sup);
printf("\n\n\t\t\tInformation of this Registration No. %ld Update Successfully In The List !!!\n",temp->reg);
return;
}
temp = temp->next;
}
printf("\n\n\t\t\tNot Found the Product with %ld Reg No. In The Information List !!!!!\n",reg);
}
int main()

{
head = NULL;
int choice,temp,quantity_order,quantity_sup;
long int reg;
char
Batch_number[250],company_name[250],imported_country[250],pro_name[150];
system("cls");
while(1)
{
system("cls");
printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
printf("\n\t\t\t ** Arafath Sezan Shipping Agency **");
printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
printf("\t\t\t ** 'Employ only' ** ");
printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
printf("\n\n\t\t\t1.Load Products on ship:");
printf("\n\n\t\t\t2.Display Loaded Products on ship In List:");
printf("\n\n\t\t\t3.Search A Product on Ship:");
printf("\n\n\t\t\t4.Delete Product Which are Already Delivered:");
printf("\n\n\t\t\t5.Updating A Product Information on ship:");
printf("\n\n\t\t\t6.Exit (If Employ done His/her Part):");
printf("\n\n\t\t\t*Select A Option From Here: ");
scanf("%d",&choice);
switch (choice)
{

case 1:
system("cls");
printf("\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-Enter New Product Information*-*-*-*-*-*-*-*-*-*-*-*-");
printf("\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
printf("\n\t\t\tEnter Product Registration Number :");
scanf("%ld",&reg);
printf("\n\t\t\tEnter Product Batch Number :");
fflush(stdin);
gets(Batch_number);
printf("\n\t\t\tEnter Company Name :");
fflush(stdin);
gets(company_name);
printf("\n\t\t\tEnter Product Import Country Name:");
fflush(stdin);
gets(imported_country);
printf("\n\t\t\tProduct Name :");
fflush(stdin);
gets(pro_name);
printf("\n\t\t\tQuantity of product (order) :");
fflush(stdin);
scanf("%d",&quantity_order);
printf("\n\t\t\tQuantity of product (Supplied) : ");
fflush(stdin);
scanf("%d",&quantity_sup);
imported_countryed(reg, Batch_number, company_name,
imported_country, pro_name, quantity_order, quantity_sup);
break;
case 2:
system("cls");
display();

break;
case 3:
system("cls");
display();
printf("\n\n\t\t\tTo Search Enter The Product Registration No. :");
scanf("%ld",&reg);
system("cls");
search(reg);
break;
case 4:
system("cls");
display();
printf("\n\n\t\t\tTo Delete Enter The Product Registration No. :");
scanf("%ld",&reg);
system("cls");
Delete(reg);
break;
case 5:
system("cls");
display();
printf("\n\n\t\t\tTo Update Enter The Product Registration No. :");
scanf("%ld",&reg);
system("cls");
update(reg);
break;
case 6:
exit(1);
default :
system("cls");
printf("\n\t\t\tInvalid Option!!!Choice Right Option!!");
}
printf("\n\n\t\t\tContinue to Again!!!");
getch();

}
}
