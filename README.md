A simple sandbox game using C and SDL2, includes two paddles and bouncing ball, endlessly bouncing.

![](https://github.com/Carlos460/basic_arcade/blob/main/assets/peak_gameplay.gif)

### Controls

The left paddle moves up (A Key) and down (D Key)
as well as the right paddle, up (Left Key) and down (Right Key).

## Setup

1. Create a CMakeLists.txt file in the root directory

2. Copy the contents of /cmake_example/CMakeLists.example.txt into the CMakeLists.txt file

3. update the CMakeLists.txt to include the path to your sdl2 installation

## Building the project
setup on mac or linux
1. Create a build folder
```
mkdir build
```

2. change your directory into the build folder
```
cd build
```

3. This project uses cmake to build the game
```
cmake ..
```
add the -DCMAKE_EXPORT_COMPILE_COMMANDS=1 option to generate compile_commands.json file

```
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
```
4. Use the make command
```
make
```
5. Run the executable
```
./basic_arcade
```
