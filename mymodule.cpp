#include <Python.h>
#include <Windows.h>

#if defined(__x86_64__) || defined(_WIN64)
typedef long long int sizeiptr;
#else
typedef int sizeiptr;
#endif

typedef HDC EGLNativeDisplayType;
typedef HWND EGLNativeWindowType;
typedef void * EGLDisplay;
typedef void * EGLConfig;
typedef void * EGLSurface;
typedef void * EGLContext;

#define EGL_CONTEXT_MAJOR_VERSION 0x3098
#define EGL_CONTEXT_MINOR_VERSION 0x30FB
#define EGL_CONTEXT_OPENGL_BACKWARDS_COMPATIBLE_ANGLE 0x3483
#define EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT 0x00000001
#define EGL_CONTEXT_OPENGL_PROFILE_MASK 0x30FD
#define EGL_CONTEXT_WEBGL_COMPATIBILITY_ANGLE 0x33AC
#define EGL_OPENGL_ES_API 0x30A0
#define EGL_RED_SIZE 0x3024
#define EGL_GREEN_SIZE 0x3023
#define EGL_BLUE_SIZE 0x3022
#define EGL_NONE 0x3038

void (*(*eglGetProcAddress)(const char * name))();
const char * (*eglQueryString)(EGLDisplay display, int name);
EGLDisplay (*eglGetDisplay)(EGLNativeDisplayType display_id);
unsigned (*eglInitialize)(EGLDisplay dpy, int * major, int * minor);
unsigned (*eglGetConfigs)(EGLDisplay dpy, EGLConfig * configs, int config_size, int * num_config);
unsigned (*eglGetConfigAttrib)(EGLDisplay dpy, EGLConfig config, int attribute, int * value);
EGLSurface (*eglCreateWindowSurface)(EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const int * attrib_list);
unsigned (*eglBindAPI)(unsigned api);
EGLContext (*eglCreateContext)(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const int * attrib_list);
unsigned (*eglMakeCurrent)(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx);
unsigned (*eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);

HWND hwnd;
HDC hdc;
HGLRC hrc;

EGLDisplay display;
EGLSurface surface;
EGLContext context;

int width;
int height;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam) {
    switch (umsg) {
        case WM_CLOSE: {
            PostQuitMessage(0);
            return 0;
        }
    }
    return DefWindowProc(hwnd, umsg, wparam, lparam);
}

