CROSS_COMPILE 	=arm-none-linux-gnueabi-
CC		= $(CROSS_COMPILE)gcc
CXX		= $(CROSS_COMPILE)g++

all: chat

chat: main.o chat_server.o
	$(CXX)	-o chat main.o chat_server.o
	
main.o: main.cpp chat_server.cpp chat_server.h
	$(CXX)	-c main.cpp
	
chat_server.o: chat_server.cpp chat_server.h
	$(CXX)	-c chat_server.cpp