#!/bin/bash
kun=true
g++ -o gen.exe gen.cpp
g++ -o coin.exe coin.cpp
g++ -o bruteforce.exe bruteforce.cpp
while $kun; do
  ./gen.exe
  ./coin.exe
  ./bruteforce.exe

  file1="correct.txt"
  file2="wrong.txt"

  if cmp -s "$file1" "$file2"; then
    printf 'The same'
  else
    printf 'Different'
    exit 0
  fi
done
exit 0