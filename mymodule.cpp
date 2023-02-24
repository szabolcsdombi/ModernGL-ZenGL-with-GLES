#include <Python.h>
#include <Windows.h>
#include <unordered_map>

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

struct ImageFormat {
    unsigned format;
    unsigned type;
};

std::unordered_map<unsigned, unsigned> texture_targets;
std::unordered_map<unsigned, unsigned> targetbindings;
std::unordered_map<unsigned, ImageFormat> internalformats;

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

#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_ARRAY_BUFFER 0x8892
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_FRAMEBUFFER 0x8D40
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_SAMPLER_BINDING 0x8919
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE0 0x84C0
#define GL_VERTEX_ARRAY 0x8074
#define GL_VERTEX_ARRAY_BINDING 0x85B5

#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_3D 0x806F
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE_BINDING_3D 0x806A
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A

#define GL_BYTE 0x1400
#define GL_DEPTH_COMPONENT 0x1902
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_DEPTH_STENCIL 0x84F9
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_FLOAT 0x1406
#define GL_INT 0x1404
#define GL_R16 0x822A
#define GL_R16F 0x822D
#define GL_R16I 0x8233
#define GL_R16UI 0x8234
#define GL_R32F 0x822E
#define GL_R32I 0x8235
#define GL_R32UI 0x8236
#define GL_R8 0x8229
#define GL_R8_SNORM 0x8F94
#define GL_R8I 0x8231
#define GL_R8UI 0x8232
#define GL_RED 0x1903
#define GL_RED_INTEGER 0x8D94
#define GL_RG 0x8227
#define GL_RG_INTEGER 0x8228
#define GL_RG16 0x822C
#define GL_RG16F 0x822F
#define GL_RG16I 0x8239
#define GL_RG16UI 0x823A
#define GL_RG32F 0x8230
#define GL_RG32I 0x823B
#define GL_RG32UI 0x823C
#define GL_RG8 0x822B
#define GL_RG8_SNORM 0x8F95
#define GL_RG8I 0x8237
#define GL_RG8UI 0x8238
#define GL_RGBA 0x1908
#define GL_RGBA_INTEGER 0x8D99
#define GL_RGBA16F 0x881A
#define GL_RGBA16I 0x8D88
#define GL_RGBA16UI 0x8D76
#define GL_RGBA32F 0x8814
#define GL_RGBA32I 0x8D82
#define GL_RGBA32UI 0x8D70
#define GL_RGBA8 0x8058
#define GL_RGBA8_SNORM 0x8F97
#define GL_RGBA8I 0x8D8E
#define GL_RGBA8UI 0x8D7C
#define GL_SHORT 0x1402
#define GL_SRGB8_ALPHA8 0x8C43
#define GL_STENCIL_INDEX 0x1901
#define GL_STENCIL_INDEX8 0x8D48
#define GL_UNSIGNED_BYTE 0x1401
#define GL_UNSIGNED_INT 0x1405
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_UNSIGNED_SHORT 0x1403

