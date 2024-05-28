# LZ77
The user specifies whether they want to compress or decompress a file, and then provides two paths: one for the input file and one for the output file. 
The program, using LZ77 encoding, compresses (or decompresses, depending on the user's choice) the input file and saves the result to the output file. 
After compressing and decompressing a given file, the original file should be fully restored.
# Algorithm
In each step, the algorithm keeps a short segment of the recently compressed text (the so-called window). 
It then searches for the longest prefix in the yet-to-be-compressed sequence that is found within this window. 
The output file records the index where this prefix occurrence starts, its length, and the character following this prefix. 
The window is then shifted by the length of this prefix plus one character, and the process is repeated.
# Implementation
In the algorithm implementation, a window of size 255 elements is used. 
This allows both the index and the length of the prefix to fit into a single byte. 
A deque (double-ended queue) is used for the implementation of the buffer and the window, enabling constant-time insertion and removal of elements from both ends. 
Additionally, for simplification, the window is initially filled with zeros to maintain a consistent size throughout the algorithm's execution.
# Testing
To test the program, three text files were created, containing articles from Wikipedia: about footwear, Ricky Martin, and Selena Gomez. 
Additionally, two BMP files were found: one with an image drawn in Paint and another with a photograph.
