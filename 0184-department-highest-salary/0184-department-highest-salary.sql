# Write your MySQL query statement below
SELECT Department.name AS Department, Employee.name AS Employee,Employee.salary AS Salary FROM Employee
JOIN Department ON Employee.departmentid=Department.id
WHERE Employee.salary = (
    SELECT MAX(salary)
    FROM Employee Emp
    WHERE Emp.departmentId = Employee.departmentId
);