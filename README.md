A simple sandbox game using C and the SDL2 library, includes two paddles and bouncing ball, endlessly bouncing.

The left paddle move up (A Key) and down (D Key)
as well as the right paddle, up (Left Key) and down (Right Key).

## Build the project
setup on mac or linux
1. Make build folder
```
mkdir build
```

2. change your directory into build folder
```
cd build
```

3. This project used cmake to build the game
```
cmake ..
```
or add the -DCMAKE_EXPORT_COMPILE_COMMANDS=1 option to generate compile_commands.json file

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
