"""用 SQLite 的小型資料表檢查已整理的標準 SELECT 題解。"""

from __future__ import annotations

import sqlite3
import re
from pathlib import Path


ROOT = Path(__file__).resolve().parent
CASES = [
    (
        "0175_combine-two-tables.sql",
        """CREATE TABLE Person(personId INT, lastName TEXT, firstName TEXT);
        CREATE TABLE Address(addressId INT, personId INT, city TEXT, state TEXT);
        INSERT INTO Person VALUES(1,'Wang','Allen'),(2,'Alice','Bob');
        INSERT INTO Address VALUES(1,2,'New York City','New York');""",
        [("Allen", "Wang", None, None), ("Bob", "Alice", "New York City", "New York")],
    ),
    (
        "0176_second-highest-salary.sql",
        """CREATE TABLE Employee(id INT, salary INT);
        INSERT INTO Employee VALUES(1,100),(2,200),(3,200),(4,300);""",
        [(200,)],
    ),
    (
        "0176_second-highest-salary.sql",
        """CREATE TABLE Employee(id INT, salary INT);
        INSERT INTO Employee VALUES(1,100),(2,100);""",
        [(None,)],
    ),
    (
        "0181_employees-earning-more-than-their-managers.sql",
        """CREATE TABLE Employee(id INT, name TEXT, salary INT, managerId INT);
        INSERT INTO Employee VALUES(1,'Joe',70000,3),(2,'Henry',80000,4),
        (3,'Sam',60000,NULL),(4,'Max',90000,NULL);""",
        [("Joe",)],
    ),
    (
        "0182_duplicate-emails.sql",
        """CREATE TABLE Person(id INT, email TEXT);
        INSERT INTO Person VALUES(1,'a@b.com'),(2,'c@d.com'),(3,'a@b.com');""",
        [("a@b.com",)],
    ),
    (
        "0183_customers-who-never-order.sql",
        """CREATE TABLE Customers(id INT, name TEXT);
        CREATE TABLE Orders(id INT, customerId INT);
        INSERT INTO Customers VALUES(1,'Joe'),(2,'Henry'),(3,'Sam'),(4,'Max');
        INSERT INTO Orders VALUES(1,3),(2,1);""",
        [("Henry",), ("Max",)],
    ),
    (
        "0178_rank-scores.sql",
        """CREATE TABLE Scores(id INT, score DECIMAL(4,2));
        INSERT INTO Scores VALUES(1,3.50),(2,3.65),(3,4.00),
        (4,3.85),(5,4.00),(6,3.65);""",
        [(4.00, 1), (4.00, 1), (3.85, 2), (3.65, 3), (3.65, 3), (3.50, 4)],
        True,
    ),
    (
        "0180_consecutive-numbers.sql",
        """CREATE TABLE Logs(id INT, num TEXT);
        INSERT INTO Logs VALUES(1,'1'),(2,'1'),(3,'1'),(4,'1'),(5,'2'),
        (6,'3'),(7,'3'),(8,'3'),(9,'2');""",
        [("1",), ("3",)],
    ),
    (
        "0184_department-highest-salary.sql",
        """CREATE TABLE Employee(id INT, name TEXT, salary INT, departmentId INT);
        CREATE TABLE Department(id INT, name TEXT);
        INSERT INTO Employee VALUES(1,'Joe',70000,1),(2,'Jim',90000,1),
        (3,'Henry',80000,2),(4,'Sam',60000,2),(5,'Max',90000,1);
        INSERT INTO Department VALUES(1,'IT'),(2,'Sales');""",
        [("IT", "Jim", 90000), ("IT", "Max", 90000), ("Sales", "Henry", 80000)],
    ),
    (
        "0185_department-top-three-salaries.sql",
        """CREATE TABLE Employee(id INT, name TEXT, salary INT, departmentId INT);
        CREATE TABLE Department(id INT, name TEXT);
        INSERT INTO Employee VALUES(1,'Joe',85000,1),(2,'Henry',80000,2),
        (3,'Sam',60000,2),(4,'Max',90000,1),(5,'Janet',69000,1),
        (6,'Randy',85000,1),(7,'Will',70000,1);
        INSERT INTO Department VALUES(1,'IT'),(2,'Sales');""",
        [("IT", "Max", 90000), ("IT", "Joe", 85000), ("IT", "Randy", 85000),
         ("IT", "Will", 70000), ("Sales", "Henry", 80000),
         ("Sales", "Sam", 60000)],
    ),
    (
        "0262_trips-and-users.sql",
        """CREATE TABLE Trips(id INT, client_id INT, driver_id INT, city_id INT, status TEXT, request_at TEXT);
        CREATE TABLE Users(users_id INT, banned TEXT, role TEXT);
        INSERT INTO Users VALUES(1,'No','client'),(2,'Yes','client'),(3,'No','client'),
        (10,'No','driver'),(11,'No','driver'),(12,'Yes','driver');
        INSERT INTO Trips VALUES(1,1,10,1,'completed','2013-10-01'),
        (2,1,11,1,'cancelled_by_driver','2013-10-01'),
        (3,2,10,1,'cancelled_by_client','2013-10-01'),
        (4,3,10,1,'cancelled_by_client','2013-10-02'),
        (5,1,10,1,'completed','2013-10-02'),
        (6,1,12,1,'completed','2013-10-03');""",
        [("2013-10-01", 0.5), ("2013-10-02", 0.5)],
    ),
    (
        "0511_game-play-analysis-i.sql",
        """CREATE TABLE Activity(player_id INT, device_id INT, event_date TEXT, games_played INT);
        INSERT INTO Activity VALUES(1,2,'2016-03-01',5),(1,2,'2016-05-02',6),
        (2,3,'2017-06-25',1),(3,1,'2016-03-02',0),(3,4,'2018-07-03',5);""",
        [(1, "2016-03-01"), (2, "2017-06-25"), (3, "2016-03-02")],
    ),
    (
        "0570_managers-with-at-least-5-direct-reports.sql",
        """CREATE TABLE Employee(id INT, name TEXT, department TEXT, managerId INT);
        INSERT INTO Employee VALUES(1,'Alex','A',NULL),(2,'Bob','A',1),(3,'Cathy','A',1),
        (4,'Drew','A',1),(5,'Eve','A',1),(6,'Finn','A',1),(7,'Gail','B',NULL);""",
        [("Alex",)],
    ),
    (
        "0577_employee-bonus.sql",
        """CREATE TABLE Employee(empId INT, name TEXT, supervisor INT, salary INT);
        CREATE TABLE Bonus(empId INT, bonus INT);
        INSERT INTO Employee VALUES(1,'Joe',NULL,70000),(2,'Henry',1,80000),
        (3,'Sam',NULL,60000),(4,'Max',NULL,90000);
        INSERT INTO Bonus VALUES(1,500),(2,1200),(3,NULL);""",
        [("Joe", 500), ("Max", None), ("Sam", None)],
    ),
    (
        "0584_find-customer-referee.sql",
        """CREATE TABLE Customer(id INT, name TEXT, referee_id INT);
        INSERT INTO Customer VALUES(1,'Will',NULL),(2,'Jane',NULL),(3,'Alex',2),
        (4,'Bill',NULL),(5,'Zack',1),(6,'Mark',2);""",
        [("Will",), ("Jane",), ("Bill",), ("Zack",)],
    ),
    (
        "0585_investments-in-2016.sql",
        """CREATE TABLE Insurance(pid INT, tiv_2015 REAL, tiv_2016 REAL, lat REAL, lon REAL);
        INSERT INTO Insurance VALUES(1,10,100,1,1),(2,10,200,2,2),
        (3,20,300,3,3),(4,30,400,1,1),(5,10,50,5,5);""",
        [(250.0,)],
    ),
    (
        "0586_customer-placing-the-largest-number-of-orders.sql",
        """CREATE TABLE Orders(order_number INT, customer_number INT);
        INSERT INTO Orders VALUES(1,1),(2,2),(3,3),(4,3),(5,3),(6,1);""",
        [(3,)],
    ),
    (
        "0595_big-countries.sql",
        """CREATE TABLE World(name TEXT, continent TEXT, area INT, population INT, gdp BIGINT);
        INSERT INTO World VALUES('A','X',3000000,1,0),('B','Y',1,25000000,0),
        ('C','Z',2999999,24999999,0);""",
        [("A", 1, 3000000), ("B", 25000000, 1)],
    ),
    (
        "0596_classes-with-at-least-5-students.sql",
        """CREATE TABLE Courses(student TEXT, class TEXT, PRIMARY KEY(student,class));
        INSERT INTO Courses VALUES('A','Math'),('B','Math'),('C','Math'),('D','Math'),
        ('E','Math'),('A','Science'),('B','Science'),('C','Science'),('D','Science');""",
        [("Math",)],
    ),
    (
        "0601_human-traffic-of-stadium.sql",
        """CREATE TABLE Stadium(id INT, visit_date TEXT, people INT);
        INSERT INTO Stadium VALUES(1,'2017-01-01',120),(2,'2017-01-02',100),
        (3,'2017-01-03',150),(4,'2017-01-04',30),(5,'2017-01-05',50),
        (6,'2017-01-06',100),(7,'2017-01-07',110),(8,'2017-01-08',130);""",
        [(1, "2017-01-01", 120), (2, "2017-01-02", 100), (3, "2017-01-03", 150),
         (6, "2017-01-06", 100), (7, "2017-01-07", 110), (8, "2017-01-08", 130)],
        True,
    ),
    (
        "0602_friend-requests-ii-who-has-the-most-friends.sql",
        """CREATE TABLE RequestAccepted(requester_id INT, accepter_id INT, accept_date TEXT);
        INSERT INTO RequestAccepted VALUES(1,2,'2020-01-01'),(1,3,'2020-01-02'),
        (2,3,'2020-01-03'),(3,4,'2020-01-04');""",
        [(3, 3)],
    ),
    (
        "0607_sales-person.sql",
        """CREATE TABLE SalesPerson(sales_id INT, name TEXT, salary INT, commission_rate INT, hire_date TEXT);
        CREATE TABLE Company(com_id INT, name TEXT, city TEXT);
        CREATE TABLE Orders(order_id INT, order_date TEXT, com_id INT, sales_id INT, amount INT);
        INSERT INTO SalesPerson VALUES(1,'Amy',100,1,'2020-01-01'),
        (2,'Bob',100,1,'2020-01-01'),(3,'Cal',100,1,'2020-01-01');
        INSERT INTO Company VALUES(10,'RED','X'),(11,'BLUE','Y');
        INSERT INTO Orders VALUES(1,'2020-01-01',10,2,50),(2,'2020-01-02',11,3,70);""",
        [("Amy",), ("Cal",)],
    ),
    (
        "0610_triangle-judgement.sql",
        """CREATE TABLE Triangle(x INT, y INT, z INT);
        INSERT INTO Triangle VALUES(3,4,5),(1,2,3),(5,5,9);""",
        [(3, 4, 5, "Yes"), (1, 2, 3, "No"), (5, 5, 9, "Yes")],
        True,
    ),
    (
        "0619_biggest-single-number.sql",
        """CREATE TABLE MyNumbers(num INT);
        INSERT INTO MyNumbers VALUES(8),(3),(3),(6);""",
        [(8,)],
    ),
    (
        "0620_not-boring-movies.sql",
        """CREATE TABLE Cinema(id INT, movie TEXT, description TEXT, rating REAL);
        INSERT INTO Cinema VALUES(1,'A','fun',8.0),(2,'B','fun',10.0),
        (3,'C','boring',9.0),(5,'D','fun',9.0);""",
        [(5, "D", "fun", 9.0), (1, "A", "fun", 8.0)],
        True,
    ),
    (
        "0626_exchange-seats.sql",
        """CREATE TABLE Seat(id INT, student TEXT);
        INSERT INTO Seat VALUES(1,'A'),(2,'B'),(3,'C'),(4,'D'),(5,'E');""",
        [(1, "B"), (2, "A"), (3, "D"), (4, "C"), (5, "E")],
        True,
    ),
    (
        "1050_actors-and-directors-who-cooperated-at-least-three-times.sql",
        """CREATE TABLE ActorDirector(actor_id INT, director_id INT, timestamp INT);
        INSERT INTO ActorDirector VALUES(1,1,1),(1,1,2),(1,1,3),
        (1,2,4),(1,2,5),(2,2,6);""",
        [(1, 1)],
    ),
    (
        "1068_product-sales-analysis-i.sql",
        """CREATE TABLE Product(product_id INT, product_name TEXT);
        CREATE TABLE Sales(sale_id INT, product_id INT, year INT, quantity INT, price INT);
        INSERT INTO Product VALUES(100,'Nokia'),(200,'Apple');
        INSERT INTO Sales VALUES(1,100,2008,10,5000),(2,100,2009,12,5000),
        (3,200,2011,15,9000);""",
        [("Nokia", 2008, 5000), ("Nokia", 2009, 5000), ("Apple", 2011, 9000)],
    ),
    (
        "1075_project-employees-i.sql",
        """CREATE TABLE Project(project_id INT, employee_id INT);
        CREATE TABLE Employee(employee_id INT, name TEXT, experience_years REAL);
        INSERT INTO Project VALUES(1,1),(1,2),(1,3),(2,1),(2,4);
        INSERT INTO Employee VALUES(1,'A',3),(2,'B',2),(3,'C',1),(4,'D',2);""",
        [(1, 2.0), (2, 2.5)],
    ),
    (
        "1084_sales-analysis-iii.sql",
        """CREATE TABLE Product(product_id INT, product_name TEXT, unit_price INT);
        CREATE TABLE Sales(seller_id INT, product_id INT, buyer_id INT,
                           sale_date TEXT, quantity INT, price INT);
        INSERT INTO Product VALUES(1,'S8',1000),(2,'G4',800),(3,'Pixel',900);
        INSERT INTO Sales VALUES(1,1,1,'2019-01-21',2,2000),
        (2,2,2,'2019-02-17',1,800),(3,2,3,'2019-06-02',1,800),
        (4,3,4,'2019-06-15',1,900);""",
        [(1, "S8")],
    ),
    (
        "1141_user-activity-for-the-past-30-days-i.sql",
        """CREATE TABLE Activity(user_id INT, session_id INT,
                               activity_date TEXT, activity_type TEXT);
        INSERT INTO Activity VALUES(1,1,'2019-06-27','open_session'),
        (1,2,'2019-06-28','open_session'),
        (1,3,'2019-07-20','open_session'),(1,4,'2019-07-20','scroll_down'),
        (2,5,'2019-07-20','send_message'),
        (3,6,'2019-07-21','open_session'),(4,7,'2019-07-21','end_session'),
        (5,8,'2019-07-27','open_session'),(6,9,'2019-07-28','open_session');""",
        [("2019-06-28", 1), ("2019-07-20", 2), ("2019-07-21", 2),
         ("2019-07-27", 1)],
    ),
    (
        "1527_patients-with-a-condition.sql",
        """CREATE TABLE Patients(patient_id INT, patient_name TEXT, conditions TEXT);
        INSERT INTO Patients VALUES(1,'Daniel','YFEV COUGH'),(2,'Alice',''),
        (3,'Bob','DIAB100 MYOP'),(4,'George','ACNE DIAB100'),
        (5,'Alain','DIAB201'),(6,'Boundary','XDIAB100');""",
        [(3, "Bob", "DIAB100 MYOP"), (4, "George", "ACNE DIAB100")],
    ),
    (
        "1581_customer-who-visited-but-did-not-make-any-transactions.sql",
        """CREATE TABLE Visits(visit_id INT, customer_id INT);
        CREATE TABLE Transactions(transaction_id INT, visit_id INT, amount INT);
        INSERT INTO Visits VALUES(1,23),(2,9),(4,30),(5,54),(6,96),(7,54),(8,54);
        INSERT INTO Transactions VALUES(2,5,310),(3,5,300),(9,5,200),(12,1,910),(13,2,970);""",
        [(30, 1), (54, 2), (96, 1)],
    ),
    (
        "1587_bank-account-summary-ii.sql",
        """CREATE TABLE Users(account INT, name TEXT);
        CREATE TABLE Transactions(trans_id INT, account INT, amount INT, transacted_on TEXT);
        INSERT INTO Users VALUES(900001,'Alice'),(900002,'Bob'),(900003,'Charlie'),(900004,'Dana');
        INSERT INTO Transactions VALUES(1,900001,7000,'2020-08-01'),(2,900001,7000,'2020-09-01'),
        (3,900001,-3000,'2020-09-02'),(4,900002,1000,'2020-09-12'),
        (5,900003,6000,'2020-08-07'),(6,900003,6000,'2020-09-07'),
        (7,900003,-4000,'2020-09-11');""",
        [("Alice", 11000)],
    ),
    (
        "1633_percentage-of-users-attended-a-contest.sql",
        """CREATE TABLE Users(user_id INT, user_name TEXT);
        CREATE TABLE Register(contest_id INT, user_id INT);
        INSERT INTO Users VALUES(6,'Alice'),(2,'Bob'),(7,'Alex');
        INSERT INTO Register VALUES(215,6),(209,2),(208,2),(210,6),(208,6),(209,7),
        (209,6),(215,7),(208,7),(210,2),(207,2),(210,7);""",
        [(208, 100.0), (209, 100.0), (210, 100.0), (215, 66.67), (207, 33.33)],
        True,
    ),
    (
        "1661_average-time-of-process-per-machine.sql",
        """CREATE TABLE Activity(machine_id INT, process_id INT, activity_type TEXT, timestamp REAL);
        INSERT INTO Activity VALUES(0,0,'start',0.712),(0,0,'end',1.520),
        (0,1,'start',3.140),(0,1,'end',4.120),(1,0,'start',0.550),(1,0,'end',1.550),
        (1,1,'start',0.430),(1,1,'end',1.420),(2,0,'start',4.100),(2,0,'end',4.512),
        (2,1,'start',2.500),(2,1,'end',5.000);""",
        [(0, 0.894), (1, 0.995), (2, 1.456)],
    ),
    (
        "1667_fix-names-in-a-table.sql",
        """CREATE TABLE Users(user_id INT, name TEXT);
        INSERT INTO Users VALUES(2,'bOB'),(1,'aLice');""",
        [(1, "Alice"), (2, "Bob")],
        True,
    ),
    (
        "1683_invalid-tweets.sql",
        """CREATE TABLE Tweets(tweet_id INT, content TEXT);
        INSERT INTO Tweets VALUES(1,'Let us Code'),(2,'More than fifteen chars are here!'),
        (3,'123456789012345');""",
        [(2,)],
    ),
    (
        "1693_daily-leads-and-partners.sql",
        """CREATE TABLE DailySales(date_id TEXT, make_name TEXT, lead_id INT, partner_id INT);
        INSERT INTO DailySales VALUES('2020-12-8','toyota',0,1),('2020-12-8','toyota',1,0),
        ('2020-12-8','toyota',1,2),('2020-12-7','toyota',0,2),('2020-12-7','toyota',0,1),
        ('2020-12-8','honda',1,2),('2020-12-8','honda',2,1),('2020-12-7','honda',0,1),
        ('2020-12-7','honda',1,2),('2020-12-7','honda',2,1),('2020-12-7','honda',2,1);""",
        [('2020-12-8','toyota',2,3),('2020-12-7','toyota',1,2),
         ('2020-12-8','honda',2,2),('2020-12-7','honda',3,2)],
    ),
    (
        "1729_find-followers-count.sql",
        """CREATE TABLE Followers(user_id INT, follower_id INT);
        INSERT INTO Followers VALUES(0,1),(1,0),(2,0),(2,1);""",
        [(0,1),(1,1),(2,2)],
        True,
    ),
    (
        "1731_the-number-of-employees-which-report-to-each-employee.sql",
        """CREATE TABLE Employees(employee_id INT, name TEXT, reports_to INT, age INT);
        INSERT INTO Employees VALUES(9,'Hercy',NULL,43),(6,'Alice',9,41),
        (4,'Bob',9,36),(2,'Winston',NULL,37);""",
        [(9,'Hercy',2,39)],
    ),
    (
        "1741_find-total-time-spent-by-each-employee.sql",
        """CREATE TABLE Employees(emp_id INT, event_day TEXT, in_time INT, out_time INT);
        INSERT INTO Employees VALUES(1,'2020-11-28',4,32),(1,'2020-11-28',55,200),
        (1,'2020-12-03',1,42),(2,'2020-11-28',3,33),(2,'2020-12-09',47,74);""",
        [('2020-11-28',1,173),('2020-11-28',2,30),
         ('2020-12-03',1,41),('2020-12-09',2,27)],
    ),
    (
        "1757_recyclable-and-low-fat-products.sql",
        """CREATE TABLE Products(product_id INT, low_fats TEXT, recyclable TEXT);
        INSERT INTO Products VALUES(0,'Y','N'),(1,'Y','Y'),(2,'N','Y'),(3,'Y','Y'),(4,'N','N');""",
        [(1,),(3,)],
    ),
    (
        "1789_primary-department-for-each-employee.sql",
        """CREATE TABLE Employee(employee_id INT, department_id INT, primary_flag TEXT);
        INSERT INTO Employee VALUES(1,1,'N'),(2,1,'Y'),(2,2,'N'),(3,3,'N'),
        (4,2,'N'),(4,3,'Y'),(4,4,'N');""",
        [(1,1),(2,1),(3,3),(4,3)],
    ),
    (
        "1795_rearrange-products-table.sql",
        """CREATE TABLE Products(product_id INT, store1 INT, store2 INT, store3 INT);
        INSERT INTO Products VALUES(0,95,100,105),(1,70,NULL,80);""",
        [(0,'store1',95),(0,'store2',100),(0,'store3',105),(1,'store1',70),(1,'store3',80)],
    ),
    (
        "1873_calculate-special-bonus.sql",
        """CREATE TABLE Employees(employee_id INT, name TEXT, salary INT);
        INSERT INTO Employees VALUES(2,'Meir',3000),(3,'Michael',3800),(7,'Addilyn',7400),
        (8,'Juan',6100),(9,'Kannon',7700);""",
        [(2,0),(3,0),(7,7400),(8,0),(9,7700)],
        True,
    ),
    (
        "1890_the-latest-login-in-2020.sql",
        """CREATE TABLE Logins(user_id INT, time_stamp TEXT);
        INSERT INTO Logins VALUES(6,'2020-06-30 15:06:07'),(6,'2021-04-21 14:06:06'),
        (6,'2019-03-07 00:18:15'),(8,'2020-02-01 05:10:53'),(8,'2020-12-30 00:46:50'),
        (2,'2020-01-16 02:49:50'),(2,'2019-08-25 07:59:08'),
        (14,'2019-07-14 09:00:00'),(14,'2021-01-06 11:59:59');""",
        [(6,'2020-06-30 15:06:07'),(8,'2020-12-30 00:46:50'),(2,'2020-01-16 02:49:50')],
    ),
    (
        "1907_count-salary-categories.sql",
        """CREATE TABLE Accounts(account_id INT, income INT);
        INSERT INTO Accounts VALUES(3,108939),(2,12747),(8,87709),(6,91796);""",
        [('Low Salary',1),('Average Salary',0),('High Salary',3)],
        True,
    ),
    (
        "1934_confirmation-rate.sql",
        """CREATE TABLE Signups(user_id INT, time_stamp TEXT);
        CREATE TABLE Confirmations(user_id INT, time_stamp TEXT, action TEXT);
        INSERT INTO Signups VALUES(3,'2020-03-21 10:16:13'),(7,'2020-01-04 13:57:59'),
        (2,'2020-07-29 23:09:44'),(6,'2020-12-09 10:39:37');
        INSERT INTO Confirmations VALUES(3,'2021-01-06 03:30:46','timeout'),
        (3,'2021-07-14 14:00:00','timeout'),(7,'2021-06-12 11:57:29','confirmed'),
        (7,'2021-06-13 12:58:28','confirmed'),(7,'2021-06-14 13:59:27','confirmed'),
        (2,'2021-01-22 00:00:00','confirmed'),(2,'2021-02-28 23:59:59','timeout');""",
        [(3,0.0),(7,1.0),(2,0.5),(6,0)],
    ),
    (
        "1965_employees-with-missing-information.sql",
        """CREATE TABLE Employees(employee_id INT, name TEXT);
        CREATE TABLE Salaries(employee_id INT, salary INT);
        INSERT INTO Employees VALUES(2,'Crew'),(4,'Haven'),(5,'Kristian');
        INSERT INTO Salaries VALUES(5,76071),(1,22517),(4,63539);""",
        [(1,),(2,)],
        True,
    ),
    (
        "1978_employees-whose-manager-left-the-company.sql",
        """CREATE TABLE Employees(employee_id INT, name TEXT, manager_id INT, salary INT);
        INSERT INTO Employees VALUES(3,'Mila',9,60301),(12,'Antonella',NULL,31000),
        (13,'Emery',NULL,67084),(1,'Kalel',11,21241),(9,'Mikaela',NULL,50937),
        (11,'Joziah',6,28485);""",
        [(11,)],
        True,
    ),
]

