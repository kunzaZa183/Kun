kun=true
g++ -o gen.exe gen.cpp
g++ -o brute.exe brute.cpp
g++ -o grader.exe grader.cpp
while $kun; do

  ./gen.exe
  ./brute.exe
  ./grader.exe

  if cmp -s "corr.txt" "sol.txt"; then
    printf 'Same '
  else
    printf 'Different'
    exit 0
  fi

done
exit 0