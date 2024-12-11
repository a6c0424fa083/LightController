# LightController

 ---


## About this Project

This is the Host(Computer) version of the LightController.


## How to get the Project

You can download a .zip file or use
```shell
git clone https://github.com/a6c0424fa083/LightController.git
```
to get the Project.


## How to build the Project
This Project is build using the cmake build system only!<br>
To build it simply follow these few steps:<br>

**Note:**<br>
You should change the targeted architecture in the root CMakeLists.txt file according to your system architecture.

**CMakeLists.txt:**
```cmake
                                                             # Lines

# define build architecture                                  #    26
set(CMAKE_OSX_ARCHITECTURES    x86_64) # x86_64 / arm64      #    27
set(CMAKE_LIBRARY_ARCHITECTURE x84_64) # x86_64 / arm64      #    28
```

Therefore, edit the lines 27 / 28 to your needs.

### Create a build directory

You can choose a fitting build-directory name.

```shell
mkdir your-build-directory
```


### Prebuild the Project using cmake

Run cmake to prebuild the Project.

```shell
cmake -S . -B ./your-build-directory
```

**Note:**<br>
You can use the -G flag to select a custom generator.
See ```cmake --help``` to get more information
about the available generators on your operating system.
Since make is the default for unix systems
there is no need the add the flag in this case.
But feel free to use other build systems
that you are the most comfortable with.
Be careful when spelling the build system
since correct use of spaces, dashes and capitalization are necessary
to detect the target build system.

**Example:**<br>
Use ```cmake -S . -B ./your-build-directory -G "Ninja"```
to build for ninja builds.


### Build the Project using make

Execute the Makefile to compile the Project.

```shell
cd ./your-build-directory
make
```

This will execute the main target in the cmake-generated Makefile
and build the Project to an executable
located in the root of the build directory ```your-build-directory```.


## Run the Project

That's it! You can now execute the executable.<br>
**Note:**<br>
If you are using Mac a simple double-tap causes issues (the font-path could not be found).
To avoid this start the application in the Terminal with ```./LightController```.


## Testing

**The following Environments have been tested and run the program:**<br>

- [x] macOS Sequoia / arm64
- [x] ubuntu 6.8.0-50-generic / x86_64