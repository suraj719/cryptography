/*This program is used to encrypt a text and decrypt the text based on user's choice*/

#include<stdio.h>
#include<string.h>

void salting(char text[],char salt[]);
void iterative(char salted[],char iterated3[]);
void encrypt(char iterated3[],char encrypted[]);
void decrypt(char encrypted[],char salt[]);

int main(void) {
    char text[100],salt[100]="hello",salted[300],iterated3[900],encrypted[900];
    int choice;
    printf("1. ENCRYPT A TEXT\n2. DECRYPT A TEXT\nENTER YOUR CHOICE: ");
    scanf("%d",&choice);
    if(choice==1) {
    	printf("Enter the text to encrypt: ");
    	scanf(" %[^\n]",text);
    	strcpy(salted,salt);
    	salting(text,salted);
    	salting(salt,salted);
    	iterative(salted,iterated3);
    	encrypt(iterated3,encrypted);
    	printf("\nENCRYPTED TEXT: %s\n",encrypted);
    }
    else if(choice==2) {
    	printf("Enter the encrypted text: ");
    	scanf("%s",encrypted);
        decrypt(encrypted,salt);
    }
    else {
    	printf("\ninvalid input\n");
    }
return 0;
}

void salting(char text[],char salt[]) {
    strcat(salt,text); //adding the salt to text(salt=salt+text)
}

void iterative(char salted[],char iterated3[]) {
    //iterating the salted text for three times
    char temp[600];
    strcpy(iterated3,salted);
    strcpy(temp,iterated3);
    strcat(iterated3,temp);
    strcat(iterated3,temp); 
}

void encrypt(char iterated3[],char encrypted[]) {
    //text encryption(inceasing the value by 1)
    int i;
    for(i=0;i<strlen(iterated3);i++) {
         encrypted[i]=iterated3[i]+1;
    }
    encrypted[i]='\0';
}

void decrypt(char encrypted[],char salt[]) {
    char decoded[600],decrypted[600];
    int i,j;
    for(i=0;i<strlen(encrypted);i++) { 
        //decrypting the iterated string(decreasing the value by 1)
        decoded[i]=encrypted[i]-1;
    }
    decoded[i]='\0';
    char tem[strlen(decoded)/3];
    for(j=0;j<(strlen(decoded)/3);j++) {
    	tem[j]=decoded[j];  //storing only the 1/3rd part of decrypted string in tem variable
    }
    tem[j]='\0';
    int k=0;
    for(int i=strlen(salt);i<(strlen(tem)-strlen(salt));i++) {
    	decrypted[k]=tem[i]; //fetching the main text which starts just after the salt and ends just before the salt
    	k++;
    }
    decrypted[k]='\0';
    printf("\nDECRYPTED TEXT: %s\n",decrypted);
}

//!!!HAPPY CODING!!!