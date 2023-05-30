#include <iostream>
#include <string>

#include "../../include/Util.h"

int strToInt(const std::string &s)
{
  int nb = 0;
  long unsigned int i;
  for (i = 0; i < s.length(); i++)
  {
    nb *= 10;
    nb += (s.at(i) - 48);
  }
  return nb;
}

double strToDouble(const std::string &str)
{
  double nb = 0;
  long unsigned int i = 0, p = 10;
  int neg = 1;

  //Gestion des nombres négatifs
  if (!((str.at(i) >= '0' && str.at(i) <= '9') || str.at(i) == '-'))
    throw std::invalid_argument("Invalid argument");
  if (str.at(0) == '-')
  {
    i++;
    neg = -1;
  }

  //Gestion des nombres avant la virgule
  while (i < str.length() && str.at(i) != '.')
  {
    nb *= 10;
    if (!((str.at(i) >= '0' && str.at(i) <= '9') || str.at(i) == '-'))
      throw std::invalid_argument("Invalid argument");
    nb += str.at(i) - 48;
    i++;
  }
  i++;

  //Gestion des nombres après la virgule
  while (i < str.length())
  {
    if (!((str.at(i) >= '0' && str.at(i) <= '9') || str.at(i) == '-'))
      throw std::invalid_argument("Invalid argument");
    nb += double(str.at(i) - 48) / p;
    p *= 10;
    i++;
  }
  return (neg * nb);
}