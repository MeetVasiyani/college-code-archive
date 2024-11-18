CREATE TABLE EMP (
    EID INT,
    EName VARCHAR(50),
    Department VARCHAR(50),
    Salary INT,
    JoiningDate DATE,
    City VARCHAR(50)
);

INSERT INTO EMP VALUES (101, 'Rahul', 'Admin', 56000, '1990-01-01', 'Rajkot');
INSERT INTO EMP VALUES (102, 'Hardik', 'IT', 18000, '1990-09-25', 'Ahmedabad');
INSERT INTO EMP VALUES (103, 'Bhavin', 'HR', 25000, '1991-05-14', 'Baroda');
INSERT INTO EMP VALUES (104, 'Bhoomi', 'Admin', 39000, '1991-02-08', 'Rajkot');
INSERT INTO EMP VALUES (105, 'Rohit', 'IT', 17000, '1990-07-23', 'Jamnagar');
INSERT INTO EMP VALUES (106, 'Priya', 'IT', 9000, '1990-10-18', 'Ahmedabad');
INSERT INTO EMP VALUES (107, 'Bhoomi', 'HR', 34000, '1991-12-25', 'Rajkot');

                                                    --PART A--

--Display the Highest, Lowest, Label the columns Maximum, Minimum respectively.--
SELECT MAX(Salary) AS Maximum, MIN(Salary) AS Minimum FROM EMP;

--Display Total, and Average salary of all employees. Label the columns Total_Sal and Average_Sal,respectively.--
SELECT SUM(Salary) AS Total_Sal, AVG(Salary) AS Average_Sal FROM EMP;

--Find total number of employees of EMPLOYEE table.--
SELECT COUNT(*) AS Total_Employees FROM EMP;

--Find highest salary from Rajkot city.--
SELECT MAX(Salary) FROM EMP WHERE City = 'Rajkot';

--Give maximum salary from IT department.--
SELECT MAX(Salary) FROM EMP WHERE Department = 'IT';

--Count employee whose joining date is after 8-feb-91.--
SELECT COUNT(*) FROM EMP WHERE JoiningDate > '1991-02-08';

--Display average salary of Admin department.--
SELECT AVG(Salary) AS Average_Salary FROM EMP WHERE Department = 'Admin';

--Display total salary of HR department.--
SELECT SUM(Salary) AS Total_Salary FROM EMP WHERE Department = 'HR';

--Count total number of cities of employee without duplication.--
SELECT COUNT(DISTINCT City) FROM EMP;

--Count unique departments.--
SELECT COUNT(DISTINCT Department) FROM EMP;

--Give minimum salary of employee who belongs to Ahmedabad.--
SELECT MIN(Salary) FROM EMP WHERE City = 'Ahmedabad';

--Find city wise highest salary.--
SELECT City, MAX(Salary) AS Highest_Salary FROM EMP GROUP BY City;

--Find department wise lowest salary.--
SELECT Department, MIN(Salary) AS Lowest_Salary FROM EMP GROUP BY Department;

--Display city with the total number of employees belonging to each city.--
SELECT City, COUNT(*) FROM EMP GROUP BY City;

--Give total salary of each department of EMP table.--
SELECT Department, SUM(Salary) AS Total_Salary FROM EMP GROUP BY Department;

--Give average salary of each department of EMP table without displaying the respective department name.--
SELECT Department, AVG(Salary) FROM EMP GROUP BY Department;

                                                    --PART B--

--Count the number of employees living in Rajkot.--
SELECT COUNT(*) FROM EMP WHERE City = 'Rajkot';

--Display the difference between the highest and lowest salaries. Label the column DIFFERENCE.--
SELECT MAX(Salary) - MIN(Salary) AS DIFFERENCE FROM EMP;

--Display the total number of employees hired before 1st January, 1991.--
SELECT COUNT(*) FROM EMP WHERE JoiningDate < '1991-01-01';

                                                    --PART C--

--Count the number of employees living in Rajkot or Baroda.--
SELECT COUNT(*) FROM EMP WHERE City IN ('Rajkot', 'Baroda');

--Display the total number of employees hired before 1st January, 1991 in IT department.--
SELECT COUNT(*) FROM EMP WHERE JoiningDate < '1991-01-01' AND Department = 'IT';

--Find the Joining Date wise Total Salaries.--
SELECT JoiningDate, SUM(Salary) AS Total_Salary FROM EMP GROUP BY JoiningDate;

--Find the Maximum salary department & city wise in which city name starts with ‘R’.--
SELECT Department, City, MAX(Salary) AS Maximum_Salary FROM EMP WHERE City LIKE 'R%' GROUP BY Department, City;