Here is the complete solution for the final and most difficult paper, Paper 6.

### 📜 Paper 6: Table & Data Generation Scripts

This paper uses the most comprehensive schema, adding a `Payments` table for financial analysis. Here are the scripts to create the four tables and populate them with sample data designed to test all 10 advanced queries.

#### 1\. Table Generation Script (DDL)

This script creates the `Customers`, `Products`, `Orders`, and `Payments` tables.

```sql
-- Create Customers Table
CREATE TABLE Customers (
    CustomerID INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    JoinDate DATE NOT NULL
);

-- Create Products Table
CREATE TABLE Products (
    ProductID INT PRIMARY KEY,
    ProductName VARCHAR(100) NOT NULL,
    Category VARCHAR(50) NOT NULL,
    Price DECIMAL(10,2) NOT NULL,
    StockQuantity INT NOT NULL
);

-- Create Orders Table
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    CustomerID INT FOREIGN KEY REFERENCES Customers(CustomerID),
    ProductID INT FOREIGN KEY REFERENCES Products(ProductID),
    OrderDate DATE NOT NULL,
    Quantity INT NOT NULL,
    Price DECIMAL(10,2) NOT NULL,       -- Price at time of order
    Amount DECIMAL(10,2) NOT NULL,     -- Total = Quantity * Price
    ShippedDate DATE NULL,
    OrderStatus VARCHAR(20) CHECK (OrderStatus IN ('Pending', 'Shipped', 'Delivered', 'Cancelled'))
);

-- Create Payments Table
CREATE TABLE Payments (
    PaymentID INT PRIMARY KEY IDENTITY(1,1),
    OrderID INT FOREIGN KEY REFERENCES Orders(OrderID),
    PaymentDate DATE NOT NULL,
    PaymentAmount DECIMAL(10,2) NOT NULL
);
```

#### 2\. Sample Data Insertion (DML)

This script populates the tables with logical data.

```sql
-- Insert Sample Customers
INSERT INTO Customers (CustomerID, Name, JoinDate) VALUES
(1, 'Arun Kumar', '2023-01-10'),
(2, 'Bhavna Gupta', '2023-02-15'),
(3, 'Chetan Shah', '2023-03-20'),
(4, 'Divya Iyer', '2023-04-05'),
(5, 'Esha David', '2023-05-12'); -- Q5: No orders

-- Insert Sample Products
INSERT INTO Products (ProductID, ProductName, Category, Price, StockQuantity) VALUES
(101, 'Laptop', 'Electronics', 1200.00, 10),
(102, 'Wireless Mouse', 'Electronics', 25.00, 50),
(103, 'Keyboard', 'Electronics', 45.00, 30), -- Q4: Basis for price comparison
(104, 'Desk Chair', 'Furniture', 150.00, 20),
(105, 'Coffee Maker', 'Appliances', 80.00, 5),
(106, 'Cookbook', 'Books', 30.00, 100); -- Q7: Category with no orders

-- Insert Sample Orders
INSERT INTO Orders (OrderID, CustomerID, ProductID, OrderDate, Quantity, Price, Amount, ShippedDate, OrderStatus) VALUES
-- Q1: Arun's orders for outstanding amount
(1, 1, 101, '2025-01-15', 1, 1200.00, 1200.00, '2025-01-17', 'Delivered'), -- Fully paid
(2, 1, 102, '2025-02-10', 2, 25.00, 50.00, '2025-02-11', 'Delivered'),   -- Partially paid

-- Q2: Bhavna 2 orders, same product, same day
(3, 2, 101, '2025-03-05', 1, 1200.00, 1200.00, '2025-03-07', 'Delivered'), -- Q3: Delivered, no payment
(4, 2, 101, '2025-03-05', 1, 1200.00, 1200.00, '2025-03-08', 'Shipped'),

-- Q6: Stock < Pending
(5, 3, 105, '2025-04-01', 5, 80.00, 400.00, NULL, 'Pending'), -- Stock 5, Pending 5
(6, 4, 105, '2025-04-02', 2, 80.00, 160.00, NULL, 'Pending'), -- Stock 5, Pending 5+2=7

-- Q8: Re-order within 7 days (Arun, Mouse)
(7, 1, 102, '2025-04-05', 1, 25.00, 25.00, '2025-04-06', 'Delivered'), -- First order
(8, 1, 102, '2025-04-08', 1, 25.00, 25.00, '2025-04-09', 'Delivered'), -- Re-order 3 days later

-- Q10: Date-wise pending
(9, 3, 102, '2025-04-02', 1, 25.00, 25.00, NULL, 'Pending');

-- Insert Sample Payments
INSERT INTO Payments (OrderID, PaymentDate, PaymentAmount) VALUES
(1, '2025-01-18', 1200.00), -- Q1: Fully paid
(2, '2025-02-13', 30.00);    -- Q1: Partially paid (50 - 30 = 20 outstanding)
```

