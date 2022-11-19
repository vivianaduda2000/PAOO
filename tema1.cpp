
 
#include<iostream>
using namespace std;


class Employee {
  private: 
    std::string name;
    int experience; //years of experience
    
   public:
   Employee(std::string empl_name, int empl_exp) ;
    Employee(const Employee &new_employee); //= delete; //copy constructor
    Employee& operator = (const Employee& copy ); //copy assignment operator
    ~Employee();//destructor
  
    
    void display() {
      std::cout << "Name: " << name << endl << "Years of experience: "<< experience << endl;
    }
  
};
//initialization
Employee::Employee (std::string empl_name, int empl_exp)
:name(empl_name), experience(empl_exp) {}

//destructor
Employee::~Employee()
{
    cout <<"Employee destroyed"<<endl;
}

 // Copy constructor
   Employee:: Employee(const Employee &new_employee) {
      name = new_employee.name;
      experience = new_employee.experience;
    }
    //copy assignment operator
  Employee &Employee::operator=(const Employee &copy) {
   std::cout<<"Copy assignment operator: "<<endl;
   this->experience = copy.experience;
   this->name = copy.name;
     return *this;
   
   }
  /*class ProductManager : public Employee
  {
    public:
    ProductManager();
    ~ProductManager();
    ProductManager(const ProductManager &p); //= delete;
    ProductManager &operator = (const ProductManager &p);
    void display();
  };
ProductManager::ProductManager() : Employee ("Vlad", 20)
{

}
ProductManager :: ~ProductManager()
{
  std::cout <<"Product Manager destroyed"<<std::endl;
}*/

int main() {
  // Parameterized constructor
  Employee employee1("Ioana", 2); 
  // Copy constructor
  Employee employee2 = employee1; 
  Employee employee3("Maria", 1);
  employee3=employee1; //for the copy assignment operator
  employee3.display();
  cout << "Employee1 using parameterized constructor : \n";
  employee1.display();
  cout << "Employee2 using copy constructor : \n";
  employee2.display();
  return 0;
}