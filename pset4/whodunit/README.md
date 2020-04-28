# Questions

## What's `stdint.h`?

c header file contain set of typede (integers with exact width and with minimum and maximum allowable values for each type)

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

it make clear what is the data we dealing with for examole uint32_t mean integer with 38 bit

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 1 byte
DWORD =4 bytes
LONG = 4 bytes
WORD = 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x42 0x4D in hexadecimal, same as BM in ASCII

## What's the difference between `bfSize` and `biSize`?

biSize: The number of bytes required by the structure the header part (BITMAPFILEHEADER=14-BITMAPINFOHEADER=40)
bfSize: The size in bytes of the bitmap file (image + header=image+54)


## What does it mean if `biHeight` is negative?

For uncompressed RGB bitmaps, if biHeight is positive, the bitmap is a bottom-up DIB with the origin at the lower left corner.
If biHeight is negative, the bitmap is a top-down DIB with the origin at the upper left corner.
For YUV bitmaps, the bitmap is always top-down, regardless of the sign of biHeight.
Decoders should offer YUV formats with postive biHeight, but for backward compatibility they should accept YUV formats with either positive or negative biHeight.
For compressed formats, biHeight must be positive, regardless of image orientation.

DIB(device-independent bitmaps)

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount: Specifies the number of bits per pixel (bpp)

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

in line 24 if it can't open the input file
in line 32 if it can't open the output file

## Why is the third argument to `fread` always `1` in our code?

it is number of elemnts with size of (second argument) to be read

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3 byte od padding (4-3*3%4)%4=(4-1)%4=3

## What does `fseek` do?

skip over specified number of bytes in padding

## What is `SEEK_CUR`?

start skipping at the current location
