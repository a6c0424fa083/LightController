# LightController

 ---


## About this Project

This is the Host(Computer) version of the LightController.


## How to build the Project
This Project is build using the cmake build system only!<br>
To build it simply follow these few steps (in Project root):

### Create a build directory

```shell
mkdir your-build-directory
```


### Prebuild the Project using cmake

```shell
cmake -S . -B ./your-build-directory
```

**Note:**<br>
You can use the -G flag to select a custom generator.
See ```cmake --help``` to get more information
on what generators are available on you operating system.
Since make is the default for unix systems
there is no need the add the flag in this case.
But feel free to use other build systems
that you are the most comfortable with.
Be careful when spelling the build system
since spaces, dashes and capitalization are necessary
to detect the target build system.

**Example:**<br>
Use ```cmake -S . -B ./your-build-directory -G "Ninja"```
to build for ninja builds.


### Build the Project using make

```shell
cd ./your-build-directory
make
```

This will execute the main target in the cmake-generated Makefile
and build the Project to an executable
located in the root of the build directory.
