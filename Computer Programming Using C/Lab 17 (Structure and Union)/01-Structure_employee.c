/*Create, declare and initialize structure employee.*/
struct employee {
    int id;
    char name[50];
    float salary;
};

void main() {
    struct employee emp = {101, "John Doe", 50000.00};

    printf("Employee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);
    printf("Employee Salary: %.2f\n", emp.salary);

}
