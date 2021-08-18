#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Fname 20
#define Lname 30

typedef struct {
    char firstname[Fname];
    char lastname[Lname];
    int score;
    int streak;//in days
}employeeComp;

void CreateNewFile();//Create and format the new file
void GetInfo(char pre[Fname], char nom[Lname], int* num, int* record);
void PrintInfo(employeeComp Var1);

int main(){
    employeeComp Emp1;
    Emp1.score =0;
    Emp1.streak =0;
    GetInfo(Emp1.firstname, Emp1.lastname, &Emp1.score , &Emp1.streak);

    //For debugging purposes
    //printf("2)Employee: %s %s, Score: %d, Streak(days): %d\n", Emp1.firstname, Emp1.lastname, Emp1.score, Emp1.streak);

    PrintInfo(Emp1);
    return 0;
}

//Gets the information from user about employee name, lastname, their score, and daily score
void GetInfo(char pre[Fname], char nom[Lname], int *num, int *record){
    //int num2,record2;
    printf("Please enter the first name: ");
    fgets(pre, Fname, stdin);
    printf("Please enter the last name: ");
    fgets(nom, Lname, stdin);
    printf("Please enter the score: ");
    scanf("%d", &*num);
    printf("Please enter any streak held (in days): ");
    scanf("%d", &*record);

    //would have done scanf("%d", &num2); but the above code avoids the declaration of two new ints
    //the idea is to scanf a value into the variable pointed by num( which contains the address of Emp1.score)
    // while still keeping the & character so that the compiler doesnt return an error
    //*num = num2;
    //*record = record2;

    //Replace "\n" with "\0" at the end of each string
    pre[strcspn(pre,"\n")] = 0;
    nom[strcspn(nom,"\n")] = 0;

    //For debugging purposes
    //printf("1)Employee: %s %s, Score: %d, Streak(days): %d\n", pre, nom, num, record);
}

void PrintInfo(employeeComp Var2){
    FILE *fptr;
    fptr = fopen("EmployeeData.txt", "a");
    fprintf(fptr,"Employee: %s %s, Score: %d, Streak(days): %d\n", Var2.firstname, Var2.lastname, Var2.score, Var2.streak);
    fclose(fptr);
}

//Now print onto a file
