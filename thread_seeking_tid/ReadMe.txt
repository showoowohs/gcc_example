1. make 
2. run app
#./thread_seeking_tid

3. ctrl + z 
Created a thread. Default name is: thread_seeking_
^Z
[1]  + 14242 suspended  ./thread_seeking_tid

5. use ps scarch thread name
#ps H -C thread_seeking_tid -o 'pid tid cmd comm'
  PID   TID CMD                         COMMAND
14059 14059 ./thread_seeking_tid             thread_seeking_
14059 14060 ./thread_seeking_tid             THREADFOO

//reference
http://blog.csdn.net/u011028408/article/details/41515955
