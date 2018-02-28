#include "MainForm.h"

using namespace ptlab1;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ptlab1::MainForm form;   
	Application::Run(%form);
}