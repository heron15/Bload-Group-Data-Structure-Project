#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define s1 50
#define s2 10

struct donor
{
    char name[s1];
    int age;
    char bloodGroup[s2];
    char number[s1];
    struct donar *next;
};

struct donar *head;

void insert(char *name, int age, char *bloodGroup, char *number)
{
    struct donor *donorS = (struct donor *)malloc(sizeof(struct donor));

    strcpy(donorS->name, name);
    donorS->age = age;
    strcpy(donorS->bloodGroup, bloodGroup);
    strcpy(donorS->number, number);
    donorS->next=NULL;

    if(head==NULL)
    {
        head=donorS;
    }
    else
    {
        donorS->next=head;
        head=donorS;
    }
}

void display()
{
    struct donor *temp = head;

    while(temp!=NULL)
    {
        printf("\nDonar Name: %s\n", temp->name);
        printf("Donar Age: %d\n", temp->age);
        printf("Donar Blood Group: %s\n", temp->bloodGroup);
        printf("Donar Number: %s\n", temp->number);

        temp=temp->next;
    }
}

void search(char *bloodGroup)
{
    struct donor *temp = head;

    while(temp!=NULL)
    {
        if(strcmp(temp->bloodGroup,bloodGroup)==0)
        {
            printf("\nDonar Name: %s\n", temp->name);
            printf("Donar Age: %d\n", temp->age);
            printf("Donar Blood Group: %s\n", temp->bloodGroup);
            printf("Donar Number: %s\n", temp->number);
        }
        temp=temp->next;
    }
}

int main()
{
    char name[s1];
    int age;
    char bloodGroup[s2];
    char number[s1];
    int n;

    printf("\n\n\n\t\t\t\t   __      __   ___  | |   ___    ___    _ __ ___     ___  \n");
    printf("\t\t\t\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ \n");
    printf("\t\t\t\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ \n");
    printf("\t\t\t\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| \n");

    do
    {
        printf("\n1. Add Donor Details.\n2. Search Donor.\n3. View All Donor.\n4. Exit.\n");

        printf("\nChose a Option: ");
        scanf("%d", &n);

        switch(n)
        {

        case 1:
            getchar();
            printf("\nEnter name: ");
            gets(name);//heronmoy Biswas
            printf("Enter Age: ");
            scanf("%d", &age);
            getchar();
            printf("Enter Blood Group: ");
            gets(bloodGroup);
            printf("Enter Number: ");
            gets(number);

            insert(name, age, bloodGroup, number);

            break;

        case 2:
            printf("Enter Blood Group: ");
            scanf("%s", &bloodGroup);

            search(bloodGroup);

            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("\nWrong!! Option Choses.\n");
            break;
        }

    }
    while(n!=4);

    return 0;
}
