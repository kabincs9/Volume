# 🔊 Volume - WAV Audio Volume Adjuster

![C](https://img.shields.io/badge/Language-C-blue.svg)
![CS50](https://img.shields.io/badge/CS50-Week%204-orange.svg)
![Audio](https://img.shields.io/badge/Audio-WAV%20Processing-purple.svg)

A clean C program that increases or decreases the volume of a **WAV audio file** by any given factor.

## ✨ Overview

This program takes a WAV sound file as input, applies a volume scaling factor (e.g., 2.0 to make it louder, 0.5 to make it quieter), and saves the modified audio as a new WAV file. It correctly preserves the WAV header while modifying all audio samples.

Perfect for learning binary file processing and audio data manipulation.

## 🎯 Features

- ✅ Reads and writes standard WAV audio files
- ✅ Properly copies and preserves the 44-byte WAV header
- ✅ Scales every audio sample by the given factor
- ✅ Supports both increasing and decreasing volume
- ✅ Handles 16-bit signed audio samples accurately
- ✅ Clean and simple command-line interface
- ✅ Robust error checking for file operations

## 🚀 Quick Start

```bash
# Clone the repository
git clone https://github.com/kabincs9/volume.git
cd volume

# Compile
make

# Run the program
./volume input.wav output.wav 2.0
