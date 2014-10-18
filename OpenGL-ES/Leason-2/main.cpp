#include "Win32NativeWindow.h"
#include "Render.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	Win32NativeWindow nativeWindow;
	bool success = nativeWindow.CreateNativeWindow(800, 600, hInstance);

	int rc = 0;
	if (success) {
		Render render(&nativeWindow);
		rc = render.run();
	}
	return rc;
}