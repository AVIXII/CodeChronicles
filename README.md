# **CodeChronicles**  
*A CP Warrior's Dojo*

## **Setup Guide**

### **Step 1: Install Sublime Text 4**
- Install **Sublime Text 4** on your system. Follow the instructions according to your own system.

### **Step 2: Configure the Build System**
- Open **Sublime Text**.
- Go to **Tools** > **Build System** > **New Build System**.
- Copy and paste the following code into the new build system file. Custom name this file (Something like "cpcpp" ;)

```

  
{
    "shell_cmd": "g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -D_GLIBCXX_DEBUG \"${file}\" -o \"${file_path}/a.out\"",
    "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
    "working_dir": "${file_path}",
    "selector": "source.c++, source.cpp",

    "variants": [
        {
            "name": "Run to Output File",
            "shell_cmd": "g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -D_GLIBCXX_DEBUG \"${file}\" -o \"${file_path}/a.out\" && \"${file_path}/a.out\" < \"${file_path}/input.txt\" > \"${file_path}/output.txt\""
        },
        {
            "name": "Run in Terminal (Interactive)",
            // Uses xterm with -hold.
            // -hold: Keeps the window open after the program finishes so you can see the output.
            // -e: Executes your program.
            "shell_cmd": "g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -D_GLIBCXX_DEBUG \"${file}\" -o \"${file_path}/a.out\" && xterm -fa 'Monospace' -fs 11 -hold -e \"${file_path}/a.out\""
        }
    ]
}

```

This will bind the build command to the `Ctrl + Shift + b` key. If some code already exists add only the part within the curly braces.











for opening the folders or files of packages use browse packages

Extras:
1) Install Package Control
2) Must haves:
    SideBarEnhancements
    A File Icon

