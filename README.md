# A C++ Starter Project

This is your C++ workspace for CS 1410, pre-configured with a compiler, debugger, and build system.

## Option 1: GitHub Codespaces (Recommended)

Codespaces runs a fully configured development environment in your browser — no installs needed.

1. On your repository page, click the green **Code** button → **Codespaces** tab → **Create codespace on main**.
2. Wait about a minute for the environment to load.
3. You're ready — the terminal, compiler, and debugger are all set up.

> **Free tier:** GitHub gives every account 60 free Codespaces hours per month, which is more than enough for this course. Just remember to **stop your Codespace** when you're done working. You can do this from the bottom-left status bar in VS Code (→ "Stop Current Codespace"), or by visiting [github.com/codespaces](https://github.com/codespaces) and stopping it from there.
>
> **Need more hours?** Apply for the [GitHub Student Developer Pack](https://education.github.com/pack) using your `.edu` email. Once approved, your account is upgraded to Pro, which includes 90 Codespaces hours per month.

## Option 2: Local Development (VS Code + Docker)

If you prefer to work offline or have used up your Codespaces hours, you can run the same environment locally.

**One-time setup:**
1. Install [Docker Desktop](https://www.docker.com/products/docker-desktop/).
2. Install [Visual Studio Code](https://code.visualstudio.com).
3. In VS Code, install the **Dev Containers** extension.

**Opening the project:**
Clone this repository and open its folder in VS Code. When prompted to "Reopen in Container," click it. If no prompt appears, click the Dev Containers icon in the bottom-left corner and select **Reopen in Container**.

## Working with the Project Structure

Place your header files (`.h`) in `include/` and your source files (`.cpp`) in `src/`.

When you add a new program, add a line to `CMakeLists.txt` and save the file:

```cmake
add_executable(program_name src/file1.cpp src/file2.cpp)
```

List all `.cpp` files that make up the program, space-separated, after the program name inside the `add_executable` function.

## Building the Project

For the first time or after any change to `CMakeLists.txt`, re-run CMake from the `build/` folder. First, change to the `build/` folder if you are not there already:

```bash
cd build
```

Then run:

```bash
cmake ..
```

To compile your program, run:

```bash
make
```

Then run your program by name. For example:

```bash
./main
```

## Debugging

This project includes a pre-configured debugger setup in `.vscode/launch.json`. Before debugging, CMake must be configured with debug symbols enabled. From the `build/` folder, run:

```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

This replaces the plain `cmake ..` from the Building section — if you already ran that, re-run this command instead. It only needs to be done once (or after switching build types). Then to debug a program:

1. Open its source file in VS Code and click in the left margin to set breakpoints.
2. Open the **Run and Debug** panel (or press `F5`).
3. Select the configuration matching your program name from the dropdown (e.g., **Debug main**).
4. Press the green play button — VS Code will compile and launch the debugger automatically.

**Adding a new debug configuration:** When you add a new program to `CMakeLists.txt`, add a matching entry in `.vscode/launch.json`. The easiest way is to duplicate an existing entry and change only the `name` and `program` fields to match your new executable. For example, if you added `add_executable(lab2 src/lab2.cpp)`, duplicate the existing entry and update it to:

```json
{
    "name": "Debug lab2",
    "type": "cppdbg",
    "request": "launch",
    "program": "${workspaceFolder}/build/lab2",
    "args": [],
    "stopAtEntry": false,
    "cwd": "${workspaceFolder}",
    "environment": [],
    "externalConsole": false,
    "MIMode": "gdb",
    "preLaunchTask": "build"
}
```
