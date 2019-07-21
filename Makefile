CC=cc
CPP=c++
CFLAGS=-pipe -ansi  -pipe -g
CPPFLAGS= -pipe -g
LIBS=-lm  
CPPLIBS=-lm  -lstdc++
ALL= 100 101 120 112 123 131 133 210 263  264 297 299 327 340 400 401 409 424 465 540 548 644 673 699 706 712 725 748 755ac 839 10152 10152ac 10010 10033 10038 10050 10115 10142  10167 10189 10205 10315 10361 10815 11234 q8 10267 10196 10474 1598 1598ac 1585 1225 1586 1368 10340 1583 1584 227 232 272 1587 12096 136 10082 489

TESTDIR=./tests/
all:$(ALL)

100:100.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
101:101.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
112:112.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
120:120.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
123:123.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
131:131.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
133:133.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
210:210.cpp
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
706:706.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
712:712.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

	
725:725.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
748:748.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
q8:q8.cpp
	$(CC) $< -o $@ $(CFLAGS) $(CPPLIBS) 
	
755ac:755ac.cpp
	$(CC) $< -o $@ $(CFLAGS) $(CPPLIBS) 
839:839.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
1225:1225.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
1368:1368.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
1585:1585.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
1586:1586.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
1598:1598.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
1598ac:1598ac.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
10010:10010.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10033:10033.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10038:10038.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10050:10050.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10115:10115.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10142:10142.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10152:10152.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10152ac:10152ac.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10167:10167.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10189:10189.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10196:10196.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10205:10205.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10267:10267.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10315:10315.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS)
10340:10340.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS)
10361:10361.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS)
	
10815:10815.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 

11234:11234.c
	$(CC) $< -o $@ $(CFLAGS) $(LIBS) 
10474:10474.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
1583:1583.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
1584:1584.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
227:227.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
232:232.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
272:272.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
1587:1587.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
12096:12096.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
136:136.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
10082:10082.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 
489:489.cpp
	$(CPP) $< -o $@ $(CFLAGS) $(LIBS) 

.PYONY: clean cleanobj cleanout
clean:cleanobj cleanout
	-rm  -rf $(ALL) 
	-rm  -rf *.dSYM

cleanobj:
	-rm -f *.o

cleanout:
	-rm -f $(TESTDIR)*.out



