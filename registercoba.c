#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ADT_Mesin_Kata.h" // Include Mesin Kata header

#define MAX_LINE_LENGTH 256
#define TXT_FILE "client_data.txt"


// Helper function to write data to TXT
void write_txt(int id, const char *username, const char *password) {
    FILE *file = fopen(TXT_FILE, "a");
    if (!file) {
        printf("Could not open file: %s\n", TXT_FILE);
        return;
    }
    // Write data in "ID Username Password" format
    fprintf(file, "%d %s %s\n", id, username, password);
    fclose(file);
}

// Function to check if a file exists
int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

// Function to register a new client
void register_client() {
    char username[MAX_LINE_LENGTH];
    char password[MAX_LINE_LENGTH];
    char temp[MAX_LINE_LENGTH];

    printf("Insert username: ");
    STARTWORD(); // Start reading input
    strncpy(username, currentWord.TabWord, currentWord.Length);
    username[currentWord.Length] = '\0'; // Null-terminate the string

    printf("Insert password: ");
    STARTWORD(); // Read password
    strncpy(password, currentWord.TabWord, currentWord.Length);
    password[currentWord.Length] = '\0';

    // Check if file exists and open it
    FILE *file = fopen(TXT_FILE, "r");
    if (!file) {
        // If file doesn't exist, create it
        printf("No existing data found. Creating new data file...\n");
        file = fopen(TXT_FILE, "w");
        if (!file) {
            printf("Error creating file: %s\n", TXT_FILE);
            return;
        }
        fclose(file);
    } else {
        // Check for duplicate username
        while (fgets(temp, sizeof(temp), file)) {
            char existing_username[MAX_LINE_LENGTH];
            sscanf(temp, "%*d %s %*s", existing_username); // Parse username
            if (strcmp(existing_username, username) == 0) {
                printf("Username already taken. Please try again.\n");
                fclose(file);
                return;
            }
        }
        fclose(file);
    }

    int user_id = 1; // Initialize ID

    // Calculate the next available ID by checking existing entries
    file = fopen(TXT_FILE, "r");
    while (fgets(temp, sizeof(temp), file)) {
        int existing_id;
        sscanf(temp, "%d", &existing_id); // Parse ID
        if (existing_id >= user_id) {
            user_id = existing_id + 1;
        }
    }
    fclose(file);

    write_txt(user_id, username, password);
    printf("Registration successful! Welcome, %s!\n", username);
}

int main() {
    register_client();
    return 0;
}
