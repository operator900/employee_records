#include <iostream>
#include "employee.h"

using namespace std;

namespace Records {
    //Constructor
    Employee::Employee(const std::string& firstName, const std::string &lastName) : mFirstName(firstName), mLastName(lastName){}

    //Promote an employee with a given amount added to their salary.
    void Employee::promote(int raiseAmount){
        setSalary(getSalary() + raiseAmount);
    }
    //Demote an employee with a given amount deducted from their salary.
    void Employee::demote(int demeritAmount){
        setSalary(getSalary() - demeritAmount);
    }
    //Hire an individual.
    void Employee::hire(){
        mHired = true;
    }
    //Fire an individual.
    //Later version can add a function to remove individual from the database.
    void Employee::fire(){
        mHired = false;
    }
    //Display employee's information.
    void Employee::display() const {
        cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
        cout << "----------------------------------------" << endl;
        cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
        cout << "Employee Number: " << getEmployeeNumber() << endl;
        cout << "Salary: $" << getSalary() << endl;
        cout << endl;
    }
    //Setters & getters for private members. 
    void Employee::setFirstName(const std::string& firstName){
        mFirstName = firstName;
    }

    const std::string& Employee::getFirstName() const {
        return mFirstName;
    }

    void Employee::setLastName(const std::string& lastName){
        mLastName = lastName;
    }

    const std::string& Employee::getLastName() const {
        return mLastName;
    }

    void Employee::setEmployeeNumber(int employeeNumber){
        mEmployeeNumber = employeeNumber;
    }
    int Employee::getEmployeeNumber() const{
        return mEmployeeNumber;
    }

    void Employee::setSalary(int newSalary){
        mSalary = newSalary;
    }
    int Employee::getSalary() const{
        return mSalary;
    }

    bool Employee::isHired() const{
        return mHired;
    }
}
//Testing employee class
    /* int main() {
        using namespace Records;

        cout << "Testing the employee class." << endl;
        Employee emp;
        emp.setFirstName("John");
        emp.setLastName("Doe");
        emp.setEmployeeNumber(71);
        emp.setSalary(50000);
        emp.promote();
        emp.promote(50);
        emp.hire();
        emp.display();
        return 0;
}
 */