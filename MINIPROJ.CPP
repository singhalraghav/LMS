#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>

char mypassword[10]={"admin"};
void password();
void mainmenu();
void addBook();
void showallBook();
void search();
void removeBook ();

//void  viewbooks();
//void editbooks();
typedef struct Book
{
char title[20];
char author[20];
int page;
int price;
}Book;
Book *book;
void main()
{
int size;
clrscr();
printf("enter total no. of book");
scanf("%d",&size);
book= (Book*) malloc(sizeof(Book)*size);
password();

getch();
}
void mainmenu()
{
clrscr();
int i;
gotoxy(20,3);
printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2 MAIN MENU \xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
gotoxy(20,5);
printf("\xDB\xDB\xDB\xDB\xb2 1. Add Books");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xb2 2.Show All Books");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xb2 3. Search books");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xb2 4. Remove Books");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xb2 5. Close Application");
gotoxy(20,15);
printf("\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2");
gotoxy(20,17);
printf("enter your choice");
switch(getch())
{
case '1':
addBook();
break;
case '2':
showallBook();
break;
case '3':
search();
break;
case '4':
removeBook();
break;
case '5':
clrscr();
gotoxy(16,3);
printf("\tlibrary management system");
gotoxy(16,4);
printf("\tmini project in c language");
gotoxy(16,5);
printf("\tdesigned and developed by");
gotoxy(16,7);
printf("\tMOHIT AND RAGHAV");
gotoxy(16,8);
printf("****************************************");
gotoxy(16,10);
printf("****************************************");
gotoxy(16,12);
printf("****************************************");
gotoxy(10,17);
printf("exiting in 10 seconds.....");
delay(10000);
exit(0);
break;
default:
gotoxy(20,23);
printf("\ainvalid choice. try again");
}
if(getch())
{
mainmenu();
}
}
void password()
{
clrscr();
char str[50]= "library management system";
 int i=0;
char ch,pwd[10];
int j;
gotoxy(10,4);
for(j=1;j<=10;j++)
{
delay(100);
printf("*");
}
for(j=0;j< strlen(str);j++)
{delay(100);
printf("%c",str[j]);
}
for(j=0;j<=10;j++)
{
delay(100);
printf("*");
}
gotoxy(15,7);
printf("enter password");
while(ch!=13)
{
ch=getch();
if(ch!=13&&ch!=8)
{
printf("*");
pwd[i] = ch;
i++;
}
}
pwd[i]='\0';
if(strcmp(pwd,mypassword)==0)
{
gotoxy(15,9) ;
printf("password match");
gotoxy(17,10) ;
printf("press any key to continue");
getch();
mainmenu();
}
else
{
gotoxy(15,16);
printf("\aincorrect password");
getch();
password();
}
}
 int count=1;
 int size;
void addBook()
{
system("cls");
printf("\n***** ADD NEW BOOKS DETAIL *****");
printf("\nENTER BOOK TITLE");
gets(book[count].title);
printf("\nENTER BOOK AUTHOR");
gets(book[count].author);
printf("\nENTER BOOK PRICE");
scanf("%d",&book[count].price);
printf("\nENTER BOOK PAGE");
scanf("%d",&book[count].page);
count++;
}
void showallBook()
{
int i;
system("cls");
printf("\n\n\t\t@@@@@@@@@@@ Book Details @@@@@@@@@@@@");
printf("\n\n\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-");
printf("\n\tBook Title\tBook Author\tBook Price\tBook Page");
printf("\n\t\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-");
for(i=1;i<count; i++)
{
printf("\n\t%s",book[i].title);
printf("\t%s",book[i].author);
printf("\t%d",book[i].price);
printf("\t\t%d",book[i].page);
}
}
void search()
{
char btitle[15];
int i;
printf("\nEnter Book Title to be Search : ");
gets(btitle);
for(i=1;i<count;i++)
{
if(strcmpi(book[i].title,btitle)==0)
{
system("cls");
printf("\n\n\t\t############Book Details#############");
printf("\n\n\tBook Title      :    %s",book[i].title);
printf("\nBook Author    :  %s",book[i].author);
printf("\nBook Price     :   %f",book[i].price);
printf("\n\tBook Page      :   %d\n",book[i].page);
}
}
}
void removeBook()
{
char btitle[10];
int i,j;
Book *temp;
printf("\nEnter Book Title to be Removed  :  ");
gets(btitle);
for(i=0;i<count;i++)
{
if(stricmp(book[i].title,btitle)==0)
{
system("cls");
printf("\n\n\t\t############Remove Book Detail############");
printf("\n\n\t\tBook Title   :   %s",book[i].title);
printf("\n\t\tBook Author    :  %s",book[i].author);
printf("\n\t\tBook Price     :  %f",book[i].price);
printf("\n\t\tBook Page      :  %d\n",book[i].page);
for(j=i;j<count-1;j++)
book=book+1;
count--;
return ;
}
}
}







