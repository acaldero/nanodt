# nanodt: Nano Distributed Table (v2.0)

## Tabla de contenidos
  * [Initial init-set-get service](#initial-non-distributed-service)
  * [Distributed service based on mqueue (POSIX queue)](#distributed-service-based-on-mqueue-posix-queue)
  * [Distributed service based on sockets](#distributed-service-based-on-sockets)


## Initial non-distributed service

### Compile 

```
$ cd centralized
$ make
gcc -g -Wall -c app-c.c
gcc -g -Wall -c lib.c
gcc -g -Wall app-c.o lib.o  -o app-c
```

### Execute 

```
$ ./app-c
set("nombre", 1, 0x123)
get("nombre", 1) -> 0x123
```

### Arquitecture

```mermaid
sequenceDiagram
    app-c          ->> lib.c: request lib.h API
    lib.c          ->> app-c: return result of API call
```


## Distributed service based on mqueue (POSIX queue)

### Compile 

```
$ cd distributed-mqueue
$ make
gcc -g -Wall -c app-d.c
gcc -g -Wall -c lib-client.c
gcc -g -Wall -c lib.c
gcc -g -Wall -lrt app-d.o lib.o lib-client.o       -o app-d  -lrt
gcc -g -Wall -c lib-server.c
gcc -g -Wall            lib.o lib-client.o lib-server.o  -o lib-server  -lrt
```

### Execute 

*TIP: POSIX queues are used for communicating processes in the same machine*

<html>
<table>
<tr><th>Step</th><th>Client</th><th>Server</th></tr>
<tr>
<td>1</td>
<td></td>
<td>
 
```
$ ./lib-server
```
 
</td>
</tr>

<tr>
<td>2</td>
<td>

```
$ ./app-d
d_set("nombre", 1, 0x123)
d_get("nombre", 1) -> 0x123
```

</td>
<td>
 
```

 1 = init(nombre, 10);
 1 = set(nombre, 1, 0x123);
 1 = get(nombre, 1, 0x123);
```
 
</td>
</tr>

<tr>
<td>3</td>
<td></td>
<td>

```
^Caccept: Interrupted system call
```

</td>
</tr>
</table>
</html>

*TIP: POSIX queues can be visible from command line:

``` bash
sudo mkdir /dev/mqueue
sudo mount -t mqueue none /dev/mqueue
ls -las /dev/mqueue
```

### Arquitecture 

```mermaid
sequenceDiagram
    app-d          ->> lib-client.c: request lib.h API in a distributed way
    lib-client.c   ->> lib-server.c: request remote API
    lib-server.c   ->> lib.c: request lib.h API call
    lib.c          ->> lib-server.c: return API call result
    lib-server.c   ->> lib-client.c: return remote result
    lib-client.c   ->> app-d: return result of the distributed API call
```


## Distributed service based on *sockets*

*TIP: Before execute in two different machine please update the server IP address in lib-client.c*

### Compile 

```
$ cd distributed-sockets
$ make
gcc -g -Wall -c app-d.c
gcc -g -Wall -c lib-client.c
gcc -g -Wall -c lib.c
gcc -g -Wall  app-d.o lib.o lib-client.o       -o app-d
gcc -g -Wall -c lib-server.c
gcc -g -Wall            lib.o lib-client.o lib-server.o  -o lib-server
```

### Execute 

<html>
<table>
<tr><th>Step</th><th>Client</th><th>Server</th></tr>
<tr>
<td>1</td>
<td></td>
<td>
 
```
$ ./lib-server
```
 
</td>
</tr>

<tr>
<td>2</td>
<td>

```
$ ./app-d
d_set("nombre", 1, 0x123)
d_get("nombre", 1) -> 0x123
```

</td>
<td>
 
```

 1 = init(nombre, 10);
 1 = set(nombre, 1, 0x123);
 1 = get(nombre, 1, 0x123);
```
 
</td>
</tr>

<tr>
<td>3</td>
<td></td>
<td>

```
^Caccept: Interrupted system call
```

</td>
</tr>
</table>
</html>

### Arquitecture 

```mermaid
sequenceDiagram
    app-d          ->> lib-client.c: request lib.h API in a distributed way
    lib-client.c   ->> lib-server.c: request remote API
    lib-server.c   ->> lib.c: request lib.h API call
    lib.c          ->> lib-server.c: return API call result
    lib-server.c   ->> lib-client.c: return remote result
    lib-client.c   ->> app-d: return result of the distributed API call
```


## Additional information

 * [Introduction to lab 1 (Spanish)](https://www.youtube.com/watch?v=LWeuoihcKyI)
 * [Introduction to lab 2 (Spanish)](https://www.youtube.com/watch?v=tmFu_JenEi0)

