CREATE TABLE STU_INFO (
    Rno INT,
    Name VARCHAR(50),
    Branch VARCHAR(10)
);

INSERT INTO STU_INFO VALUES (101, 'Raju', 'CE');
INSERT INTO STU_INFO VALUES (102, 'Amit', 'CE');
INSERT INTO STU_INFO VALUES (103, 'Sanjay', 'ME');
INSERT INTO STU_INFO VALUES (104, 'Neha', 'EC');
INSERT INTO STU_INFO VALUES (105, 'Meera', 'EE');
INSERT INTO STU_INFO VALUES (106, 'Mahesh', 'ME');

CREATE TABLE RESULT (
    Rno INT,
    SPI DECIMAL(3,1)
);

INSERT INTO RESULT VALUES (101, 8.8);
INSERT INTO RESULT VALUES (102, 9.2);
INSERT INTO RESULT VALUES (103, 7.6);
INSERT INTO RESULT VALUES (104, 8.2);
INSERT INTO RESULT VALUES (105, 7.0);
INSERT INTO RESULT VALUES (107, 8.9);

CREATE TABLE EMPLOYEE_MASTER (
    EmployeeNo VARCHAR(10) PRIMARY KEY,
    Name VARCHAR(50),
    ManagerNo VARCHAR(10),
);

INSERT INTO EMPLOYEE_MASTER VALUES ('E01', 'Tarun', NULL);
INSERT INTO EMPLOYEE_MASTER VALUES ('E02', 'Rohan', 'E02');
INSERT INTO EMPLOYEE_MASTER VALUES ('E03', 'Priya', 'E01');
INSERT INTO EMPLOYEE_MASTER VALUES ('E04', 'Milan', 'E03');
INSERT INTO EMPLOYEE_MASTER VALUES ('E05', 'Jay', 'E01');
INSERT INTO EMPLOYEE_MASTER VALUES ('E06', 'Anjana', 'E04');

                                                    --PART A--

-- Combine information from student and result table using cross join or Cartesian product.--
SELECT * FROM STU_INFO CROSS JOIN RESULT;

-- Perform inner join on Student and Result tables.--
SELECT * FROM STU_INFO INNER JOIN RESULT ON STU_INFO.Rno = RESULT.Rno;

-- Perform the left outer join on Student and Result tables.--
SELECT * FROM STU_INFO LEFT OUTER JOIN RESULT ON STU_INFO.Rno = RESULT.Rno;

-- Perform the right outer join on Student and Result tables.--
SELECT * FROM STU_INFO RIGHT OUTER JOIN RESULT ON STU_INFO.Rno = RESULT.Rno;

-- Perform the full outer join on Student and Result tables.--
SELECT * FROM STU_INFO FULL OUTER JOIN RESULT ON STU_INFO.Rno = RESULT.Rno;

-- Display Rno, Name, Branch and SPI of all students.--
SELECT STU_INFO.Rno, STU_INFO.Name, STU_INFO.Branch, RESULT.SPI FROM STU_INFO INNER JOIN RESULT ON STU_INFO.Rno = RESULT.Rno;

-- Display Rno, Name, Branch and SPI of CE branch’s student only.--
SELECT STU_INFO.Rno, STU_INFO.Name, STU_INFO.Branch, RESULT.SPI FROM STU_INFO INNER JOIN RESULT ON STU_INFO.Rno = RESULT.Rno WHERE STU_INFO.Branch = 'CE';

-- Display Rno, Name, Branch and SPI of other than EC branch’s student only.--
SELECT STU_INFO.Rno, STU_INFO.Name, STU_INFO.Branch, RESULT.SPI FROM STU_INFO INNER JOIN RESULT ON STU_INFO.Rno = RESULT.Rno WHERE STU_INFO.Branch <> 'EC';

-- Display average result of each branch.--
SELECT STU_INFO.Branch, AVG(RESULT.SPI) AS Average_SPI FROM STU_INFO INNER JOIN RESULT ON STU_INFO.Rno = RESULT.Rno GROUP BY STU_INFO.Branch;

-- Display average result of CE and ME branch.--
SELECT STU_INFO.Branch, AVG(RESULT.SPI) AS Average_SPI FROM STU_INFO INNER JOIN RESULT ON STU_INFO.Rno = RESULT.Rno WHERE STU_INFO.Branch IN ('CE', 'ME') GROUP BY STU_INFO.Branch;

                                                    --PART B--

-- Display average result of each branch and sort them in ascending order by SPI.
SELECT STU_INFO.Branch, AVG(RESULT.SPI) AS Average_SPI FROM STU_INFO INNER JOIN RESULT ON STU_INFO.Rno = RESULT.Rno GROUP BY STU_INFO.Branch ORDER BY Average_SPI ASC;

-- Display highest SPI from each branch and sort them in descending order.--
SELECT STU_INFO.Branch, MAX(RESULT.SPI) AS Highest_SPI FROM STU_INFO INNER JOIN RESULT ON STU_INFO.Rno = RESULT.Rno GROUP BY STU_INFO.Branch ORDER BY Highest_SPI DESC;

                                                    --PART C--

