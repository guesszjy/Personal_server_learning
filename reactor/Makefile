CXX=g++
CFLAGS=-g -Wall
OBJS=reactor.o reactor_impl.o listen_handle.o sock_handle.o epoll_demultiplexer.o
BIN=client server

.SUFFIXES:.cpp .o

.cpp.o:
	$(CXX) -c $< $(CFLAGS) 

all:$(BIN)

server:server.o $(OBJS)
	$(CXX) $^ -o $@

client:client.o
	$(CXX) $^ -o $@

clean:
	$(RM) *.o  $(BIN) core*
