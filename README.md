InventoryManagement
===================

C++ Inventory Management Software - Supports FIFO and LIFO methods

Lessons Learned
----------------
<br>1. C++ classes, basic I/O
<br>2. Whereas Java objects are references (think pointers), C++ class instances are more like structs. Since C++ passes arguments by value to functions, we need to thereby pass the pointer to a class instance as an arg in order to modify it within the function.
<br>3. Given "*h.add(x)", we make the function call first and then dereference the result of that call. If we want to dereference h and then make the call, then we would do this: "(*h).add(x)".

Features
-----------------
<br>1. Allows users to specify whether they want to use a FIFO or a LIFO method for tracking inventory
<br>2. Allows users to add or remove items from the inventory
   * If FIFO, we remove the oldest inventory.
   * If LIFO, we remove the latest inventory.
   
<br>3. At the end, after the user is done manipulating the inventory, we display the ending inventory and COGS.
<br>4. Error handling - Displays error messages to guide user in the right direction and allows user to try again.
