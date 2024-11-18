--Sub Queries--
CREATE TABLE STUDENT_DATA (
    no INT,
    Name VARCHAR(50),
    City VARCHAR(50),
    DID INT
);

CREATE TABLE ACADEMIC (
    Rno INT,
    SPI DECIMAL(3,1),
    Bklog INT
);

CREATE TABLE DEPARTMENT (
    DID INT,
    DName VARCHAR(50)
);

INSERT INTO STUDENT_DATA VALUES (101, 'Raju', 'Rajkot', 10);
INSERT INTO STUDENT_DATA VALUES (102, 'Amit', 'Ahmedabad', 20);
INSERT INTO STUDENT_DATA VALUES (103, 'Sanjay', 'Baroda', 40);
INSERT INTO STUDENT_DATA VALUES (104, 'Neha', 'Rajkot', 20);
INSERT INTO STUDENT_DATA VALUES (105, 'Meera', 'Ahmedabad', 30);
INSERT INTO STUDENT_DATA VALUES (106, 'Mahesh', 'Baroda', 10);

INSERT INTO ACADEMIC VALUES (101, 8.8, 0);
INSERT INTO ACADEMIC VALUES (102, 9.2, 2);
INSERT INTO ACADEMIC VALUES (103, 7.6, 1);
INSERT INTO ACADEMIC VALUES (104, 8.2, 4);
INSERT INTO ACADEMIC VALUES (105, 7.0, 2);
INSERT INTO ACADEMIC VALUES (106, 8.9, 3);

INSERT INTO DEPARTMENT VALUES (10, 'Computer');
INSERT INTO DEPARTMENT VALUES (20, 'Electrical');
INSERT INTO DEPARTMENT VALUES (30, 'Mechanical');
INSERT INTO DEPARTMENT VALUES (40, 'Civil');

                                                    --SUBQUERIES PART A--

-- 1. Display details of students who are from computer department.--
SELECT * FROM STUDENT_DATA WHERE DID = (SELECT DID FROM DEPARTMENT WHERE DName = 'Computer');

-- 2. Displays name of students whose SPI is more than 8.--
SELECT Name FROM STUDENT_DATA WHERE no IN (SELECT Rno FROM ACADEMIC WHERE SPI > 8);

-- 3. Display details of students of computer department who belongs to Rajkot city.--
SELECT * FROM STUDENT_DATA WHERE  DID = (SELECT DID FROM DEPARTMENT WHERE DName = 'Computer') AND City = 'Rajkot';

-- 4. Find total number of students of electrical department.--
SELECT COUNT(*) FROM STUDENT_DATA WHERE DID = (SELECT DID FROM DEPARTMENT WHERE DName = 'Electrical');

-- 5. Display name of student who is having maximum SPI.--
SELECT Name FROM STUDENT_DATA WHERE no = (SELECT Rno FROM ACADEMIC WHERE SPI = (SELECT MAX(SPI) FROM ACADEMIC));

-- 6. Display details of students having more than 1 backlog.--
SELECT * FROM STUDENT_DATA WHERE no IN (SELECT Rno FROM ACADEMIC WHERE Bklog > 1);

                                                    --SUBQUERIES PART B--

-- 1. Display name of students who are either from computer department or from mechanical department.--
SELECT Name FROM STUDENT_DATA WHERE DID IN (SELECT DID FROM DEPARTMENT WHERE DName IN ('Computer', 'Mechanical'));

-- 2. Display name of students who are in same department as 102 studying in.
SELECT Name FROM STUDENT_DATA WHERE DID = (SELECT DID FROM STUDENT_DATA WHERE no = 102);

                                                    --SUBQUERIES PART C--

-- 1. Display name of students whose SPI is more than 9 and who is from electrical department.--
SELECT Name FROM STUDENT_DATA WHERE DID IN (SELECT DID FROM DEPARTMENT WHERE DName = 'Electrical') AND no IN (SELECT Rno FROM ACADEMIC WHERE SPI > 9);

-- 2. Display name of student who is having second highest SPI.
SELECT Name FROM STUDENT_DATA WHERE no = (SELECT Rno FROM ACADEMIC WHERE SPI = (SELECT MAX(SPI) FROM ACADEMIC WHERE SPI < (SELECT MAX(SPI) FROM ACADEMIC)));

