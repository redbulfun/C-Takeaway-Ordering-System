#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

// Login
bool compare(char *f_name, char* n)
{
    FILE* fp = fopen(f_name, "r+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return false;
    }

    char line[256] = { "\0" };
    char name[50] = { "\0" };
    char password[50] = { "\0" };
    int found = 0;

    // Find the user to log in
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "%s\t%s", name, password);
        if (strcmp(name, n) == 0)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Your name is not found in file!\n");
        fclose(fp);
        return false;
    }
    else
    {
        // Input password
        int i;
        for (i = 0; i < 5; i++)
        {
            printf("Please input your password:");
            char p[100] = { "\0" };
            scanf("%s", p);
            if (strcmp(password, p) == 0)
            {
                fclose(fp);
                return true;
            }
        }
        if (i == 5)
        {
            printf("Password wrong!\n");
            return false;
        }
    }
}

// Register
void writeIntoFile_p(char * f_name ,char* n, char* p)
{
    FILE* fp = fopen(f_name, "a+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }
    fprintf(fp, "%s\t%s", n, p);
    fclose(fp);
    printf("LinkedList data written to '%s'\n", "merchantpassword.txt");
}

// Change password
void updatePassword(char * f_name ,char* n, char* new_p)
{
    FILE* fp = fopen(f_name, "r+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    char line[256] = { "\0" };
    char name[50] = { "\0" };
    char password[50] = { "\0" };
    long filePos;
    int found = 0;

    // Find the user to change the password
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "%s\t%s", name, password);
        if (strcmp(name, n) == 0)
        {
            filePos = ftell(fp) - (strlen(line) + 1); // Return the address to change the password
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Your are not found in file!\n");
        fclose(fp);
        return;
    }

    // Find and change the password
    fseek(fp, filePos, SEEK_SET);
    fprintf(fp, "%s\t%s\n", n, new_p); // Change password
    fclose(fp);
    printf("Password updated for '%s'\n", n);
}