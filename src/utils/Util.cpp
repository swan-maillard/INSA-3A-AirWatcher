#include <iostream>
#include <string>

#include "../../include/Util.h"

int strToInt(const std::string &s) 
{
  int nb = 0;
  long unsigned int i;
  for (i = 0 ; i < s.length() ; i++){
    nb*=10;
    nb += (s.at(i) - 48);
  }
  return nb;
}

double strToDouble(const std::string &str) 
{
    double nb = 0;
    long unsigned int i = 0, p = 10;
    while (i < str.length() && str.at(i) != '.'){
        nb *= 10;
        nb += str.at(i) - 48;
        i++;
    }
    i++;
    while (i < str.length()){
        nb += double(str.at(i) - 48 ) / p;
        p*=10;
        i++;
    }
    return nb;
}