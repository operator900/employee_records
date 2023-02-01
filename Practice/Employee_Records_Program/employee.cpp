#include <iostream>
#include "employee.h"

using namespace std;

namespace Records {
    //Constructor
    Employee::Employee(const std::string& firstName, const std::string &lastName) : mFirstName(firstName), mLastName(lastName){}

    /*
        promote(int)

        Promote an employee with a given amount added to their salary.

        Returns:
            None.
        Throws:
            logic_error if Employee is not found. 
            - Note: program does crash if a string is entered.
    */
    void Employee::promote(int raiseAmount){
        setSalary(getSalary() + raiseAmount);
    }
    /*
        demote(int)

        Demote an employee with a given amount deducted from their salary.

        Returns:
            None.
        Throws:
            logic_error if Employee is not found.
            - Note: as stated above, program crashes if string is entered
    */
    void Employee::demote(int demeritAmount){
        setSalary(getSalary() - demeritAmount);
    }
    /*
        hire()

        Hire an individual.

        Returns:
            None. Sets the employee's status as hired. 
        Throws:
            None.
    
    */
    void Employee::hire(){
        mHired = true;
    }
    /*
        fire()

        Fire an individual.

        Returns:
            None. Sets the ex-employee's status as fired.
    */
    void Employee::fire(){
        mHired = false;
    }

    /*
        display()

        Displays an individual's information.

        Returns:
            None
        Throws:
            None
    */
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