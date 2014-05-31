#include "history.h"

History::History(INVENTORY_TYPE t) {
  this->type = t;
}

/* Add lastest inventory purchase to the end of the list. */
void History::add(Purchase p) {
   history.push_back(p);
}

/* When inventory is consumed, remove oldest inventory under FIFO system
 * and latest inventory under LIFO system. Add value of consumed inventory
 * to cost of goods sold. */
void History::remove() {
   Purchase p;
   switch (type) {
      case LIFO: p = history.back(); history.pop_back(); break;
      case FIFO: p = history.front(); history.pop_front(); break;
   }
   costOfGoodsSold += p.getQuantity() * p.getPrice();
}

/* Return the value of the ending inventory in dollars. */
float History::getEndingInventoryDollars() {
    float value = 0.0f;
    list<Purchase>::iterator it;

    for (it = history.begin(); it != history.end(); it++) {
       Purchase p = *it;
       value += p.getQuantity() * p.getPrice();
    }
    return value;
}

/* Return the number of units in the ending inventory. */
int History::getEndingInventoryUnits() {
   int n = 0;
   list<Purchase>::iterator it;

   for (it = history.begin(); it != history.end(); it++) {
      	Purchase p = *it;
	n += p.getQuantity();
   }
   return n;
}

void History::print() {
   list<Purchase>::iterator it;

   cout << "\n*****CURRENT INVENTORY*******" << endl;
   if (history.empty()) {
      cout << "\tEMPTY";
   }
   for (it = history.begin(); it != history.end(); it++) {
	(*it).print();
   }

   cout << "\n********INVENTORY SUMMARY*******\n";
   cout << "Units Ending Inventory = " << getEndingInventoryUnits() << endl;
   cout << "Ending Inventory = $" << getEndingInventoryDollars() << endl; 
   cout << "Cost of Goods Sold = $" << getCostOfGoodsSold() << endl;
}
