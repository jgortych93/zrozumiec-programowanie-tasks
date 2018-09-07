#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#define BUFFER_SIZE 100
#define WPRINF_ERROR "Wprintf failed"
int main()
{
    // no second parameter indcates that the LC_CTYPE should be taken from env vars, by default it's C type
    setlocale(LC_CTYPE,"");

    // wide char allows any coding type, the L before string indicates that this is UNICODE string
    wchar_t before_decoding[BUFFER_SIZE] =L"\u263a\u263b\ The text from excersise is too long. I'm too lazy to type that \u263a\u263b\n ";

    // printf operates on ASCII, %ls is for wide string
    if (wprintf(L"%ls\n",before_decoding) < 0)
        printf(WPRINF_ERROR);

    return 0;
}
