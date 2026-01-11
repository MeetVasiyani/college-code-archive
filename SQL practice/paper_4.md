### 📜 Paper 4: Table & Data Generation Scripts

This paper uses an e-commerce schema focused on analytics. Here are the scripts to create the tables and insert sample data designed to test all 10 queries.

#### 1\. Table Generation Script (DDL)

This script creates the `Customers`, `Products`, and `Orders` tables.

```sql
-- Create Customers Table
CREATE TABLE Customers (
    CustomerID INT PRIMARY KEY IDENTITY(1,1),
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) UNIQUE,
    JoinDate DATE NOT NULL,
    TotalOrders INT DEFAULT 0
);

-- Create Products Table
CREATE TABLE Products (
    ProductID INT PRIMARY KEY IDENTITY(1,1),
    ProductName VARCHAR(100) NOT NULL,
    Category VARCHAR(50),
    Price DECIMAL(10,2) NOT NULL,
    StockQuantity INT NOT NULL,
    LastRestockDate DATE
);

-- Create Orders Table
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY IDENTITY(1,1),
    CustomerID INT FOREIGN KEY REFERENCES Customers(CustomerID),
    ProductID INT FOREIGN KEY REFERENCES Products(ProductID),
    OrderDate DATE NOT NULL,
    Quantity INT NOT NULL,
    TotalAmount DECIMAL(10,2),
    OrderStatus VARCHAR(20) CHECK (OrderStatus IN ('Pending', 'Shipped', 'Delivered', 'Cancelled'))
);
```

#### 2\. Sample Data Insertion (DML)

This script populates the tables with logical data.
_Note: We assume the "current date" for these queries is **November 17, 2025**._

```sql
-- Insert Sample Customers
INSERT INTO Customers (FirstName, LastName, Email, JoinDate) VALUES
('Amit', 'Sharma', 'amit@example.com', '2023-01-05'), -- Q1/Q8: Top customer
('Priya', 'Singh', 'priya@example.com', '2023-02-10'), -- Q4: Repeat buyer
('Ravi', 'Kumar', 'ravi@example.com', '2023-03-15'),  -- Q7: Ordered every month
('Divya', 'Mehta', 'divya@example.com', '2023-04-20'), -- Q10: Unusual pattern
('Sunil', 'Verma', 'sunil@example.com', '2023-05-01'), -- Q9: Cancelled/Pending
('Tina', 'Das', 'tina@example.com', '2023-06-11');

-- Insert Sample Products
INSERT INTO Products (ProductName, Category, Price, StockQuantity, LastRestockDate) VALUES
('Laptop', 'Electronics', 1200.00, 15, '2025-10-01'),
('Headphones', 'Electronics', 150.00, 8, '2025-09-15'),  -- Q6: Low stock (< 10)
('Yoga Mat', 'Sports', 25.00, 50, '2025-10-20'),     -- Q4: Ordered twice
('Old Gadget', 'Electronics', 50.00, 100, '2024-01-01'), -- Q2/Q5: Old orders
('Smartphone', 'Electronics', 800.00, 20, '2025-11-01');

-- Insert Sample Orders
-- Assume Current Date is 2025-11-17
INSERT INTO Orders (CustomerID, ProductID, OrderDate, Quantity, TotalAmount, OrderStatus) VALUES
-- Q1/Q8: Amit is top customer (4 orders)
(1, 1, '2025-05-10', 1, 1200.00, 'Delivered'),
(1, 2, '2025-06-15', 2, 300.00, 'Delivered'),
(1, 5, '2025-07-20', 1, 800.00, 'Delivered'),
(1, 3, '2025-10-01', 1, 25.00, 'Shipped'),

-- Q4: Priya is repeat buyer of Yoga Mat
(2, 3, '2025-08-01', 1, 25.00, 'Delivered'),
(2, 3, '2025-08-10', 2, 50.00, 'Delivered'),

-- Q2/Q5: Old Gadget ordered > 90 days ago
(3, 4, '2025-01-15', 1, 50.00, 'Delivered'),

-- Q6: Headphones: Stock 8, Demand > 20 (10+10+5=25)
(4, 2, '2025-09-01', 10, 1500.00, 'Shipped'),
(5, 2, '2025-09-05', 10, 1500.00, 'Shipped'),
(6, 2, '2025-09-10', 5, 750.00, 'Delivered'),

-- Q9: Sunil has Pending/Cancelled orders
(5, 5, '2025-11-10', 1, 800.00, 'Pending'),
(5, 1, '2025-11-01', 1, 1200.00, 'Cancelled'),

-- Q10: Divya's unusual pattern (Gap > 60 days, then large order)
(4, 3, '2025-06-01', 1, 25.00, 'Delivered'),  -- Order 1
(4, 1, '2025-09-01', 1, 1200.00, 'Shipped'), -- Order 2 (92-day gap, large order)

-- Q3: Monthly Sales (Jun-Nov)
(6, 5, '2025-06-05', 1, 800.00, 'Delivered'), -- June
(1, 5, '2025-07-20', 1, 800.00, 'Delivered'), -- July
(2, 3, '2025-08-01', 1, 25.00, 'Delivered'),  -- August
(4, 2, '2025-09-01', 10, 1500.00, 'Shipped'), -- September
(1, 3, '2025-10-01', 1, 25.00, 'Shipped'),   -- October
(5, 5, '2025-11-10', 1, 800.00, 'Pending'),  -- November

-- Q7: Ravi ordered every month in 2025
(3, 4, '2025-01-15', 1, 50.00, 'Delivered'),
(3, 4, '2025-02-15', 1, 50.00, 'Delivered'),
(3, 4, '2025-03-15', 1, 50.00, 'Delivered'),
(3, 4, '2025-04-15', 1, 50.00, 'Delivered'),
(3, 4, '2025-05-15', 1, 50.00, 'Delivered'),
(3, 4, '2025-06-15', 1, 50.00, 'Delivered'),
(3, 4, '2025-07-15', 1, 50.00, 'Delivered'),
(3, 4, '2025-08-15', 1, 50.00, 'Delivered'),
(3, 4, '2025-09-15', 1, 50.00, 'Delivered'),
(3, 4, '2025-10-15', 1, 50.00, 'Delivered'),
(3, 4, '2025-11-15', 1, 50.00, 'Delivered');
```

