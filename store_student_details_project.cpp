#include <stdio.h>
#include <iostream>
#include <conio.h>
#include<stdlib.h>
#include<unistd.h>

// Declear student details structure 

struct student {
    int roll;
    char section[2];
    char firstName[20];
    char lastName[20];
    int Studentid;
};

struct student s;

//Declear function 

void addrecord();
void displayrecord();
void searchrecord();
void deleterecord();
void mainthing();

//Initialize addrecord function for add student details

void addrecord() {
    int ch;
    FILE* fp;
    fp = fopen("studenttt.txt", "ab+"); //Open and Create file 
    if (fp == NULL) {
        printf("File may not exist on your computer or there is an error opening the file.\n");
        return;
    }

    //Take input student details from user

    printf("Enter the roll of student: ");
    scanf("%d", &s.roll);

    printf("Enter the section of student: ");
    scanf("%s", s.section);

    printf("Enter the first name of student: ");
    scanf("%s", s.firstName);

    printf("Enter the last name of student: ");
    scanf("%s", s.lastName);

    printf("Enter the Studentid: ");
    scanf("%d", &s.Studentid);

    //Store the details in file and close file

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    void clrscr(void);
    printf("Record added.\n");

    //Give suggesation to user what do next 

    printf(".............................................................\n");
    printf("1. Add another record          \n");
    printf("2. Main         \n");

    printf("Enter the number of what to do: ");
    scanf("%d", &ch);

     switch (ch) {
    case 1:
        void clrscr(void);
        addrecord();
        getchar();
        break;
    default:
        void clrscr(void);
        printf("Exit successfully :)\n");
        printf("Thanks\n");
        getchar();
        break;
     }
     printf("< Press 'ENTER' to main >\n");
}

//Initialize displayrecord function for display the store student details

void displayrecord() {
    FILE* fp;
    fp = fopen("studenttt.txt", "rb"); //Open file for read the file
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    //Display the student details and close file

    printf(".......................................................................\n");
    printf("                       STUDENT DETAILS                         \n");
    printf("........................................................................\n");
    printf("ROll no \t Section \t Student Name \t\t  Studentid\n");

    while (fread(&s, sizeof(s), 1, fp) == 1) {
    printf("  %d\t\t  %s\t\t  %s %s \t\t\t%d\n", s.roll, s.section, s.firstName, s.lastName, s.Studentid);
    }

    fclose(fp); 

    printf(".............................................................\n");
    printf("< Press 'ENTER' to main >\n");
    getchar(); 
}

//Initialize searchrecord function for particular student details searching 

void searchrecord() {
    int id,ch;
     FILE* fp;
    fp = fopen("studenttt.txt", "rb"); //Open file for searching
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    //Input student id for searching details in store data file  

    printf("Enter student id for searching: ");
    scanf("%d",&id);

    //Display the search student details and close file

    printf(".......................................................................\n");
    printf("                       STUDENT DETAILS                         \n");
    printf("........................................................................\n");
    printf("ROll no \t Section \t Student Name \t\t  Studentid\n");

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (id==s.Studentid){
    printf("  %d\t\t  %s\t\t  %s %s \t\t   %d\n", s.roll, s.section, s.firstName, s.lastName, s.Studentid);
    }
    }
    

    fclose(fp);

    //Give suggesation to user what do next

    printf(".............................................................\n");
    printf("1. Search again          \n");
    printf("2. Main         \n");

    printf("Enter the number of what to do: ");
    scanf("%d", &ch);

     switch (ch) {
    case 1:
        void clrscr(void);
        searchrecord();
        getchar();
        break;
    default:
        void clrscr(void);
        printf("Exit successfully :)\n");
        printf("Thanks\n");
        getchar();
        break;
     }
    printf("< Press 'ENTER' to main >\n");

}

//Initialize deleterecord function for delete student stored details

void deleterecord() {
    int id,found = 0,ch;
     FILE* fp;
    fp = fopen("studenttt.txt", "ab+"); //Open the file 
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    //Take input student id from user to delete student details

    printf("Enter student id for searching: ");
    scanf("%d",&id);
    
    //Delete student details in stored file and close the file

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (id==s.Studentid){
            found = 1;
            continue;
    }

    fwrite(&s,sizeof(s),1,fp);
    
    }
    if (found){
        int newFileSize = ftell(fp)-sizeof(s);
        ftruncate(fileno(fp),newFileSize);
        printf(".............................................................\n");
        printf("Record delete successfully.\n");
        printf(".............................................................\n");
    }
    else
    {
        printf(".............................................................\n");
        printf("Record not found.\n");
        printf(".............................................................\n");
    }

    fclose(fp);

    //Give suggesation to user to what do next

    printf(".............................................................\n");
    printf("1. Delete Another Record          \n");
    printf("2. Main         \n");

    printf("Enter the number of what to do: ");
    scanf("%d", &ch);

     switch (ch) {
    case 1:
        void clrscr(void);
        deleterecord();
        getchar();
        break;
    default:
        void clrscr(void);
        printf("Exit successfully :)\n");
        printf("Thanks\n");
        getchar();
        break;
     }
    printf("< Press 'ENTER' to main >\n");

}

//Initialize mainthing function for display about the project and do in this 

void mainthing() {

    //Display the main menu interface for user what to do

    int ch;
    void clrscr(void);
    printf("\n");
    printf(".......................................\n");
    printf("         Student Record System         \n");
    printf(".......................................\n");
    printf("\n");

    printf("1. Add new student record         \n");
    printf("2. Display student record         \n");
    printf("3. Search student record          \n");
    printf("4. Delete student record          \n");
    printf("5. Exit record                    \n");
    printf("______________________________________\n");

    //Take input from user what user doing in this program

    printf("Enter the number of what to do: ");
    scanf("%d", &ch);

    //Execution the function what user give instruction

    switch (ch) {
    case 1:
        void clrscr(void);
        addrecord();
        getchar();

        //After executing this program back to the main menu

        mainthing();
        break;
    case 2:
        void clrscr(void);
        displayrecord();
        getchar();

        //After executing this program back to the main menu

        mainthing();
        break;
    case 3:
        void clrscr(void);
        searchrecord();
        getchar();

        //After executing this program back to the main menu

        mainthing();
        break;
    case 4:
        void clrscr(void);
        deleterecord();
        getchar();

        //After executing this program back to the main menu

        mainthing();
        break;

    default:

        //For exit the program

        printf("Exit successfully :)\n");
        printf("Thanks\n");
        getchar();
        break;
    }

}

int main() {

    //Calling the main menu program 

    mainthing();
    return 0;
}
