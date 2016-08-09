#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 500                                                    //declaring random size

char* encrypt(char *key, char *words)                               //encrypting the plaintext function
{
    int kLen = strlen(key);                                         //to get key length
    int wLen = strlen(words)-1;                                     //to get plaintext length
    int i, j, pos;
    char* ciper=(char*)malloc(wLen*sizeof(char));
    //printf("%d\n",wLen);
    for(i=0;i<wLen;i+=kLen)                                        //run through plaintext character and increase i by kLen
    {
        for(j=0;j<kLen;j++)                                        //run through key
        {
            pos=key[j]-'0'-1;                                  //set the position of the character of the plaintext 
            if(pos+i<wLen)
            {
            ciper[i+j]=words[i+pos];                           //store the character of the plaintext according to the key
            printf("%c",ciper[i+j]);                           //and it is done by i+pos
            }
        }
    }
    return ciper;                                               //returning ciphertext
}

int main()
{
    char key[10], str[SIZE];                                    //declaring variables
    char *ciphertext;
    FILE *fp = fopen("plaintext.txt", "r");                     //opening plaintext file to read the plaintext
    FILE *fp1 = fopen("ciphertext.txt", "w");                   //opening file to write ciphertext
    if(fp == NULL)
    {
        printf("File doesnt exist");                            //If file is not available give error message
    }
    if(fgets(str, sizeof(str), fp)!=NULL)                       //read and store the characters from plaintext file
    {
        //printf("%s", str);

    printf("Enter the key:");
    fgets(key, SIZE, stdin);                                    //read and store the key from console user
     ciphertext=encrypt(key, str);                              //calling encrypt function
    fprintf(fp1, "%s", ciphertext);                             //writing ciphertext to the output file
    }
    fclose(fp);
    fclose(fp1);                                                //closing both input and output files
    return 0;
}
