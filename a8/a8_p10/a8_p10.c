#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    FILE *file;
    char fileName[64], line[64];
    char *tempUsername, *tempPassword, *username, *password;
    char *usernames[100];
    int i = 0, usernameCount = 0, position = 0, endPositions[100];

    scanf("%s", fileName);
    getchar();

    file = fopen(fileName, "r");
    if (file == NULL) { // Check if file was opened successfully
        printf("File couldn't be opened!\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        // Check if there is a newline character at the end
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0'; // Substitute for null-terminator
        // Else leave it as it is (in case of last line)

        // Save end position of line and add 1 to count newline character
        position += (((int) strlen(line)) + 1); // + 1 counting newline
        endPositions[i] = position;

        // Add username to array usernames
        if (i % 2 == 0) {
            char *user;
            user = (char *) malloc(sizeof(char) * strlen(line));
            strcpy(user, line);
            usernames[i / 2] = user;
            usernameCount++; // Increment number of usernames
        }
        i++;
    }

    while(1) { // Infinite loop to get new input for username and password
        tempUsername = (char *) malloc(sizeof(char) * 64);
        tempPassword = (char *) malloc(sizeof(char) * 64);

        // Check if malloc was successful
        if (tempUsername == NULL || tempPassword == NULL) 
            exit(1);
        scanf("%[^\n]%*c", tempUsername);
        username = (char *) malloc(sizeof(char) * strlen(tempUsername));
        
        if (username == NULL)
            exit(1);

        strcpy(username, tempUsername);
        if (strcmp(username, "exit") == 0) {
            printf("Exiting ...\n");
            free(tempPassword);
            free(tempUsername);
            free(username);
            return 0;
        }
        
        scanf("%[^\n]%*c", tempPassword);
        password = (char *) malloc(sizeof(char) * strlen(tempPassword));
        if (password == NULL)  // Check if malloc was successful
            exit(1);
        strcpy(password, tempPassword);

        free(tempUsername);
        free(tempPassword);

        // Loop until we find username in array or we surpass usernameCount
        for (i = 0; i < usernameCount; i++) {
            if (strcmp(username, usernames[i]) == 0) {
                break;
            }
        }
        
        // Check if we traversed the whole array of usernames
        if (i == usernameCount) { // Username not found
            printf("Access to user %s is denied.\n", username);
            continue;
        } else { // Username found
            // Go to position with index 2*i based on username index i
            fseek(file, endPositions[2*i], SEEK_SET);
            fgets(line, sizeof(line), file); // Get password from file
            // Same
            if (line[strlen(line) - 1] == '\n')
                line[strlen(line) - 1] = '\0';
            // Check if inputted password and password in file match
            if (strcmp(password, line) == 0)
                printf("Access to user %s is granted.\n", username);
            else printf("Access to user %s is denied.\n", username);
        }

        free(username);
        free(password);
    }
    return 0;
}