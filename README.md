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


## How to install the necessary tools for building the Project

### Mac

- The compiler ```clang++``` can be installed
  by installing the command line tools via ```xcode-select --install```
  and finish the installation in the gui System Settings -> Software Updates
- Install ```brew``` (installation guide can be found here: https://brew.sh)
- Install ```cmake``` and ```make``` using ```brew install cmake make```

### Linux

- Use your packet manager e.g. ```apt``` or ```packman``` to install ```cmake``` and ```make```
- Apt example: ```apt install cmake make gcc g++ gdb``` (gcc etc. are the compilers)

### Windows

- Install the cygwin packet manager following this guide https://cygwin.com/install.html<br>

**NOTE:**<br>
It is important to install the packet manager directly at C:\cygwin64 (the default location)

- If you land on a cellular view change the **view** to **Full** and search for **gcc**
- In the colum **New** change the selection (**Skip** by default) for **gcc-g++** to the latest stable version
- Search for **gdb**, **make**, **cmake**, **libGL-devel**, **libGLU-devel**, **libXrandr-devel**, **libXi-devel**, **libXinerama-devel**, **libXcursor-devel**, **libXrender-devel**, **meson**, **ninja**, **python3**, **python3-pip** and **git** as well and set the latest version
- On the bottom right hit **Next** and finish the installation
- In the Searchbar type **Enviroment Variables** and go the **Edit Enviroment Variables** page
- Under **User variables** double-tap the **Path** variable and add ```C:\cygwin64\bin``` as a path
- Restart your PC
- Run ```python -m pip install meson```

***WORK IN PROGRESS!***


## How to build the Project
This Project is build using the cmake build system only!<br>
To build it simply follow these few steps:<br>

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

If you are on an arm64 device run:

```shell
cmake -S . -B ./your-build-directory -DCMAKE_OSX_ARCHITECTURES=arm64 -DCMAKE_LIBRARY_ARCHITECTURES=arm64
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
to build for ninja builds.<br>
Or ```cmake -S . -B ./your-build-directory -G "Unix Makefiles"```
to force makefile build.


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

That's it! You can now execute the executable.

**Note:**<br>
If you are using Mac a simple double-tap causes issues since the relative project root changes.
To avoid this start the application in the Terminal with ```./LightController```.


## Testing

**The following Environments have been tested and run the program:**<br>

***WORK IN PROGRESS!***
