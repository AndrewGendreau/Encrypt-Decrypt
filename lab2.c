#include <stdio.h>
#include <string.h>

shift_encryption();
transposition_encryption();
shift_decryption();
transposition_decryption();

void main()
{
int option;
printf("1) Shift Encryption \t 2) Transposition Encryption \t 3)Shift Decryption \t 4)Transposition Decryption");
printf("Enter The Option:");
scanf("%d", &option);
switch(option)
{
case 1://shift_encryption();
	printf("Shift Encryption");
	break;
case 2: //transposition_encryption();
	printf("Transposition Encryption");
	break;
case 3://shift_decryption();
	printf("Shift Decryption");
	break;
case 4://transposition_decryption();
        printf("Transposition Decryption");
        break;
case 5:exit();
}
}

shift_encryption()
{
int key;
char *c, dir, buff[500];
FILE *filename;
printf("Enter the key in the range of:");
scanf("%d", &key);
printf("Enter the direction of the key:(l/r)");
scanf("%c", &dir);
filename = fopen(plaintext.txt, "r");
if(filename==NULL)
{
	printf("File Not Found!!!");
	exit();
}
else
{
	c = fgets(buff, 500, filename);
{

}
fclose(filename);
encrypt_output();
}

shift_decryption()
{
char dir, buff1[500];
FILE *filename1 = fopen(ciphertext.txt, "r");
if(filename1==NULL)
{
	printf("File Not Found!!!");
	exit();
}
else
{
	c1 = fgets(buff, 500, filename1);
}
fclose(filename1);
decrypt_output();
}