void (*glTexParameteri)(unsigned int target, unsigned int pname, int param);
void (*glTexImage2D)(unsigned int target, int level, int internalformat, int width, int height, int border, unsigned int format, unsigned int type, const void * pixels);
void (*glReadBuffer)(unsigned int src);
void (*glReadPixels)(int x, int y, int width, int height, unsigned int format, unsigned int type, void * pixels);
void (*glGetIntegerv)(unsigned int pname, int * data);
const unsigned char * (*glGetString)(unsigned int name);
void (*glTexSubImage2D)(unsigned int target, int level, int xoffset, int yoffset, int width, int height, unsigned int format, unsigned int type, const void * pixels);
void (*glBindTexture)(unsigned int target, unsigned int texture);
void (*glDeleteTextures)(int n, const unsigned int * textures);
void (*glGenTextures)(int n, unsigned int * textures);
void (*glTexImage3D)(unsigned int target, int level, int internalformat, int width, int height, int depth, int border, unsigned int format, unsigned int type, const void * pixels);
void (*glTexSubImage3D)(unsigned int target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, unsigned int format, unsigned int type, const void * pixels);
void (*glActiveTexture)(unsigned int texture);
void (*glBindBuffer)(unsigned int target, unsigned int buffer);
void (*glDeleteBuffers)(int n, const unsigned int * buffers);
void (*glGenBuffers)(int n, unsigned int * buffers);
void (*glBufferData)(unsigned int target, sizeiptr size, const void * data, unsigned int usage);
void (*glBufferSubData)(unsigned int target, sizeiptr offset, sizeiptr size, const void * data);
void (*glGetBufferSubData)(unsigned int target, sizeiptr offset, sizeiptr size, void * data);
unsigned char (*glUnmapBuffer)(unsigned int target);
void (*glDrawBuffers)(int n, const unsigned int * bufs);
void (*glEnableVertexAttribArray)(unsigned int index);
void (*glVertexAttribPointer)(unsigned int index, int size, unsigned int type, unsigned char normalized, int stride, const void * pointer);
void (*glBindBufferRange)(unsigned int target, unsigned int index, unsigned int buffer, sizeiptr offset, sizeiptr size);
void (*glVertexAttribIPointer)(unsigned int index, int size, unsigned int type, int stride, const void * pointer);
void (*glBindRenderbuffer)(unsigned int target, unsigned int renderbuffer);
void (*glDeleteRenderbuffers)(int n, const unsigned int * renderbuffers);
void (*glGenRenderbuffers)(int n, unsigned int * renderbuffers);
void (*glBindFramebuffer)(unsigned int target, unsigned int framebuffer);
void (*glDeleteFramebuffers)(int n, const unsigned int * framebuffers);
void (*glGenFramebuffers)(int n, unsigned int * framebuffers);
void (*glFramebufferTexture2D)(unsigned int target, unsigned int attachment, unsigned int textarget, unsigned int texture, int level);
void (*glFramebufferRenderbuffer)(unsigned int target, unsigned int attachment, unsigned int renderbuffertarget, unsigned int renderbuffer);
void (*glGenerateMipmap)(unsigned int target);
void (*glBlitFramebuffer)(int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, unsigned int mask, unsigned int filter);
void (*glRenderbufferStorageMultisample)(unsigned int target, int samples, unsigned int internalformat, int width, int height);
void (*glFramebufferTextureLayer)(unsigned int target, unsigned int attachment, unsigned int texture, int level, int layer);
void * (*glMapBufferRange)(unsigned int target, sizeiptr offset, sizeiptr length, unsigned int access);
void (*glBindVertexArray)(unsigned int array);
void (*glDeleteVertexArrays)(int n, const unsigned int * arrays);
void (*glGenVertexArrays)(int n, unsigned int * arrays);
void (*glDrawArraysInstanced)(unsigned int mode, int first, int count, int instancecount);
void (*glDrawElementsInstanced)(unsigned int mode, int count, unsigned int type, const void * indices, int instancecount);
void (*glGenSamplers)(int count, unsigned int * samplers);
void (*glDeleteSamplers)(int count, const unsigned int * samplers);
void (*glBindSampler)(unsigned int unit, unsigned int sampler);
void (*glSamplerParameteri)(unsigned int sampler, unsigned int pname, int param);
void (*glSamplerParameterf)(unsigned int sampler, unsigned int pname, float param);
void (*glSamplerParameterfv)(unsigned int sampler, unsigned int pname, const float * param);
void (*glVertexAttribDivisor)(unsigned int index, unsigned int divisor);

HWND hwnd;
HDC hdc;
HGLRC hrc;

EGLDisplay display;
EGLSurface surface;
EGLContext context;

int width;
int height;

PyObject * gl;

void glMultiDrawArraysIndirect(unsigned mode, const void * indirect, int drawcount, int stride) {
}

void glMultiDrawElementsIndirect(unsigned mode, unsigned type, const void * indirect, int drawcount, int stride) {
}

void glBindBuffersRange(unsigned target, unsigned first, int count, const unsigned * buffers, const sizeiptr * offsets, const sizeiptr * sizes) {
    for (int i = 0; i < count; ++i) {
        glBindBufferRange(target, first + i, buffers[i], offsets[i], sizes[i]);
    }
}

void glBindTextures(unsigned first, int count, const unsigned * textures) {
    int active_texture = 0;
    glGetIntegerv(GL_ACTIVE_TEXTURE, &active_texture);
    for (int i = 0; i < count; ++i) {
        glActiveTexture(GL_TEXTURE0 + first + i);
        unsigned target = texture_targets[textures[i]];
        glBindTexture(target, textures[i]);
    }
    glActiveTexture(active_texture);
}

void glBindSamplers(unsigned first, int count, const unsigned * samplers) {
    for (int i = 0; i < count; ++i) {
        glBindSampler(first + i, samplers[i]);
    }
}

void glBindImageTextures(unsigned first, int count, const unsigned * textures) {
}

void glCreateBuffers(int n, unsigned * buffers) {
    int array_buffer_binding = 0;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &array_buffer_binding);
    glGenBuffers(n, buffers);
    for (int i = 0; i < n; ++i) {
        glBindBuffer(GL_ARRAY_BUFFER, buffers[i]);
    }
    glBindBuffer(GL_ARRAY_BUFFER, array_buffer_binding);
}

void glNamedBufferStorage(unsigned buffer, sizeiptr size, const void * data, unsigned flags) {
    int array_buffer_binding = 0;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &array_buffer_binding);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, array_buffer_binding);
}

