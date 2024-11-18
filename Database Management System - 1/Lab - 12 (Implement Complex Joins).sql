CREATE TABLE DEPT (
    DepartmentID INT PRIMARY KEY,
    DepartmentName VARCHAR(100) NOT NULL UNIQUE,
    DepartmentCode VARCHAR(50) NOT NULL UNIQUE,
    Location VARCHAR(50) NOT NULL
);

CREATE TABLE PERSON (
    PersonID INT PRIMARY KEY,
    PersonName VARCHAR(100) NOT NULL,
    DepartmentID INT,
    Salary DECIMAL(8, 2) NOT NULL,
    JoiningDate DATETIME NOT NULL,
    City VARCHAR(100) NOT NULL,
    FOREIGN KEY (DepartmentID) REFERENCES DEPT(DepartmentID)
);

INSERT INTO DEPT VALUES (1, 'Admin', 'Adm', 'A-Block');
INSERT INTO DEPT VALUES (2, 'Computer', 'CE', 'C-Block');
INSERT INTO DEPT VALUES (3, 'Civil', 'CI', 'G-Block');
INSERT INTO DEPT VALUES (4, 'Electrical', 'EE', 'E-Block');
INSERT INTO DEPT VALUES (5, 'Mechanical', 'ME', 'B-Block');

INSERT INTO PERSON VALUES (101, 'Rahul Tripathi', 2, 56000, '2000-01-01', 'Rajkot');
INSERT INTO PERSON VALUES (102, 'Hardik Pandya', 3, 18000, '2001-09-25', 'Ahmedabad');
INSERT INTO PERSON VALUES (103, 'Bhavin Kanani', 4, 25000, '2000-05-14', 'Baroda');
INSERT INTO PERSON VALUES (104, 'Bhoomi Vaishnav', 1, 39000, '2005-02-08', 'Rajkot');
INSERT INTO PERSON VALUES (105, 'Rohit Topiya', 2, 17000, '2001-07-23', 'Jamnagar');
INSERT INTO PERSON VALUES (106, 'Priya Menpara', NULL, 9000, '2000-10-18', 'Ahmedabad');
INSERT INTO PERSON VALUES (107, 'Neha Sharma', 3, 34000, '2002-12-25', 'Rajkot');
INSERT INTO PERSON VALUES (108, 'Nayan Goswami', 3, 25000, '2001-07-01', 'Rajkot');
INSERT INTO PERSON VALUES (109, 'Mehul Bhundiya', 4, 13500, '2005-01-09', 'Baroda');
INSERT INTO PERSON VALUES (110, 'Mohit Maru', 5, 14000, '2000-05-25', 'Jamnagar');

                                                    --PART A--

-- Find all persons with their department name & code.--
SELECT PERSON.PersonName, DEPT.DepartmentName, DEPT.DepartmentCode
FROM PERSON INNER JOIN DEPT
ON PERSON.DepartmentID = DEPT.DepartmentID;

-- Find the person's name whose department is in C-Block.--
SELECT PERSON.PersonName
FROM PERSON INNER JOIN DEPT
ON PERSON.DepartmentID = DEPT.DepartmentID
WHERE DEPT.Location = 'C-Block';

-- Retrieve person name, salary & department name who belongs to Jamnagar city.--
SELECT PERSON.PersonName, PERSON.Salary, DEPT.DepartmentName
FROM PERSON INNER JOIN DEPT
ON PERSON.DepartmentID = DEPT.DepartmentID
WHERE PERSON.City = 'Jamnagar';

-- Retrieve person name, salary & department name who does not belong to Rajkot city.--
SELECT PERSON.PersonName, PERSON.Salary, DEPT.DepartmentName
FROM PERSON INNER JOIN DEPT
ON PERSON.DepartmentID = DEPT.DepartmentID
WHERE PERSON.City <> 'Rajkot';

-- Retrieve person’s name of the person who joined the Civil department after 1-Aug-2001.--
SELECT PERSON.PersonName
FROM PERSON INNER JOIN DEPT
ON PERSON.DepartmentID = DEPT.DepartmentID
WHERE DEPT.DepartmentName = 'Civil' AND PERSON.JoiningDate > '2001-08-01';

