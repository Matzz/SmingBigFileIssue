# Linux
```
hostnamectl
   Static hostname: ---
         Icon name: ---
           Chassis: laptop
        Machine ID: ---
           Boot ID: ---
  Operating System: Linux Mint 20
            Kernel: Linux 5.4.0-56-generic
      Architecture: x86-64

```
Files mounted to spiffs:
```
rw-rw-r-- 1 matzz matzz  84K Dec 12 23:26 jquery.min.js
-rw-rw-r-- 1 matzz matzz   13 Dec 12 21:37 test.txt
```

## Working file (test.txt):

### Request:
```
echo -e "GET /get?file=test.txt\n\n" | nc 192.168.4.1 80
HTTP/1.1 200 OK
Content-Type: text/plain
ETag: "00f-2-d0-8"
Content-Length: 13
Connection: keep-alive
Server: HttpServer/Sming

a
b
cde
1234
```

### Logs:

```
271542673 onAccept, tcp: 3fff1360, state: 0 K=0, Free heap size=43904
271542976 TCP 3fff14c8 +connection
271543345 TCP 3fff14c8 timeout updating: 70 -> 0
271545457 Opening connection. Total connections: 1
271549902 TcpServer onClient: 192.168.4.2

271555572 The headers are complete
271571410 found test.txt
271571793 attached file: 'test.txt' (13 bytes) #0x3fff1170
271572899 MemoryDataStream::realloc 0 -> 17
271573062 Storing 17 bytes in stream
271575532 MemoryDataStream::realloc 17 -> 171
271579152 Storing 26 bytes in stream
271582472 Storing 20 bytes in stream
271585781 Storing 20 bytes in stream
271589083 Storing 24 bytes in stream
271592359 Storing 26 bytes in stream
271595625 Storing 2 bytes in stream
271598876 TCP 3fff14c8 onReadyToSendData: 1
271602962 TCP 3fff14c8 Written: 135, Available: 2780, isFinished: 0, PushCount: 1
271609967 TcpClient stream finished
271613643 TCP 3fff14c8 Written: 13, Available: 2645, isFinished: 0, PushCount: 1
271620293 TcpClient stream finished
271623899 TCP 3fff14c8 received: 25 bytes
271627195 TCP 3fff14c8 onReadyToSendData: 1
271633320 TCP 3fff14c8 sent: 148
271634075 TCP 3fff14c8 onReadyToSendData: 2
272572980 TCP 3fff14c8 connection closed by timeout: 1 (from 0)
272573220 TCP 3fff14c8 connection closing
272573648 TCP 3fff14c8 ~connection
272574557 Destroying connection. Total connections: 0
272847971 -TCP connection

```

## Not working file on Linux Mint 20 (jquery.min.js):

### Request

```
echo -e "GET /get?file=jquery.min.js\n\n" | nc 192.168.4.1 80
[Here it hangs..]
```

### Logs
```
272847971 -TCP connection
351709706 onAccept, tcp: 3fff1360, state: 0 K=0, Free heap size=43904
351710049 TCP 3fff14c8 +connection
351710416 TCP 3fff14c8 timeout updating: 70 -> 0
351712523 Opening connection. Total connections: 1
351716967 TcpServer onClient: 192.168.4.2

351722774 The headers are complete
351751884 found jquery.min.js
351761020 attached file: 'jquery.min.js' (85659 bytes) #0x3fff1840
351762241 MemoryDataStream::realloc 0 -> 17
351762390 Storing 17 bytes in stream
351763730 MemoryDataStream::realloc 17 -> 176
351767345 Storing 31 bytes in stream
351770668 Storing 24 bytes in stream
351773972 Storing 23 bytes in stream
351777273 Storing 24 bytes in stream
351780558 Storing 26 bytes in stream
351783820 Storing 2 bytes in stream
351787071 TCP 3fff14c8 onReadyToSendData: 1
351791164 TCP 3fff14c8 Written: 147, Available: 2780, isFinished: 0, PushCount: 1
351798166 TcpClient stream finished
351802172 TCP 3fff14c8 Written: 1024, Available: 2633, isFinished: 0, PushCount: 1
351809178 TCP 3fff14c8 Written: 1024, Available: 1609, isFinished: 0, PushCount: 2
351816236 TCP 3fff14c8 Written: 585, Available: 585, isFinished: 0, PushCount: 3
351823169 TCP 3fff14c8 received: 30 bytes
352823017 TCP 3fff14c8 connection closed by timeout: 1 (from 0)
352823400 TCP 3fff14c8 connection closing
352824053 TCP 3fff14c8 ~connection
352824660 Destroying connection. Total connections: 0
353097979 -TCP connection
```


# Working file from Android phone browser (jquery.min.js):

## Request
From browser. jquery.min.js is printed to browser window

