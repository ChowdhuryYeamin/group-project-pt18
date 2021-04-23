test: tempmain.cpp Wav.o audiofile.o audiotype.o
	g++ -o testing tempmain.cpp Wav.o audiofile.o audiotype.o -lstdc++fs

Wav.o: Wav.cpp Wav.h WaveHeader.h audiofile.h audiotype.h 
	g++ -c Wav.cpp 

audiofile.o: audiofile.cpp audiofile.h WaveHeader.h
	g++ -c audiofile.cpp

audiotype.o: audiotype.cpp audiotype.h audiofile.h WaveHeader.h
	g++ -c audiotype.cpp
