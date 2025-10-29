void encodingPart(char msg[]){
    int i; 
  
    strrev(msg); 
    
    for (i = 0; msg[i] != '\0'; i++) {
        msg[i] = msg[i] ^ (1 << 1);  // toggle 2nd bit (bit index 1)
        msg[i] = msg[i] ^ (1 << 4);  // toggle 5th bit (bit index 4)
    }


    return;
}
void decodingPart(char mes[]){
    for (int i=0 ; mes[i]!='\0'; i++){
        mes[i]=mes[i]^(1<<1);
        mes[i]=mes[i]^(1<<4);
    }
    strrev(mes);
    return ;
}
#include<stdio.h>
#include<string.h>
int main(){
     char msg[100];
     int choice;
     while(1){
        printf("-----DISPLAY MENU-------\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");

        printf("Enter your choice (1-3)");
        scanf("%d",&choice);

    printf("Enter your message: ");
    scanf(" %[^\n]",msg); 

    if (choice==1){
        encodingPart(msg);
        printf("\nEncoded message: %s\n", msg);
     }
     else if (choice==2){
        decodingPart(msg);
        printf("\n Decoded message: %s\n", msg);

     }
     else if (choice==3){
        printf(" you exit the program ");
        break;
     }
     else printf("Invalid choice ");


}
     return 0;
}