---

### 🚀 Paper 4: SQL Queries

#### **Question 1:** Find top 5 customers by total order amount.

**Expected Output:**

| CustomerName | TotalSpent |
| :----------- | :--------- |
| Sunil Verma  | 3500.00    |
| Divya Mehta  | 2725.00    |
| Amit Sharma  | 2325.00    |
| Tina Das     | 1550.00    |
| Ravi Kumar   | 600.00     |



#### **Question 2:** List products with no orders in the last 90 days.

**Expected Output:**

| ProductName |
| :---------- |
| Old Gadget  |



#### **Question 3:** Calculate monthly sales for the last 6 months.

**Expected Output:**

| SalesMonth | TotalSales |
| :--------- | :--------- |
| 2025-06    | 1625.00    |
| 2025-07    | 850.00     |
| 2025-08    | 125.00     |
| 2025-09    | 3800.00    |
| 2025-10    | 75.00      |
| 2025-11    | 2050.00    |



#### **Question 4:** Find customers who ordered the same product more than once. (repeat buyers)

**Expected Output:**

| CustomerName | ProductName | OrderCount |
| :----------- | :---------- | :--------- |
| Priya Singh  | Yoga Mat    | 2          |
| Ravi Kumar   | Old Gadget  | 11         |



#### **Question 5:** Identify products never ordered in the last 3 months.

**Expected Output:**

| ProductName |
| :---------- |
| Old Gadget  |



#### **Question 6:** List products with low stock (less than 10 units) and high demand (more than 20 units ordered).

**Expected Output:**

| ProductName | StockQuantity | TotalUnitsOrdered |
| :---------- | :------------ | :---------------- |
| Headphones  | 8             | 25                |



#### **Question 7:** List customers who ordered in every month of the current year.

**Expected Output:**

| CustomerName |
| :----------- |
| Ravi Kumar   |



#### **Question 8:** Find customers who has placed maximum number of orders.

**Expected Output:**

| CustomerName | NumberOfOrders |
| :----------- | :------------- |
| Ravi Kumar   | 11             |



#### **Question 9:** List customers whose order was either 'Cancelled' or 'Pending'.

**Expected Output:**

| CustomerName | OrderStatus |
| :----------- | :---------- |
| Sunil Verma  | Cancelled   |
| Sunil Verma  | Pending     |



#### **Question 10:** Find customers with unusual ordering patterns (gaps \> 60 days followed by large orders).

**Expected Output:**

| CustomerName | PrevOrderDate | NextOrderDate | GapInDays | LargeOrderAmount |
| :----------- | :------------ | :------------ | :-------- | :--------------- |
| Divya Mehta  | 2025-06-01    | 2025-09-01    | 92        | 1200.00          |

