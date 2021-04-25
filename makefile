test: tempmain.cpp Wav.o audiofile.o audiotype.o
	g++ -o testing tempmain.cpp Wav.o audiofile.o audiotype.o -lstdc++fs

Wav.o: Wav.cpp Wav.h WaveHeader.h audiofile.h audiotype.h 
	g++ -c Wav.cpp 

audiofile.o: audiofile.cpp audiofile.h WaveHeader.h
	g++ -c audiofile.cpp

audiotype.o: audiotype.cpp audiotype.h audiofile.h WaveHeader.h
	g++ -c audiotype.cpp

echo.o: echo.cpp echo.h Processor.h
	g++ -c echo.cpp

noisegate.o: noisegate.cpp noisegate.h Processor.h
	g++ -c noisegate.cpp

limiter.o: limiter.cpp limiter.h Processor.h
	g++ -c limiter.cpp
