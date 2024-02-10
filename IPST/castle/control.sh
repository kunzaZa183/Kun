kun=true
problem=castle

g++ -std=gnu++17 -O2 -pipe -o main.exe main.cpp $problem.cpp
g++ -std=gnu++17 -O2 -pipe -o brute.exe brute.cpp $problem.cpp
g++ -o gen.exe gen.cpp
while $kun; do

  ./gen.exe
  ./main.exe
  ./brute.exe

  file1="sol.txt"
  file2="correct.txt"

  if cmp -s "$file1" "$file2"; then
    printf 'The same'
  else
    printf 'Different'
    exit 0
  fi
done
exit 0