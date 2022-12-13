#include <iostream>
#include <memory>
using namespace std;



class Employee {
     private: 
    std::string name;
    int experience; //years of experience
    Employee *e;
  
    
   public:
   Employee() {};
   Employee(std::string empl_name, int empl_exp) ;
   Employee(const Employee &copy); 
    
    Employee& operator = (const Employee &copy ); 
    Employee& operator += (const Employee &copy ); //ITEM10 - assigment operator to return a reference to *this
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
   Employee::Employee(const Employee &copy) {
      name = copy.name;
      experience = copy.experience;
    }


  //ITEM 10
  Employee &Employee::operator+=(const Employee &copy) {
   std::cout<<"Copy assignment operator +=" <<std::endl;
   this->experience += copy.experience;
   this->name += copy.name;
     return *this;
   
   }


Employee &Employee::operator=(const Employee &copy){
  //ITEM11

if (this == &copy)
{
  std::cout <<"Assignment to self" <<std::endl;
  return *this;
}
 std::cout<<"Copy assignment operator +="<<std::endl;
   this->experience = copy.experience;
   this->name = copy.name;
     return *this;
   
}


 
  class ProductManager : public Employee
  {
    private:
    int age; //ITEM 12
    public:
    ProductManager();
    ProductManager (std::string empl_name, int empl_exp, int age); //ITEM 12
    ~ProductManager();
    ProductManager &operator = (const ProductManager &p_m);
    //ProductManager (ProductManager &pr_manag);
    void display1();
  };

  //for ITEM 12
void ProductManager::display1()
    {
      std::cout<<this->age<<std::endl;
    }


ProductManager :: ProductManager (std::string empl_name, int empl_exp, int age) 
: Employee (empl_name, empl_exp), age(age) //ITEM 12
{

}

//ITEM 12
ProductManager &ProductManager::operator = (const ProductManager &pm)
{
  if (this == &pm)
  {
    std::cout <<"Assignment to self" <<std::endl;
    return *this;
  }
  std::cout << "Copy assignment operator in ProductManager" <<std::endl;
  Employee::operator=(pm); //assign base class parts
  this->age = pm.age;
  return *this;
}




ProductManager:: ~ProductManager() {
  std::cout<<" ProductManager Destroyed"<<endl;
}



//ITEM 13 
Employee* factoryMethod() {
  return (new Employee);
} 

class Intern{
  private:
  bool angajat = false;
  int age = 22;


  public:
  Intern(int age) {
    std::cout << "Intern Constructor"<<std::endl;
     this->age = age;
  }

  Intern (const Intern &i){
    std::cout <<"Intern copy constructor"<<std::endl;
    this->age = i.age;
    this->angajat = i.angajat;
  }

  ~Intern(){
    std::cout<<"Intern sters"<<std::endl;
  }

  int getVarsta(){
    return this->age;
  }

  int getAngajat(){
    return this->angajat;
  }

  void setAngajat(bool angajat){
    this->angajat = angajat;
  }

  void InterAngajat(){
    if(this->angajat == false)
       std::cout<<"Intern cu varsta de " << this->age <<  " NU este angajat"<<std::endl;
        else
            std::cout<<"Intern cu varsta de " << this->age << " este angajat" <<std::endl;
  }

};
void lock(Intern &i){
    std::cout<<"Intern cu varsta de " << i.getVarsta() << "nu se regaseste in baza de date"<<std::endl;
    i.setAngajat(true);
}

void unlock(Intern &i){
    std::cout<<"Intern cu varsta de " << i.getVarsta() << " se regaseste din nou in baza de date"<<std::endl;
    i.setAngajat(false);
}


class Manager{
    private:
        Intern &intern;
    public:
    Manager(Intern &i):intern(i){
        lock(intern);
    }
    ~Manager(){
        unlock(intern);
    }
};




int main() {

//TEMA 3:
//ITEM 13
     {
        std::auto_ptr<Employee> employee1(factoryMethod()); //smart pointer whose destructor automatically calls delete on what it points to
        std::auto_ptr<Employee> employee2(employee1);
    }
   
    {
        std::shared_ptr<Employee> employee1(factoryMethod()); //reference-counting smart pointer that keeps track of how many objects point to a particular resource and automatically deletes the resource
        std::cout << "Employee1 " << employee1.use_count() << std::endl; //Returns the number of different shared_ptr instances managing the current object(employee1)
        std::shared_ptr<Employee> employee2(employee1);
        std::cout << "Employee1 " << employee1.use_count() << std::endl;
        std::shared_ptr<Employee> employee3(employee1);
        std::cout << "Employee1 " << employee1.use_count() << std::endl;
        std::cout << "Employee3 " << employee3.use_count() << std::endl;
    }

    //ITEM 14
     Intern i(18);
    Manager *manager = new Manager(i);
    i.InterAngajat();
    delete manager;
    i.InterAngajat();
    lock(i);
    i.InterAngajat();
    unlock(i);
    i.InterAngajat();


/* TEMA2:
  //ITEM 10:
  Employee e ("Vivi", 4);
  Employee e1 ("Ion", 1);
  Employee e2 ("Maria", 7);
  e2 += e1 += e;
  e2.display();


  //ITEM 11: 
     e=e1;
     //e.display();
     e2=e2;

  //ITEM 12:
   ProductManager pm1("Vasile", 4, 30);
   ProductManager pm2("Cristi", 1, 20);

   pm1 = pm2;
   pm1.display1();



  /* TEMA1:
  Employee employee1("Ioana", 2); 
  // Copy constructor
  Employee employee2 = employee1; 
  Employee employee3("Maria", 1);
  employee3+=employee1; //for the copy assignment operator
  employee3.display();
  cout << "Employee1 using parameterized constructor : \n";
  employee1.display();
  cout << "Employee2 using copy constructor : \n";
  employee2.display();
*/
 
}

