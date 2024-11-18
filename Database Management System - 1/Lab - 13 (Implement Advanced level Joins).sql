CREATE TABLE City (
    CityID INT PRIMARY KEY,
    Name VARCHAR(50) UNIQUE NOT NULL,
    Pincode INT NOT NULL,
    Remarks VARCHAR(50)
);

CREATE TABLE Village (
    VID INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    CityID INT,
    FOREIGN KEY (CityID) REFERENCES City(CityID)
);

INSERT INTO City VALUES (1, 'Rajkot', 360005, 'Good');
INSERT INTO City VALUES (2, 'Surat', 335009, 'Very Good');
INSERT INTO City VALUES (3, 'Baroda', 390001, 'Awesome');
INSERT INTO City VALUES (4, 'Jamnagar', 361003, 'Smart');
INSERT INTO City VALUES (5, 'Junagadh', 362229, 'Historic');
INSERT INTO City VALUES (6, 'Morvi', 363641, 'Ceramic');

INSERT INTO Village VALUES (101, 'Raiya', 1);
INSERT INTO Village VALUES (102, 'Madhapar', 1);
INSERT INTO Village VALUES (103, 'Dodka', 3);
INSERT INTO Village VALUES (104, 'Falla', 4);
INSERT INTO Village VALUES (105, 'Bhesan', 5);
INSERT INTO Village VALUES (106, 'Dhoraji', 5);

-- 1. Display all the villages of Rajkot city.--
SELECT Village.Name FROM Village INNER JOIN City ON Village.CityID = City.CityID WHERE City.Name = 'Rajkot';

-- 2. Display city along with their villages & pin code.--
SELECT City.Name, Village.Name, City.Pincode FROM City INNER JOIN Village ON City.CityID = Village.CityID;

-- 3. Display the city having more than one village.--
SELECT City.Name FROM City INNER JOIN Village ON City.CityID = Village.CityID GROUP BY City.Name HAVING COUNT(Village.VID) > 1;

-- 4. Display the city having no village.--
SELECT City.Name FROM City LEFT JOIN Village ON City.CityID = Village.CityID WHERE Village.VID IS NULL;

-- 5. Count the total number of villages in each city.--
SELECT City.Name, COUNT(Village.VID) AS TotalVillages FROM City INNER JOIN Village ON City.CityID = Village.CityID GROUP BY City.Name;

-- 6. Count the number of cities having more than one village.--
SELECT COUNT(DISTINCT City.CityID) FROM City INNER JOIN Village ON City.CityID = Village.CityID GROUP BY City.Name HAVING COUNT(Village.VID) > 1;

CREATE TABLE STU_MASTER (
    Rno INT PRIMARY KEY,
    Name VARCHAR(50),
    Branch VARCHAR(10) DEFAULT 'General',
    SPI DECIMAL(3, 2) CHECK (SPI <= 10),
    Bklog INT CHECK (Bklog >= 0)
);

INSERT INTO STU_MASTER VALUES (101, 'Raju', 'CE', 8.80, 0);
INSERT INTO STU_MASTER VALUES (102, 'Amit', 'CE', 2.20, 3);
INSERT INTO STU_MASTER VALUES (103, 'Sanjay', 'ME', 1.50, 6);
INSERT INTO STU_MASTER VALUES (104, 'Neha', 'EC', 7.65, 0);
INSERT INTO STU_MASTER VALUES (105, 'Meera', 'EE', 5.52, 2);
INSERT INTO STU_MASTER VALUES (106, 'Mahesh', 'ME', 4.50, 3);

-- Trying to update SPI to an invalid value (greater than 10)--
UPDATE STU_MASTER SET SPI = 12 WHERE Name = 'Raju';

-- Trying to update Bklog to an invalid value (less than 0)--
UPDATE STU_MASTER SET Bklog = -1 WHERE Name = 'Neha';
