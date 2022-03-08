def CaesarCypher(Array, Offset, isEncoding):
    if Offset > 0 or Offset < 0:
        Offset %= 26
    elif Offset == 0:
        return Array
    
    for i in range(0, len(Array)):
        Array[i] = chr(97 + ((ord(Array[i]) - 97) + Offset) % 26) if isEncoding else chr(97 + ((ord(Array[i]) - 97) - Offset) % 26)
    
    return Array
