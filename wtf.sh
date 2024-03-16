kun=true
g++ -o main2.exe main2.cpp
g++ -o main4.exe main4.cpp
g++ -o main3.exe main3.cpp
while $kun; do

  ./main2.exe
  ./main3.exe
  ./main4.exe

  corr="corr.txt"
  normal="out.txt"

  if cmp -s "$corr" "$normal"; then
    printf 'Same '
  else
    printf 'Different '
    exit 0
  fi
done
exit 0