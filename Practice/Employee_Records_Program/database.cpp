#include <iostream>
#include <stdexcept>
#include "database.h"
#include "employee.h"

using namespace std;
using namespace Records;

namespace Records {
            //Add employee to the database.
            Employee& Database::addEmployee(const std::string& firstName, const std::string& lastName){
                Employee theEmployee(firstName, lastName);
                theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
                theEmployee.hire();
                mEmployees.push_back(theEmployee);
                return mEmployees[mEmployees.size() - 1];
            }
            //Find an employee from the database using their employee number.
            Employee& Database::getEmployee(int employeeNumber){
                for(auto& employee : mEmployees) {
                    if (employee.getEmployeeNumber() == employeeNumber){
                        return employee;
                    }           
                }
                throw logic_error("No employee found.");
            }
            //Find an employee using first name and last name.
            Employee& Database::getEmployee(const std::string& firstName, const std::string& lastName){
                for (auto& employee : mEmployees) {
                    if(employee.getFirstName() == firstName && employee.getLastName() == lastName){
                        return employee;
                    }
                }
                throw logic_error("No employee found.");
            }
            //Display all employees in the database.
            void Database::displayAll() const{
                for(const auto& employee : mEmployees){
                    employee.display();
                }
            }
            //Display all employees currently employed to the company.
            void Database::displayCurrent() const{
                for(const auto& employee : mEmployees){
                    if(employee.isHired()){
                        employee.display();
                    }
                }
            }
            //Display all employees fired and/or laid off from the company.
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