PyObject * meth_init(PyObject * self, PyObject * args) {
    HINSTANCE hinst = GetModuleHandle(NULL);
    HCURSOR hcursor = (HCURSOR)LoadCursor(NULL, IDC_ARROW);
    WNDCLASS wnd_class = {CS_OWNDC, WindowProc, 0, 0, hinst, NULL, hcursor, NULL, NULL, "mywindow"};
    RegisterClass(&wnd_class);

    width = 1280;
    height = 720;

    int style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE;
    int sw = GetSystemMetrics(SM_CXSCREEN);
    int sh = GetSystemMetrics(SM_CYSCREEN);

    RECT rect = {0, 0, width, height};
    AdjustWindowRect(&rect, style, false);

    int w = rect.right - rect.left;
    int h = rect.bottom - rect.top;
    int x = (sw - w) / 2;
    int y = (sh - h) / 2;

    hwnd = CreateWindow("mywindow", "Window", style, x, y, w, h, NULL, NULL, hinst, NULL);
    if (!hwnd) {
        PyErr_BadInternalCall();
        return NULL;
    }

    hdc = GetDC(hwnd);
    if (!hdc) {
        PyErr_BadInternalCall();
        return NULL;
    }

    HMODULE angle = LoadLibrary("libGLESv2.dll");
    eglGetProcAddress = (decltype(eglGetProcAddress))GetProcAddress(angle, "EGL_GetProcAddress");
    eglQueryString = (decltype(eglQueryString))eglGetProcAddress("eglQueryString");
    eglGetDisplay = (decltype(eglGetDisplay))eglGetProcAddress("eglGetDisplay");
    eglInitialize = (decltype(eglInitialize))eglGetProcAddress("eglInitialize");
    eglGetConfigs = (decltype(eglGetConfigs))eglGetProcAddress("eglGetConfigs");
    eglGetConfigAttrib = (decltype(eglGetConfigAttrib))eglGetProcAddress("eglGetConfigAttrib");
    eglCreateWindowSurface = (decltype(eglCreateWindowSurface))eglGetProcAddress("eglCreateWindowSurface");
    eglBindAPI = (decltype(eglBindAPI))eglGetProcAddress("eglBindAPI");
    eglCreateContext = (decltype(eglCreateContext))eglGetProcAddress("eglCreateContext");
    eglMakeCurrent = (decltype(eglMakeCurrent))eglGetProcAddress("eglMakeCurrent");
    eglSwapBuffers = (decltype(eglSwapBuffers))eglGetProcAddress("eglSwapBuffers");

    display = eglGetDisplay(NULL);

    if (!eglInitialize(display, NULL, NULL)) {
        PyErr_BadInternalCall();
        return NULL;
    }

    int num_configs = 0;
    EGLConfig configs[256] = {};
    eglGetConfigs(display, NULL, 0, &num_configs);
    eglGetConfigs(display, configs, num_configs, &num_configs);

    EGLConfig config = NULL;
    for (int i = 0; i < num_configs; ++i) {
        int red_bits = 0;
        int green_bits = 0;
        int blue_bits = 0;
        int samples = 0;
        eglGetConfigAttrib(display, configs[i], EGL_RED_SIZE, &red_bits);
        eglGetConfigAttrib(display, configs[i], EGL_GREEN_SIZE, &green_bits);
        eglGetConfigAttrib(display, configs[i], EGL_BLUE_SIZE, &blue_bits);
        if (red_bits == 8 && green_bits == 8 && blue_bits == 8) {
            config = configs[i];
            break;
        }
    }

    if (!config) {
        PyErr_BadInternalCall();
        return NULL;
    }

    surface = eglCreateWindowSurface(display, config, hwnd, NULL);

    if (!surface) {
        PyErr_BadInternalCall();
        return NULL;
    }

    if (!eglBindAPI(EGL_OPENGL_ES_API)) {
        PyErr_BadInternalCall();
        return NULL;
    }

    int attribs[] = {
        EGL_CONTEXT_MAJOR_VERSION, 3,
        EGL_CONTEXT_MINOR_VERSION, 0,
        EGL_NONE,
    };

    context = eglCreateContext(display, config, NULL, attribs);
    if (!context) {
        PyErr_BadInternalCall();
        return NULL;
    }

    if (!eglMakeCurrent(display, surface, surface, context)) {
        PyErr_BadInternalCall();
        return NULL;
    }

    Py_RETURN_NONE;
}

PyObject * meth_update(PyObject * self) {
    eglSwapBuffers(display, surface);

    MSG msg = {};
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            Py_RETURN_FALSE;
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    Py_RETURN_TRUE;
}

PyObject * meth_load_opengl_function(PyObject * self, PyObject * arg) {
    const char * name = PyUnicode_AsUTF8(arg);
    void * proc = (void *)eglGetProcAddress(name);
    return PyLong_FromVoidPtr(proc);
}

PyMethodDef module_methods[] = {
    {"init", (PyCFunction)meth_init, METH_NOARGS},
    {"update", (PyCFunction)meth_update, METH_NOARGS},
    {"load_opengl_function", (PyCFunction)meth_load_opengl_function, METH_O},
    {},
};

PyModuleDef module_def = {PyModuleDef_HEAD_INIT, "mymodule", NULL, -1, module_methods};

extern "C" PyObject * PyInit_mymodule() {
    PyObject * module = PyModule_Create(&module_def);
    return module;
}
