// Modifies the volume of an audio file

#include <stdint.h> // (for int16_t, uint8_t)
#include <stdio.h>
#include <stdlib.h>
// takes wav as input
// multiplies each sample (audio data) by a volume factor e.g. 2.0 doubles the volume

// saves the result to a new WAV file,

// without changing the first 44 bytes of the file; the WAV header.

// WAV files begin with a 44-byte “header” that contains information about the file itself, no
// change is needed WAV file contains a sequence of samples, each a single 2-byte (16-bit) integer
// // multiply user value to increase volume
// representing the audio signal at a particular point in time
// Number of bytes in .wav header
const int HEADER_SIZE = 44; // a constant//should not be altered

int main(int argc, char *argv[]) // main() function accepts command-line arguments
{
    // Check command-line arguments
    if (argc != 4) // if exactly 3 command-line arguments are passed (argv[1], argv[2], argv[3]) for
                   // input output and function
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) // input file failed to open. then, prints error and exits.
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL) // same for output
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]); // converts the volume factor (a string) into a float using
                                  // atof().

    // TODO: Copy header from input file to output file
    // as in the description Copy WAV header from input file to output file problem

    uint8_t headercopy[HEADER_SIZE]; // as HEADER_SIZE already mentioned before // making header
                                     // copy for easyness
    fread(&headercopy, HEADER_SIZE, 1,
          input); // as &c, sizeof(char), 1, file) and only 1 times as 44 bytes
                  // and now need to copy
    fwrite(&headercopy, HEADER_SIZE, 1, output);
    // The opened file “remembers” the number of bytes that were successfully read,
    //  such that subsequent calls to this function for stream will return bytes after those already
    //  read...

    // TODO: Read samples from input file and write updated data to output file

    int16_t rewrite; // signed 16-bit integer to store each audio sample int... /// rewrite or temp
                     // just to take inout and update
    while (fread(&rewrite, sizeof(int16_t), 1, input) != 0)
    {
        rewrite *= factor; // then only // as factor predetermined in float
        // factor = 2.0 → double the volume

//factor = 0.5  half the volume

//factor = 1.0 same volume no change
        fwrite(&rewrite, sizeof(int16_t), 1, output);

        // one sample from the input is taken

        // then it multiplies the sample by the volume factor.

        // write the modified sample to the output. and // int16 .. as standard WAV file is 2 bytes
        // (16-bit signed integer) factor < 1, volume is decreased.

        // and  factor > 1, volume is increased.
    }

    // Close files
    fclose(input);
    fclose(output);
}
