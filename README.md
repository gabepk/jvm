English/[Português](https://github.com/gabepk/jvm/blob/master/README.pt.md)

# Java Virtual Machine

## Introduction

C ++ implementation of a simplified Java Virtual Machine based on Java 2 for the Basic Software discipline at the University of Brasília, 2nd semester of 2015.

Most of the instructions in the Java 2 bytecode are implemented, except: `monitorenter, monitorexit, athrow`.

The implementation also simulates basic I / O functionalities (eg `System.out.println ()`) and strings.

## Instructions and Recommendations
* To create its functionality, always create a branch from the dev.
* Always pull before you start working and push.
* Always create explanatory commits, so we can go back to some commit if something goes wrong.
* Before merge your functionality into dev, always rebase with dev, resolve conflicts (if any), and make sure everything is working.
* If the functionality is ready (also compiling and working) after rebase with dev, merge with dev.
* Document the code using [Doxygen](http://www.doxygen.nl/manual/docblocks.html) in the Javadoc standard.
* Whenever you create a new .c / .cpp file, add it to CMakeLists.txt.

## Project Folders
* .C / .cpp files are contained in the / src folder
* .H / .hpp files are contained in the / include folder
* Examples of .java programs (and their respective .class) are in / examples
* The documentation is in the / docs folder

## File Generation .class
To generate a .class file from a .java program, run the following command:
`javac -source 1.2 -target 1.2 programa.java`

## Project Compilation
To compile the project, first create a folder at the root of the project:
`mkdir build && cd build`

With that done, run CMake and do the make:
`cmake .. && make`
The executable file will then be created, ready to run.

## Execution
* `./jvm file.class` (will run the program contained in .class file)
* `./jvm file.class saida.txt` (will run the program contained in .class file and will show the formatted structure of the .class file in output.txt)

The Test.class file in `examples` folder is a simple program that calculates the 42nd element of the Fibonacci sequenc. You can use it as a test for the first run. Remember to put the .class file in the same directory as the executable.

In addition, make sure that the `java` folder is in the same directory as the executable so that the Object.class class can be found by the JVM. CMake will automate this, but you should know this information in case you compile the project in another way.

## Generating Documentation
To generate the documentation, run the following command at the root of the project: `doxygen`
With this done, the HTML documentation will be in doxygen / html / and in LaTeX it will be in doxygen / latex /.

## References
* [JVM specification - 2nd edition](http://web.cecs.pdx.edu/~apt/vmspec/VMSpecTOC.doc.html)
* [Basic Git](https://git-scm.com/book/pt-br/v1/Primeiros-passos-Noções-Básicas-de-Git)
* [SourceTree - git client with graphical interface](https://www.sourcetreeapp.com)
* [CMake 3.3.2 - download](https://cmake.org/download/)
* [Portuguese explanation of .class](http://www.bertochi.com.br/zines/cogubin/edicoes/1/ClassInjection.txt)

## Developers
* Ana Paulino
* Arthur Emídio
* Gabriella Esteves
* Matheus Andrade
* Matheus Bastos
