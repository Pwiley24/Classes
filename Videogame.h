#include <iostream>
#include <cstring>
#include "digitalMedia.h"

using namespace std;

class Videogame: public digitalMedia{
private:
  float rating = 0;
  char* publisher;

public:
  Videogame();
  float getRating();
  void setRating(float rate);
  char* getPublisher();
  void setPublisher(char*);
  virtual void print(char*, int date, char*, float rate);
};

