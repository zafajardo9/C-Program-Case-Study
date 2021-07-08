#include <stdio.h>
#include <stdlib.h>

#define REGULAR R
#define CASUAL C

typedef struct Employee{
    int employee_number;
    char employee_name[50];
    char status_code;
    int hours_worked;

    float basic_pay;
    float basic_rate;
    float deductions;

    float overtime;
    
}Employee;//emp[5]

int main() {


    FILE* file = fopen("employee.txt", "r"); //can be r+

    if(file == NULL) {
        printf("CAnt find the file");
        return 1;
    }
    char buffer[500];
    //fgets(buffer, 500, file);

    int i = 0;

    Employee emp[5];
    while(!feof(file)) {
        fgets(buffer, 500, file);
        Employee* e = emp + i;
        sscanf(buffer, "%d %s %c %d %f %f %f", &e->employee_number, &e->status_code, &e->hours_worked, &e->basic_pay, &e->basic_rate, &e->deductions); //
        puts(buffer);
        i++;
    }


    int n = i;

    for(i = 0; i < n; i++) {
        printf("%d\t%s\t%c\t%d\t%f\t%f\t%f\t%f \n", emp[i].employee_number,emp[i].employee_name,emp[i].status_code,emp[i].hours_worked,emp[i].basic_pay,emp[i].basic_rate,emp[i].deductions);
    }
    //CLOSE THE FILE
    fclose(file);

    return 0;
}