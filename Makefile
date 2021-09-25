output: main.cpp
	g++ main.cpp -o wordcounts.exe

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o wordcounts.exe
