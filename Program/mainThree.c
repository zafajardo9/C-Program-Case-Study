#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
NOTES:
160 hrs worked. if hrs work exceed 160 hrs. then give overtime pay
net pay => netpay = basic pay + overtime - deductions
*/
struct emp {
    int employee_number;
    char employee_name[15];
    char status_code[1];
    int hours_worked;
    float basic_salary;
    float deductions;
    float overtime;
    float net_pay;
    float basic_rate;

};
struct emp e;
// void set_employee(struct employee e) {
//     e.employee_number = 100;
// }

//PRINTING
// void print_details(employee e) {
//     printf("%s");
// }


// size of the structure
long int size = sizeof(e);

void mainPrint();
void getValues(int i, int temp);
int overtime(int temp);
void Net_Pay(int temp, int net_pay);

FILE *file;




void mainPrint() {
    system("Color 2");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t============= WELCOME ==============\n\n\n\n\n\n\n\t\t\t\t\n");


	system("pause");
}
//TODO: change the logic for overtime
void getValues(int i, int temp) {

	int j;
	fseek(file, 0, SEEK_END);
	system("cls");

	//Number
	//TODO: 10 characters use strlen() fuction
    printf("[%d]Enter Employee Number: ", i);
    while(scanf("%d", &e.employee_number) <= 0 ) {
        if(e.employee_number >= 10) {
            printf("Input more");
        } else {
            break;
        }

		printf("Employee number must be a number\n");
    	printf("[%d]Enter Employee Number: ", i);
    	scanf("%*s");
	}

    //NAME
    printf("[%d]Enter Employee Name: ", i);
    scanf("\n");
	gets(&*e.employee_name);

    //status
    printf("[%d]Enter Employee Status(R / C): ", i);
    scanf("%s", &e.status_code);
    while(!(*e.status_code == 'r' ||  'R' || *e.status_code == 'c' ||  'C')) {// while not ! (R,r,C,c) the input
		printf("Please enter proper code!\n"); //print enter proper code
    	printf("[%d]Enter Employee Status(R / C): ", i);
		scanf("%s", &e.status_code);
	}

    //hours
    printf("[%d]Enter Employee Hours Worked: ", i);
    while(scanf("%d", &e.hours_worked) <= 0) {
		printf("Please enter a valid number!\n");
    	printf("[%d]Enter Employee Hours Worked: ", i);
    	scanf("%*s");
	}
    //pay
    printf("[%d]Enter Basic Salary: ", i);//30000
    while(scanf("%f", &e.basic_salary) <= 0) {
		printf("Please enter a valid number!\n");
    	printf("[%d]Enter Basic Salary: ", i);
    	scanf("%*s");
	}


    printf("[%d]Enter Basic Rate: ", i);
    while(scanf("%f", &e.basic_rate) <= 0) {
		printf("Please enter a valid number!\n");
    	printf("[%d]Enter Basic Salary: ", i);
    	scanf("%*s");
	}

	if (e.hours_worked > 160)//if hours worked is greater than 160
        {// example: hours worked = 161, basic salary = 30000
            e.overtime = e.hours_worked - 160;
            e.overtime *= e.basic_rate * 0.5;
        	//e.overtime = e.basic_salary * 0.05; //overtime = 30000 x 0.05 = 1500
        	//e.overtime *= e.hours_worked - 160; //overtime = 1500 x (hours worked 161 - 160)
        	//printing over time = 1500
        }
        else{
            e.overtime = 0;
        }

    //deduction
    printf("[%d]Enter Employee Deductions: ", i);//2356
    while(scanf("%f", &e.deductions) <= 0) {
		printf("Please enter a valid number!\n");
    	printf("[%d]Enter Employee Deductions: ", i);
    	scanf("%*s");

	}
   e.net_pay = (e.basic_salary + e.overtime) - e.deductions;
	//net pay = (30000 + 1500) - 2356
	//net pay = 29144
	fwrite(&e, size, 1, file);
	fflush(stdin);

}


int main() {

    file = fopen("employee.txt", "wb+"); //can be r+
    if(file == NULL) {
        printf("WARNING!!! \nFILE CANNOT BE CREATED!!!");
        return -1;
        exit(1);
    }
    int temp, net_pay;
    mainPrint();
    int i = 1;

    while(i <= 2) {//The input should have 5 employees
        getValues(i, temp); //struct
        i++;
    }

	system("cls"); //clear output screen

	rewind(file);
		printf("\t\t\t\t\t\tABC COMPANY\n\t\t\t\t\t\tMakaty City\n\n\t\t\t\t\t\tPayroll\n");
		printf("===============================================================================================================");
		printf("\nEmployee Number\tEmployee Name\tStatus\t\tBasic Salary\tOver time pay\tDeductions\tNet Pay\n");
		printf("===============================================================================================================\n");


    //PRINTING
    while (fread(&e, size, 1, file) == 1)
	{

		printf("\n%d\t%s\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
			e.employee_number,
			e.employee_name,
            (*e.status_code == 'r' || *e.status_code == 'R') ? "Regular" : "Casual", // if status code == r or R, print Regular else Casual
            e.basic_salary,
            e.overtime,
            e.deductions,
			e.net_pay);

	}

    return  0;

}