CC=gcc
CPP=g++
CFLAGS=-O2 -pipe -ansi -g 
CPPFLAGS=-lm -lcrypt -O2 -pipe 
LIBS=-lm -lcrypt 
CPPLIBS=-lm -lcrypt -lstdc++
ALL= 120 112 123 133 263  264 297 299 327 340 400 401 409 424 465 540 548 644 673 699 712 725 748 755 755ac 839 10152 10152ac 10010 10115 10361 10815 11234
TESTDIR=./tests/
all:$(ALL)

112:112.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
120:120.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
123:123.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

133:133.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
263:263.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

264:264.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

297:297.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
299:299.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
327:327.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
340:340.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
400:400.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
401:401.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS)

409:409.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS)
424:424.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS)
465:465.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS)
540:540.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS)
548:548.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
644:644.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
673:673.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

699:699.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
712:712.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

	
725:725.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
748:748.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
755:755.cpp
	$(CC) $< -o $@ $(CFLAGS) $(CPPLIBS) 
	
755ac:755ac.cpp
	$(CC) $< -o $@ $(CFLAGS) $(CPPLIBS) 
839:839.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10010:10010.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

10115:10115.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10152:10152.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10152ac:10152ac.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10361:10361.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS)
	
10815:10815.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

11234:11234.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

.PYONY: clean cleanobj cleanout
clean:cleanobj cleanout
	-rm  -rf $(ALL) 

cleanobj:
	-rm -f *.o

cleanout:
	-rm -f $(TESTDIR)*.out



