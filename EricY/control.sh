#!/bin/bash
kun=true
g++ -o gen.exe gen.cpp
g++ -o sol.exe sol.cpp
g++ -o check.exe check.cpp
while $kun; do
  ./gen.exe
  ./sol.exe
  ./check.exe
  file_contents=$(<"result.txt")
  want="CORRECT"
  echo $file_contents
  if [ "$file_contents" != "$want" ]
  then
    exit 0
  fi
done
exit 0