
glisten: obj/anyoption.o main.cpp
	c++ obj/anyoption.o main.cpp -o glisten

obj/anyoption.o: anyoption/anyoption.cpp anyoption/anyoption.h
	c++ -c anyoption/anyoption.cpp -o obj/anyoption.o

clean:
	-rm -rf obj/*
	-rm glisten

