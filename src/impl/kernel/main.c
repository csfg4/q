void kernel_main()
{
    SetCursorPosition(PositionFromCoords(0, 0));
    PrintString("Hello World!\n\rThis is on a newline with a carrige return!\n\r");
    PrintString(HexToString(0x1234abcd));
    return;
}