void glNamedBufferSubData(unsigned buffer, sizeiptr offset, sizeiptr size, const void * data) {
    int array_buffer_binding = 0;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &array_buffer_binding);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
    glBindBuffer(GL_ARRAY_BUFFER, array_buffer_binding);
}

void * glMapNamedBufferRange(unsigned buffer, sizeiptr offset, sizeiptr length, unsigned access) {
    int array_buffer_binding = 0;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &array_buffer_binding);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    void * result = glMapBufferRange(GL_ARRAY_BUFFER, offset, length, access);
    glBindBuffer(GL_ARRAY_BUFFER, array_buffer_binding);
    return result;
}

unsigned char glUnmapNamedBuffer(unsigned buffer) {
    int array_buffer_binding = 0;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &array_buffer_binding);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    unsigned char result = glUnmapBuffer(GL_ARRAY_BUFFER);
    glBindBuffer(GL_ARRAY_BUFFER, array_buffer_binding);
    return result;
}

void glGetNamedBufferSubData(unsigned buffer, sizeiptr offset, sizeiptr size, void * data) {
    int array_buffer_binding = 0;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &array_buffer_binding);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glGetBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
    glBindBuffer(GL_ARRAY_BUFFER, array_buffer_binding);
}

void glCreateFramebuffers(int n, unsigned * framebuffers) {
    int read_framebuffer_binding = 0;
    int draw_framebuffer_binding = 0;
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &read_framebuffer_binding);
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &draw_framebuffer_binding);
    glGenFramebuffers(n, framebuffers);
    for (int i = 0; i < n; ++i) {
        glBindFramebuffer(GL_FRAMEBUFFER, framebuffers[i]);
    }
    glBindFramebuffer(GL_READ_FRAMEBUFFER, read_framebuffer_binding);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, draw_framebuffer_binding);
}

void glNamedFramebufferRenderbuffer(unsigned framebuffer, unsigned attachment, unsigned renderbuffertarget, unsigned renderbuffer) {
    int read_framebuffer_binding = 0;
    int draw_framebuffer_binding = 0;
    int renderbuffer_binding = 0;
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &read_framebuffer_binding);
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &draw_framebuffer_binding);
    glGetIntegerv(GL_RENDERBUFFER_BINDING, &renderbuffer_binding);
    glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, renderbuffertarget, renderbuffer);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, read_framebuffer_binding);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, draw_framebuffer_binding);
    glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer_binding);
}

void glNamedFramebufferParameteri(unsigned framebuffer, unsigned pname, int param) {
}

void glNamedFramebufferTexture(unsigned framebuffer, unsigned attachment, unsigned texture, int level) {
    int read_framebuffer_binding = 0;
    int draw_framebuffer_binding = 0;
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &read_framebuffer_binding);
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &draw_framebuffer_binding);
    unsigned target = texture_targets[texture];
    glBindTexture(target, texture);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, target, texture, level);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, read_framebuffer_binding);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, draw_framebuffer_binding);
}

void glNamedFramebufferTextureLayer(unsigned framebuffer, unsigned attachment, unsigned texture, int level, int layer) {
    int read_framebuffer_binding = 0;
    int draw_framebuffer_binding = 0;
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &read_framebuffer_binding);
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &draw_framebuffer_binding);
    unsigned target = texture_targets[texture];
    glBindTexture(target, texture);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glFramebufferTextureLayer(GL_FRAMEBUFFER, attachment, texture, level, layer);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, read_framebuffer_binding);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, draw_framebuffer_binding);
}

void glNamedFramebufferDrawBuffers(unsigned framebuffer, int n, const unsigned * bufs) {
    int read_framebuffer_binding = 0;
    int draw_framebuffer_binding = 0;
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &read_framebuffer_binding);
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &draw_framebuffer_binding);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glDrawBuffers(n, bufs);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, read_framebuffer_binding);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, draw_framebuffer_binding);
}

void glNamedFramebufferReadBuffer(unsigned framebuffer, unsigned src) {
    int read_framebuffer_binding = 0;
    int draw_framebuffer_binding = 0;
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &read_framebuffer_binding);
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &draw_framebuffer_binding);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glReadBuffer(src);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, read_framebuffer_binding);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, draw_framebuffer_binding);
}

void glBlitNamedFramebuffer(unsigned readFramebuffer, unsigned drawFramebuffer, int srcX0, int srcY0, int srcX1, int srcY1, int dstX0, int dstY0, int dstX1, int dstY1, unsigned mask, unsigned filter) {
    int read_framebuffer_binding = 0;
    int draw_framebuffer_binding = 0;
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &read_framebuffer_binding);
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &draw_framebuffer_binding);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, readFramebuffer);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, drawFramebuffer);
    glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, read_framebuffer_binding);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, draw_framebuffer_binding);
}

