#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void mainMenu();
void create_user();
void login();

char globalUserId[10];
char globalPassword[8];


void login(){
    char userId1[10],password1[8];
    printf(".................................................\n");
    printf("\t\t\tLogin User \n");
    printf(".................................................\n");
repeater:
    printf("Enter user id: ");
    scanf("%s",userId1);
    printf("\nEnter your password: ");
    scanf("%s",password1);

    if (strcmp(globalUserId,userId1) == 0 && strcmp(globalPassword,password1) == 0){
        printf("Login successfully\n");
    } else {
        printf("Enter correct user id and password\n");
        goto repeater;
    }
    printf("Press enter to menu");
    fflush(stdin);
    getchar();
    printf("\n");
    mainMenu();
}

void reset_password(){
    char curpass[8];
    char newpass[8];
    printf(".................................................\n");
    printf("\t\t\tReset your password \n");
    printf(".................................................\n");
repeater:
    printf("Enter your current password: ");
    scanf("%s",curpass);

    if (strcmp(globalPassword,curpass)==0){
        printf("Enter your New Password: ");
        scanf("%s",newpass);
        strcpy(globalPassword,newpass);
    } else{
        printf("Current password is wrong!\n");
        goto repeater;
    }
    printf("Password reset successfully. \n");
    printf("Press enter to menu ");
    fflush(stdin);
    getchar();
    printf("\n");
    mainMenu();
}

void create_user(){
    char userId[10];
    char password[8];
    printf(".................................................\n");
    printf("\t\t\tCreate User \n");
    printf(".................................................\n");

    printf("Enter your User id: ");
    scanf("%s",userId);
repeater:
    printf("Enter your 8 character password: ");
    scanf("%s",password);
    for (int i=0; i<=strlen(password); i++){
        if (password[8] != '\0'){
            printf("Input 8 character\n");
            goto repeater;
        }
    }
    printf("User id and password create successfully\n");
    strcpy(globalUserId,userId);
    strcpy(globalPassword,password);
    printf("\n Press enter to main menu");
    fflush(stdin);
    getchar();
    printf("\n");
    mainMenu();
}


void mainMenu(){
    int cho;
    printf("1.  Create User id and password\n");
    printf("2.  Login\n");
    printf("3.  Reset Password\n");
    printf("Enter your choice: ");
    scanf("%d",&cho);

    switch (cho)
    {
    case 1:
        create_user();
        break;
    case 2:
        login();
        break;

    case 3:
        reset_password();
        break;

    default:
        printf("Exit Successfully.\n");
        printf("Thank You!");

        break;
    }
}

int main()
{
    mainMenu();

    return 0;
}