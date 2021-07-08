#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>

#define REGULAR R
#define CASUAL C
const int size = 5;

/*
NOTES:
160 hrs worked. if hrs work exceed 160 hrs. then give overtime pay

net pay => netpay = basic pay + overtime - deductions

*/

typedef struct Employee{
    int employee_number;
    char employee_name[50];
    char status_code;
    int hours_worked;

    double basic_pay;
    double basic_rate;
    double deductions;

    
}Employee;

//FUNCTION
int getOvertime(Employee e[], int temp, double overtime_pay) {
    double overtime_rate = .5;

    overtime_pay = overtime_rate * temp; //mali ata logic
    return overtime_pay;
}


void Net_Pay(Employee e, int temp, double net_pay, double overtime_pay) {
    //net pay => netpay = basic pay + overtime - deductions
    net_pay = e.basic_pay + overtime_pay - e.deductions;
    printf("%d", net_pay);
}


//MAIN
int main() {

    FILE *file;
    file = fopen("employee.txt", "w");

    if(file == NULL) {
        printf("WARNING!!! \nFILE CANNOT BE CREATED!!!");
        return -1;
        exit(1);
    }

    //system("cls");

    Employee e[5];
    int i;

/*
            &e[i].employee_number
            &e[i].employee_name, 
            &e[i].status_code, 
            &e[i].hours_worked, 
            &e[i].basic_pay, 
            &e[i].basic_rate, 
            &e[i].deductions);
*/

    for (i = 0; i < size; i++){
        printf("EMPLOYEE %d \n", i+1);
        printf("[%d]Enter Employee Number: ", i+1);
            scanf("%d", &e[i].employee_number);


        printf("[%d]Enter Employee Name: ", i+1);
            scanf("%s", &e[i].employee_name);
        printf("Enter Employee Status Code (R/C): ");
            scanf("%s", &e[i].status_code);

        while(!(e[i].status_code == 'r' || e[i].status_code == 'R' || e[i].status_code == 'c' || e[i].status_code == 'C')) {
            printf("Please enter proper code!\n"); 
            printf("[%d]Enter Employee Status(R / C): ", i);
            scanf("%s", &e[i].status_code);
	    }
        
        printf("Hours Worked: ");
            scanf("%d", &e[i].hours_worked);
        printf("Basic Pay: ");
            scanf("%lf", &e[i].basic_pay);
        printf("Basic Rate: ");
            scanf("%lf", &e[i].basic_rate);
        printf("Deductions: ");
            scanf("%lf", &e[i].deductions);

         
        fprintf(file,"%d\t%s\t%s\t%d\t%f\t%f\t%f\n", 
            e[i].employee_number,
            e[i].employee_name, 
            e[i].status_code, 
            e[i].hours_worked, 
            e[i].basic_pay, 
            e[i].basic_rate, 
            e[i].deductions);
            
        printf("\n");
    }
        fclose(file);


    //CLEARR
    system("cls");
    file = fopen("employee.txt", "r");//output
    if(file == NULL) {
        printf("WARNING!!! \nFILE CANNOT BE FOUND!!!");
        return -1;
        exit(1);
    }

    system("cls");
    printf("THE DATA\n\n");
    for (i = 0; i < size; i++){
        printf("EMPLOYEE [%d] \n", i+1);

        fscanf(file, "%d\t%s\t%s\t%d\t%lf\t%lf\t%lf\n", 
            &e[i].employee_number, 
            &e[i].employee_name, 
            &e[i].status_code, 
            &e[i].hours_worked, 
            &e[i].basic_pay, 
            &e[i].basic_rate, 
            &e[i].deductions);

        //FUNCTION
        double overtime_pay;
        double overtimeFI;
        double net_pay;
        if(e[i].hours_worked > 160) {
            //getting overtime
            int temp = e[i].hours_worked - 160;
            overtimeFI = getOvertime(e, temp, overtime_pay);

            //getting net
            //Net_Pay(e[i],temp,net_pay,overtime_pay);
        }
        
        printf("Employee Number\t\tEmployee Name\t\tStatus\t\tBasic Salary\t\tOvertime Pay\t\tDeductions\t\tNetpay\n");
   
    //Loyola
    while (fread(&e, size, 1, file) == 1)
	{

		printf("\n %d\t\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
			e[i].employee_number,  
			e[i].employee_name, 
            (e[i].status_code == 'r' || e[i].status_code == 'R') ? "Regular" : "Casual", 			
            e[i].basic_salary,
            e[i].overtime,
            e[i].deductions,
			e[i].net_pay);
	
	}


        // char buffer[500];
        // while(!feof(file)) {
        //     fgets(buffer, 500, file);
        //     sscanf(buffer, "%d %s %s %d %lf %lf %lf", 
        //         &e->employee_number, 
        //         &e->status_code, 
        //         &e->hours_worked, 
        //         &e->basic_pay, 
        //         &e->basic_rate, 
        //         &e->deductions); //
        //     puts(buffer);
        //     i++;
        // }
    }


    fclose(file);
    return 0;
}
