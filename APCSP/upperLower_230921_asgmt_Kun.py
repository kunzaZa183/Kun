def cap(string, bool):
    string = list(string)
    if bool == "True":
        for i in range(len(string)):
            if(string[i] >= 'a' and string[i] <= 'z'):
                string[i] = chr(ord('A') - ord('a') + ord(string[i]))
    elif bool == "False":
        for i in range(len(string)):
            if(string[i] >= 'A' and string[i] <= 'Z'):
                string[i] = chr(ord('a') - ord('A') + ord(string[i]))
    print("".join(string))

cap("D0g", "True")
cap("aplus", "False")
cap("catgiraffe", "False")
cap("ApLuS", "True")
cap("ApLuS", "False")
cap("#d0G#", "True")
cap("#d0G#", "False")
cap("aplusdog#13337#", "False")
cap("CoEe1234", "True")
cap("wow", "True")
cap("77777", "True")
cap("77777", "False")
