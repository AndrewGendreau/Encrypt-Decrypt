#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 500

char* encrypt(char *key, char *words)
{
    int kLen = strlen(key);
    int wLen = strlen(words)-1;
    int i, j, pos;
    char* ciper=(char*)malloc(wLen*sizeof(char));
    printf("%d\n",wLen);
    for(i=0;i<wLen;i+=kLen)
    {
        for(j=0;j<kLen;j++)
        {
            pos=key[j]-'0'-1;
            if(pos+i<wLen)
            {
            ciper[i+j]=words[i+pos];
            printf("%c",ciper[i+j]);
            }
        }
    }
    return ciper;
}

int main()
{
    char key[10], str[SIZE];
    char *ciphertext;
    FILE *fp = fopen("//home//sruthi//Desktop//transpose.txt", "r");
    FILE *fp1 = fopen("//home//sruthi//Desktop//ciphertext.txt", "w");
    if(fp == NULL)
    {
        printf("File doesnt exist");
    }
    if(fgets(str, sizeof(str), fp)!=NULL)
    {
        printf("%s", str);

    printf("Enter the key:");
    gets(key);
     ciphertext=encrypt(key, str);
    fprintf(fp1, "%s", ciphertext);
    }
    fclose(fp);
    fclose(fp1);
    return 0;
}

