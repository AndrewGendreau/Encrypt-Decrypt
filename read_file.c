#include<stdio.h>
#include<string.h>
#define SIZE 500


int main()
{

   FILE *fp;
   //char text[SIZE];
   char ch;
   fp = fopen("text","r");
   ch=fgetc(fp);
   while(ch!=EOF)
   {
   // encrption(ch);
    printf("%c",ch);
          
 ch=fgetc(fp);
   }
   fclose(fp);
}