void glCreateRenderbuffers(int n, unsigned * renderbuffers) {
    int renderbuffer_binding = 0;
    glGetIntegerv(GL_RENDERBUFFER_BINDING, &renderbuffer_binding);
    glGenRenderbuffers(n, renderbuffers);
    for (int i = 0; i < n; ++i) {
        glBindRenderbuffer(GL_RENDERBUFFER, renderbuffers[i]);
    }
    glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer_binding);
}

void glNamedRenderbufferStorageMultisample(unsigned renderbuffer, int samples, unsigned internalformat, int width, int height) {
    int renderbuffer_binding = 0;
    glGetIntegerv(GL_RENDERBUFFER_BINDING, &renderbuffer_binding);
    glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
    glRenderbufferStorageMultisample(GL_RENDERBUFFER, samples, internalformat, width, height);
    glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer_binding);
}

void glCreateTextures(unsigned target, int n, unsigned * textures) {
    int texture_binding = 0;
    glGetIntegerv(targetbindings[target], &texture_binding);
    glGenTextures(n, textures);
    for (int i = 0; i < n; ++i) {
        glBindTexture(target, textures[i]);
        texture_targets[textures[i]] = target;
    }
    glBindTexture(target, texture_binding);
}

void glTextureStorage2D(unsigned texture, int levels, unsigned internalformat, int width, int height) {
    unsigned target = texture_targets[texture];
    unsigned format = internalformats[internalformat].format;
    unsigned type = internalformats[internalformat].type;
    int texture_binding = 0;
    glGetIntegerv(targetbindings[target], &texture_binding);
    glBindTexture(target, texture);
    for (int level = 0; level < levels; ++level) {
        glTexImage2D(target, level, internalformat, width, height, 0, format, type, NULL);
        width = width > 2 ? width >> 1 : 1;
        height = height > 2 ? height >> 1 : 1;
    }
    glBindTexture(target, texture_binding);
}

void glTextureStorage3D(unsigned texture, int levels, unsigned internalformat, int width, int height, int depth) {
    unsigned target = texture_targets[texture];
    unsigned format = internalformats[internalformat].format;
    unsigned type = internalformats[internalformat].type;
    int texture_binding = 0;
    glGetIntegerv(targetbindings[target], &texture_binding);
    glBindTexture(target, texture);
    for (int level = 0; level < levels; ++level) {
        glTexImage3D(target, level, internalformat, width, height, depth, 0, format, type, NULL);
        width = width > 2 ? width >> 1 : 1;
        height = height > 2 ? height >> 1 : 1;
        if (target != GL_TEXTURE_2D_ARRAY && target != GL_TEXTURE_CUBE_MAP_ARRAY) {
            depth = depth > 2 ? depth >> 1 : 1;
        }
    }
    glBindTexture(target, texture_binding);
}

void glTextureSubImage2D(unsigned texture, int level, int xoffset, int yoffset, int width, int height, unsigned format, unsigned type, const void * pixels) {
    unsigned target = texture_targets[texture];
    int texture_binding = 0;
    glGetIntegerv(targetbindings[target], &texture_binding);
    glBindTexture(target, texture);
    glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
    glBindTexture(target, texture_binding);
}

void glTextureSubImage3D(unsigned texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, unsigned format, unsigned type, const void * pixels) {
    unsigned target = texture_targets[texture];
    int texture_binding = 0;
    glGetIntegerv(targetbindings[target], &texture_binding);
    glBindTexture(target, texture);
    glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
    glBindTexture(target, texture_binding);
}

void glTextureParameteri(unsigned texture, unsigned pname, int param) {
    unsigned target = texture_targets[texture];
    int texture_binding = 0;
    glGetIntegerv(targetbindings[target], &texture_binding);
    glBindTexture(target, texture);
    glTexParameteri(target, pname, param);
    glBindTexture(target, texture_binding);
}

void glGenerateTextureMipmap(unsigned texture) {
    unsigned target = texture_targets[texture];
    int texture_binding = 0;
    glGetIntegerv(targetbindings[target], &texture_binding);
    glBindTexture(target, texture);
    glGenerateMipmap(target);
    glBindTexture(target, texture_binding);
}

void glCreateVertexArrays(int n, unsigned * arrays) {
    int vertex_array_binding = 0;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &vertex_array_binding);
    glGenVertexArrays(n, arrays);
    for (int i = 0; i < n; ++i) {
        glBindVertexArray(arrays[i]);
    }
    glBindVertexArray(vertex_array_binding);
}

void glEnableVertexArrayAttrib(unsigned vaobj, unsigned index) {
    int vertex_array_binding = 0;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &vertex_array_binding);
    glBindVertexArray(vaobj);
    glEnableVertexAttribArray(index);
    glBindVertexArray(vertex_array_binding);
}

