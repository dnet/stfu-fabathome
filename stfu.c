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

