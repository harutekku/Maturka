def IsPalindrome(String):
    i = 0
    j = len(String) - 1

    while i < j:
        if String[i] != String[j]:
            return False
        else:
            i += 1
            j -= 1
    
    return True

def FindPattern(String, Pattern):
    
    retVal = [  ]

    for i in range(0, len(String)):
        if String[i] == Pattern[0]:
            occurence = i
            
            j = 0
            iTemp = i
            while iTemp != len(String) and j != len(Pattern):
                if String[iTemp] == Pattern[j]:
                    iTemp += 1
                    j += 1

            if j == len(Pattern):
                retVal.append(occurence)
    return retVal

