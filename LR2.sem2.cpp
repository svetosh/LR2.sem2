#include <iostream>
#include <string>

using namespace std;

class school
{

private:

 string name;
 int money;
 int howManyTeatcher;
 
 public:
 
  school(string newName, int newMoney, int newTeatcher)
  {
	  name = newName;
	  money = newMoney;
	  howManyTeatcher = newTeatcher;
	  cout << "Constuctor" << endl;
  }
  
  int financing()
  {
	 int res = money * howManyTeatcher;
	 return res; 
  }

	void print()
	{
		cout << "Teatchers " << howManyTeatcher << endl;
		cout << "Money for a teatcher " << money << endl;
		cout << "Name school " << name << endl;
	}
};

class region
{
	
	private:
	
	string name;
	int coeff;
	
	public:
	
	region(string newName, int newCoeff)
	{
	    cout << "Constuctor" << endl;
		name = newName;
		coeff = newCoeff;
	}
	
	void print()
	{
		cout << "Name region " << name << endl;
		cout << "Coefficient " << coeff << endl;
	}
};




int main()
{
	school a("Bauman", 10000, 5);
	a.financing();
	a.print();
	
	
	
	return 0;
}
