#!/bin/bash

print_benchmark() {
  paste bm_vector_ft.log bm_vector_stl.log
}

test_benchmark() {
  echo "-- test benchmark --"
  ./tester_stl -b $1 > bm_vector_stl.log
  ./tester_ft -b $1 > bm_vector_ft.log
  echo "< stl vs ft >"
  print_benchmark
}

print_diff_log() {
  while read line
  do
    echo $line
  done < diff.log
}

test_output() {
  echo "-- test output --"
  ./tester_stl -t $1 > vector_stl.log
  ./tester_ft -t $1 > vector_ft.log
  diff vector_stl.log vector_ft.log > diff.log
  if [ $? -eq 0 ]; then
    echo "[ OK ]"
  elif [ $? -eq 1 ]; then
    print_diff_log
  fi
}

main() {
  test_output $1
  echo ""
  test_benchmark $1
}

main $1

rm bm_vector_ft.log bm_vector_stl.log vector_ft.log vector_stl.log diff.log

exit 0
