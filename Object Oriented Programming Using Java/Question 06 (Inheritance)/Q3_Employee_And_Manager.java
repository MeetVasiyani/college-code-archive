/*
Create a class named 'Member' having the following members:
 i. Name
 ii. Age
 iii. Phone number
 iv. Address
 v. Salary

It also has a method named 'printSalary' which prints the salary of the members.
Two classes 'Employee' and Manager' inherits the 'Member' class. The 'Employee' and 'Manager' classes have data members
'specialization' and 'department' respectively. Now assign name, age, phone number address and salary to an employee and a 
manager by making an object of both of these classes and print the same along with specialization and department respectively. 
*/
class Member {
    String name;
    int age;
    String phoneNumber;
    String address;
    double salary;

    public void printSalary() {
        System.out.println("Salary: " + salary);
    }
}

class Employee extends Member {
    String specialization;

    public Employee(String name, int age, String phoneNumber, String address, double salary, String specialization) {
        super.name = name;
        super.age = age;
        super.phoneNumber = phoneNumber;
        super.address = address;
        super.salary = salary;
        this.specialization = specialization;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", phoneNumber='" + phoneNumber + '\'' +
                ", address='" + address + '\'' +
                ", salary=" + salary +
                ", specialization='" + specialization + '\'' +
                '}';
    }
}

class Manager extends Member {
    String department;

    public Manager(String name, int age, String phoneNumber, String address, double salary, String department) {
        super.name = name;
        super.age = age;
        super.phoneNumber = phoneNumber;
        super.address = address;
        super.salary = salary;
        this.department = department;
    }

    @Override
    public String toString() {
        return "Manager{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", phoneNumber='" + phoneNumber + '\'' +
                ", address='" + address + '\'' +
                ", salary=" + salary +
                ", department='" + department + '\'' +
                '}';
    }
}

public class Q3_Employee_And_Manager {

    public static void main(String[] args) {
        Employee employee = new Employee("John Doe", 30, "123-456-7890", "123 Main St", 50000.0, "Software Engineer");
        Manager manager = new Manager("Jane Smith", 40, "987-654-3210", "456 Elm St", 80000.0, "Marketing");

        System.out.println("Employee Details:");
        System.out.println(employee);
        employee.printSalary();

        System.out.println("\nManager Details:");
        System.out.println(manager);
        manager.printSalary();
    }
}