-- 3. Display city names whose students branch wise SPI is 9.2.
SELECT DISTINCT City FROM STUDENT_DATA WHERE no IN (SELECT Rno FROM ACADEMIC WHERE SPI = 9.2);

--Set Operators--
CREATE TABLE COMPUTER (
    RollNo INT PRIMARY KEY,
    Name VARCHAR(50)
);

INSERT INTO COMPUTER VALUES (101, 'Ajay');
INSERT INTO COMPUTER VALUES (109, 'Haresh');
INSERT INTO COMPUTER VALUES (115, 'Manish');

CREATE TABLE ELECTRICAL (
    RollNo INT PRIMARY KEY,
    Name VARCHAR(50)
);

INSERT INTO ELECTRICAL VALUES (105, 'Ajay');
INSERT INTO ELECTRICAL VALUES (107, 'Mahesh');
INSERT INTO ELECTRICAL VALUES (115, 'Manish');

                                                    --Set Operators PART A--

-- 1. Display name of students who is either in Computer or in Electrical.--
SELECT Name FROM COMPUTER UNION SELECT Name FROM ELECTRICAL;

-- 2. Display name of students who is either in Computer or in Electrical including duplicate data.--
SELECT Name FROM COMPUTER UNION ALL SELECT Name FROM ELECTRICAL;

-- 3. Display name of students who is in both Computer and Electrical.--
SELECT Name FROM COMPUTER INTERSECT SELECT Name FROM ELECTRICAL;

-- 4. Display name of students who are in Computer but not in Electrical.--
SELECT Name FROM COMPUTER EXCEPT SELECT Name FROM ELECTRICAL;

-- 5. Display name of students who are in Electrical but not in Computer.--
SELECT Name FROM ELECTRICAL EXCEPT SELECT Name FROM COMPUTER;

-- 6. Display all the details of students who are either in Computer or in Electrical.--
SELECT * FROM COMPUTER UNION SELECT * FROM ELECTRICAL;

-- 7. Display all the details of students who are in both Computer and Electrical.--
SELECT * FROM COMPUTER INTERSECT SELECT * FROM ELECTRICAL;

CREATE TABLE EMP_DATA (
    EID INT,
    Name VARCHAR(50)
);

INSERT INTO EMP_DATA VALUES (1, 'Ajay');
INSERT INTO EMP_DATA VALUES (9, 'Haresh');
INSERT INTO EMP_DATA VALUES (5, 'Manish');

CREATE TABLE CUSTOMER (
    CID INT,
    Name VARCHAR(50)
);

INSERT INTO CUSTOMER VALUES (5, 'Ajay');
INSERT INTO CUSTOMER VALUES (7, 'Mahesh');
INSERT INTO CUSTOMER VALUES (5, 'Manish');

                                                    --Set Operators PART B--

-- 1. Display name of persons who is either Employee or Customer.--
SELECT Name FROM EMP_DATA UNION SELECT Name FROM CUSTOMER;

-- 2. Display name of persons who is either Employee or Customer including duplicate data.--
SELECT Name FROM EMP_DATA UNION ALL SELECT Name FROM CUSTOMER;

-- 3. Display name of persons who is both Employee as well as Customer.--
SELECT Name FROM EMP_DATA INTERSECT SELECT Name FROM CUSTOMER;

-- 4. Display name of persons who are Employee but not Customer.--
SELECT Name FROM EMP_DATA EXCEPT SELECT Name FROM CUSTOMER;

-- 5. Display name of persons who are Customer but not Employee.--
SELECT Name FROM CUSTOMER EXCEPT SELECT Name FROM EMP_DATA;

                                                    --Set Operators PART C--

-- 1. Perform all the queries of Part-B but display ID and Name columns instead of Name only. --
SELECT * FROM EMP_DATA UNION SELECT * FROM CUSTOMER;
SELECT * FROM EMP_DATA UNION ALL SELECT * FROM CUSTOMER;
SELECT * FROM EMP_DATA INTERSECT SELECT * FROM CUSTOMER;
SELECT * FROM EMP_DATA EXCEPT SELECT * FROM CUSTOMER;
SELECT * FROM CUSTOMER EXCEPT SELECT * FROM EMP_DATA;