CC=clang
LIB=-lcurl -lm
client:*.c
	$(CC) *.c -o server.e $(LIB)
clean:
	rm -rf *.e *.out
