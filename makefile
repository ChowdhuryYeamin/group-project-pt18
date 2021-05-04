test: tempmain.cpp Wav.o audiofile.o echo.o noisegate.o limiter.o normalization.o dataprinter.o
	g++ -o testing tempmain.cpp Wav.o audiofile.o echo.o noisegate.o limiter.o normalization.o dataprinter.o -lstdc++fs

Wav.o: Wav.cpp Wav.h WaveHeader.h audiofile.h  
	g++ -c Wav.cpp 

audiofile.o: audiofile.cpp audiofile.h WaveHeader.h
	g++ -c audiofile.cpp

echo.o: echo.cpp echo.h Processor.h
	g++ -c echo.cpp

noisegate.o: noisegate.cpp noisegate.h Processor.h
	g++ -c noisegate.cpp

limiter.o: limiter.cpp limiter.h Processor.h
	g++ -c limiter.cpp

normalization.o: normalization.cpp normalization.h Processor.h
	g++ -c normalization.cpp

dataprinter.o: dataprinter.cpp dataprinter.h Processor.h
	g++ -c dataprinter.cpp
