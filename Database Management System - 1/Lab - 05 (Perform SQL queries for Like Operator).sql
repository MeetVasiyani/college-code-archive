                                                    --PART A--

CREATE TABLE STUDENT (
    StuID INT,
    FirstName VARCHAR(25),
    LastName VARCHAR(25),
    Website VARCHAR(50),
    City VARCHAR(25),
    Address VARCHAR(100)
);

INSERT INTO STUDENT VALUES (1011, 'Keyur', 'Patel', 'techonthenet.com', 'Rajkot', 'A-303 "Vasant Kunj", Rajkot');
INSERT INTO STUDENT VALUES (1022, 'Hardik', 'Shah', 'digminecraft.com', 'Ahmedabad', '"Ram Krupa", Raiya Road');
INSERT INTO STUDENT VALUES (1033, 'Kajal', 'Trivedi', 'bigactivities.com', 'Baroda', 'Raj bhavan plot, near garden');
INSERT INTO STUDENT VALUES (1044, 'Bhoomi', 'Gajera', 'checkyourmath.com', 'Ahmedabad', '"Jig''s Home", Narol');
INSERT INTO STUDENT VALUES (1055, 'Harmit', 'Mitel', '@me.darshan.com', 'Rajkot', 'B-55, Raj Residency');
INSERT INTO STUDENT VALUES (1066, 'Ashok', 'Jani', NULL, 'Baroda', 'A502, Club House Building');


--Display the name of students whose name starts with ‘k’--
SELECT * FROM STUDENT WHERE NAME LIKE 'k%';

--Display the name of students whose name consists of five characters.--
SELECT * FROM STUDENT WHERE NAME LIKE '_____';

--Retrieve the first name & last name of students whose city name ends with a & contains six characters.--
SELECT  FIRSTNAME,LASTNAME FROM STUDENT WHERE CITY LIKE '%a' AND CITY LIKE '______';

--Display all the students whose last name ends with ‘tel’.--
SELECT * FROM STUDENT WHERE LASTNAME LIKE '%tel';

--Display all the students whose first name starts with ‘ha’ & ends with‘t’.--
SELECT * FROM STUDENT WHERE NAME LIKE 'ha%' AND NAME LIKE '%t';

--Display all the students whose first name starts with ‘k’ and third character is ‘y’.--
SELECT * FROM STUDENT WHERE NAME LIKE 'k_y%';

--Display the name of students having no website and name consists of five characters.--
SELECT FIRSTNAME FROM STUDENT WHERE WEBSITE IS NULL AND NAME LIKE '_____';

--Display all the students whose last name consist of ‘jer’--
SELECT * FROM STUDENT WHERE NAME LIKE '%jer%';

--Display all the students whose city name starts with either ‘r’ or ‘b’.--
SELECT * FROM STUDENT WHERE CITY LIKE 'r%' OR CITY LIKE 'b%';

--Display all the name students having websites.--
SELECT * FROM STUDENT WHERE WEBSITE IS NOT NULL;

--Display all the students whose name starts from alphabet A to H.--
SELECT * FROM STUDENT WHERE NAME LIKE '[A-H]%';

--Display all the students whose name’s second character is vowel.--
SELECT * FROM STUDENT WHERE NAME LIKE '_[a,e,i,o,u]%';

--Display the name of students having no website and name consists of minimum five characters.--
SELECT FIRSTNAME FROM STUDENT WHERE WEBSITE IS NULL AND NAME LIKE '_____%';

--Display all the students whose last name starts with ‘Pat’.--
SELECT * FROM STUDENT WHERE NAME LIKE 'Pat%';

--Display all the students whose city name does not starts with ‘b’.--
SELECT * FROM STUDENT WHERE CITY NOT LIKE 'b%';

                                                    --PART B--

--Display all the students whose name starts from alphabet A or H.--
SELECT * FROM STUDENT WHERE NAME LIKE '[A-H]%';

--Display all the students whose name’s second character is vowel and of and start with H.--
SELECT * FROM STUDENT WHERE NAME LIKE '_[a,e,i,o,u]%';

--Display all the students whose last name does not ends with ‘a’.--
SELECT * FROM STUDENT WHERE NAME NOT LIKE '%a';

--Display all the students whose first name starts with consonant.--
SELECT * FROM STUDENT WHERE FIRSTNAME LIKE '[a,e,i,o,u]%';

--Display all the students whose website contains .net--
SELECT * FROM STUDENT WHERE WEBSITE LIKE '%.net%';

                                                    --PART C--

--Display all the students whose address consist of -.--
SELECT * FROM STUDENT WHERE ADDRESS LIKE '%-%';

--Display all the students whose address contains single quote or double quote.--
SELECT * FROM STUDENT WHERE Address LIKE '%''%' OR Address LIKE '%"%' ;

--Display all the names those are either four or five characters.--
SELECT * FROM STUDENT WHERE NAME LIKE '____' OR NAME LIKE '_____';