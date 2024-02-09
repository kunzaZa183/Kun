kun=true
# g++ -o gen.exe gen.cpp
g++ -o gen.exe gen.cpp
while $kun; do

  # ./gen.exe
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