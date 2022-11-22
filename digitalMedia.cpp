#include <iostream>
#include <cstring>
#include "digitalMedia.h"

using namespace std;

digitalMedia::digitalMedia(){
  title = new char[30];
}

char* digitalMedia::getTitle() {
  return title;
}
void digitalMedia::setTitle(char* name){
  title = new char[30];
  strcpy(title, name);
}
int digitalMedia::getYear(){
  return year;
}
void digitalMedia::setYear(int date){
  year = date;
}
virtual void digitalMedia::print(){
  cout << "Error- no assigned media type" << endl;
}