# These cases execute a SQLite equivalent where MySQL uses a dialect-specific
# date function or DELETE JOIN. The equivalence keeps the same row-matching rule.
SQLITE_EQUIVALENTS = {
    "0196_delete-duplicate-emails.sql": (
        """CREATE TABLE Person(id INT, email TEXT);
        INSERT INTO Person VALUES(1,'a@b.com'),(2,'c@d.com'),(3,'a@b.com'),(4,'x@y.com');""",
        "DELETE FROM Person WHERE EXISTS (SELECT 1 FROM Person AS earlier "
        "WHERE earlier.email = Person.email AND earlier.id < Person.id);",
        [(1, "a@b.com"), (2, "c@d.com"), (4, "x@y.com")],
        "DELETE later\nFROM Person AS later\nJOIN Person AS earlier\n  ON earlier.email = later.email\n AND earlier.id < later.id;",
    ),
    "0197_rising-temperature.sql": (
        """CREATE TABLE Weather(id INT, recordDate TEXT, temperature INT);
        INSERT INTO Weather VALUES(1,'2015-01-01',10),(2,'2015-01-02',25),
        (3,'2015-01-03',20),(4,'2015-01-04',30),(5,'2015-01-06',40);""",
        "SELECT today.id FROM Weather AS today JOIN Weather AS yesterday "
        "ON julianday(today.recordDate) - julianday(yesterday.recordDate) = 1 "
        "WHERE today.temperature > yesterday.temperature;",
        [(2,), (4,)],
        "DATEDIFF(today.recordDate, yesterday.recordDate) = 1",
    ),
    "0550_game-play-analysis-iv.sql": (
        """CREATE TABLE Activity(player_id INT, device_id INT, event_date TEXT, games_played INT);
        INSERT INTO Activity VALUES(1,1,'2020-01-01',2),(1,1,'2020-01-02',3),
        (2,2,'2020-01-01',1),(3,3,'2020-01-05',4),(3,3,'2020-01-07',2);""",
        "WITH FirstLogin AS (SELECT player_id, MIN(event_date) AS first_login FROM Activity GROUP BY player_id) "
        "SELECT ROUND(AVG(CASE WHEN next_day.player_id IS NOT NULL THEN 1 ELSE 0 END), 2) "
        "FROM FirstLogin AS first_day LEFT JOIN Activity AS next_day "
        "ON next_day.player_id = first_day.player_id "
        "AND next_day.event_date = DATE(first_day.first_login, '+1 day');",
        [(0.33,)],
        "DATE_ADD(first_day.first_login, INTERVAL 1 DAY)",
    ),
}

