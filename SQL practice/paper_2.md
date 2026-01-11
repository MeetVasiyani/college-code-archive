### 📜 Paper 2: Table & Data Generation Scripts

This paper uses a "Sportswear Database" schema. Here are the scripts to create the five tables and populate them with sample data to test this paper's queries.

#### 1\. Table Generation Script (DDL)

This script creates the `color`, `customer`, `category`, `clothing`, and `clothing_order` tables.

```sql
-- Create color Table
CREATE TABLE color (
    id INT PRIMARY KEY IDENTITY(1,1),
    name VARCHAR(50) NOT NULL,
    extra_fee DECIMAL(5,2) DEFAULT 0
);

-- Create customer Table
CREATE TABLE customer (
    id INT PRIMARY KEY IDENTITY(1,1),
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    favorite_color_id INT FOREIGN KEY REFERENCES color(id)
);

-- Create category Table
CREATE TABLE category (
    id INT PRIMARY KEY IDENTITY(1,1),
    name VARCHAR(50) NOT NULL,
    parent_id INT FOREIGN KEY REFERENCES category(id) NULL
);

-- Create clothing Table
CREATE TABLE clothing (
    id INT PRIMARY KEY IDENTITY(1,1),
    name VARCHAR(100) NOT NULL,
    size VARCHAR(5) NOT NULL,
    price DECIMAL(10,2) NOT NULL,
    color_id INT FOREIGN KEY REFERENCES color(id),
    category_id INT FOREIGN KEY REFERENCES category(id)
);

-- Create clothing_order Table
CREATE TABLE clothing_order (
    id INT PRIMARY KEY IDENTITY(1,1),
    customer_id INT FOREIGN KEY REFERENCES customer(id),
    clothing_id INT FOREIGN KEY REFERENCES clothing(id),
    items INT NOT NULL,
    order_date DATE NOT NULL
);
```

#### 2\. Sample Data Insertion (DML)

This script populates the tables with logical data to test all 10 queries.

```sql
-- Insert Sample Colors
INSERT INTO color (name, extra_fee) VALUES
('Red', 5.00),    -- has extra fee
('Green', 0.00),
('Blue', 0.00),
('Black', 5.00),  -- has extra fee
('White', 0.00);

-- Insert Sample Customers
INSERT INTO customer (first_name, last_name, favorite_color_id) VALUES
('Jay', 'Patel', 1),     -- Favorite is Red
('Dhruv', 'Shah', 2),    -- Favorite is Green
('Amit', 'Verma', 1),    -- Favorite is Red
('Priya', 'Mehta', 3),   -- Favorite is Blue
('Ravi', 'Singh', NULL), -- No favorite color
('Meera', 'Das', 5);     -- Customer with no purchases

-- Insert Sample Categories
INSERT INTO category (name, parent_id) VALUES
('Mens', NULL),          -- Main category
('Womens', NULL),        -- Main category
('T-Shirt', 1),          -- Subcategory of Mens
('Joggers', 1),          -- Subcategory of Mens
('Hoodie', 1),           -- Subcategory of Mens
('T-Shirt', 2),          -- Subcategory of Womens
('Joggers', 2);          -- Subcategory of Womens

-- Insert Sample Clothing
INSERT INTO clothing (name, size, price, color_id, category_id) VALUES
('Basic Tee', 'M', 20.00, 5, 3),        -- White, Mens T-Shirt
('V-Neck Tee', 'L', 25.00, 3, 3),        -- Blue, Mens T-Shirt (for Jay's order)
('Performance Jogger', 'L', 45.00, 4, 4), -- Black, Mens Joggers
('Cuffed Jogger', 'M', 40.00, 2, 4),      -- Green, Mens Joggers
('Graphic Hoodie', 'XL', 60.00, 1, 5),    -- Red, Mens Hoodie
('Womens Basic Tee', 'S', 20.00, 5, 6),   -- White, Womens T-Shirt
('Womens Lounge Jogger', 'M', 50.00, 4, 7); -- Black, Womens Joggers

-- Insert Sample Orders
INSERT INTO clothing_order (customer_id, clothing_id, items, order_date) VALUES
-- Jay's order for T-Shirt after 1st April 2024
(1, 2, 2, '2024-05-15'), -- Jay, V-Neck Tee, Qty 2

-- Order for financial year 2024-25
(2, 4, 1, '2024-06-10'), -- Dhruv, Cuffed Jogger, Qty 1

-- Order of favorite color
(1, 5, 1, '2024-07-01'), -- Jay, Graphic Hoodie (Red), Qty 1. Jay's fav color is Red.

-- Customer who wears XL
(4, 5, 1, '2024-08-01'), -- Priya, Graphic Hoodie (XL), Qty 1

-- Multiple orders for customer totals
(1, 3, 1, '2024-09-05'), -- Jay, Performance Jogger, Qty 1
(2, 7, 1, '2023-11-20'), -- Dhruv, Womens Lounge Jogger, Qty 1
(3, 1, 3, '2024-10-10'); -- Amit, Basic Tee, Qty 3
```

