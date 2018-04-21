#include "BankAccount.h"

BankAccount::BankAccount(double anAmount) : balance(anAmount) {} 
bool BankAccount::operator== (const BankAccount & b) {return &b == this;}
bool BankAccount::operator!= (const BankAccount & b) {return &b != this;}
void BankAccount::printOn(ostream & o) const { o << "$" << balance << "\n"; }

ostream& operator<<(ostream& o, BankAccount& b){ 
	b.printOn(o);
	return o;
}
