bazinga: testreadwrite.o
	gcc testreadwrite.o -o readwriterunner
testreadwrite.o:
	gcc -c testreadwrite.c
run: bazinga
	./readwriterunner
clean:
	rm readwriterunner *.o oof_* *~*
