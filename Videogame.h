#include <iostream>
#include <cstring>
#include "digitalMedia.h"

using namespace std;

class Videogame: public digitalMedia{
private:
  float rating;
  char* publisher;

public:
  Videogame();
  float getRating();
  void setRating(float rate);
  char* getPublisher();
  void setPublisher(char*);
  virtual void print();
};