## Logs
```
431272995 -TCP connection
618668903 onAccept, tcp: 3fff1498, state: 0 K=0, Free heap size=43064
618669260 TCP 3fff17d8 +connection
618669645 TCP 3fff17d8 timeout updating: 70 -> 0
618671742 Opening connection. Total connections: 1
618676182 TcpServer onClient: 192.168.4.3

618680715 onAccept, tcp: 3fff1638, state: 0 K=1, Free heap size=42280
618686265 TCP 3fff1b80 +connection
618689450 TCP 3fff1b80 timeout updating: 70 -> 0
618693726 Opening connection. Total connections: 2
618698200 TcpServer onClient: 192.168.4.3

618706897 The headers are complete
618723878 found jquery.min.js
618733035 attached file: 'jquery.min.js' (85659 bytes) #0x3fff1740
618734240 MemoryDataStream::realloc 0 -> 17
618734402 Storing 17 bytes in stream
618735746 MemoryDataStream::realloc 17 -> 176
618739391 Storing 31 bytes in stream
618742714 Storing 24 bytes in stream
618746021 Storing 23 bytes in stream
618749317 Storing 24 bytes in stream
618752608 Storing 26 bytes in stream
618755868 Storing 2 bytes in stream
618759120 TCP 3fff17d8 onReadyToSendData: 1
618763231 TCP 3fff17d8 Written: 147, Available: 2780, isFinished: 0, PushCount: 1
618770218 TcpClient stream finished
618774224 TCP 3fff17d8 Written: 1024, Available: 2633, isFinished: 0, PushCount: 1
618781228 TCP 3fff17d8 Written: 1024, Available: 1609, isFinished: 0, PushCount: 2
618788284 TCP 3fff17d8 Written: 585, Available: 585, isFinished: 0, PushCount: 3
618795221 TCP 3fff17d8 received: 533 bytes
618847338 TCP 3fff17d8 sent: 1390
618847655 TCP 3fff17d8 onReadyToSendData: 2
618848583 TCP 3fff17d8 Written: 1024, Available: 1390, isFinished: 0, PushCount: 1
618851013 TCP 3fff17d8 Written: 366, Available: 366, isFinished: 0, PushCount: 2
618858986 TCP 3fff17d8 sent: 1390
618860893 TCP 3fff17d8 onReadyToSendData: 2
618865374 TCP 3fff17d8 Written: 1024, Available: 1390, isFinished: 0, PushCount: 1
618872271 TCP 3fff17d8 Written: 366, Available: 366, isFinished: 0, PushCount: 2
618880152 TCP 3fff17d8 sent: 1390
618882224 TCP 3fff17d8 onReadyToSendData: 2
618886716 TCP 3fff17d8 Written: 1024, Available: 1390, isFinished: 0, PushCount: 1
618893690 TCP 3fff17d8 Written: 366, Available: 366, isFinished: 0, PushCount: 2
618901496 TCP 3fff17d8 sent: 1390
618903568 TCP 3fff17d8 onReadyToSendData: 2
618908055 TCP 3fff17d8 Written: 1024, Available: 1390, isFinished: 0, PushCount: 1
618914951 TCP 3fff17d8 Written: 366, Available: 366, isFinished: 0, PushCount: 2
618922892 TCP 3fff17d8 sent: 1390
618924909 TCP 3fff17d8 onReadyToSendData: 2
618929415 TCP 3fff17d8 Written: 1024, Available: 1390, isFinished: 0, PushCount: 1
618936374 TCP 3fff17d8 Written: 366, Available: 366, isFinished: 0, PushCount: 2
618944290 TCP 3fff17d8 sent: 1390
618946254 TCP 3fff17d8 onReadyToSendData: 2
618950740 TCP 3fff17d8 Written: 1024, Available: 1390, isFinished: 0, PushCount: 1
618957634 TCP 3fff17d8 Written: 366, Available: 366, isFinished: 0, PushCount: 2
619823546 TCP 3fff1b80 connection closed by timeout: 1 (from 0)
619823827 TCP 3fff1b80 connection closing
619824220 TCP 3fff1b80 ~connection
619825161 Destroying connection. Total connections: 1
620069365 TCP 3fff17d8 sent: 2780
620069647 TCP 3fff17d8 onReadyToSendData: 2
620070560 TCP 3fff17d8 Written: 1024, Available: 2780, isFinished: 0, PushCount: 1
620073215 TCP 3fff17d8 Written: 1024, Available: 1756, isFinished: 0, PushCount: 2
620080324 TCP 3fff17d8 Written: 732, Available: 732, isFinished: 0, PushCount: 3
620090005 TCP 3fff17d8 sent: 1390
620090296 TCP 3fff17d8 onReadyToSendData: 2
620094714 TCP 3fff17d8 Written: 1024, Available: 1390, isFinished: 0, PushCount: 1
620101605 TCP 3fff17d8 Written: 366, Available: 366, isFinished: 0, PushCount: 2
620109301 TCP 3fff17d8 sent: 1390
620111484 TCP 3fff17d8 onReadyToSendData: 2
620115989 TCP 3fff17d8 Written: 1024, Available: 1390, isFinished: 0, PushCount: 1
620122862 TCP 3fff17d8 Written: 366, Available: 366, isFinished: 0, PushCount: 2
620130797 TCP 3fff17d8 sent: 1390
620132829 TCP 3fff17d8 onReadyToSendData: 2
620137338 TCP 3fff17d8 Written: 1024, Available: 1390, isFinished: 0, PushCount: 1
620144289 TCP 3fff17d8 Written: 366, Available: 366, isFinished: 0, PushCount: 2
620151919 -TCP connection
620154013 TCP 3fff17d8 sent: 1390
620156519 TCP 3fff17d8 onReadyToSendData: 2
620161049 TCP 3fff17d8 Written: 1024, Available: 1390, isFinished: 0, PushCount: 1
620167890 TCP 3fff17d8 Written: 366, Available: 366, isFinished: 0, PushCount: 2
620175863 TCP 3fff17d8 sent: 1390
620177848 TCP 3fff17d8 onReadyToSendData: 2
620182434 TCP 3fff17d8 Written: 1024, Available: 1390, isFinished: 0, PushCount: 1
620189231 TCP 3fff17d8 Written: 366, Available: 366, isFinished: 0, PushCount: 2
621298272 TCP 3fff17d8 connection closed by timeout: 1 (from 0)
621298620 TCP 3fff17d8 connection closing
621299493 TCP 3fff17d8 ~connection
621299874 Destroying connection. Total connections: 0
621548015 -TCP connection
```
