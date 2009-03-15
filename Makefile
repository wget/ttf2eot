ttf2eot: OpenTypeUtilities.o ttf2eot.o
	g++ -o $@ $^

clean:
	rm -f *.o *.core core ttf2eot *.eot
