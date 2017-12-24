// JSArray\init.cpp

#using <System.dll>
#using <System.Windows.Forms.dll>

#include "init.h"
#include "gui.h"

using namespace System;
using namespace System::Windows::Forms;

Initializer::Initializer(void)
{
    init();
}

Initializer::~Initializer()
{

}

void Initializer::init()
{
    // Initialize the ApplicationContext object for JSArray.
    jsarray_context = (gcnew ApplicationContext());
    jsarray_context->MainForm = (gcnew JSArray::gui());
    Application::Run(jsarray_context);
}
