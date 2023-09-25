def social(string):
    if string[3] == '-' and string[6] == '-':
        return print(string[-4:])
    return print("bad")

social("463-44-5678")
social("46-144-5678")
social("111-44-5678")
social("463044-5678")
social("463-99-8888")
social("123-11-5323")
social("463-4-55678")
social("46314415678")