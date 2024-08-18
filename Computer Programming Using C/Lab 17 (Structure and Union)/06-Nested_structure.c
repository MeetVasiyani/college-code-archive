/*Demonstrate nested structure.*/

#include <stdio.h>

struct address {
    int house_number;
    char street[50];
    char city[50];
    char state[20];
    char zip[10];
};

struct employee {
    int id;
    char name[50];
    float salary;
    struct address address;
};

void main() {
    struct employee emp = {101, "John Doe", 30000.00, {123, "Main Street", "Anytown", "CA", "91234"}};

    printf("Employee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);
    printf("Employee Salary: %.2f\n", emp.salary);
    printf("Employee Address:\n");
    printf("House Number: %d\n", emp.address.house_number);
    printf("Street: %s\n", emp.address.street);
    printf("City: %s\n", emp.address.city);
    printf("State: %s\n", emp.address.state);
    printf("Zip: %s\n", emp.address.zip);

}
