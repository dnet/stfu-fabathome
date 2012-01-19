/*
 * stfu.c - presses no whenever Fab@Home displays an abort dialog
 *
 * Copyright (c) 2012 András Veres-Szentkirályi
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include <windows.h>
#include <stdio.h>

int main(int argc, char** argv) {
	printf("Press CTRL-C to exit\n");
	while (1) {
		HWND win = FindWindowA("#32770", "FabAtHome");
		if (win != NULL) {
			printf("Found FabAtHome window: HWND=0x%X", win);
			HWND label = FindWindowExA(win, NULL, "Static",
				"Fabrication Loop Timeout: Abort Build?");
			if (label != NULL) {
				printf(" -> Found label: HWND=0x%X", label);
				SendMessage(win, WM_COMMAND, IDNO, 0);
				printf(" -> Pressed [NO]");
			}
			putchar('\n');
		}
		Sleep(100);
	}
}

