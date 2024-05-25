#include <iostream>
#include <fstream>
#include <tree.hpp>
#include <functional>
#include "IOFunctions.hpp"
#include "keySumm.hpp"

int main(int argc, char* argv[])
{
  using namespace miheev;
  if (argc != 3)
  {
    std::cerr << "Invalid amount of arguments\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "Unable to open the file\n";
    return 1;
  }

  Tree< int, std::string > data;
  readTree(input, data);
  if (data.empty())
  {
    return 0;
  }

  using TraverseMethod = std::function< KeySumm(tree_t*, KeySumm) >;
  Tree< std::string, TraverseMethod > orders;
  orders["ascending"] = &Tree< int, std::string >::traverseLnR< KeySumm >;
  orders["descending"] = &Tree< int, std::string >::traverseRnL< KeySumm >;
  orders["breadth"] = &Tree< int, std::string >::traverseBreadth< KeySumm >;

  KeySumm result;
  try
  {
    result = orders.at(argv[1])(&data, KeySumm()); // TODO: возмжоно получится убрать один из параметров
  }
  catch (const std::out_of_range& e)
  {
    std::cerr << e.what() << '\n';
    return 2;
  }

  std::cout << result.getResults() << '\n';

  return 0;
}
