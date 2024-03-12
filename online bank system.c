// project  online banking system
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user{
  char phone[50];
  char ac[50];
  char password[50];
  float balance;
};

int main(){
    int choice;
    struct user usr,usr1;
    FILE *fp;
    char filename[50],phone[50],pword[50];
    int opt;
    char cont ='y';
    float amount;

    printf("\nWhat do you want to do?");
    printf("\n\n1. Register an account");
    printf("\n2. Login to an account");

    printf("\n\n Your choice:\t");
    scanf("%d",&opt);

    if(opt==1){
       //system("clear");
       printf("Enter your Account no:\t");
       scanf("%s",usr.ac);
       printf("\nEnter your phone number:\t");
       scanf("%s",usr.phone);
       printf("\nEnter your password:\t");
       scanf("%s",usr.password);
       usr.balance = 0;
       strcpy(filename,usr.phone);
       fp=fopen(strcat(filename,".dat"),"w");
       fwrite(&usr,sizeof(struct user),1,fp);
       if(fwrite != 0){
        printf("\n\nAccount succesfully registered..");
       }
       else {
        printf("\n\nSomething went wrong please try again!");
       }
       fclose(fp);
    }
    if(opt==2){
           // system("clear");
            printf("\nphone number:\t");
            scanf("%s",phone);
            printf("password:\t");
            scanf("%s",pword);
            strcpy(filename,phone);
            fp= fopen(strcat(filename,".dat"),"r");
            if(fp==NULL){
                printf("\nAccount number not registered");
            }
            else{
            fread(&usr,sizeof(struct user),1,fp);
            fclose(fp);
            if(!strcmp(pword,usr.password)){
                while(cont == 'y'){
                   // system("clear");
                    printf("\nPress 1 to check balance");
                    printf("\nPress 2 to deposit an account");
                    printf("\nPress 3 to withdraw");
                    printf("\nPress 4 to transfer the balance");
                    printf("\nPress 5 to change the password");
                    printf("\n\n Your choice:\t");
                    scanf("%d",&choice);

                    switch(choice){
                      case 1:
                          printf("\nYour current balance is Rs.%0.2f",usr.balance);
                          break;
                      case 2:
                        printf("\nEnter the amount:\t");
                        scanf("%f",&amount);
                         usr.balance += amount;
                         fp =fopen(filename,"w");
                         fwrite(&usr,sizeof(struct user),1,fp);
                         if(fwrite != NULL) printf("\nSuccessfully deposited.");
                         fclose(fp);
                         break;
                      case 3:
                        printf("\nEnter the amount:\t");
                        scanf("%f",&amount);
                         usr.balance -= amount;
                         fp =fopen(filename,"w");
                         fwrite(&usr,sizeof(struct user),1,fp);
                         if(fwrite != NULL){
                            printf("\nYou have withdrawn Rs.%0.2f",amount);
                         fclose(fp);}
                         break;
                      case 4 :
                        printf("\nplease enter the phone number to transfer the balance:\t");
                        scanf("%s",phone);
                        printf("\nPlease enter the amount to transfer:\t");
                        scanf("%f",&amount);
                        strcpy(filename,phone);
                        fp= fopen(strcat(filename,".dat"),"w");
                        if(fp==NULL) printf("\n Account Number is not registered");
                        else {
                            fread(&usr1,sizeof(struct user),1,fp);
                        fclose(fp);
                        if(amount> usr.balance){
                            printf("\nInsufficient Balance");}
                        else{


                            fp=fopen(filename,"w");
                            usr1.balance += amount;
                            fwrite(&usr1,sizeof(struct user),1,fp);
                            fclose(fp);
                            if(fwrite != NULL){
                                printf("\nyou have successfully Transfer Rs.%0.2f to %s",amount,phone);
                                strcpy(filename,usr.phone);
                                fp =fopen(strcat(filename,".dat"),"w");
                                usr.balance -= amount;
                                fwrite(&usr,sizeof(struct user),1,fp);
                                fclose(fp);
                                break;


                        }

                    }

                     case 5:

                         printf("\nPlease enter your new password:\t");
                        scanf("%s",pword);
                        fp = fopen(filename,"w");
                        strcpy(usr.password,pword);
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL)
                        printf("\nPassword succesfully changed");
                        }
                      break;
                   default:
                    printf("\nInvalid option");

                     }






                    printf("\n Do you want to continue the transaction [y/n]\t");
                    scanf("%s",&cont);
                }
            }
            else {
                printf("\nInvalid password");
            }
    }
    }
       return 0;
       }




