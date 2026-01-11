### 📜 Paper 5: Table & Data Generation Scripts

First, here are the SQL scripts to create the tables and insert sample data. The sample data is designed to provide meaningful results for all the queries in this paper.

#### 1\. Table Generation Script (DDL)

This script creates the `Customers`, `Products`, and `Orders` tables based on the schema from the exam paper [cite: 271-307].

```sql
-- Create Customers Table
CREATE TABLE Customers (
    CustomerID INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(50) NOT NULL,
    JoinDate DATE NOT NULL
[cite_start]); [cite: 272-278]

-- Create Products Table
CREATE TABLE Products (
    ProductID INT PRIMARY KEY IDENTITY(1,1),
    ProductName VARCHAR(100) NOT NULL,
    Category VARCHAR(50),
    Price DECIMAL(10,2) NOT NULL,
    StockQuantity INT NOT NULL
[cite_start]); [cite: 279-288]

-- Create Orders Table
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY IDENTITY(1,1),
    CustomerID INT FOREIGN KEY REFERENCES Customers(CustomerID),
    ProductID INT FOREIGN KEY REFERENCES Products(ProductID),
    OrderDate DATE NOT NULL,
    Quantity INT NOT NULL,
    TotalOrderAmount DECIMAL(10,2) NOT NULL,
    Price DECIMAL(10,2) NOT NULL, -- Price at the time of sale
    OrderStatus VARCHAR(20) CHECK (OrderStatus IN ('Pending', 'Shipped', 'Delivered', 'Cancelled'))
[cite_start]); [cite: 291-307]
```

#### 2\. Sample Data Insertion (DML)

This script populates the tables with logical data to test the queries.

```sql
-- Insert Sample Customers
INSERT INTO Customers (Name, JoinDate) VALUES
('Alice Smith', '2023-01-15'),
('Bob Johnson', '2023-02-20'),
('Charlie Brown', '2023-03-05'),
('David Lee', '2023-04-10'),
('Eve Davis', '2023-05-12');

-- Insert Sample Products
INSERT INTO Products (ProductName, Category, Price, StockQuantity) VALUES
('16" Laptop', 'Computer', 1200.00, 10),
('Wireless Mouse', 'Computer', 25.00, 50),
('iPhone 15', 'Mobile', 999.00, 20),
('Galaxy S24', 'Mobile', 899.00, 30),
('Mechanical Keyboard', 'Computer', 75.00, 5),  -- Low stock
('4K Monitor', 'Computer', 450.00, 15),
('Desk Lamp', 'Home', 45.00, 100);             -- Never ordered

-- Insert Sample Orders
INSERT INTO Orders (CustomerID, ProductID, OrderDate, Quantity, Price, TotalOrderAmount, OrderStatus) VALUES
-- High-value orders
(4, 3, '2024-10-01', 3, 999.00, 2997.00, 'Pending'),   -- David, iPhone 15
(2, 3, '2024-05-11', 2, 999.00, 1998.00, 'Shipped'),    -- Bob, iPhone 15
(1, 1, '2024-05-10', 1, 1200.00, 1200.00, 'Delivered'), -- Alice, Laptop
(2, 1, '2024-07-15', 1, 1200.00, 1200.00, 'Delivered'), -- Bob, Laptop

-- Repeat buyers (Alice on iPhone, Eve on Keyboard)
(1, 3, '2024-10-05', 1, 999.00, 999.00, 'Delivered'),  -- Alice, iPhone 15
(1, 3, '2024-10-10', 1, 999.00, 999.00, 'Delivered'),  -- Alice, iPhone 15 (Repeat)

-- Stock < Pending query (Keyboard: Stock 5, Pending 3+4=7)
(5, 5, '2024-11-15', 3, 75.00, 225.00, 'Pending'),    -- Eve, Keyboard
(5, 5, '2024-11-16', 4, 75.00, 300.00, 'Pending'),    -- Eve, Keyboard (Repeat)

-- Cancelled order before 2024
(2, 2, '2023-12-20', 1, 25.00, 25.00, 'Cancelled'),   -- Bob, Mouse

-- Other orders
(1, 2, '2024-05-10', 1, 25.00, 25.00, 'Delivered'),    -- Alice, Mouse
(3, 4, '2024-06-01', 1, 899.00, 899.00, 'Delivered');  -- Charlie, Galaxy S24
```

-----

### 🚀 Paper 5: SQL Queries

#### **Question 1:** List top 5 highest amount orders with Customer Name & Product Name. [cite: 310]

