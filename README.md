A simple sandbox game using C and SDL2, includes two paddles and bouncing ball, endlessly bouncing.

![](https://github.com/Carlos460/basic_arcade/blob/main/assets/peak_gameplay.gif)

The left paddle moves up (A Key) and down (D Key)
as well as the right paddle, up (Left Key) and down (Right Key).

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
