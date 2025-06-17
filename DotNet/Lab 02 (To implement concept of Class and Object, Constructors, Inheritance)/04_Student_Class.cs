/*4.(A) Write a program with following specications: 
Class Name: Student
Data Members: Enrollment_No, Student_Name, Semester, CPI and SPI 
Get Students Details using constructor and DisplayStudentDetails() using member function.
*/

class Student
{
    int Enrollment_No;
    string Student_Name;
    int Semester;
    double CPI;
    double SPI;

    public Student(int Enrollment_No, string Student_Name, int Semester, double CPI, double SPI)
    {
        this.Enrollment_No = Enrollment_No;
        this.Student_Name = Student_Name;
        this.Semester = Semester;
        this.CPI = CPI;
        this.SPI = SPI;
    }

    public void DisplayStudentDetails()
    {
        System.Console.WriteLine($"Enrollment_No : {Enrollment_No}");
        System.Console.WriteLine($"Student_Name : {Student_Name}");
        System.Console.WriteLine($"Semester : {Semester}");
        System.Console.WriteLine($"CPI : {CPI}");
        System.Console.WriteLine($"SPI : {SPI}");
    }
}

class Program4
{
    public static void Main(string[] args)
    {
        Student student1 = new Student(12345, "John Doe", 5, 8.5, 8.2);
        student1.DisplayStudentDetails();
    }
}