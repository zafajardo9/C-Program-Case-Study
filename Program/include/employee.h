#ifndef EMPLOYEE_STRUCT
# define EMPLOYEE_STRUCT

typedef struct EMPLOYEE_STRUCT
{
    int number;
    char* name;
    void* (*statuscode)(struct EMPLOYEE_STRUCT* self);
}Employee;

#endif