lst = "aeiouAEIOU"
def isvowel(c):
    return lst.find(c)!=-1
def check(string):
    if isvowel(string[0]) or isvowel(string[-1]):
        print("yes")
    else:
        print("no")

check("dog#cat#pigaplus")
check("pigs#apluscompsci#food")
check("##catgiraffeapluscompscI")
check("apluscatsanddogsaplus###")
check("###")
check("Aplusdog#13337#pigaplusprogram")
check("code#H00P#code1234")
check("##wowgira77##eplus")
check("catsandaplusdogsaplus###")
check("7")
check("A")
check("E")
check("9AEIOUaeiou@")