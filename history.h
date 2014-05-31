#include "purchase.h"

typedef enum { LIFO, FIFO } INVENTORY_TYPE;

class History {
   private:
	list<Purchase> history;
	float costOfGoodsSold;
	INVENTORY_TYPE type;

   public:
	History() { type = LIFO; costOfGoodsSold = 0.0f; }
	History(INVENTORY_TYPE);
	void setType(INVENTORY_TYPE t) { this->type = t; }
	void add(Purchase);
	void remove();
	Purchase peek();
	float getEndingInventoryDollars();
	int getEndingInventoryUnits();
	float getCostOfGoodsSold() { return costOfGoodsSold; }
	void print();
};
