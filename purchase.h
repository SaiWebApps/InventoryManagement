#include <stdio.h>
#include <list>
#include <iostream>
#include <string>

using namespace std;

class Purchase
{
   private:
	int quantity; //Number of units purchased
	float price; //Price of purchase

   public:
	Purchase() { quantity = 0; price = 0.0f; }
	Purchase(int quantity, float price);
	int getQuantity() { return quantity; }
	float getPrice() { return price; }
	void print() { cout << quantity << " units @ $" << price <<  endl; }
};
