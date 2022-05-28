# LRUCache
This is the one of implementations of LRUCache.

#Steps
1.Enter number of commands(N) you want to make on cache.
2.Enter size of buffer for cache.
3.And start to enter your command on given format.

get KEY (Returns Value of the key if exists else -1)
set KEY VALUE (Inserts if current KEY doesn't exists)

#Exaple

10 4
set 50 43
50 
43 
-----------------------
set 1 1
1 50 
1 43 
-----------------------
set 4 3
4 1 50 
3 1 43 
-----------------------
get 50
(43)
50 4 1 
43 3 1 
-----------------------
set 50 10
50 4 1 
10 3 1 
-----------------------
set 50 90
50 4 1 
90 3 1 
-----------------------
set 8 8
8 50 4 1 
8 90 3 1 
-----------------------
set 6 66
6 8 50 4 
66 8 90 3 
-----------------------
set 89 89
89 6 8 50 
89 66 8 90 
-----------------------
get 8
(8)
8 89 6 50 
8 89 66 90 
-----------------------

Process finished with exit code 0
