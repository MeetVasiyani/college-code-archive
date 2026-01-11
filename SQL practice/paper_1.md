### 📜 Paper 1: Table & Data Generation Scripts

This paper uses an **Employee Management** schema. Here are the scripts to create the `Department` and `Employee` tables and populate them with sample data to test all 15 queries.

#### 1\. Table Generation Script (DDL)

This script creates the tables based on the schema from the exam paper .

```sql
-- Create Department Table
CREATE TABLE Department (
    DeptID INT PRIMARY KEY,
    DeptName VARCHAR(50) NOT NULL
);

-- Create Employee Table
CREATE TABLE Employee (
    EmpID INT PRIMARY KEY,
    Name VARCHAR(100),
    Email VARCHAR(100),
    City VARCHAR(50),
    Mobile VARCHAR(20),
    JoiningDate DATE,
    Salary DECIMAL(10, 2),
    DeptID INT FOREIGN KEY REFERENCES Department(DeptID)
);
```

#### 2\. Sample Data Insertion (DML)

This script populates the tables with logical data to test all 15 queries.

```sql
-- Insert Sample Departments
INSERT INTO Department (DeptID, DeptName) VALUES
(1, 'Computer'),
(2, 'Civil'),
(3, 'Mechanical'),
(4, 'HR'),
(5, 'Finance');

-- Insert Sample Employees
INSERT INTO Employee (EmpID, Name, Email, City, Mobile, JoiningDate, Salary, DeptID) VALUES
-- Q1: Changa
(101, 'Sandeep', 'sandeep@test.com', 'Mumbai', '1112223334', '2021-05-15', 50000.00, 1),
(102, 'Rajesh Kumar', 'rajesh@test.com', 'Changa', '2223334445', '2022-03-10', 55000.00, 1),

-- Q2: Joined after 01 Jun 2022, Computer or Civil
(103, 'Priya Sharma', 'priya@test.com', 'Pune', '3334445556', '2022-06-05', 60000.00, 1),
(104, 'Amit Singh', 'amit@test.com', 'Delhi', '4445556667', '2022-07-20', 62000.00, 2),

-- Q3: No mobile or email
(105, 'Sneha Patel', 'sneha@test.com', 'Pune', NULL, '2021-08-01', 58000.00, 1),
(106, 'Vikram Rathod', NULL, 'Mumbai', '6667778889', '2022-01-12', 53000.00, 2),

-- Q4/Q5: Top salaries
(107, 'Anjali Mehta', 'anjali@test.com', 'Delhi', '7778889990', '2020-02-18', 90000.00, 1),
(108, 'Manish Jain', 'manish@test.com', 'Changa', '8889990001', '2021-11-05', 85000.00, 2),
(109, 'Kavita Iyer', 'kavita@test.com', 'Pune', '9990001112', '2022-04-30', 88000.00, 1),

-- Q5: Top 3 dept wise
(110, 'Rahul Dave', 'rahul@test.com', 'Mumbai', '1231231234', '2021-09-22', 82000.00, 2),
(111, 'Meera Krishnan', 'meera@test.com', 'Delhi', '2342342345', '2022-08-14', 86000.00, 1),

-- Q9: Dept with > 9 (Computer will have 10)
(112, 'Varun Gill', 'varun@test.com', 'Pune', '3453453456', '2023-01-01', 50000.00, 1),
(113, 'Deepak Shah', 'deepak@test.com', 'Changa', '4564564567', '2023-02-11', 48000.00, 1),
(114, 'Nisha Verma', 'nisha@test.com', 'Mumbai', '5675675678', '2023-03-15', 47000.00, 1),
(115, 'Suresh Reddy', 'suresh@test.com', 'Delhi', '6786786789', '2023-04-20', 46000.00, 1),

-- Q10: Mechanical
(116, 'Rina Desai', 'rina@test.com', 'Pune', '7897897890', '2022-05-10', 60000.00, 3),
(117, 'Gaurav Kumar', 'gaurav@test.com', 'Mumbai', '8908908901', '2022-06-12', 65000.00, 3),

-- Q12: HR > 45k
(118, 'Pooja Singh', 'pooja@test.com', 'Delhi', '9019019012', '2021-07-07', 48000.00, 4),
(119, 'Alok Nath', 'alok@test.com', 'Pune', '0120120123', '2022-09-30', 40000.00, 4),

-- Q13: Same name
(120, 'Amit Singh', 'amit2@test.com', 'Pune', '1122112211', '2023-05-01', 51000.00, 5),
(121, 'Priya Sharma', 'priya2@test.com', 'Mumbai', '2233223322', '2023-06-10', 70000.00, 5);
```

---

### 🚀 Paper 1: SQL Queries

#### **Question 1:** List all Employees which belongs to Changa.

**Expected Output:**

| EmpID | Name         | City   |
| :---- | :----------- | :----- |
| 102   | Rajesh Kumar | Changa |
| 108   | Manish Jain  | Changa |
| 113   | Deepak Shah  | Changa |

#### **Question 2:** List all Employees who joined after 01 Jun, 2022 and belongs to either Computer or Civil.

**Expected Output:**

| EmpID | Name           | JoiningDate | DeptName |
| :---- | :------------- | :---------- | :------- |
| 103   | Priya Sharma   | 2022-06-05  | Computer |
| 104   | Amit Singh     | 2022-07-20  | Civil    |
| 111   | Meera Krishnan | 2022-08-14  | Computer |
| 112   | Varun Gill     | 2023-01-01  | Computer |
| 113   | Deepak Shah    | 2023-02-11  | Computer |
| 114   | Nisha Verma    | 2023-03-15  | Computer |
| 115   | Suresh Reddy   | 2023-04-20  | Computer |

