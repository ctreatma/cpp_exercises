CC = g++
OPTS = -Wall -O2
OPTS2 = -Wall -c
OBJS = skip_node.o skip_list.o random_fun.o

analyze: analyze.cc ${OBJS}
	${CC} ${OPTS} -lm -o analyze analyze.cc ${OBJS}

skip_node.o: skip_node.cc skip_node.h
	${CC} ${OPTS2} skip_node.cc

skip_list.o: skip_list.cc skip_list.h random_fun.o skip_node.o
	${CC} ${OPTS2} skip_list.cc

random_fun.o: random_fun.c random_fun.c
	${CC} ${OPTS2} random_fun.c

clean:
	rm analyze *.o
