/*
Developer comments:
    - Should probably add a function to remove an employee completely from the vector of Employees. If a user makes
        a mistake of adding something they didn't want, there's no way of removing it currently.
    
*/

#include <iostream>
#include <stdexcept>
#include "database.h"
#include "employee.h"

using namespace std;
using namespace Records;

namespace Records {
            /*
                addEmployee(string, string)

                Add employee to the database.

            Returns: Employee
                Variable of type employee from the vector of employees in database.h
            Throws:
                N/A. Tested multiple items, does not break. 

            */
            Employee& Database::addEmployee(const std::string& firstName, const std::string& lastName){
                Employee theEmployee(firstName, lastName);
                theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
                theEmployee.hire();
                mEmployees.push_back(theEmployee);
                return mEmployees[mEmployees.size() - 1];
            }
            /*
                getEmployee(int)

                Find an employee from the database using their employee number.

            Returns: Employee
                Returns a variable of type Employee
            Throws:
                logic_error if Employee number is not found.
            */
            Employee& Database::getEmployee(int employeeNumber){
                for(auto& employee : mEmployees) {
                    if (employee.getEmployeeNumber() == employeeNumber){
                        return employee;
                    }           
                }
                throw logic_error("No employee found.");
            }
            /*
                getEmployee(string, string)

                Find an employee from the database using their first and last name.

                Returns: Employee
                    Returns a variable of type Employee
                Throws:
                    logic_error if Employee name is not found.
            */
            Employee& Database::getEmployee(const std::string& firstName, const std::string& lastName){
                for (auto& employee : mEmployees) {
                    if(employee.getFirstName() == firstName && employee.getLastName() == lastName){
                        return employee;
                    }
                }
                throw logic_error("No employee found.");
            }
            /*
                displayAll()

                Display all employees in the database.

                Returns:
                    N/A
                Throws:
                    N/A
            */
            void Database::displayAll() const{
                for(const auto& employee : mEmployees){
                    employee.display();
                }
            }
            /*
                displayCurrent()

                Display all employees currently employed to the company.

                Returns:
                    N/A
                Throws:
                    N/A
            */
            void Database::displayCurrent() const{
                for(const auto& employee : mEmployees){
                    if(employee.isHired()){
                        employee.display();
                    }
                }
            }
            /*
                displayFormer()

                Display all employees fired and/or laid off from the company.

                Returns:
                    N/A
                Throws:
                    N/A
            */
            void Database::displayFormer() const{
                for(const auto& employee : mEmployees){
                    if(!employee.isHired()){
                        employee.display();
                    }
                }
            }
}

//Testing database class
/* int main() {

    Database myDB;
    Employee& emp1 = myDB.addEmployee("Greg", "Wallis");
    emp1.fire();

    Employee& emp2 = myDB.addEmployee("Marc", "White");
    emp2.setSalary(100000);

    Employee& emp3 = myDB.addEmployee("John", "Doe");
    emp3.setSalary(10000);
    emp3.promote();

    cout << "All employees: " << endl << endl;
    myDB.displayAll();

    cout << endl << "Current employees: " << endl << endl;
    myDB.displayCurrent();

    cout << endl << "Former employees: " << endl << endl;
    myDB.displayFormer();


} */