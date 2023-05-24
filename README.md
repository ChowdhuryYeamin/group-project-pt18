# CS 202 Semester Project Template

Audio Processing Project

This project involves creating signal processing modules for audio WAV files. It's designed to handle both 8-bit and 16-bit audio modules.

Project Architecture

The architecture includes the construction of necessary WAV classes capable of extracting 8-bit and 16-bit data. These classes are not provided as a part of the starter project and must be built as a part of this assignment.

The extracted data should be passed on to the appropriate processor for signal processing. We will be working with four types of processors in this assignment:

Noisegate: A dynamic range processor used to control the level of noise below a specified threshold.
Echo: A processor that creates a time-delayed copy of the audio signal, producing an "echo" effect.
Normalization: A processor that adjusts the overall volume level of an audio file to bring it to a standard level.
Limiter: A processor used to prevent the audio level from going over a specified limit, preventing distortion and clipping.
After the processors have been applied to the data, the modified data should be written back to the WAV file. This writing process should be handled by a dedicated data printer class.

Your task is to implement this architecture effectively, ensuring all components work seamlessly together.

Please note, this project requires an understanding of audio signal processing theory. Incremental development and testing are highly recommended to ensure the functionality of individual components before integrating them into the overall system.
