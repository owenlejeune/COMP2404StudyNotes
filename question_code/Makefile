exam:	main.o BankAccount.o
	g++ -o exam main.o BankAccount.o

main.o:	BankAccount.o main.cc BankAccount.h
	g++ -c main.cc

BankAccount.o:	BankAccount.h
	g++ -c BankAccount.cc

clean:
	rm -f *.o exam
