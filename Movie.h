#include <iostream>
#include <cstring>
#include "digitalMedia.h"

using namespace std;

class Movie: public digitalMedia{
 private:
  int duration;
  float rating;
  char* director;

 public:
  Movie();
  void setRating(float rate);
  float getRating();
  void setDirector(char*);
  char* getDirector();
  int getDuration();
  void setDuration(int time);
  virtual void print(); 
};
