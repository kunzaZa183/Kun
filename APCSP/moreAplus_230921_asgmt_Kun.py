def aplus(string):
    ct = 0
    for i in range(max(len(string)-4, 0)):
        if string[i:i+5] == "aplus":
            ct += 1
    if ct > 1:
        print("yes")
    else:
        print("no")

aplus("dog#cat#pigaplus")
aplus("pigs#apluscompsci#food")
aplus("##catgiraffeapluscompsci")
aplus("apluscatsanddogsaplus###")
aplus("###")
aplus("aplusdog#13337#pigaplusprogram")
aplus("code#H00P#code1234")
aplus("##wowgira77##eplus")
aplus("catsandaplusdogsaplus###")
aplus("7")