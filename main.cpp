#include "history.h"

void addToInventory(History *h) {
    int quantity;
    float price;

    cout << "Please enter an integer quantity: ";
    cin >> quantity;
    cout << "Please enter the price of the purchase: ";
    cin >> price;
    (*h).add(Purchase(quantity, price));
}

void processInput(History *h) {
    char op;

    cout << "Desired Operation? (A)dd, (R)emove - ";
    cin >> op;
    switch(op) {
	case 'A': addToInventory(h); break;
	case 'R': (*h).remove(); break; 
	default: cerr << "Invalid operation\n"; break;
    }
}

void processInventoryType(History *h) {
    char type;
    cout << "(F)ifo OR (L)ifo? ";
    cin >> type;
    
    switch (type) {
      case 'F': (*h).setType(FIFO); break;
      case 'L': (*h).setType(LIFO); break;
      default: cerr << "Invalid input - Please type F or L." << endl;
    }
}

int main() {
  History history;
  char status = 'N';

  cout << "Welcome to Inventory Management 1.0" << endl;
  processInventoryType(&history);

  while (1) {
    processInput(&history);
   
    cout << "Continue add/remove operations? (Y/N) ";
    cin >> status;
    if (status == 'N' || status == 'n') {
       break;
    }
    cout << "-------------------" << endl;
  }

  history.print();
  return 0;
}
