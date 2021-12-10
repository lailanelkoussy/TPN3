CPP=g++ --std=c++11
CFLAGS= -Wall -MD

all : projet

OBJS =  main.o MapReduce.o Core.o

projet : main.o MapReduce.o Core.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $<

MapReduce.o : MapReduce.cpp MapReduce.hpp
	$(CPP) $(CFLAGS) -c $<

Core.o : Core.cpp Core.hpp
	$(CPP) $(CFLAGS) -c $<

clean :
	rm *.o
	rm -f *.d

test: all
	./projet

-include $(OBJS:.o=.d)