                                                    --MATH FUNCTIONS - PART A--
--Display the result of 5 multiply by 30.--
SELECT 5 * 30;

--Find out the absolute value of -25, 25, -50 and 50.--
SELECT ABS(-25), ABS(25), ABS(-50), ABS(50);

--Find smallest integer value that is greater than or equal to 25.2, 25.7 and -25.2.--
SELECT CEILING(25.2), CEILING(25.7), CEILING(-25.2);

--Find largest integer value that is smaller than or equal to 25.2, 25.7 and -25.2.--
SELECT FLOOR(25.2), FLOOR(25.7), FLOOR(-25.2);

--Find out remainder of 5 divided 2 and 5 divided by 3.--
SELECT 5 % 2, 5 % 3;

-- Find out value of 3 raised to 2nd power and 4 raised 3rd power.--
SELECT POWER(3, 2), POWER(4, 3);

-- Find out the square root of 25, 30 and 50.--
SELECT SQRT(25), SQRT(30), SQRT(50);

-- Find out the square of 5, 15, and 25.--
SELECT SQUARE(5), SQUARE(15), SQUARE(25);

-- Find out the value of PI.--
SELECT PI();

-- Find out round value of 157.732 for 2, 0 and -2 decimal points.--
SELECT ROUND(157.732, 2), ROUND(157.732, 0), ROUND(157.732, -2);

-- Find out exponential value of 2 and 3.--
SELECT EXP(2), EXP(3);

-- Find out logarithm having base e of 10 and 2.--
SELECT LOG(10), LOG(2);

-- Find out logarithm having base b having value 10 of 5 and 100.--
SELECT  LOG10(5) , LOG10(100);

-- Find sine, cosine and tangent of 3.1415.--
SELECT SIN(3.1415), COS(3.1415), TAN(3.1415);

-- Find sign of -25, 0 and 25.--
SELECT SIGN(-25), SIGN(0), SIGN(25);

-- Generate random number using function.--
SELECT RAND();

                                                    --MATH FUNCTIONS - PART B--

CREATE TABLE EMP_MASTER (
    EmpNo INT,
    EmpName CHAR(15),
    JoiningDate DATE,
    Salary DECIMAL(7, 2),
    Commission INT,
    City CHAR(15),
    DeptCode VARCHAR(10)
);

INSERT INTO EMP_MASTER VALUES (101, 'Keyur', '2002-01-05', 12000.00, 4500, 'Rajkot', '3@g');
INSERT INTO EMP_MASTER VALUES (102, 'Hardik', '2004-02-15', 14000.00, 2500, 'Ahmedabad', '3@');
INSERT INTO EMP_MASTER VALUES (103, 'Kajal', '2006-03-14', 15000.00, 3000, 'Baroda', '3-GD');
INSERT INTO EMP_MASTER VALUES (104, 'Bhoomi', '2005-06-23', 12500.00, 1000, 'Ahmedabad', '1A3D');
INSERT INTO EMP_MASTER VALUES (105, 'Harmit', '2004-02-15', 14000.00, 2000, 'Rajkot', '312A');

-- Display the result of Salary plus Commission.--
SELECT Salary + Commission FROM EMP_MASTER;

-- Find smallest integer value that is greater than or equal to 55.2, 35.7 and -55.2.--
SELECT CEILING(55.2), CEILING(35.7), CEILING(-55.2);

-- Find largest integer value that is smaller than or equal to 55.2, 35.7 and -55.2.--
SELECT FLOOR(55.2), FLOOR(35.7), FLOOR(-55.2);

-- Find out remainder of 55 divided 2 and 55 divided by 3.--
SELECT 55 % 2, 55 % 3;

-- Find out value of 23 raised to 2nd power and 14 raised 3rd power.--
SELECT POWER(23, 2), POWER(14, 3);

                                                    --MATH FUNCTIONS - PART C--

-- Find out the square root of 36, 49 and 81.--
SELECT SQRT(36), SQRT(49), SQRT(81);

-- Find out the square of 3, 9, and 12.--
SELECT SQUARE(3), SQUARE(9), SQUARE(12);

-- Find out round value of 280.8952 for 2, 0 and -2 decimal points.--
SELECT ROUND(280.8952, 2), ROUND(280.8952, 0), ROUND(280.8952, -2);

-- Find sine, cosine and tangent of 4.2014.--
SELECT SIN(4.2014), COS(4.2014), TAN(4.2014);

-- Find sign of -55, 0 and 95.--
SELECT SIGN(-55), SIGN(0), SIGN(95);

                                                    --STRING FUNCTIONS - PART A--

-- Find the length of following. (I) NULL (II) ‘ hello ’ (III) Blank--
SELECT LEN(NULL), LEN('HELLO'), LEN('BLANK');

-- Display your name in lower & upper case.--
SELECT LOWER('MEET VASIYANI'), UPPER('meet vasiyani');

-- Display first three characters of your name.--
SELECT LEFT('MEET VASIYANI', 3);

-- Display 3rd to 10th character of your name.--
SELECT SUBSTRING('MEET VASIYANI', 3, 8);

