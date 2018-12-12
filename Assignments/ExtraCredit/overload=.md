# **Overloading the assignment operator**

The **assignment operator** copies values from a pre-existing object to another

#### Assignment vs. Copy constructor

The purpose of the two are basically the same, but the difference is the assignment operator uses already existing objects
  where the copy constructor creates a new object and assigns the values

#### overloading the assignment operator(operator=) must be done as a **Member Function**

##### **Assignment Example**

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
    return 0;}
