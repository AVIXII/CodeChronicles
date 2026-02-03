---

# ⚔️ CodeChronicles: The CP Warrior's Dojo

Welcome to the **CodeChronicles** setup guide. This configuration transforms **Sublime Text 4** into a high-performance Competitive Programming environment, complete with automated input/output handling and powerful debugging flags.

## 📋 Prerequisites

Before configuring Sublime Text, ensure your system has the necessary compiler and terminal tools installed (specifically for the interactive mode):

* **C++ Compiler:** `g++` (part of `build-essential` on Linux).
* **Terminal:** `xterm` (Required for the interactive console pop-up).

```bash
# Ubuntu/Debian users:
sudo apt install build-essential xterm

```

---

## 🚀 Setup Guide

### **Step 1: Install Sublime Text 4**

Download and install **Sublime Text 4** from the official website:

* [Download Sublime Text](https://www.sublimetext.com/download)

### **Step 2: Configure the Build System**

This custom build system handles compilation, inputs, and outputs automatically.

1. Open **Sublime Text**.
2. Navigate to **Tools** > **Build System** > **New Build System...**
3. Paste the following configuration into the file:

```json
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
            "shell_cmd": "g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -D_GLIBCXX_DEBUG \"${file}\" -o \"${file_path}/a.out\" && xterm -fa 'Monospace' -fs 11 -hold -e \"${file_path}/a.out\""
        }
    ]
}

```

4. Save the file as `CP_Warrior.sublime-build` (or `cpcpp.sublime-build`).

### **Step 3: The "Dojo" Layout (Recommended)**

To maximize efficiency, set up your screen to see code, input, and output simultaneously.

1. Create a folder for your CP problems.
2. Inside that folder, create two empty files: `input.txt` and `output.txt`.
3. In Sublime Text, go to **View** > **Layout** > **Columns: 3**.
4. **Group 1 (Left):** Open your `.cpp` code file.
5. **Group 2 (Middle):** Open `input.txt`.
6. **Group 3 (Right):** Open `output.txt`.

### **Step 4: Power-Ups (Packages)**

Enhance the visual experience and file management.

1. **Install Package Control:**
* Press `Ctrl + Shift + P` (Command Palette).
* Type `Install Package Control` and hit Enter.


2. **Install Extensions:**
* Press `Ctrl + Shift + P` > Type `Package Control: Install Package`.
* Search for and install:
* **SideBarEnhancements** (Better file operations in the sidebar).
* **A File Icon** (Beautiful icons for file types).





---

## 🎮 How to Use

### **Running Your Code**

You have three modes of operation. Press **`Ctrl + Shift + B`** to select your build variant:

| Variant | Description |
| --- | --- |
| **C++ (Default)** | Compiles the code only. Checks for errors. |
| **Run to Output File** | Compiles and pipes `input.txt` into your program, writing results to `output.txt`. |
| **Run in Terminal** | Compiles and opens a separate **XTerm** window for interactive input. |

> **Pro Tip:** Once you select a variant using `Ctrl + Shift + B`, you can simply press **`Ctrl + B`** to repeat that last used build command instantly.

### **Compilation Flags Explained**

Your build system uses these flags to make you a better coder:

* `-O2`: Standard optimization level for CP.
* `-Wall -Wextra -Wshadow`: Warns you about potential bugs, unused variables, and shadowed variables.
* `-D_GLIBCXX_DEBUG`: Enables strict debug mode for STL containers (catches index out of bounds errors immediately).

---

## ⚠️ War Strategy: Interactive Problems

When solving **Interactive Problems** (where your code queries the judge in real-time), adhere to the following rule to avoid `Idleness Limit Exceeded` or `Wrong Answer`:

**❗ DISABLE FAST I/O**

You **must comment out** the standard synchronization lines in your template:

```cpp
void solve() {
    // ios_base::sync_with_stdio(false);  <-- COMMENT THIS
    // cin.tie(NULL);                     <-- COMMENT THIS
    
    // Your interactive code here...
}

```

**Why?**
Fast I/O disables the automatic flushing of the output buffer. In interactive problems, if the buffer isn't flushed, the judge never receives your query, your program waits forever for a response, and the judge times you out.

Alternatively, if you keep Fast I/O, you must manually type `cout << flush;` or `cout << endl;` after every output.

---

### **Troubleshooting**

* **"Browse Packages":** If you need to edit manual configurations, go to `Preferences` > `Browse Packages`.
* **XTerm not found:** If the interactive mode fails, ensure `xterm` is installed on your Linux system (`sudo apt install xterm`).

---