-- Write a query to convert ‘abc123efg’ to ‘abcXYZefg’ & ‘abcabcabc’ to ‘ab5ab5ab5’ using REPLACE.--
SELECT REPLACE('abc123efg', '123', 'XYZ'), REPLACE('abcabcabc', 'abc', 'ab5');

-- Write a query to display ASCII code for ‘a’,’A’,’z’,’Z’, 0, 9.--
SELECT ASCII('a'), ASCII('A'), ASCII('z'), ASCII('Z'), ASCII(0), ASCII(9);

-- Write a query to display character based on number 97,65,122,90,48,57.--
SELECT CHAR(97), CHAR(65), CHAR(122), CHAR(90), CHAR(48), CHAR(57);

-- Write a query to remove spaces from left of a given string ‘hello world ‘.--
SELECT LTRIM(' hello world ');

-- Write a query to remove spaces from right of a given string ‘ hello world ‘.--
SELECT RTRIM(' hello world ');

-- Write a query to display first 4 & Last 5 characters of ‘SQL Server’.--
SELECT LEFT('SQL Server', 4), RIGHT('SQL Server', 5);

-- Write a query to convert a string ‘1234.56’ to number (Use cast and convert function).--
SELECT CAST('1234.56' AS DECIMAL(5, 2));
SELECT CONVERT(DECIMAL(5, 2), '1234.56');

-- Write a query to convert a float 10.58 to integer (Use cast and convert function).--
SELECT CAST(10.58 AS INT);
SELECT CONVERT(INT, 10.58);

-- Put 10 space before your name using function.--
SELECT SPACE(10) + 'MEET VASIYANI';

-- Combine two strings using + sign as well as CONCAT ().--
SELECT 'MEET' + ' VASIYANI';
SELECT CONCAT('MEET', ' VASIYANI');

-- Find reverse of “Darshan”.--
SELECT REVERSE('Darshan');

-- Repeat your name 3 times.--
SELECT REPLICATE('MEET VASIYANI', 3);

                                                    --STRING FUNCTIONS - PART B--

-- Find the length of FirstName and LastName columns.--
SELECT LEN(FirstName), LEN(LastName) FROM STUDENT;

-- Display FirstName and LastName columns in lower & upper case.--
SELECT LOWER(FirstName), LOWER(LastName), UPPER(FirstName), UPPER(LastName) FROM STUDENT;

-- Display first three characters of FirstName column.--
SELECT LEFT(FirstName, 3) FROM STUDENT;

-- Display 3rd to 10th character of Website column.--
SELECT SUBSTRING(Website, 3, 8) FROM STUDENT;

-- Write a query to display first 4 & Last 5 characters of Website column.--
SELECT LEFT(Website, 4), RIGHT(Website, 5) FROM STUDENT;


                                                    --STRING FUNCTIONS - PART C--


-- Put 10 space before FirstName using function.--
SELECT SPACE(10) + FirstName FROM STUDENT;

-- Combine FirstName and LastName columns using + sign as well as CONCAT ().--
SELECT FirstName + ' ' + LastName FROM STUDENT;
SELECT CONCAT(FirstName, ' ', LastName) FROM STUDENT;

-- Combine all columns using + sign as well as CONCAT ().--
SELECT StuID + ' ' + FirstName + ' ' + LastName + ' ' + Website + ' ' + City + ' ' + Address FROM STUDENT;
SELECT CONCAT(StuID , ' ', FirstName, ' ', LastName, ' ', Website, ' ', City, ' ', Address) FROM STUDENT;

-- Find reverse of FirstName column.--
SELECT StuID, FirstName, REVERSE(FirstName) AS ReversedFirstName FROM STUDENT;

-- Repeat FirstName column 3 times--
SELECT StuID, FirstName, REPLICATE(FirstName, 3) AS RepeatedFirstName FROM STUDENT;

-- Give the Names which contains 5 characters.--
SELECT StuID, FirstName FROM STUDENT WHERE LEN(FirstName) = 5;

-- Combine the result as <FirstName> Lives in <City>.--
SELECT CONCAT(FirstName, ' Lives in ', City) AS CombinedResult FROM STUDENT;

-- Combine the result as Student_ID of < FirstName > is <StuID> .--
SELECT CONCAT('Student_ID of ', FirstName, ' is ', StuID) AS CombinedResult FROM STUDENT;

                                                    --DATE FUNCTIONS - PART A--

-- Write a query to display the current date & time. Label the column Today_Date.--
SELECT GETDATE() AS Today_Date;

-- Write a query to find new date after 365 day with reference to today.--
SELECT DATEADD(DAY, 365, GETDATE());

-- Display the current date in a format that appears as may 5 1994 12:00AM.--
SELECT CONVERT(VARCHAR(30), GETDATE(), 106);
SELECT FORMAT(GETDATE(), 'MMM dd yyyy hh:mm tt');

-- Display the current date in a format that appears as 03 Jan 1995.--
SELECT CONVERT(VARCHAR(30), GETDATE(), 103);
SELECT FORMAT(GETDATE(), 'dd MMM yyyy');