void glVertexArrayElementBuffer(unsigned vaobj, unsigned buffer) {
    int vertex_array_binding = 0;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &vertex_array_binding);
    glBindVertexArray(vaobj);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
    glBindVertexArray(vertex_array_binding);
}

unsigned vertex_array_temp_buffer;
sizeiptr vertex_array_temp_offset;
int vertex_array_temp_stride;

void glVertexArrayVertexBuffer(unsigned vaobj, unsigned bindingindex, unsigned buffer, sizeiptr offset, int stride) {
    vertex_array_temp_buffer = buffer;
    vertex_array_temp_offset = offset;
    vertex_array_temp_stride = stride;
}

void glVertexArrayAttribFormat(unsigned vaobj, unsigned attribindex, int size, unsigned type, unsigned char normalized, unsigned relativeoffset) {
    int vertex_array_binding = 0;
    int array_buffer_binding = 0;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &vertex_array_binding);
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &array_buffer_binding);
    glBindVertexArray(vaobj);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_array_temp_buffer);
    glVertexAttribPointer(attribindex, size, type, normalized, vertex_array_temp_stride, (void *)vertex_array_temp_offset);
    glBindBuffer(GL_ARRAY_BUFFER, array_buffer_binding);
    glBindVertexArray(vertex_array_binding);
}

void glVertexArrayAttribIFormat(unsigned vaobj, unsigned attribindex, int size, unsigned type, unsigned relativeoffset) {
    int vertex_array_binding = 0;
    int array_buffer_binding = 0;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &vertex_array_binding);
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &array_buffer_binding);
    glBindVertexArray(vaobj);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_array_temp_buffer);
    glVertexAttribIPointer(attribindex, size, type, vertex_array_temp_stride, (void *)vertex_array_temp_offset);
    glBindBuffer(GL_ARRAY_BUFFER, array_buffer_binding);
    glBindVertexArray(vertex_array_binding);
}

void glVertexArrayBindingDivisor(unsigned vaobj, unsigned bindingindex, unsigned divisor) {
    int vertex_array_binding = 0;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &vertex_array_binding);
    glBindVertexArray(vaobj);
    glVertexAttribDivisor(bindingindex, divisor);
    glBindVertexArray(vertex_array_binding);
}

