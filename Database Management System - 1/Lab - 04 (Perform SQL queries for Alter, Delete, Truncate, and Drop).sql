                                                    --ALTER OPERATION--

                                                    --PART A--

--Add two more columns City VARCHAR (20) and Pincode INT.
ALTER TABLE DEPOSIT ADD CITY VARCHAR(20),PINCODE INT;
SELECT * FROM DEPOSIT;

--Change the size of CNAME column from VARCHAR (50) to VARCHAR (35).
ALTER TABLE DEPOSIT ALTER COLUMN CNAME VARCHAR(35);
SELECT * FROM DEPOSIT;

--Change the data type DECIMAL to INT in amount Column.
ALTER TABLE DEPOSIT ALTER COLUMN AMOUNT INT;
SELECT * FROM DEPOSIT;

--Rename Column ActNo to ANO.
EXEC SP_RENAME 'DEPOSIT.ACTNO','ANO';
SELECT * FROM DEPOSIT;

--Delete Column City from the DEPOSIT table.
ALTER TABLE DEPOSIT DROP COLUMN CITY;
SELECT * FROM DEPOSIT;

--Change name of table DEPOSIT to DEPOSIT_DETAIL.
EXEC SP_RENAME 'DEPOSIT','DEPOSIT_DETAIL';
SELECT * FROM DEPOSIT_DETAIL;

                                                    --PART B--

--Rename Column ADATE to AOPENDATE OF DEPOSIT_DETAIL table.
EXEC SP_RENAME 'DEPOSIT_DETAIL.ADATE','AOPENDATE';
SELECT * FROM DEPOSIT_DETAIL;

--Delete Column AOPENDATE from the DEPOSIT_DETAIL table.
ALTER TABLE DEPOSIT_DETAIL DROP COLUMN AOPENDATE;
SELECT * FROM DEPOSIT_DETAIL;

--Rename Column CNAME to CustomerName.
EXEC SP_RENAME 'DEPOSIT_DETAIL.CNAME','CustomerName';
SELECT * FROM DEPOSIT_DETAIL;

                                                    --PART C--

CREATE TABLE STUDENT_DETAIL (
    Enrollment_No VARCHAR(20),
    Name VARCHAR(25),
    CPI DECIMAL(5,2),
    Birthdate DATETIME
);

INSERT INTO STUDENT_DETAIL VALUES ('EN001', 'John Doe', 8.50, '2000-01-15');
INSERT INTO STUDENT_DETAIL VALUES ('EN002', 'Jane Smith', 7.20, '1999-05-23');
INSERT INTO STUDENT_DETAIL VALUES ('EN003', 'Sam Brown', 9.10, '2001-07-11');
INSERT INTO STUDENT_DETAIL VALUES ('EN004', 'Alice Johnson', 8.00, '2000-03-22');
INSERT INTO STUDENT_DETAIL VALUES ('EN005', 'Bob Martin', 7.50, '1998-12-30');

SELECT * FROM STUDENT_DETAIL;

--Add two more columns City VARCHAR (20) (Not null) and Backlog INT (Null).
ALTER TABLE STUDENT_DETAIL ADD CITY VARCHAR(20) NOT NULL,BACKLOG INT;
SELECT * FROM STUDENT_DETAIL;

--Change the size of NAME column of student_detail from VARCHAR (25) to VARCHAR (35).
ALTER TABLE STUDENT_DETAIL ALTER COLUMN NAME VARCHAR(35);
SELECT * FROM STUDENT_DETAIL;

--Change the data type DECIMAL to INT in CPI Column.
ALTER TABLE STUDENT_DETAIL ALTER COLUMN CPI INT;
SELECT * FROM STUDENT_DETAIL;

--Rename Column Enrollment_No to ENO.
EXEC SP_RENAME 'STUDENT_DETAIL.Enrollment_No','ENO';
SELECT * FROM STUDENT_DETAIL;

--Delete Column City from the student_detail table.
ALTER TABLE STUDENT_DETAIL DROP COLUMN CITY;
SELECT * FROM STUDENT_DETAIL;

--Change name of table student_detail to STUDENT_MASTER.
EXEC SP_RENAME 'STUDENT_DETAIL','STUDENT_MASTER';
SELECT * FROM STUDENT_MASTER;

                                                    --DELETE, DROP, TRUNCATE OPERATION--

                                                    --PART A--