MUTATION_CASES = [
    (
        "0627_swap-salary.sql",
        """CREATE TABLE Salary(id INT, name TEXT, sex TEXT, salary INT);
        INSERT INTO Salary VALUES(1,'A','m',100),(2,'B','f',200),(3,'C','m',300);""",
        [(1, "A", "f", 100), (2, "B", "m", 200), (3, "C", "f", 300)],
    ),
]


def main() -> int:
    failed = 0
    passed = 0
    for case in CASES:
        filename, fixture, expected, *options = case
        ordered = options[0] if options else False
        with sqlite3.connect(":memory:") as database:
            database.create_function("regexp", 2, lambda pattern, value: int(re.search(pattern, value or "") is not None))
            database.create_function("left", 2, lambda value, count: value[:count])
            database.create_function("concat", 2, lambda left, right: left + right)
            database.executescript(fixture)
            query = (ROOT / "sql" / filename).read_text(encoding="utf-8")
            actual = database.execute(query).fetchall()
        ok = actual == expected if ordered else (
            set(actual) == set(expected) and len(actual) == len(expected)
        )
        print(f"{'PASS' if ok else 'FAIL'} {filename}: {actual}")
        failed += not ok
        passed += ok

    for filename, (fixture, equivalent, expected, source_fragment) in SQLITE_EQUIVALENTS.items():
        query = (ROOT / "sql" / filename).read_text(encoding="utf-8")
        if source_fragment not in query:
            print(f"FAIL {filename}: expected MySQL clause was not found")
            failed += 1
            continue
        with sqlite3.connect(":memory:") as database:
            database.executescript(fixture)
            if filename == "0196_delete-duplicate-emails.sql":
                database.executescript(equivalent)
                actual = database.execute("SELECT id, email FROM Person ORDER BY id").fetchall()
            else:
                actual = database.execute(equivalent).fetchall()
        ok = actual == expected
        print(f"{'PASS' if ok else 'FAIL'} {filename} (SQLite equivalent): {actual}")
        failed += not ok
        passed += ok

    for filename, fixture, expected in MUTATION_CASES:
        with sqlite3.connect(":memory:") as database:
            database.executescript(fixture)
            database.executescript((ROOT / "sql" / filename).read_text(encoding="utf-8"))
            actual = database.execute("SELECT id, name, sex, salary FROM Salary ORDER BY id").fetchall()
        ok = actual == expected
        print(f"{'PASS' if ok else 'FAIL'} {filename}: {actual}")
        failed += not ok
        passed += ok

    function_file = ROOT / "sql" / "0177_nth-highest-salary.sql"
    function_source = function_file.read_text(encoding="utf-8")
    function_body = function_source.split("RETURN (", 1)[1].rsplit(");", 1)[0]
    sqlite_function_query = function_body.replace("salary_rank = N", "salary_rank = ?")
    with sqlite3.connect(":memory:") as database:
        database.executescript(
            "CREATE TABLE Employee(id INT, salary INT);"
            "INSERT INTO Employee VALUES(1,100),(2,200),(3,200),(4,300);"
        )
        actual = [
            database.execute(sqlite_function_query, (rank,)).fetchone()
            for rank in (1, 2, 3, 4)
        ]
    expected = [(300,), (200,), (100,), (None,)]
    ok = actual == expected
    print(f"{'PASS' if ok else 'FAIL'} 0177_nth-highest-salary.sql function body: {actual}")
    failed += not ok
    passed += ok

    print(f"Summary: {passed}/{passed + failed} passed")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
