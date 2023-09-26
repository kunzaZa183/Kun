def func(string, num):
    for i in string:
        print( chr((ord(i) - ord('a') - num + 26) % 26 + ord('a')), end ="" )
    print()
func("abcdef", 1)
func("abcdef", 2)
func("abcdef", 3)
func("dogcatpig", 1)
func("dogcatpig", 2)
func("dogcatpig", 3)