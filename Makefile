bin/main: bin src/lib/*.cpp src/include/*.h src/main/mAntiClipping.cpp
	g++ -o bin/mAntiClipping src/lib/*.cpp src/main/mAntiClipping.cpp -fpermissive -w

bin:
	mkdir -p bin
