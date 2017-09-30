#include "stdio.h"
#include "string.h"

struct students {
    char name[100];
    char phoneNumber[100];
    char birthday[100];
};

struct students student[100];

int InputName(int i) {
    FILE *MyFileName = fopen("students.txt","a+");
    if (MyFileName == NULL) {
        printf("Can't open file.\n");
        return -1;
    }
    int ValidName = 0;
    while (ValidName == 0) {
        printf("Input name of student.\n");
        fflush(stdin);
        fgets(student[i].name, 100, stdin);
        if(((strlen(student[i].name)-1) > 20) || ((strlen(student[i].name)-1) < 3)) {
            printf("Input name between 3 and 20 characters.\n");
        } else {
            ValidName = 1;
        }
    }
    fputs(student[i].name, MyFileName);
    fclose(MyFileName);
    printf("Successfully added student's name!\n");
}

void InputPhoneNumber(int i) {
    FILE *MyFilePhoneNumber = fopen("students.txt","a+");
    printf("Input phone number.\n");
    fgets(student[i].phoneNumber, 100, stdin);
    fflush(stdin);
    fputs(student[i].phoneNumber, MyFilePhoneNumber);
    fclose(MyFilePhoneNumber);
    printf("Successfully added student's phone number!\n");
}

void InputBirthday(int i) {
    FILE *MyFileBirthday = fopen("students.txt","a+");
    printf("Input birthday.\n");
    fgets(student[i].birthday, 100, stdin);
    fflush(stdin);
    fputs(student[i].birthday, MyFileBirthday);
    fclose(MyFileBirthday);
    printf("Successfully added student's birthday!\n");
}

void InputStudent(){
    int n;
    printf("Input no of students.\n");
    scanf(" %i", &n);
    fflush(stdin);
    for (int i = 0; i < n; ++i) {
        InputName(i);
        InputPhoneNumber(i);
        InputBirthday(i);
    }
}

void StudentList() {
    char bufferMyFile[100];
    FILE *MyFileRead = fopen("students.txt","r");
    while(fgets(bufferMyFile,100,MyFileRead)){
        printf("%s", bufferMyFile);
    }
    fclose(MyFileRead);
}

void Menu() {
    printf("\n\n----------Menu----------\n\n");
    printf("1. Input Students.\n");
    printf("2. View Student List.\n");
    printf("3. Exit.\n\n");
}

int main() {
    while (1) {
        Menu();
        printf("Enter choice.\n");
        int choice;
        scanf(" %d", &choice);
        switch (choice) {
            case 1 :
               InputStudent();
               break;
            case 2 :
                StudentList();
              break;
            case 3 :
                return 0;
            default:
                printf("Please enter a number on the menu.\n");
               break;
       }
    }
}