#### **Question 3:** List all Employees with department name who don't have either mobile or email.

**Expected Output:**

| EmpID | Name          | Email          | Mobile     | DeptName |
| :---- | :------------ | :------------- | :--------- | :------- |
| 105   | Sneha Patel   | sneha@test.com | NULL       | Computer |
| 106   | Vikram Rathod | NULL           | 6667778889 | Civil    |

#### **Question 4:** List top 5 employees as per salaries.

**Expected Output:**

| EmpID | Name           | Salary   |
| :---- | :------------- | :------- |
| 107   | Anjali Mehta   | 90000.00 |
| 109   | Kavita Iyer    | 88000.00 |
| 111   | Meera Krishnan | 86000.00 |
| 108   | Manish Jain    | 85000.00 |
| 110   | Rahul Dave     | 82000.00 |

#### **Question 5:** List top 3 employees department wise as per salaries.

**Expected Output:**

| DeptName   | Name           | Salary   | DeptRank |
| :--------- | :------------- | :------- | :------- |
| Civil      | Manish Jain    | 85000.00 | 1        |
| Civil      | Rahul Dave     | 82000.00 | 2        |
| Civil      | Amit Singh     | 62000.00 | 3        |
| Computer   | Anjali Mehta   | 90000.00 | 1        |
| Computer   | Kavita Iyer    | 88000.00 | 2        |
| Computer   | Meera Krishnan | 86000.00 | 3        |
| Finance    | Priya Sharma   | 70000.00 | 1        |
| Finance    | Amit Singh     | 51000.00 | 2        |
| HR         | Pooja Singh    | 48000.00 | 1        |
| HR         | Alok Nath      | 40000.00 | 2        |
| Mechanical | Gaurav Kumar   | 65000.00 | 1        |
| Mechanical | Rina Desai     | 60000.00 | 2        |

---

#### **Question 6:** List City with Employee Count.

**Expected Output:**

| City   | EmployeeCount |
| :----- | :------------ |
| Changa | 3             |
| Delhi  | 5             |
| Mumbai | 6             |
| Pune   | 7             |

#### **Question 7:** List City Wise Maximum, Minimum & Average Salaries & Give Proper Name As MaxSal, MinSal & AvgSal.

**Expected Output:**

| City   | MaxSal   | MinSal   | AvgSal   |
| :----- | :------- | :------- | :------- |
| Changa | 85000.00 | 48000.00 | 62666.67 |
| Delhi  | 90000.00 | 46000.00 | 66400.00 |
| Mumbai | 82000.00 | 47000.00 | 58833.33 |
| Pune   | 88000.00 | 40000.00 | 58285.71 |

#### **Question 8:** List Department wise City wise Employee Count.

**Expected Output:**

| DeptName   | City   | EmployeeCount |
| :--------- | :----- | :------------ |
| Civil      | Changa | 1             |
| Civil      | Delhi  | 1             |
| Civil      | Mumbai | 2             |
| Computer   | Changa | 2             |
| Computer   | Delhi  | 3             |
| Computer   | Mumbai | 2             |
| Computer   | Pune   | 3             |
| Finance    | Mumbai | 1             |
| Finance    | Pune   | 1             |
| HR         | Delhi  | 1             |
| HR         | Pune   | 1             |
| Mechanical | Mumbai | 1             |
| Mechanical | Pune   | 1             |

#### **Question 9:** List Departments with more than 9 employees.

**Expected Output:**
Our sample data has 10 employees in the 'Computer' department.

| DeptName | EmployeeCount |
| :------- | :------------ |
| Computer | 10            |

#### **Question 10:** Give 10% increment in salary to all employees who belongs to Mechanical Department.

**Expected Output:**
A message indicating that 2 rows were updated (EmpID 116 and 117).

`(2 row(s) affected)`

#### **Question 11:** Update City of Sandeep from Mumbai to Pune having 101 as Employee ID.

**Expected Output:**
A message indicating that 1 row was updated.

`(1 row(s) affected)`

#### **Question 12:** Delete all the employees who belongs to HR Department & Salary is more than 45,000.

**Expected Output:**
A message indicating that 1 row was deleted (Pooja Singh, EmpID 118, Salary 48000).

`(1 row(s) affected)`

#### **Question 13:** List Employees with same name with occurrence of name.

**Expected Output:**
'Amit Singh' and 'Priya Sharma' both appear twice.

| Name         | OccurrenceCount |
| :----------- | :-------------- |
| Amit Singh   | 2               |
| Priya Sharma | 2               |

#### **Question 14:** List Department wise Average Salary.

**Expected Output:**
_Note: This output assumes Query 10 (`UPDATE`) and Query 12 (`DELETE`) **have** been run._

- Mechanical Avg: (60000*1.1 + 65000*1.1) / 2 = 68750
- HR Avg: (Pooja was deleted, Alok remains) = 40000

| DeptName   | AverageSalary |
| :--------- | :------------ |
| Computer   | 65200.00      |
| Civil      | 70500.00      |
| Mechanical | 68750.00      |
| HR         | 40000.00      |
| Finance    | 60500.00      |

#### **Question 15:** List City wise highest paid employee.

**Expected Output:**
_Note: This output assumes Query 11 (`UPDATE`) has run, so Sandeep is now in Pune._

| City   | Name         | Salary   |
| :----- | :----------- | :------- |
| Changa | Manish Jain  | 85000.00 |
| Delhi  | Anjali Mehta | 90000.00 |
| Mumbai | Rahul Dave   | 82000.00 |
| Pune   | Kavita Iyer  | 88000.00 |
