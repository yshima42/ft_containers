#include "test_map.hpp"

#include "MapBenchmark.hpp"
#include "MapTester.hpp"
#include "PairTester.hpp"
#include "test.hpp"

void test_pair() {
  std::cout << "<pair test>" << std::endl;
  ft::pair<int, std::string> p1(1, "hello");
  PairTester<int, std::string> p(p1);
  p.test_all();
}

void test_map() {
  test_pair();

  std::vector<ft::pair<int, std::string> > pair_elems;
  pair_elems.push_back(ft::make_pair(-1, "A"));
  pair_elems.push_back(ft::make_pair(0, "B"));
  pair_elems.push_back(ft::make_pair(1, "C"));
  pair_elems.push_back(ft::make_pair(2, "D"));
  pair_elems.push_back(ft::make_pair(3, "E"));

  std::vector<ft::pair<int, std::string> > base_pairs;
  base_pairs.push_back(ft::make_pair(10, "ccccc"));
  base_pairs.push_back(ft::make_pair(-10, "aaaaa"));
  base_pairs.push_back(ft::make_pair(30, "eeeee"));
  base_pairs.push_back(ft::make_pair(20, "ddddd"));
  base_pairs.push_back(ft::make_pair(0, "bbbbb"));

  ft::map<int, std::string> base_map;
  for (size_t i = 0; i < pair_elems.size(); i++) {
    base_map.insert(pair_elems[i]);
  }

  MapTester<int, std::string> m(base_map, base_pairs);
  m.test_all();

  std::cout << GREEN << "Fixed class" << std::endl;

  std::vector<ft::pair<Fixed, char> > pair_elems2;
  pair_elems2.push_back(ft::make_pair(-1.2f, 'a'));
  pair_elems2.push_back(ft::make_pair(0, 'b'));
  pair_elems2.push_back(ft::make_pair(1.54f, 'c'));
  pair_elems2.push_back(ft::make_pair(2.34f, 'd'));
  pair_elems2.push_back(ft::make_pair(3.34f, 'e'));

  std::vector<ft::pair<Fixed, char> > base_pairs2;
  base_pairs2.push_back(ft::make_pair(10.1f, 'f'));
  base_pairs2.push_back(ft::make_pair(-10.2f, 'g'));
  base_pairs2.push_back(ft::make_pair(30.44f, 'h'));
  base_pairs2.push_back(ft::make_pair(20.44f, 'i'));
  base_pairs2.push_back(ft::make_pair(0, 'j'));

  ft::map<Fixed, char> base_map2;
  for (size_t i = 0; i < pair_elems2.size(); i++) {
    base_map2.insert(pair_elems2[i]);
  }

  MapTester<Fixed, char> m2(base_map2, base_pairs2);
  m2.test_all();

}

void benchmark_map() {
  // ft::map<int, int> base;
  // MapBenchmark<int, int> s(base);
  // s.test_all();
}
