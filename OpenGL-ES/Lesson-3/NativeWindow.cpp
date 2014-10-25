#include "NativeWindow.h"

NativeWindow::NativeWindow() : m_deviceContext(0), m_nativeWindow(0)
{
}

NativeWindow::NativeWindow(const NativeWindow&& o)
{
	m_deviceContext = o.m_deviceContext;
	m_nativeWindow = o.m_nativeWindow;
}

NativeWindow::~NativeWindow()
{
}

NativeWindow& NativeWindow::operator=(const NativeWindow&& o)
{
	if (this == &o) return *this;
	m_deviceContext = o.m_deviceContext;
	m_nativeWindow = o.m_nativeWindow;
}