--Retrieve the names of employee along with their manager’s name from the Employee table.--
SELECT e.Name AS EmployeeName,
       m.Name AS ManagerName
FROM EMPLOYEE_MASTER AS e
JOIN EMPLOYEE_MASTER AS m
ON e.ManagerNo = m.EmployeeNo;


                                                    --EXTRA QUESTIONS--

CREATE TABLE [dbo].[CUSTOMER2](
	[customer_id] [int] NULL,
	[cust_name] [varchar](30) NULL,
	[city] [varchar](30) NULL,
	[Grade] [int] NULL,
	[salesman_id] [int] NULL
) ON [PRIMARY];

INSERT CUSTOMER2 VALUES (3002, N'Nick Rimando', N'New York', 100, 5001)
INSERT CUSTOMER2 VALUES (3007, N'Brad Davis', N'New York', 200, 5001)
INSERT CUSTOMER2 VALUES (3005, N'Graham Zusi', N'California', 200, 5002)
INSERT CUSTOMER2 VALUES (3008, N'Julian Green', N'London', 300, 5002)
INSERT CUSTOMER2 VALUES (3004, N'Fabian Johnson', N'Paris', 300, 5006)
INSERT CUSTOMER2 VALUES (3009, N'Geoff Cameron', N'Berlin', 100, 5003)
INSERT CUSTOMER2 VALUES (3003, N'Jozy Altidor', N'Moscow', 200, 5007)
INSERT CUSTOMER2 VALUES (3001, N'Brad Guzan', N'London', NULL, 5005)
INSERT CUSTOMER2 VALUES (4001, N'abc', N'ABC', 900, NULL)

CREATE TABLE [dbo].[ORDERS](
	[ord_no] [int] NULL,
	[purch_amt] [decimal](8, 2) NULL,
	[ord_date] [datetime] NULL,
	[customer_id] [int] NULL,
	[salesman_id] [int] NULL
) ON [PRIMARY];

INSERT ORDERS VALUES (70001, CAST(150.50 AS Decimal(8, 2)), CAST(N'2012-12-05 00:00:00.000' AS DateTime), 3005, 5002)
INSERT ORDERS VALUES (70009, CAST(270.65 AS Decimal(8, 2)), CAST(N'2012-11-10 00:00:00.000' AS DateTime), 3001, 5005)
INSERT ORDERS VALUES (70001, CAST(65.26 AS Decimal(8, 2)), CAST(N'2012-10-05 00:00:00.000' AS DateTime), 3002, 5001)
INSERT ORDERS VALUES (70004, CAST(110.50 AS Decimal(8, 2)), CAST(N'2012-08-17 00:00:00.000' AS DateTime), 3009, 5003)
INSERT ORDERS VALUES (70007, CAST(948.50 AS Decimal(8, 2)), CAST(N'2012-11-10 00:00:00.000' AS DateTime), 3005, 5002)
INSERT ORDERS VALUES (70005, CAST(2400.60 AS Decimal(8, 2)), CAST(N'2012-07-27 00:00:00.000' AS DateTime), 3007, 5001)
INSERT ORDERS VALUES (70008, CAST(5760.00 AS Decimal(8, 2)), CAST(N'2012-11-10 00:00:00.000' AS DateTime), 3002, 5001)
INSERT ORDERS VALUES (70010, CAST(1983.43 AS Decimal(8, 2)), CAST(N'2012-10-10 00:00:00.000' AS DateTime), 3004, 5006)
INSERT ORDERS VALUES (70003, CAST(2480.40 AS Decimal(8, 2)), CAST(N'2012-10-10 00:00:00.000' AS DateTime), 3009, 5003)
INSERT ORDERS VALUES (70012, CAST(250.45 AS Decimal(8, 2)), CAST(N'2012-06-27 00:00:00.000' AS DateTime), 3008, 5002)
INSERT ORDERS VALUES (70011, CAST(75.29 AS Decimal(8, 2)), CAST(N'2012-08-17 00:00:00.000' AS DateTime), 3003, 5007)
INSERT ORDERS VALUES (70013, CAST(3045.60 AS Decimal(8, 2)), CAST(N'2012-04-25 00:00:00.000' AS DateTime), 3002, 5001)
INSERT ORDERS VALUES (70001, CAST(150.50 AS Decimal(8, 2)), CAST(N'2012-12-05 00:00:00.000' AS DateTime), 3005, 5002)
INSERT ORDERS VALUES (70009, CAST(270.65 AS Decimal(8, 2)), CAST(N'2012-11-10 00:00:00.000' AS DateTime), 3001, 5005)
INSERT ORDERS VALUES (70001, CAST(65.26 AS Decimal(8, 2)), CAST(N'2012-10-05 00:00:00.000' AS DateTime), 3002, 5001)

