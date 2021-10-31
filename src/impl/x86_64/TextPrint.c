#pragma once
#include "Typedefs.c"
#include "TextModeColourCodes.c"
#define VGA_MEMORY (uint_8*)0xb8000
#define VGA_WIDTH 80

uint_16 CursorPosition;

void SetCursorPosition(uint_16 position)
{
    if (CursorPosition > 2000) CursorPosition = 2000;
    if (CursorPosition < 0) CursorPosition = 0;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint_8)(position & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint_8)((position >> 8) & 0xFF));

    CursorPosition = position;
}

uint_16 PositionFromCoords(uint_8 x, uint_8 y)
{
    return y * VGA_WIDTH + x;
}

void PrintString(const char* str, uint_8 colour)
{
    uint_8* charPtr = (uint_8*)str;
    uint_16 index = CursorPosition;
    while(*charPtr != 0)
    {
        switch(*charPtr)
        {
            case 10:
                index += VGA_WIDTH;
                break;
            case 13:
                index -= index % VGA_WIDTH;
                break;
            default:
            *(VGA_MEMORY + index * 2) = *charPtr;
            *(VGA_MEMORY + index * 2 + 1) = colour;
            ++index;
        }
        ++charPtr;
    }
    SetCursorPosition(index);
}



char hexToStringOutput[128];
const char *HexToString(uint_32 value)
{
    char *p = hexToStringOutput;
    int numNibbles = sizeof(uint_32) * 2;
    for(int t = 0; t < numNibbles; ++t)
    {
        int digit = (value & 0xf0000000) >> 28;
        if(digit < 10)
            *p++ = digit + '0';
        else
            *p++ = (digit - 10) + 'a';
        
        value <<= 4;
    }
    *p = 0;
    return hexToStringOutput;
}