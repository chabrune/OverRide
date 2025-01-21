Q}|u`sfg~sf{}|a3

0x1337d00d

Dans la fonction main on a un scanf %d qui prend l'entree user en int et l'envoie en parametre a la fonction test avec la valeur 0x1337d00d

Dans la fonction test la valeur 0x1337d00d est soustraite a notre entree scanf

Si la difference est superieure a 0x15 (21d) la fonction appelle rand() puis decrypt avec le resultat aleatoire 
Sinon elle utilise une table de saut pour aller au cas correspondant a la difference comme argument

Donc on sait que le resultat de notre valeur soutrait a 0x1337d00d doit etre entre 1 et 21.

18 en binaire 
00010010


322424845 - 18 = 322424827

Q}|u`sfg~sf{}|a3

Q = 01010001 
    ^
    00010010 = 01000011 = 'C'

} = 01111101
    ^
    00010010 = 01101111 = 'o'
    
| = 01111100
    ^
    00010010 = 01101110 = 'n'

u = 01110101
    ^
    00010010 = 01100111 = 'g'

` = 01100000
    ^
    00010010 = 01110010 = 'r'

s = 01110011
    ^
    00010010 = 01100001 = 'a'

f = 01100110
    ^
    00010010 = 01110100 = 't'

g = 01100111
    ^
    00010010 = 01110101 = 'u'

~ = 01111110
    ^
    00010010 = 01101100 = 'l'

s = 01110011
    ^
    00010010 = 01100001 = 'a'

f = 01100110
    ^
    00010010 = 01110100 = 't'

{ = 01111011
    ^
    00010010 = 01101001 = 'i'

} = 01111101
    ^
    00010010 = 01101111 = 'o'

| = 01111100
    ^
    00010010 = 01101110 'n'
    
a = 01100001
    ^
    00010010 = 01110011 's'

3 = 00110011
    ^
    00010010 = 00100001 '!'


Ensuite compare le resultat avec Congratulations!
Si valide ouvre un /bin/sh