-- Find details of all persons who belong to the computer department.--
SELECT *
FROM PERSON INNER JOIN DEPT
ON PERSON.DepartmentID = DEPT.DepartmentID
WHERE DEPT.DepartmentName = 'Computer';

-- Display all the person's name with the department whose joining date difference with the current date is more than 365 days.--
SELECT PERSON.PersonName, DEPT.DepartmentName
FROM PERSON INNER JOIN DEPT
ON PERSON.DepartmentID = DEPT.DepartmentID
WHERE DATEDIFF(DAY, PERSON.JoiningDate, GETDATE()) > 365;

-- Find department wise person counts.--
SELECT DEPT.DepartmentName, COUNT(PERSON.PersonID) AS PersonCount
FROM PERSON INNER JOIN DEPT
ON PERSON.DepartmentID = DEPT.DepartmentID
GROUP BY DEPT.DepartmentName;

-- Give department wise maximum & minimum salary with department name.--
SELECT DEPT.DepartmentName, MAX(PERSON.Salary) AS MaxSalary, MIN(PERSON.Salary) AS MinSalary
FROM PERSON INNER JOIN DEPT
ON PERSON.DepartmentID = DEPT.DepartmentID
GROUP BY DEPT.DepartmentName;

-- Find city wise total, average, maximum and minimum salary.--
SELECT City, SUM(Salary) AS TotalSalary, AVG(Salary) AS AverageSalary, MAX(Salary) AS MaxSalary, MIN(Salary) AS MinSalary
FROM PERSON
GROUP BY City;

-- Find the average salary of a person who belongs to Ahmedabad city.--
SELECT AVG(Salary) AS AverageSalary
FROM PERSON
WHERE City = 'Ahmedabad';

-- Produce Output Like: <PersonName> lives in <City> and works in <DepartmentName> Department. (In single column)--
SELECT CONCAT(PERSON.PersonName, ' lives in ', PERSON.City, ' and works in ', DEPT.DepartmentName, ' Department.') AS Output
FROM PERSON INNER JOIN DEPT
ON PERSON.DepartmentID = DEPT.DepartmentID;

                                                    --PART B--

-- Produce Output Like: <PersonName> earns <Salary> from <DepartmentName> department monthly. (In single column)--
SELECT CONCAT(PERSON.PersonName, ' earns ', PERSON.Salary, ' from ', DEPT.DepartmentName, ' department monthly.') AS Output
FROM PERSON INNER JOIN DEPT
ON PERSON.DepartmentID = DEPT.DepartmentID;

-- Find city & department wise total, average & maximum salaries.--
SELECT PERSON.City, DEPT.DepartmentName, SUM(PERSON.Salary) AS TotalSalary, AVG(PERSON.Salary) AS AverageSalary, MAX(PERSON.Salary) AS MaxSalary
FROM PERSON INNER JOIN DEPT
ON PERSON.DepartmentID = DEPT.DepartmentID
GROUP BY PERSON.City, DEPT.DepartmentName;

-- Find all persons who do not belong to any department.--
SELECT PersonName
FROM PERSON
WHERE DepartmentID IS NULL;

-- Find all departments whose total salary is exceeding 100000.--
SELECT DEPT.DepartmentName, SUM(PERSON.Salary) AS TotalSalary
FROM PERSON INNER JOIN DEPT
ON PERSON.DepartmentID = DEPT.DepartmentID
GROUP BY DEPT.DepartmentName
HAVING SUM(PERSON.Salary) > 100000;

                                                    --PART C--

-- List all departments who have no person.--
SELECT DEPT.DepartmentName
FROM DEPT LEFT JOIN PERSON
ON DEPT.DepartmentID = PERSON.DepartmentID
WHERE PERSON.PersonID IS NULL;

-- List out department names in which more than two persons are working.--
SELECT DEPT.DepartmentName
FROM DEPT INNER JOIN PERSON
ON DEPT.DepartmentID = PERSON.DepartmentID
GROUP BY DEPT.DepartmentName
HAVING COUNT(PERSON.PersonID) > 2;

-- Give a 10% increment in the computer department employee’s salary. (Use Update)--
UPDATE PERSON
SET Salary = Salary + (Salary * 0.10)
WHERE DepartmentID = (SELECT DepartmentID FROM DEPT WHERE DepartmentName = 'Computer');