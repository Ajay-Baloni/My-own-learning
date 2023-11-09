```sql
CREATE DATABASE client;

use client;

CREATE TABLE student (
id INT PRIMARY KEY,
name VARCHAR(50),
age INT NOT NULL
);

INSERT INTO student VALUES(1, "AJAY",21);
INSERT INTO student VALUES(2, "BALONI",22);

SELECT * FROM student;

DROP TABLE student;
```

## SQL Constraints

```sql

CREATE TABLE table_name (
    column1 datatype constraint,
    column2 datatype constraint,
    column3 datatype constraint,
    ....
);
```

SQL constraints are used to specify rules for the data in a table.

Constraints are used to limit the type of data that can go into a table. This ensures the accuracy and reliability of the data in the table. If there is any violation between the constraint and the data action, the action is aborted.

Constraints can be column level or table level. Column level constraints apply to a column, and table level constraints apply to the whole table.

The following constraints are commonly used in SQL:

```
NOT NULL - Ensures that a column cannot have a NULL value

UNIQUE - Ensures that all values in a column are different

PRIMARY KEY - A combination of a NOT NULL and UNIQUE. Uniquely identifies each row in a table

FOREIGN KEY - Prevents actions that would destroy links between tables

CHECK - Ensures that the values in a column satisfies a specific condition

DEFAULT - Sets a default value for a column if no value is specified

CREATE INDEX - Used to create and retrieve data from the database very quickly
```

## Aggregate Function

An aggregate function in SQL returns one value after calculating multiple values of a column. We often use aggregate functions with the GROUP BY and HAVING clauses of the SELECT statement.

There are 5 types of SQL aggregate functions

- Count()
- Sum()
- Avg()
- Min()
- Max()

For example, to find the average salary of employees in a table called "employees", you would use the AVG function with the column reference "salary" like this:

```sql
SELECT AVG (salary)

FROM employees;
```

The COUNT() function returns the number of rows in a database table.

## Clause

A clause in SQL is a built-in function that helps to fetch the required records from a database table. A clause receives a conditional expression, i.e. a column name or some terms involving the columns. The clause calculates the result based on the given statements in the expression. When a large amount of data is stored in the database, clauses are helpful to filter and analyze the queries.

- **GROUP BY** : SQL GROUP BY statement is used to arrange identical data into groups. The GROUP BY statement is used with the SQL SELECT statement.

It collects data from multiple records and groups the result by one or more column

Generally we use group by with some **aggregation function**

```sql
SELECT city
FROM student
GROUP BY city;
```

this will create a group of individual city

```sql
SELECT city ,count(name)
FROM student
GROUP BY city;
```

we can get count of name inside of each city

```sql
SELECT city ,name,count(name)
FROM student
GROUP BY city,name;
```
