The project is an Audio Processing Project designed for signal processing on audio WAV files. It can handle both 8-bit and 16-bit audio files. The primary aim is to read WAV files, process them using various signal processing techniques, and then write the modified data back to the WAV files. The project is structured to work with four types of signal processors:

1. **Noisegate**: Controls the level of noise below a specified threshold.
2. **Echo**: Creates a time-delayed copy of the audio signal, producing an "echo" effect.
3. **Normalization**: Adjusts the overall volume level of an audio file to bring it to a standard level.
4. **Limiter**: Prevents the audio level from going over a specified limit, preventing distortion and clipping.

### Core Components:

- **Wav Class**: Handles reading and writing of WAV files, including the technical and metadata information. It can read all files from a directory and manage the audio data in both 8-bit and 16-bit formats.
- **Audio Class**: Holds information about each file, including the WAV header, metadata, and filename.
- **DataPrinter Class**: Responsible for writing key technical information and metadata into a CSV file.
- **Processor Interface**: An interface for the signal processing classes (Noisegate, Echo, Normalization, Limiter), defining two pure virtual functions for processing 8-bit and 16-bit buffers.

### Signal Processors:

- **Noisegate**: Reduces noise by setting audio levels below a certain threshold to a base level (e.g., setting values around 128 to 128 for 8-bit audio).
- **Echo**: Implements an echo effect by mixing the original signal with a delayed version of itself. The delay is defined by `echoDelay`.
- **Normalization**: Normalizes the audio by finding the highest and lowest peaks in the audio and adjusting the audio levels to fit within a desired range.
- **Limiter**: Limits the audio to prevent the levels from going above or below certain thresholds, avoiding distortion.

The project emphasizes the need for an understanding of audio signal processing theory and recommends incremental development and testing to ensure the functionality of individual components before integrating them into the overall system.
