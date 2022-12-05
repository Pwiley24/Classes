#include <iostream>
#include <cstring>
#include "digitalMedia.h"

using namespace std;

class Music: public digitalMedia{
 private:
  int duration;
  char* artist;
  char* publisher;

 public:
  Music();
  char* getArtist();
  int getDuration();
  char* getPublisher();
  void setDuration(int time);
  void setArtist(char*);
  void setPublisher(char*);
  virtual void print();
};
