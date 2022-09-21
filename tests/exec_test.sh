#!/bin/bash

print_benchmark() {
  paste bm_$1_ft.log bm_$1_stl.log
}

test_benchmark() {
  echo "-- test benchmark --"
  ./tester_stl -b $1 > bm_$1_stl.log
  ./tester_ft -b $1 > bm_$1_ft.log
  echo "< stl vs ft >"
  print_benchmark $1
}

print_diff_log() {
  while read line
  do
    echo $line
  done < $1_diff.log
}

test_output() {
  echo "-- test output --"
  ./tester_stl -t $1 > $1_stl.log
  ./tester_ft -t $1 > $1_ft.log
  diff $1_stl.log $1_ft.log > $1_diff.log
  if [ $? -eq 0 ]; then
    echo "[ OK ]"
  elif [ $? -eq 1 ]; then
    print_diff_log $1
  fi
  echo ""
}

test() {
  echo "【$1】"
  test_output $1
  test_benchmark $1
  echo ""
}

main() {
  test $1
  test $2
  test $3
}

main $1 $2 $3

rm bm_$1_ft.log bm_$1_stl.log $1_ft.log $1_stl.log $1_diff.log
rm bm_$2_ft.log bm_$2_stl.log $2_ft.log $2_stl.log $2_diff.log
rm bm_$3_ft.log bm_$3_stl.log $3_ft.log $3_stl.log $3_diff.log

exit 0
