#include <iostream>
using namespace std;

class BankAccount{
  friend ostream& operator<<(ostream&, BankAccount&);
  
  public:
    BankAccount(double anAmount);
	bool operator== (const BankAccount & b);
	bool operator!= (const BankAccount & b);
	void printOn(ostream& o) const;

  private:
    double balance;
};
