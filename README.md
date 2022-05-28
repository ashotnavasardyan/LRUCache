# LRUCache
This is the one of implementations of LRUCache.

# Steps

1.Enter number of commands(N) you want to make on cache.

2.Enter size of buffer for cache.

3.And start to enter your command on given format.

* get KEY (Returns Value of the key if exists else -1)

* set KEY VALUE (Inserts if current KEY doesn't exists)

# Example

10 4 <br />
set 50 43<br />
50 <br />
43 <br />
-----------------------<br />
set 1 1<br />
1 50 <br />
1 43 <br />
-----------------------<br />
set 4 3<br />
4 1 50 <br />
3 1 43 <br />
-----------------------<br />
get 50<br />
(43)<br />
50 4 1 <br />
43 3 1 <br />
-----------------------<br />
set 50 10<br />
50 4 1 <br />
10 3 1 <br />
-----------------------<br />
set 50 90<br />
50 4 1 <br />
90 3 1 <br />
-----------------------<br />
set 8 8<br />
8 50 4 1 <br />
8 90 3 1 <br />
-----------------------<br />
set 6 66<br />
6 8 50 4 <br />
66 8 90 3 <br />
-----------------------<br />
set 89 89<br />
89 6 8 50 <br />
89 66 8 90 <br />
-----------------------<br />
get 8<br />
(8)<br />
8 89 6 50 <br />
8 89 66 90 <br />
-----------------------<br />

Process finished with exit code 0<br />