--Delete all the records of DEPOSIT_DETAIL table having amount greater than and equals to 4000.
DELETE FROM DEPOSIT_DETAIL WHERE AMOUNT >= 4000;
SELECT * FROM DEPOSIT_DETAIL;

--Delete all the accounts CHANDI BRANCH.
DELETE FROM DEPOSIT_DETAIL WHERE BRANCH = 'CHANDI';
SELECT * FROM DEPOSIT_DETAIL;

--Delete all the accounts having account number (ANO) is greater than 105.
DELETE FROM DEPOSIT_DETAIL WHERE ANO > 105;
SELECT * FROM DEPOSIT_DETAIL

--Delete all the records of Deposit_Detail table. (Use Truncate)
TRUNCATE TABLE DEPOSIT_DETAIL;
SELECT * FROM DEPOSIT_DETAIL;

--Remove Deposit_Detail table. (Use Drop)
DROP TABLE DEPOSIT_DETAIL;

                                                    --PART B--

CREATE TABLE EMPLOYEE_MASTER (
    EmpNo INT,
    EmpName VARCHAR(25),
    JoiningDate DATETIME,
    Salary DECIMAL(8,2),
    City VARCHAR(20)
);

INSERT INTO EMPLOYEE_MASTER VALUES (101, 'Keyur', '2002-01-05', 12000.00, 'Rajkot');
INSERT INTO EMPLOYEE_MASTER VALUES (102, 'Hardik', '2004-02-15', 14000.00, 'Ahmedabad');
INSERT INTO EMPLOYEE_MASTER VALUES (103, 'Kajal', '2006-03-14', 15000.00, 'Baroda');
INSERT INTO EMPLOYEE_MASTER VALUES (104, 'Bhoomi', '2005-06-23', 12500.00, 'Ahmedabad');
INSERT INTO EMPLOYEE_MASTER VALUES (105, 'Harmit', '2004-02-15', 14000.00, 'Rajkot');
INSERT INTO EMPLOYEE_MASTER VALUES (106, 'Mitesh', '2001-09-25', 5000.00, 'Jamnagar');
INSERT INTO EMPLOYEE_MASTER VALUES (107, 'Meera', NULL, 7000.00, 'Morbi');
INSERT INTO EMPLOYEE_MASTER VALUES (108, 'Kishan', '2003-02-06', 10000.00, NULL);

--Delete all the records of Employee_MASTER table having salary greater than and equals to 14000.
DELETE FROM EMPLOYEE_MASTER WHERE Salary >= 14000;
SELECT * FROM EMPLOYEE_MASTER;

--Delete all the Employees who belongs to ‘RAJKOT’ city.
DELETE FROM EMPLOYEE_MASTER WHERE City = 'Rajkot';
SELECT * FROM EMPLOYEE_MASTER;

--Delete all the Employees who joined after 1-1-2007.
DELETE FROM EMPLOYEE_MASTER WHERE JoiningDate > '2007-01-01';
SELECT * FROM EMPLOYEE_MASTER;

--Delete the records of Employees whose joining date is null and Name is not null.
DELETE FROM EMPLOYEE_MASTER WHERE JoiningDate IS NULL AND EmpName IS NOT NULL;
SELECT * FROM EMPLOYEE_MASTER;

--Delete the records of Employees whose salary is 50% of 20000.
DELETE FROM EMPLOYEE_MASTER WHERE Salary = 20000 * 0.5;
SELECT * FROM EMPLOYEE_MASTER;

--Delete the records of Employees whose City Name is not empty.
DELETE FROM EMPLOYEE_MASTER WHERE City IS NOT NULL;
SELECT * FROM EMPLOYEE_MASTER;

--Delete all the records of Employee_MASTER table. (Use Truncate)
TRUNCATE TABLE EMPLOYEE_MASTER;
SELECT * FROM EMPLOYEE_MASTER;

--Remove Employee_Master table. (Use Drop)
DROP TABLE EMPLOYEE_MASTER;


                                                    --PART C--

--Summarize Delete, Truncate and Drop

--Delete: Delete specific rows from a table based on a condition.
--Truncate: Delete all rows from a table without logging individual row deletions.
--Drop: Remove the entire table and its associated data from the database.