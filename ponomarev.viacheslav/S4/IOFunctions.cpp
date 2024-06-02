#include "IOFunctions.hpp"
#include <iostream>
#include "cutFunctions.hpp"

void ponomarev::inputFromFile(std::istream & in, BinarySearchTree< std::string, BinarySearchTree< int, std::string, int >, int > & data)
{
  std::string dataLine = "";
  std::string name = "";
  std::string value = "";
  int key = 0;
  using data_t = ponomarev::BinarySearchTree< int, std::string, int >;

  while (std::getline(in, dataLine))
  {
    data_t dataSet;
    name = ponomarev::getName(dataLine);
    while (!dataLine.empty())
    {
      key = int(ponomarev::getNumber(dataLine));
      value = ponomarev::getName(dataLine);
      dataSet.insert(std::make_pair(key, value));
    }
    data.insert(std::make_pair(name, dataSet));
  }
}