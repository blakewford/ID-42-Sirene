CC=g++

sirene: main.cpp
	$(CC) -O0 -gdwarf-4 -std=c++11 -DPROGMEM= main.cpp -o $@ -I. -include port.h -Wno-narrowing -fpermissive

clean:
	rm sirene
