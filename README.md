# parrallel-computing
parrallel-computing practice project

# Preface
This is simple cases I wrote in my hpc class. C/C++ or Fortran language used 
here.

# Configuration of Environment
I am using VS Code, it is easy to configurate the environment.

1. Use homebrew to insall openmpi.
```shell
brew install openmpi
```
2. Include your openmpi include directory in c_cpp_properties.json file located in .vscode sub dir of your current working directory.
```json
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "${workspaceFolder}/**",
                "/opt/homebrew/include"  // Where your cpp head files are located.
            ],
            "defines": [],
            "macFrameworkPath": [],
            "compilerPath": "/opt/homebrew/bin/mpicc", // 
            "cStandard": "c11",
            "cppStandard": "gnu++17",
            "intelliSenseMode": "macos-clang-arm64",
            "configurationProvider": "ms-vscode.makefile-tools"
        }
    ],
    "version": 4
}
```