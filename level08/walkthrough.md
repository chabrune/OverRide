drwxrwx---+ 1 level09 users      80 Jan 24 16:52 backups
-rwsr-s---+ 1 level09 users   12975 Oct 19  2016 level08


-rwxrwx---+ 1 level09 users    33 Jan 24 17:05 .log
-r--r-----+ 1 level09 users     0 Jan 24 16:52 backups


level08@OverRide:~$ export TEST2=$HOME/backups/.log
level08@OverRide:~$ export TEST3=$HOME/backups/backups
level08@OverRide:~$ ./level08 ${TEST2}
ERROR: Failed to open ./backups//home/users/level08/backups/.log
level08@OverRide:~$ ./level08 ${TEST3}
ERROR: Failed to open ./backups//home/users/level08/backups/backups
level08@OverRide:~$ ./level08 *${TEST3}
ERROR: Failed to open */home/users/level08/backups/backups
level08@OverRide:~$ ./level08 *${TEST2}
ERROR: Failed to open */home/users/level08/backups/.log