bin/main: bin src/lib/Printer.cpp src/lib/Line.cpp src/lib/Point.cpp src/lib/Texture.cpp src/lib/SolidPolygon.cpp src/main/mAntiClipping.cpp
	g++ -o bin/mAntiClipping src/lib/Printer.cpp src/lib/Line.cpp src/lib/Point.cpp src/lib/Texture.cpp src/lib/SolidPolygon.cpp src/main/mAntiClipping.cpp -fpermissive

bin:
	mkdir -p bin