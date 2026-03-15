#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> // For mkdir()

// Use _mkdir on Windows, mkdir on Linux/macOS
#ifdef _WIN32
    #include <direct.h>
    #define CREATE_DIR(name) _mkdir(name)
#else
    #define CREATE_DIR(name) mkdir(name, 0777)
#endif

typedef struct {
    char username[30];
    char password[30];
} User;

// Function Prototypes
void mainMenu();
void authMenu();
void signup();
int login();
void fileMenu(char *username);
void createFile(char *username);
void readFile(char *username);
void appendFile(char *username);
void listFiles(char *username);

int main() {
    authMenu();
    return 0;
}

// --- Authentication Layer ---
void authMenu() {
    int choice;
    while (1) {
        printf("\n--- WELCOME TO USER FILE SYSTEM ---\n");
        printf("1. Login\n2. Signup\n3. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            if (login()) {
                // Login successful logic happens inside login()
            }
        } else if (choice == 2) {
            signup();
        } else if (choice == 3) {
            printf("Exiting...\n");
            exit(0);
        } else {
            printf("Invalid choice!\n");
        }
    }
}

void signup() {
    User newUser;
    FILE *fp = fopen("users.txt", "a+");
    
    printf("\n--- SIGNUP ---\nUsername: ");
    scanf("%29s", newUser.username);
    printf("Password: ");
    scanf("%29s", newUser.password);

    fprintf(fp, "%s %s\n", newUser.username, newUser.password);
    fclose(fp);

    // Create a directory for the user
    CREATE_DIR(newUser.username);
    printf("Account created! Directory '%s/' is ready.\n", newUser.username);
}

int login() {
    char uname[30], pword[30], fileUname[30], filePword[30];
    printf("\n--- LOGIN ---\nUsername: ");
    scanf("%29s", uname);
    printf("Password: ");
    scanf("%29s", pword);

    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("No users found. Please signup first.\n");
        return 0;
    }

    while (fscanf(fp, "%s %s", fileUname, filePword) != EOF) {
        if (strcmp(uname, fileUname) == 0 && strcmp(pword, filePword) == 0) {
            printf("Login Successful!\n");
            fclose(fp);
            fileMenu(uname); // Move to second page
            return 1;
        }
    }
    fclose(fp);
    printf("Invalid credentials.\n");
    return 0;
}

// --- File Management Layer ---
void fileMenu(char *username) {
    int choice;
    while (1) {
        printf("\n--- USER PANEL: %s ---\n", username);
        printf("1. Create/Write File\n2. Read File\n3. Append File\n4. List Files\n5. Logout\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createFile(username); break;
            case 2: readFile(username); break;
            case 3: appendFile(username); break;
            case 4: listFiles(username); break;
            case 5: return; // Back to auth menu
            default: printf("Invalid.\n");
        }
    }
}

void createFile(char *username) {
    char filename[50], path[100], content[200];
    printf("Enter filename: ");
    scanf("%49s", filename);
    
    sprintf(path, "%s/%s.txt", username, filename); // Creates path: username/filename.txt
    
    FILE *fp = fopen(path, "w");
    printf("Enter content: ");
    getchar(); // Clear newline
    fgets(content, sizeof(content), stdin);
    fprintf(fp, "%s", content);
    fclose(fp);
    printf("File saved in your directory.\n");
}

void readFile(char *username) {
    char filename[50], path[100], ch;
    printf("Enter filename to read: ");
    scanf("%49s", filename);
    
    sprintf(path, "%s/%s.txt", username, filename);
    FILE *fp = fopen(path, "r");
    if (!fp) { printf("File not found!\n"); return; }

    printf("\n--- CONTENT ---\n");
    while ((ch = fgetc(fp)) != EOF) putchar(ch);
    fclose(fp);
    printf("\n---------------\n");
}

void appendFile(char *username) {
    char filename[50], path[100], content[100];
    printf("Enter filename to update: ");
    scanf("%49s", filename);
    
    sprintf(path, "%s/%s.txt", username, filename);
    FILE *fp = fopen(path, "a"); // 'a' for append
    if (!fp) { printf("Error opening file!\n"); return; }

    printf("Enter text to add: ");
    getchar();
    fgets(content, sizeof(content), stdin);
    fprintf(fp, "%s", content);
    fclose(fp);
    printf("File updated.\n");
}

void listFiles(char *username) {
    printf("\n--- YOUR FILES ---\n");
    char command[100];
#ifdef _WIN32
    sprintf(command, "dir /b %s", username);
#else
    sprintf(command, "ls %s", username);
#endif
    system(command);
}