-- Display the current date in a format that appears as Jan 04, 96.--
SELECT CONVERT(VARCHAR(30), GETDATE(), 101);
SELECT FORMAT(GETDATE(), 'MMM dd, yy');

-- Write a query to find out total number of months between 31-Dec-08 and 31-Mar-09.--
SELECT DATEDIFF(MONTH, '2008-12-31', '2009-03-31');

-- Write a query to find out total number of years between 25-Jan-12 and 14-Sep-10.--
SELECT DATEDIFF(YEAR, '2012-01-25', '2010-09-14');

-- Write a query to find out total number of hours between 25-Jan-12 7:00 and 26-Jan-12 10:30.--
SELECT DATEDIFF(HOUR, '2012-01-25 07:00', '2012-01-26 10:30');

-- Write a query to extract Day, Month, Year from given date 12-May-16.--
SELECT DAY('2016-05-12'), MONTH('2016-05-12'), YEAR('2016-05-12');

-- Write a query that adds 5 years to current date.--
SELECT DATEADD(YEAR, 5, GETDATE());

-- Write a query to subtract 2 months from current date.--
SELECT DATEADD(MONTH, -2, GETDATE());

-- Extract month from current date using datename () and datepart () function.--
SELECT DATENAME(MONTH, GETDATE());
SELECT DATEPART(MONTH, GETDATE());

-- Write a query to find out last date of current month.--
SELECT EOMONTH(GETDATE());

-- Calculate your age in years and months.--
SELECT DATEDIFF(YEAR, '1999-05-23', GETDATE()) AS AgeInYears, DATEDIFF(MONTH, '1999-05-23', GETDATE()) AS AgeInMonths;

                                                    --DATE FUNCTIONS - PART B--

CREATE TABLE EMP_DETAIL (
    EmpNo INT,
    EmpName VARCHAR(50),
    JoiningDate DATE,
    Salary DECIMAL(10, 2),
    City VARCHAR(50)
);

INSERT INTO EMP_DETAIL VALUES (101, 'Keyur', '2002-01-15', 12000.00, 'Rajkot');
INSERT INTO EMP_DETAIL VALUES (102, 'Hardik', '2004-02-15', 14000.00, 'Ahmedabad');
INSERT INTO EMP_DETAIL VALUES (103, 'Kajal', '2006-03-14', 15000.00, 'Baroda');
INSERT INTO EMP_DETAIL VALUES (104, 'Bhoomi', '2005-06-23', 12500.00, 'Ahmedabad');
INSERT INTO EMP_DETAIL VALUES (105, 'Harmit', '2004-02-15', 14000.00, 'Rajkot');
INSERT INTO EMP_DETAIL VALUES (106, 'Jay', '2007-03-12', 12000.00, 'Surat');

-- Write a query to find new date after 365 day with reference to JoiningDate.--
SELECT DATEADD(DAY, 365, JoiningDate) FROM EMP_DETAIL;

-- Display the JoiningDate in a format that appears as may 5 1994 12:00AM.--
SELECT FORMAT(JoiningDate, 'MMM dd yyyy hh:mm tt') FROM EMP_DETAIL;

-- Display the JoiningDate in a format that appears as 03 Jan 1995.--
SELECT FORMAT(JoiningDate, 'dd MMM yyyy') FROM EMP_DETAIL;
SELECT CONVERT(VARCHAR(30), JoiningDate, 103);

-- Display the JoiningDate in a format that appears as Jan 04, 96.--
SELECT FORMAT(JoiningDate, 'MMM dd, yy') FROM EMP_DETAIL;
SELECT CONVERT(VARCHAR(30), JoiningDate, 101);

-- Write a query to find out total number of months between JoiningDate and 31-Mar-09.--
SELECT DATEDIFF(MONTH, JoiningDate, '2009-03-31') FROM EMP_DETAIL;

-- Write a query to find out total number of years between JoiningDate and 14-Sep-10.--
SELECT DATEDIFF(YEAR, JoiningDate, '2010-09-14') FROM EMP_DETAIL;

                                                    --DATE FUNCTIONS - PART C--

-- Write a query to extract Day, Month, Year from JoiningDate.--
SELECT DAY(JoiningDate), MONTH(JoiningDate), YEAR(JoiningDate) FROM EMP_DETAIL;

-- Write a query that adds 5 years to JoiningDate.--
SELECT DATEADD(YEAR, 5, JoiningDate) FROM EMP_DETAIL;

-- Write a query to subtract 2 months from JoiningDate.--
SELECT DATEADD(MONTH, -2, JoiningDate) FROM EMP_DETAIL;

-- Extract month from JoiningDate using datename () and datepart () function.--
SELECT DATENAME(MONTH, JoiningDate) FROM EMP_DETAIL;
SELECT DATEPART(MONTH, JoiningDate) FROM EMP_DETAIL;

-- Calculate your age in years and months.--
SELECT DATEDIFF(YEAR, JoiningDate, GETDATE()) AS AgeInYears, DATEDIFF(MONTH, JoiningDate, GETDATE()) AS AgeInMonths FROM EMP_DETAIL;