---

### 🚀 Paper 6: SQL Queries

#### **Question 1:** List Customers with total outstanding amount.

**Expected Output:**

| CustomerName | OutstandingAmount |
| :----------- | :---------------- |
| Bhavna Gupta | 2400.00           |
| Chetan Shah  | 425.00            |
| Divya Iyer   | 160.00            |
| Arun Kumar   | 20.00             |

#### **Question 2:** List Customers who placed more than 2 orders in a single day of a same product.

**Expected Output:**

_(No output based on sample data and a strict interpretation of "\> 2")_

#### **Question 3:** List Orders which are delivered but payment not received.

**Expected Output:**

| CustomerName | ProductName | OrderID | OrderDate  | Amount  |
| :----------- | :---------- | :------ | :--------- | :------ |
| Bhavna Gupta | Laptop      | 3       | 2025-03-05 | 1200.00 |

#### **Question 4:** List All Products whose price is more than Product "Keyboard".

**Expected Output:**

| ProductName  | Price   |
| :----------- | :------ |
| Laptop       | 1200.00 |
| Desk Chair   | 150.00  |
| Coffee Maker | 80.00   |

#### **Question 5:** List Customers which have not placed a single order.

**Expected Output:**

| CustomerID | CustomerName | JoinDate   |
| :--------- | :----------- | :--------- |
| 5          | Esha David   | 2023-05-12 |

#### **Question 6:** List Products where StockQuantity is less than Pending Order Total Quantity.

**Expected Output:**

| ProductName  | StockQuantity | PendingOrderQuantity |
| :----------- | :------------ | :------------------- |
| Coffee Maker | 5             | 7                    |

#### **Question 7:** Category Wise Sales Summary (Include all the category even if with zero orders).

**Expected Output:**

| Category    | No. of Customers | No. of Orders | No. of Products | Total Quantity | Total Order Amount |
| :---------- | :--------------- | :------------ | :-------------- | :------------- | :----------------- |
| Appliances  | 2                | 2             | 1               | 7              | 560.00             |
| Books       | 0                | 0             | 1               | 0              | 0.00               |
| Electronics | 3                | 6             | 3               | 8              | 2725.00            |
| Furniture   | 0                | 0             | 1               | 0              | 0.00               |

#### **Question 8:** List Customer with Order detail who has placed order of same product again within 7 days.

**Expected Output:**

| CustomerName | ProductName    | PrevOrderDate | CurrentOrderDate | DaysBetween |
| :----------- | :------------- | :------------ | :--------------- | :---------- |
| Arun Kumar   | Wireless Mouse | 2025-04-05    | 2025-04-08       | 3           |

#### **Question 9:** Product Wise Total Orders, Lowest Price, Highest Price & Average Price.

**Expected Output:**

| Category    | Product        | TotalOrders | LowestPrice | HighestPrice | AveragePrice |
| :---------- | :------------- | :---------- | :---------- | :----------- | :----------- |
| Appliances  | Coffee Maker   | 2           | 80.00       | 80.00        | 80.00        |
| Electronics | Laptop         | 3           | 1200.00     | 1200.00      | 1200.00      |
| Electronics | Wireless Mouse | 4           | 25.00       | 25.00        | 25.00        |

#### **Question 10:** List Date Wise Pending Order and Pending Ordered Quantity Product Wise between fromDate and toDate.

_Note: We will run this for the date range '2025-04-01' to '2025-04-03'._

**Expected Output:**

| Date       | Product        | TotalPendingOrders | TotalPendingQuantity |
| :--------- | :------------- | :----------------- | :------------------- |
| 2025-04-01 | Coffee Maker   | 1                  | 5                    |
| 2025-04-02 | Coffee Maker   | 1                  | 2                    |
| 2025-04-02 | Wireless Mouse | 1                  | 1                    |

