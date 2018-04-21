#include "OrderedCollection.h"
#include "BankAccount.h"

int main() {
  BankAccount b1(100.0), b2(50.0), b3(200.0), b4(150.0);
  OrderedCollection<BankAccount> accounts;
  accounts.addLast(b1).addLast(b2).addLast(b3).addLast(b4).addLast(b2);

  accounts.print();
  accounts.remove(b2);
  accounts.print();
  OrderedCollection<BankAccount> a2 = accounts;
  a2.addFirst(b2);
  a2.print();
  return 0;
}
