#include<stdio.h>
#include<string.h>

typedef struct {
    char username[30];
    char password[30];
}User;
User usr[20];

/*void menu() {
    printf("\n___Welcome_to_userFile_System___\n");
    int choice;
    int i = 0;
    while(i < 3) {
        printf("\n1. Login User\n");
        printf("2. Signup User\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter a choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
            loginUser();
            case 2:
            ceateUser();
            case 3:
            updateUser();
            case 4:
            deleteUser();
            case 5:
            break;
            default:
            printf("Invalid Input, please try to input a number from 1-5.\n");
        }
        i++;
    }
}*/

//void loginUser();
void createUser() {
    User usr;
    printf("Enter a Username: ");
    scanf("%29s",usr.username);
    printf("Enter a Password: ");
    scanf("%29s",usr.password);
    FILE *fptr_append;
    fptr_append = fopen("users.txt","a");
    fprintf(fptr_append,"%s ",usr.username);
    fprintf(fptr_append,"%s\n",usr.password);
    fclose(fptr_append);
}

void updateUser() {
    User usr;
    FILE *fptr_read;
    fptr_read = fopen("users.txt","r");
    char buffer[100];
    char user[30];
    printf("Enter your username: ");
    scanf("%29s",user);
    while(fscanf(fptr_read,"%s",buffer) != EOF) {
        if(strcmp(user,buffer) != 0) {
            FILE *fptr_append;
            fptr_append = fopen("users.txt","a");
            printf("Enter new username: ");
            scanf("%29s",usr.username);
            printf("Enter new password: ");
            scanf("%29s",usr.password);
            fprintf(fptr_append,"%s ",usr.username);
            fprintf(fptr_append,"%s\n",usr.password);
            fclose(fptr_append);
            break;
        }
    }
    fclose(fptr_read);
}
//void deleteUser();

//void createFile();
//void writeFile();
//void appendFile();
//void showFile();
//void listFile();

int main() {
    //createUser();
    updateUser();
    return 0;
}
