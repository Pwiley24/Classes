#ifndef NAME
#define NAME
#include <iostream>
#include <cstring>

using namespace std;

class digitalMedia{
protected:
  int year;
  char* title;
  
 public:
  digitalMedia();
  void setYear(int date);
  char* getTitle();
  int getYear();
  void setTitle(char*);
  virtual void print();
 
};

#endif
