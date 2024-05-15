#ifndef INPUTPROCESSING_HPP
#define INPUTPROCESSING_HPP

#include <iostream>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <list>
#include "list.hpp"

namespace khoroshkin
{
  template< typename T >
  std::ostream & outGothContainer(std::ostream & out, const T & container);

  template< typename T, typename Compare >
  void sortDataStructures(std::ostream & stream, size_t size, Compare comp);
}

template< typename T >
std::ostream & khoroshkin::outGothContainer(std::ostream & out, const T & container)
{
  for (auto it = container.begin(); it != container.end(); it++)
  {
    out << std::fixed << std::setprecision(1) << *it;
    out << ((std::next(it) == container.end()) ? "\n" : " ");
  }
  return out;
}

template< typename T, typename Compare >
void khoroshkin::sortDataStructures(std::ostream & stream, size_t size, Compare comp)
{
  List< T > forwardList;
  std::list< T > list;
  std::deque< T > deque;
  for (size_t i = 0; i < size; ++i)
  {
    forwardList.push_back(static_cast< T >(rand() % 100));
  }
  std::copy(forwardList.begin(), forwardList.end(), std::back_inserter(list));
  std::copy(forwardList.begin(), forwardList.end(), std::back_inserter(deque));

  outGothContainer(stream, forwardList);
  timSort(forwardList.begin(), forwardList.end(), comp);
  outGothContainer(stream, forwardList);

  shellSort(list.begin(), list.end(), comp);
  outGothContainer(stream, list);
  timSort(list.begin(), list.end(), comp);
  outGothContainer(stream, list);

  shellSort(deque.begin(), deque.end(), comp);
  outGothContainer(stream, deque);
  timSort(deque.begin(), deque.end(), comp);
  outGothContainer(stream, deque);
  std::sort(deque.begin(), deque.end(), comp);
  outGothContainer(stream, deque);
}

#endif
