1. make 
2. run app
#./thread_create

3. ctrl + z 
Created a thread. Default name is: thread_create
^Z
[1]  + 14242 suspended  ./thread_create

5. use ps scarch thread name
#ps H -C thread_create -o 'pid tid cmd comm'
  PID   TID CMD                         COMMAND
14059 14059 ./thread_create             thread_create
14059 14060 ./thread_create             THREADFOO

http://blog.csdn.net/u011028408/article/details/41515955