CREATE TABLE [dbo].[SALESMAN](
	[salesman_id] [int] NULL,
	[name] [varchar](30) NULL,
	[city] [varchar](30) NULL,
	[commission] [decimal](4, 2) NULL
) ON [PRIMARY];

INSERT SALESMAN VALUES (5001, N'James Hoog', N'New York', CAST(0.15 AS Decimal(4, 2)))
INSERT SALESMAN VALUES (5002, N'Nail Knite', N'Paris', CAST(0.13 AS Decimal(4, 2)))
INSERT SALESMAN VALUES (5005, N'Pit Alex', N'London', CAST(0.11 AS Decimal(4, 2)))
INSERT SALESMAN VALUES (5006, N'Mc Lyon', N'Paris', CAST(0.14 AS Decimal(4, 2)))
INSERT SALESMAN VALUES (5007, N'Paul Adam', N'Rome', CAST(0.13 AS Decimal(4, 2)))
INSERT SALESMAN VALUES (5003, N'Lauson Hen', N'San Jose', CAST(0.12 AS Decimal(4, 2)))

--From the above given tables perform the following SQL queries (Join):

--1. Write a SQL query to find the salesperson and customer who reside in the same city. Return Salesman, cust_name and city.--
SELECT s.name AS Salesman, c.cust_name, c.city
FROM SALESMAN AS s
JOIN CUSTOMER2 AS c
ON s.city = c.city;

--2. Write a SQL query to find those orders where the order amount exists between 500 and 2000. Return ord_no, purch_amt, cust_name, city.--
SELECT o.ord_no, o.purch_amt, c.cust_name, c.city
FROM ORDERS AS o
JOIN CUSTOMER2 AS c
ON o.customer_id = c.customer_id
WHERE o.purch_amt BETWEEN 500 AND 2000;

--3. Write a SQL query to find the salesperson(s) and the customer(s) he represents. Return Customer Name,city, Salesman, commission.--
SELECT c.cust_name, c.city, s.name AS Salesman, s.commission
FROM CUSTOMER2 AS c
JOIN SALESMAN AS s
ON c.salesman_id = s.salesman_id;

--4. Write a SQL query to find salespeople who received commissions of more than 12 percent from the company. Return Customer Name, customer city, Salesman, commission.--
SELECT c.cust_name, c.city, s.name AS Salesman, s.commission
FROM CUSTOMER2 AS c
JOIN SALESMAN AS s
ON c.salesman_id = s.salesman_id
WHERE s.commission > 0.12;

--5. Write a SQL query to locate those salespeople who do not live in the same city where their customers live and have received a commission of more than 12% from the company. Return Customer Name, customer city, Salesman, salesman city, commission.--
SELECT c.cust_name, c.city, s.name AS Salesman, s.city AS SalesmanCity, s.commission
FROM CUSTOMER2 AS c
JOIN SALESMAN AS s
ON c.salesman_id = s.salesman_id
WHERE s.city <> c.city AND s.commission > 0.12;

--6. Write a SQL query to find the details of an order. Return ord_no, ord_date, purch_amt, Customer Name,grade,Salesman, commission.--
SELECT o.ord_no, o.ord_date, o.purch_amt, c.cust_name, c.Grade, s.name AS Salesman, s.commission
FROM ORDERS AS o
JOIN CUSTOMER2 AS c
ON o.customer_id = c.customer_id
JOIN SALESMAN AS s
ON o.salesman_id = s.salesman_id;

--7. Write a SQL statement to join the tables salesman, customer and orders so that the same column of each table appears once and only the relational rows are returned.--
SELECT *
FROM SALESMAN AS s
JOIN CUSTOMER2 AS c
ON s.salesman_id = c.salesman_id
JOIN ORDERS AS o
ON c.customer_id = o.customer_id;

--8. Write a SQL query to display the customer name, customer city, grade, salesman, salesman city. The results should be sorted by ascending customer_id.--
SELECT c.cust_name, c.city, c.Grade, s.name AS Salesman, s.city AS SalesmanCity
FROM CUSTOMER2 AS c
JOIN SALESMAN AS s
ON c.salesman_id = s.salesman_id
ORDER BY c.customer_id;

--9. Write a SQL query to find those customers with a grade less than 300. Return cust_name, customer city,grade, Salesman, salesmancity. The result should be ordered by ascending customer_id.--
SELECT c.cust_name, c.city, c.Grade, s.name AS Salesman, s.city AS SalesmanCity
FROM CUSTOMER2 AS c
JOIN SALESMAN AS s
ON c.salesman_id = s.salesman_id
WHERE c.Grade < 300
ORDER BY c.customer_id;

--10. Write a SQL statement to make a report with customer name, city, order number, order date, and order amount in ascending order according to the order date to determine whether any of the existing customers have placed an order or not.--
SELECT c.cust_name, c.city, o.ord_no, o.ord_date, o.purch_amt
FROM CUSTOMER2 AS c
LEFT JOIN ORDERS AS o
ON c.customer_id = o.customer_id
ORDER BY o.ord_date;