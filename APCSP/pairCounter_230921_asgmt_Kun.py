def pair(string):
    ct = 0
    for i in range(max(0, len(string) - 1)):
        if string[i] == string[i+1]:
            ct += 1
    print(ct)

pair("ddogccatppig")
pair("dogcatpig")
pair("xxyyzz")
pair("a")
pair("abc")
pair("aabb")
pair("dogcatpigaabbcc")
pair("aabbccdogcatpig")
pair("dogabbcccatpig")
pair("aaaa")
pair("AAAAAAAAA")