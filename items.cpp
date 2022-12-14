#include <iostream>
#include <cstring>
#include <vector>
#include "items.h"
/* Name: Ishaan Varma
   Date: 12/14/2022
   Purpose: Where the functions of the items class are implemented
*/
using namespace std;

//default constructor
Item::Item() {
  strcpy(title, "   ");
}

//regular constructor
Item::Item(const char* newTitle) {
  strcpy(title, newTitle);
}

//returns the title.
char* Item::getTitle() {
  return title;
}