**Expected Output:**
A list of the top 5 orders, sorted by `TotalOrderAmount` in descending order.

| CustomerName | ProductName | TotalOrderAmount |
| :--- | :--- | :--- |
| David Lee | iPhone 15 | 2997.00 |
| Bob Johnson | iPhone 15 | 1998.00 |
| Alice Smith | 16" Laptop | 1200.00 |
| Bob Johnson | 16" Laptop | 1200.00 |
| Alice Smith | iPhone 15 | 999.00 |

-----

#### **Question 2:** List Products with Category which are never ordered. [cite: 311]

**Expected Output:**
The one product (`Desk Lamp`) that exists in the `Products` table but has no matching entries in the `Orders` table.

| ProductName | Category |
| :--- | :--- |
| Desk Lamp | Home |

-----

#### **Question 3:** List Category wise total orders, total ordered quantity and total order amount. [cite: 312]

**Expected Output:**
A summary for each product category that has at least one order.

| Category | TotalOrders | TotalOrderedQuantity | TotalOrderAmount |
| :--- | :--- | :--- | :--- |
| Computer | 5 | 10 | 1750.00 |
| Mobile | 5 | 8 | 7893.00 |

-----

#### **Question 4:** List Products with Average Price of "Computer" Category. [cite: 313]

**Expected Output (based on interpretation):**
The average price for 'Computer' is `(1200 + 25 + 75 + 450) / 4 = 437.50`. This query lists all products with a price higher than that.

| ProductName | Price |
| :--- | :--- |
| 16" Laptop | 1200.00 |
| iPhone 15 | 999.00 |
| Galaxy S24 | 899.00 |
| 4K Monitor | 450.00 |

-----

#### **Question 5:** Find Customers who ordered the same product more than once. (repeat buyers) [cite: 316, 317]

**Expected Output:**
Our sample data has Alice buying the 'iPhone 15' twice and Eve buying the 'Mechanical Keyboard' twice.

| CustomerName | ProductName |
| :--- | :--- |
| Alice Smith | iPhone 15 |
| Eve Davis | Mechanical Keyboard |

-----

#### **Question 6:** Which Product is highest selling in terms of quantity? [cite: 318]

**Expected Output:**
A list of the product(s) with the highest total quantity sold. In our data, 'iPhone 15' (3+2+1+1=7) and 'Mechanical Keyboard' (3+4=7) are tied. `TOP 1 WITH TIES` will show both.

| ProductName | TotalQuantitySold |
| :--- | :--- |
| iPhone 15 | 7 |
| Mechanical Keyboard | 7 |

-----

#### **Question 7:** Delete those orders which are Cancelled and placed before '2024-01-01'. [cite: 320]

**Expected Output:**
A message indicating that one row was deleted (Bob's 'Cancelled' mouse order from 2023-12-20).

`(1 row(s) affected)`

-----

#### **Question 8:** List products whose current stock is less than current pending orders. [cite: 321]

**Expected Output:**
The 'Mechanical Keyboard' has a stock of 5, but 'Pending' orders total 7 (one order for 3, one for 4).

| ProductName | StockQuantity | PendingQuantity |
| :--- | :--- | :--- |
| Mechanical Keyboard | 5 | 7 |

-----

#### **Question 9:** List Top 10 Customers with highest total order amount of Category "Mobile". [cite: 322]

**Expected Output:**
A list of customers, ranked by their total spending *only* on 'Mobile' products.

| CustomerName | TotalMobileAmount |
| :--- | :--- |
| David Lee | 2997.00 |
| Bob Johnson | 1998.00 |
| Alice Smith | 1998.00 |
| Charlie Brown | 899.00 |

-----

#### **Question 10:** List Date wise Total Order Amount. [cite: 324]

**Expected Output:**
A summary of total sales revenue for each date that had an order.

*Note: This output assumes Query 7 (the `DELETE`) has **not** been run. If it was, the 2023-12-20 row would be gone.*
| OrderDate | TotalAmount |
| :--- | :--- |
| 2023-12-20 | 25.00 |
| 2024-05-10 | 1225.00 |
| 2024-05-11 | 1998.00 |
| 2024-06-01 | 899.00 |
| 2024-07-15 | 1200.00 |
| 2024-10-01 | 2997.00 |
| 2024-10-05 | 999.00 |
| 2024-10-10 | 999.00 |
| 2024-11-15 | 225.00 |
| 2024-11-16 | 300.00 |