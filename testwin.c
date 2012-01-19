#include <windows.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	int mb = MessageBoxA(0, "Fabrication Loop Timeout: Abort Build?",
		"FabAtHome", MB_YESNO | MB_ICONQUESTION);
	printf(mb == IDYES ? "yes\n" : "no\n");
}

