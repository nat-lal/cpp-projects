CC = g++
CFLAGS = -g -Wall -Werror -O2
#CFLAGS = -g -Wall -Werror 
WORKSRC = decipher.cpp bigint.cpp
WORKOBJ = $(WORKSRC:.cpp=.o)

all: $(WORKOBJ)
	$(CC) $(CFLAGS) $(WORKOBJ) -o decipher

bigint.o: bigint.cpp bigint.h
	$(CC) $(CFLAGS) -c $< -o $@

decipher: bigint.o decipher.cpp
	$(CC) $(CFLAGS) $^ -o $@
	
test: bigint.o test.cpp
	$(CC) $(CFLAGS) $^ -o $@
	
mytest: bigint.o mytest.cpp
	$(CC) $(CFLAGS) $^ -o $@
	
mytest3: bigint.o mytest3.cpp
	$(CC) $(CFLAGS) $^ -o $@
	
mytest4: bigint.o mytest4.cpp
	$(CC) $(CFLAGS) $^ -o $@
	
clean:
	rm -f *.o test decipher mytest
