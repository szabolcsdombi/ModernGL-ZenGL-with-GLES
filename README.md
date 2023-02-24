# ModernGL/ZenGL GLES compatibility

Compatibility with **WebGL** and **Raspberry Pi**.

This repository contains a testbed for running Python with a GLES 3.0 (WebGL) or GLES 3.1 (Raspberry Pi) on desktop computers.<br>
This project uses [angle](https://github.com/google/angle) to load GLES 3.0 with WebGL compatibilty or GLES 3.1 that actually runs Vulkan or DirectX under the hood.

### Development

- Place `libGLESv2.dll` to the project root. (no need to build [angle](https://github.com/google/angle), you can find one in your installed chrome/vscode's folder)

- Build this project with `pip setup.py build_ext --inplace`

- Run the test file `python test_zengl.py` or `python test_moderngl.py`

### Known Issues
