#include "greeting.h"

int main()
{
    int status = PyImport_AppendInittab("greeting", PyInit_greeting);
    if (status == -1) return -1;
    
    Py_Initialize();

    PyObject *module = PyImport_ImportModule("greeting");
    if (module == NULL) {
        Py_Finalize();
        return -1;
    }

    greeting();

    Py_Finalize();
    return 0;
}