#include "TextModeColourCodes.c"
void kernel_main()
{
    SetCursorPosition(PositionFromCoords(0, 0));
    PrintString("Hello World!\n\rThis is on a newline with a carrige return!\n\r", BACKGROUND_WHITE | FOREGROUND_CYAN);
    PrintString(HexToString(0x1234abcd), BACKGROUND_WHITE | FOREGROUND_CYAN);
    return;
}