void glCreateSamplers(int n, unsigned * samplers) {
    int active_texture = 0;
    glGetIntegerv(GL_ACTIVE_TEXTURE, &active_texture);
    glActiveTexture(GL_TEXTURE0);
    int sampler_binding = 0;
    glGetIntegerv(GL_SAMPLER_BINDING, &sampler_binding);
    glGenSamplers(n, samplers);
    for (int i = 0; i < n; ++i) {
        glBindSampler(0, samplers[i]);
    }
    glBindSampler(0, sampler_binding);
    glActiveTexture(active_texture);
}

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
        EGL_CONTEXT_MINOR_VERSION, 1,
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

    glTexParameteri = (decltype(glTexParameteri))eglGetProcAddress("glTexParameteri");
    glTexImage2D = (decltype(glTexImage2D))eglGetProcAddress("glTexImage2D");
    glReadBuffer = (decltype(glReadBuffer))eglGetProcAddress("glReadBuffer");
    glReadPixels = (decltype(glReadPixels))eglGetProcAddress("glReadPixels");
    glGetIntegerv = (decltype(glGetIntegerv))eglGetProcAddress("glGetIntegerv");
    glGetString = (decltype(glGetString))eglGetProcAddress("glGetString");
    glTexSubImage2D = (decltype(glTexSubImage2D))eglGetProcAddress("glTexSubImage2D");
    glBindTexture = (decltype(glBindTexture))eglGetProcAddress("glBindTexture");
    glDeleteTextures = (decltype(glDeleteTextures))eglGetProcAddress("glDeleteTextures");
    glGenTextures = (decltype(glGenTextures))eglGetProcAddress("glGenTextures");
    glTexImage3D = (decltype(glTexImage3D))eglGetProcAddress("glTexImage3D");
    glTexSubImage3D = (decltype(glTexSubImage3D))eglGetProcAddress("glTexSubImage3D");
    glActiveTexture = (decltype(glActiveTexture))eglGetProcAddress("glActiveTexture");
    glBindBuffer = (decltype(glBindBuffer))eglGetProcAddress("glBindBuffer");
    glDeleteBuffers = (decltype(glDeleteBuffers))eglGetProcAddress("glDeleteBuffers");
    glGenBuffers = (decltype(glGenBuffers))eglGetProcAddress("glGenBuffers");
    glBufferData = (decltype(glBufferData))eglGetProcAddress("glBufferData");
    glBufferSubData = (decltype(glBufferSubData))eglGetProcAddress("glBufferSubData");
    glGetBufferSubData = (decltype(glGetBufferSubData))eglGetProcAddress("glGetBufferSubData");
    glUnmapBuffer = (decltype(glUnmapBuffer))eglGetProcAddress("glUnmapBuffer");
    glDrawBuffers = (decltype(glDrawBuffers))eglGetProcAddress("glDrawBuffers");
    glEnableVertexAttribArray = (decltype(glEnableVertexAttribArray))eglGetProcAddress("glEnableVertexAttribArray");
    glVertexAttribPointer = (decltype(glVertexAttribPointer))eglGetProcAddress("glVertexAttribPointer");
    glBindBufferRange = (decltype(glBindBufferRange))eglGetProcAddress("glBindBufferRange");
    glVertexAttribIPointer = (decltype(glVertexAttribIPointer))eglGetProcAddress("glVertexAttribIPointer");
    glBindRenderbuffer = (decltype(glBindRenderbuffer))eglGetProcAddress("glBindRenderbuffer");
    glDeleteRenderbuffers = (decltype(glDeleteRenderbuffers))eglGetProcAddress("glDeleteRenderbuffers");
    glGenRenderbuffers = (decltype(glGenRenderbuffers))eglGetProcAddress("glGenRenderbuffers");
    glBindFramebuffer = (decltype(glBindFramebuffer))eglGetProcAddress("glBindFramebuffer");
    glDeleteFramebuffers = (decltype(glDeleteFramebuffers))eglGetProcAddress("glDeleteFramebuffers");
    glGenFramebuffers = (decltype(glGenFramebuffers))eglGetProcAddress("glGenFramebuffers");
    glFramebufferTexture2D = (decltype(glFramebufferTexture2D))eglGetProcAddress("glFramebufferTexture2D");
    glFramebufferRenderbuffer = (decltype(glFramebufferRenderbuffer))eglGetProcAddress("glFramebufferRenderbuffer");
    glGenerateMipmap = (decltype(glGenerateMipmap))eglGetProcAddress("glGenerateMipmap");
    glBlitFramebuffer = (decltype(glBlitFramebuffer))eglGetProcAddress("glBlitFramebuffer");
    glRenderbufferStorageMultisample = (decltype(glRenderbufferStorageMultisample))eglGetProcAddress("glRenderbufferStorageMultisample");
    glFramebufferTextureLayer = (decltype(glFramebufferTextureLayer))eglGetProcAddress("glFramebufferTextureLayer");
    glMapBufferRange = (decltype(glMapBufferRange))eglGetProcAddress("glMapBufferRange");
    glBindVertexArray = (decltype(glBindVertexArray))eglGetProcAddress("glBindVertexArray");
    glDeleteVertexArrays = (decltype(glDeleteVertexArrays))eglGetProcAddress("glDeleteVertexArrays");
    glGenVertexArrays = (decltype(glGenVertexArrays))eglGetProcAddress("glGenVertexArrays");
    glDrawArraysInstanced = (decltype(glDrawArraysInstanced))eglGetProcAddress("glDrawArraysInstanced");
    glDrawElementsInstanced = (decltype(glDrawElementsInstanced))eglGetProcAddress("glDrawElementsInstanced");
    glGenSamplers = (decltype(glGenSamplers))eglGetProcAddress("glGenSamplers");
    glDeleteSamplers = (decltype(glDeleteSamplers))eglGetProcAddress("glDeleteSamplers");
    glBindSampler = (decltype(glBindSampler))eglGetProcAddress("glBindSampler");
    glSamplerParameteri = (decltype(glSamplerParameteri))eglGetProcAddress("glSamplerParameteri");
    glSamplerParameterf = (decltype(glSamplerParameterf))eglGetProcAddress("glSamplerParameterf");
    glSamplerParameterfv = (decltype(glSamplerParameterfv))eglGetProcAddress("glSamplerParameterfv");
    glVertexAttribDivisor = (decltype(glVertexAttribDivisor))eglGetProcAddress("glVertexAttribDivisor");
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
    if (PyObject * ptr = PyDict_GetItem(gl, arg)) {
        Py_INCREF(ptr);
        return ptr;
    }
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

    internalformats[GL_R8] = {GL_RED, GL_UNSIGNED_BYTE};
    internalformats[GL_RG8] = {GL_RG, GL_UNSIGNED_BYTE};
    internalformats[GL_RGBA8] = {GL_RGBA, GL_UNSIGNED_BYTE};
    internalformats[GL_R8_SNORM] = {GL_RED, GL_UNSIGNED_BYTE};
    internalformats[GL_RG8_SNORM] = {GL_RG, GL_UNSIGNED_BYTE};
    internalformats[GL_RGBA8_SNORM] = {GL_RGBA, GL_UNSIGNED_BYTE};
    internalformats[GL_R8UI] = {GL_RED_INTEGER, GL_UNSIGNED_BYTE};
    internalformats[GL_RG8UI] = {GL_RG_INTEGER, GL_UNSIGNED_BYTE};
    internalformats[GL_RGBA8UI] = {GL_RGBA_INTEGER, GL_UNSIGNED_BYTE};
    internalformats[GL_R16UI] = {GL_RED_INTEGER, GL_UNSIGNED_SHORT};
    internalformats[GL_RG16UI] = {GL_RG_INTEGER, GL_UNSIGNED_SHORT};
    internalformats[GL_RGBA16UI] = {GL_RGBA_INTEGER, GL_UNSIGNED_SHORT};
    internalformats[GL_R32UI] = {GL_RED_INTEGER, GL_UNSIGNED_INT};
    internalformats[GL_RG32UI] = {GL_RG_INTEGER, GL_UNSIGNED_INT};
    internalformats[GL_RGBA32UI] = {GL_RGBA_INTEGER, GL_UNSIGNED_INT};
    internalformats[GL_R8I] = {GL_RED_INTEGER, GL_BYTE};
    internalformats[GL_RG8I] = {GL_RG_INTEGER, GL_BYTE};
    internalformats[GL_RGBA8I] = {GL_RGBA_INTEGER, GL_BYTE};
    internalformats[GL_R16I] = {GL_RED_INTEGER, GL_SHORT};
    internalformats[GL_RG16I] = {GL_RG_INTEGER, GL_SHORT};
    internalformats[GL_RGBA16I] = {GL_RGBA_INTEGER, GL_SHORT};
    internalformats[GL_R32I] = {GL_RED_INTEGER, GL_INT};
    internalformats[GL_RG32I] = {GL_RG_INTEGER, GL_INT};
    internalformats[GL_RGBA32I] = {GL_RGBA_INTEGER, GL_INT};
    internalformats[GL_R16F] = {GL_RED, GL_FLOAT};
    internalformats[GL_RG16F] = {GL_RG, GL_FLOAT};
    internalformats[GL_RGBA16F] = {GL_RGBA, GL_FLOAT};
    internalformats[GL_R32F] = {GL_RED, GL_FLOAT};
    internalformats[GL_RG32F] = {GL_RG, GL_FLOAT};
    internalformats[GL_RGBA32F] = {GL_RGBA, GL_FLOAT};
    internalformats[GL_SRGB8_ALPHA8] = {GL_RGBA, GL_UNSIGNED_BYTE};
    internalformats[GL_STENCIL_INDEX8] = {GL_STENCIL_INDEX, GL_UNSIGNED_BYTE};
    internalformats[GL_DEPTH_COMPONENT16] = {GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT};
    internalformats[GL_DEPTH_COMPONENT24] = {GL_DEPTH_COMPONENT, GL_UNSIGNED_INT};
    internalformats[GL_DEPTH24_STENCIL8] = {GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8};
    internalformats[GL_DEPTH_COMPONENT32F] = {GL_DEPTH_COMPONENT, GL_FLOAT};

    targetbindings[GL_TEXTURE_1D] = GL_TEXTURE_BINDING_1D;
    targetbindings[GL_TEXTURE_2D] = GL_TEXTURE_BINDING_2D;
    targetbindings[GL_TEXTURE_3D] = GL_TEXTURE_BINDING_3D;
    targetbindings[GL_TEXTURE_CUBE_MAP] = GL_TEXTURE_BINDING_CUBE_MAP;
    targetbindings[GL_TEXTURE_1D_ARRAY] = GL_TEXTURE_BINDING_1D_ARRAY;
    targetbindings[GL_TEXTURE_2D_ARRAY] = GL_TEXTURE_BINDING_2D_ARRAY;
    targetbindings[GL_TEXTURE_CUBE_MAP_ARRAY] = GL_TEXTURE_BINDING_CUBE_MAP_ARRAY;

    gl = PyDict_New();

    PyDict_SetItemString(gl, "glMultiDrawArraysIndirect", PyLong_FromVoidPtr((void *)glMultiDrawArraysIndirect));
    PyDict_SetItemString(gl, "glMultiDrawElementsIndirect", PyLong_FromVoidPtr((void *)glMultiDrawElementsIndirect));
    PyDict_SetItemString(gl, "glBindBuffersRange", PyLong_FromVoidPtr((void *)glBindBuffersRange));
    PyDict_SetItemString(gl, "glBindTextures", PyLong_FromVoidPtr((void *)glBindTextures));
    PyDict_SetItemString(gl, "glBindSamplers", PyLong_FromVoidPtr((void *)glBindSamplers));
    PyDict_SetItemString(gl, "glBindImageTextures", PyLong_FromVoidPtr((void *)glBindImageTextures));
    PyDict_SetItemString(gl, "glCreateBuffers", PyLong_FromVoidPtr((void *)glCreateBuffers));
    PyDict_SetItemString(gl, "glNamedBufferStorage", PyLong_FromVoidPtr((void *)glNamedBufferStorage));
    PyDict_SetItemString(gl, "glNamedBufferSubData", PyLong_FromVoidPtr((void *)glNamedBufferSubData));
    PyDict_SetItemString(gl, "glMapNamedBufferRange", PyLong_FromVoidPtr((void *)glMapNamedBufferRange));
    PyDict_SetItemString(gl, "glUnmapNamedBuffer", PyLong_FromVoidPtr((void *)glUnmapNamedBuffer));
    PyDict_SetItemString(gl, "glGetNamedBufferSubData", PyLong_FromVoidPtr((void *)glGetNamedBufferSubData));
    PyDict_SetItemString(gl, "glCreateFramebuffers", PyLong_FromVoidPtr((void *)glCreateFramebuffers));
    PyDict_SetItemString(gl, "glNamedFramebufferRenderbuffer", PyLong_FromVoidPtr((void *)glNamedFramebufferRenderbuffer));
    PyDict_SetItemString(gl, "glNamedFramebufferParameteri", PyLong_FromVoidPtr((void *)glNamedFramebufferParameteri));
    PyDict_SetItemString(gl, "glNamedFramebufferTexture", PyLong_FromVoidPtr((void *)glNamedFramebufferTexture));
    PyDict_SetItemString(gl, "glNamedFramebufferTextureLayer", PyLong_FromVoidPtr((void *)glNamedFramebufferTextureLayer));
    PyDict_SetItemString(gl, "glNamedFramebufferDrawBuffers", PyLong_FromVoidPtr((void *)glNamedFramebufferDrawBuffers));
    PyDict_SetItemString(gl, "glNamedFramebufferReadBuffer", PyLong_FromVoidPtr((void *)glNamedFramebufferReadBuffer));
    PyDict_SetItemString(gl, "glBlitNamedFramebuffer", PyLong_FromVoidPtr((void *)glBlitNamedFramebuffer));
    PyDict_SetItemString(gl, "glCreateRenderbuffers", PyLong_FromVoidPtr((void *)glCreateRenderbuffers));
    PyDict_SetItemString(gl, "glNamedRenderbufferStorageMultisample", PyLong_FromVoidPtr((void *)glNamedRenderbufferStorageMultisample));
    PyDict_SetItemString(gl, "glCreateTextures", PyLong_FromVoidPtr((void *)glCreateTextures));
    PyDict_SetItemString(gl, "glTextureStorage2D", PyLong_FromVoidPtr((void *)glTextureStorage2D));
    PyDict_SetItemString(gl, "glTextureStorage3D", PyLong_FromVoidPtr((void *)glTextureStorage3D));
    PyDict_SetItemString(gl, "glTextureSubImage2D", PyLong_FromVoidPtr((void *)glTextureSubImage2D));
    PyDict_SetItemString(gl, "glTextureSubImage3D", PyLong_FromVoidPtr((void *)glTextureSubImage3D));
    PyDict_SetItemString(gl, "glTextureParameteri", PyLong_FromVoidPtr((void *)glTextureParameteri));
    PyDict_SetItemString(gl, "glGenerateTextureMipmap", PyLong_FromVoidPtr((void *)glGenerateTextureMipmap));
    PyDict_SetItemString(gl, "glCreateVertexArrays", PyLong_FromVoidPtr((void *)glCreateVertexArrays));
    PyDict_SetItemString(gl, "glEnableVertexArrayAttrib", PyLong_FromVoidPtr((void *)glEnableVertexArrayAttrib));
    PyDict_SetItemString(gl, "glVertexArrayElementBuffer", PyLong_FromVoidPtr((void *)glVertexArrayElementBuffer));
    PyDict_SetItemString(gl, "glVertexArrayVertexBuffer", PyLong_FromVoidPtr((void *)glVertexArrayVertexBuffer));
    PyDict_SetItemString(gl, "glVertexArrayAttribFormat", PyLong_FromVoidPtr((void *)glVertexArrayAttribFormat));
    PyDict_SetItemString(gl, "glVertexArrayAttribIFormat", PyLong_FromVoidPtr((void *)glVertexArrayAttribIFormat));
    PyDict_SetItemString(gl, "glVertexArrayBindingDivisor", PyLong_FromVoidPtr((void *)glVertexArrayBindingDivisor));
    PyDict_SetItemString(gl, "glCreateSamplers", PyLong_FromVoidPtr((void *)glCreateSamplers));
    return module;
}
