# **Overloading the assignment operator**

The **assignment operator** copies values from a pre-existing object to another

#### Assignment vs. Copy constructor

The purpose of the two are basically the same, but the difference is the assignment operator uses already existing objects
  where the copy constructor creates a new object and assigns the values

#### overloading the assignment operator(operator=) must be done as a **Member Function**

##### **Assignment Example**

```
class Fraction{
 private: //private data members
	int num;
	int denom;
 
public: //public member functions
    //Default constructor
    Fraction(int num=0, int denom=1);
 
    //Overloaded assignment
        Fraction& operator= (const Fraction &fraction);
  //friend function to so we can use cout<< on fraction
	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1);
};
 
 //print function to display the fraction using friend ostream operator<<
std::ostream& operator<<(std::ostream& out, const Fraction &f1)
{
	out << f1.num << "/" << f1.denom;
	return out;
}
 
//basic assignment copy
Fraction& Fraction::operator= (const Fraction &fraction)
{
    // copy from RHS to LHS
    num = fraction.num;
    denom = fraction.denom;
 
    //return the existing object
    return *this;
}
 
int main()
{
    Fraction fiveThirds(5, 3);
    Fraction f;
    f = fiveThirds; // calls overloaded assignment
    std::cout << f;
    return 0;
    }
  ```
this will display 5/3 to the screen

The overloaded assignment return * this so we can chan assignments
	such as f1 = f2 = f3;
	
#### Self Assignment
    c++ allows self assignment is simple form, and will copy the values from itself to itself.
    However when using dynamic memorory it can be tricky. For example
```
class MyString
{
private:
    char *m_data;
    int m_length;
 
public:
    MyString(const char *data="", int length=0) :
        m_length(length)
    {
        if (!length)
            m_data = nullptr;
        else 
            m_data = new char[length];
 
        for (int i=0; i < length; ++i)
            m_data[i] = data[i];
    }
 
    // Overloaded assignment
    MyString& operator= (const MyString &str);
 
    friend std::ostream& operator<<(std::ostream& out, const MyString &s);
};
 
std::ostream& operator<<(std::ostream& out, const MyString &s)
{
    out << s.m_data;
    return out;
}
 
// A simplistic implementation of operator= (do not use)
MyString& MyString::operator= (const MyString &str)
{
    // if data exists in the current string, delete it
    if (m_data) delete[] m_data;
 
    m_length = str.m_length;
 
    // copy the data from str to the implicit object
    m_data = new char[str.m_length];
 
    for (int i=0; i < str.m_length; ++i)
        m_data[i] = str.m_data[i];
 
    // return the existing object so we can chain this operator
    return *this;
}
 
int main()
{
    MyString alex("Alex", 5); // Meet Alex
    MyString employee;
    employee = alex; // Alex is our newest employee
    std::cout << employee; // Say your name, employee
 
    return 0;
}
```
Running it as is should result in Alex being displayed
But if run by the main()
```
int main()
{
    MyString alex("Alex", 5); // Meet Alex
    alex = alex; // Alex is himself
    std::cout << alex; // Say your name, Alex
 
    return 0;
}
```
This gives garbage! due to assigning Alex to Alex
Consider what happens in the overloaded operator= when the implicit object AND the passed in parameter (str) are both variable alex. In this case, m_data is the same as str._m_data. The first thing that happens is that the function checks to see if the implicit object already has a string. If so, it needs to delete it, so we don’t end up with a memory leak. In this case, m_data is allocated, so the function deletes m_data. But str.m_data is pointing to the same address! This means that str.m_data is now a dangling pointer.

Later on, we allocate new memory to m_data (and str.m_data). So when we subsequently copy the data from str.m_data into m_data, we’re copying garbage, because str.m_data was never initialized.

#### **Detecting and handling self-assignment**

Luckily we can detect and prevent self-assignment by simply checking in the overloaded assignment
```
// self-assignment guard
    if (this == &fraction)
        return *this;
```
If the two fractions are already equal, then stop the function and return.
There is *NO* need to do this for copy constructors as there is no way to assign from an object not yet made

#### **Default Assignment Operator**
If you do not overload the assignment operator in your class, the compiler will make a default one for you. When the 
	default is used it merely does memberwise assignments. 
If we want to prevent assignment statements we can either delete the overload or put it under private