-----

### 🚀 Paper 2: SQL Queries

#### **Question 1:** List the customers whose favorite color is Red or Green and name is Jay or Dhruv.

**Expected Output:**

| first\_name | last\_name | color\_name |
| :--- | :--- | :--- |
| Jay | Patel | Red |
| Dhruv | Shah | Green |

**

#### **Question 2:** List the different types of Joggers with their sizes.

**Expected Output:**

| clothing\_name | size |
| :--- | :--- |
| Performance Jogger | L |
| Cuffed Jogger | M |
| Womens Lounge Jogger | M |

**

#### **Question 3:** List the orders of Jay of T-Shirt after 1st April 2024.

**Expected Output:**

| order\_id | customer\_name | clothing\_name | items | order\_date |
| :--- | :--- | :--- | :--- | :--- |
| 1 | Jay | V-Neck Tee | 2 | 2024-05-15 |

**

#### **Question 4:** List the customer whose favorite color is charged extra.

**Expected Output:**
'Red' and 'Black' have an extra fee. Jay and Amit have 'Red' as their favorite.

| first\_name | last\_name | favorite\_color | extra\_fee |
| :--- | :--- | :--- | :--- |
| Jay | Patel | Red | 5.00 |
| Amit | Verma | Red | 5.00 |

**

#### **Question 5:** List category wise clothing's maximum price, minimum price, average price and number of clothing items.

**Expected Output:**

| category\_name | num\_items | max\_price | min\_price | avg\_price |
| :--- | :--- | :--- | :--- | :--- |
| T-Shirt | 3 | 25.00 | 20.00 | 21.67 |
| Joggers | 3 | 50.00 | 40.00 | 45.00 |
| Hoodie | 1 | 60.00 | 60.00 | 60.00 |

**

#### **Question 6:** List the customers with no purchases at all.

**Expected Output:**
Meera Das was created with no orders.

| first\_name | last\_name |
| :--- | :--- |
| Meera | Das |

-----

#### **Question 7:** List the orders of favorite color with all the details.

**Expected Output:**
Finds orders where the `color_id` of the *clothing* matches the `favorite_color_id` of the *customer* who ordered it. In our data, Jay (fav color Red) ordered a Red Hoodie.

| order\_id | customer\_name | clothing\_name | color\_name | items | order\_date |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 3 | Jay | Graphic Hoodie | Red | 1 | 2024-07-01 |

**

#### **Question 8:** List the customers with total purchase value, number of orders and number of items purchased.

**Expected Output:**
A summary of all customers who have placed orders.

| customer\_name | num\_orders | total\_items | total\_purchase\_value |
| :--- | :--- | :--- | :--- |
| Jay Patel | 3 | 4 | 155.00 |
| Dhruv Shah | 2 | 2 | 90.00 |
| Amit Verma | 1 | 3 | 60.00 |
| Priya Mehta | 1 | 1 | 60.00 |

**

#### **Question 9:** List the Clothing item, Size, Order Value and Number of items sold during financial year 2024-25.

*Note: The financial year 2024-25 is from April 1, 2024, to March 31, 2025.*

**Expected Output:**

| clothing\_name | size | items\_sold | order\_value |
| :--- | :--- | :--- | :--- |
| V-Neck Tee | L | 2 | 50.00 |
| Cuffed Jogger | M | 1 | 40.00 |
| Graphic Hoodie | XL | 2 | 120.00 |
| Performance Jogger | L | 1 | 45.00 |
| Basic Tee | M | 3 | 60.00 |

**

#### **Question 10:** List the customers who wears XL size.

**Expected Output:**
Priya ordered an 'XL' Hoodie.

| first\_name | last\_name |
| :--- | :--- |
| Priya | Mehta |


