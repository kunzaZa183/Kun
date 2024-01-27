kun=true
# g++ -o gen.exe gen.cpp
g++ -o specialgen.exe specialgen.cpp
g++ -o sol.exe sol.cpp
g++ -o correct.exe correct.cpp
while $kun; do

  # ./gen.exe
  ./specialgen.exe
  ./sol.exe
  ./correct.exe

  file1="output.txt"
  file2="correctoutput.txt"

  if cmp -s "$file1" "$file2"; then
    printf 'The same'
  else
    printf 'Different'
    exit 0
  fi
done
exit 0