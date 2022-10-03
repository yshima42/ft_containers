#include "test_map.hpp"

#include "../test.hpp"
#include "MapBenchmark.hpp"
#include "MapTester.hpp"
#include "PairTester.hpp"

void test_pair() {
  std::cout << "<pair test>" << std::endl;
  ft::pair<int, std::string> p1(1, "hello");
  PairTester<int, std::string> p(p1);
  p.test_all();
}

// 20~30個の数字がランダムな順でmapに入れるためのvectorの作成
std::vector<ft::pair<int, char> > make_random_vec() {
  std::vector<ft::pair<int, char> > pair_elems;
  std::srand(time(NULL));
  int num = rand() % 10 + 20;
  for (int i = 0; i < num; i++) {
    pair_elems.push_back(ft::make_pair(i, 'A' + i));
  }
  std::random_shuffle(pair_elems.begin(), pair_elems.end());
  return pair_elems;
}

ft::map<int, char> make_random_map() {
  std::vector<ft::pair<int, char> > pair_elems = make_random_vec();

  ft::map<int, char> base_map;
  for (size_t i = 0; i < pair_elems.size(); i++) {
    base_map.insert(pair_elems[i]);
  }
  return base_map;
}

void test_map() {
  test_pair();

  ft::map<int, char> base_map = make_random_map();

  std::vector<ft::pair<int, char> > base_pairs = make_random_vec();

  MapTester<int, char> m(base_map, base_pairs);
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
  ft::map<int, char> base_map = make_random_map();
  std::vector<ft::pair<int, char> > base_pairs = make_random_vec();
  MapBenchmark<int, char> s(base_map, base_pairs);
  s.test_all();
}
