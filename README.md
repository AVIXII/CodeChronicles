# **CodeChronicles**  
*A CP Warrior's Dojo*

## **Setup Guide**

---
NOTE: This is not a tutorial. Strictly for personal reference. Refer at your own risk.
---


This guide is a stepwise methodology to set up the environment for competitive programming which I followed on **Fedora 41 Workstation**. All related code files are in the **"Setup"** folder. 

### **Step 1: Install Sublime Text 4**
- Install **Sublime Text 4** on your system. You can follow the instructions for installation specific to your system.

### **Step 2: Configure the Build System**
- The **build system code** is available in **"build.txt"**. Use the following code in your Sublime Text build system:
    - Open **Sublime Text**.
    - Go to **Tools** > **Build System** > **New Build System**.
    - Copy and paste the code from **"build.txt"** into the new build system file.
    - This build system will only work when you have the `input.txt` and `output.txt` files in the same directory as your code.

### **Step 3: Update Keybindings**
- Go to `Preferences` > `Keybindings`. Two files will open:
    - **Left Pane**: Default keybindings.
    - **Right Pane**: User settings.
- In the **right pane** (user settings), clear any existing content and paste the following code:

```
[
    {
        "keys": ["ctrl+enter"],
        "command": "build"
    }
]
```

This will bind the build command to the Ctrl + Enter key. If some code already exists add only the part of curly braces.

### **Step 5: Install Package**
- Enter `ctrl+shift+p`. Type and enter `install package`.
- Again, Enter `ctrl+shift+p`. Type and enter `SublimeAStyleFormatter`.

### **Step 4: Install the "SublimeAStyleFormatter" Plugin**
- Enter `ctrl+shift+p`. Type and enter `install package`.
- Again, Enter `ctrl+shift+p`. Type and enter `SublimeAStyleFormatter`.

If you did not understand this, try the following:
- Install the SublimeAStyleFormatter plugin via Package Control in Sublime Text.
- To install Package Control, go to Tools > Install Package Control (if you haven't installed it already).
- Open Command Palette (Ctrl + Shift + P), type Install Package, and press Enter.
- Search for SublimeAStyleFormatter and press Enter to install it.

### **Step 5: Configure the Plugin**
- Go to `Preferences` > `Package Settings` > `SublimeAStyleFormatter` > `Settings - User`.
- Paste the following code to enable automatic formatting on file save:
```
{
    "autoformat_on_save": true
}
```
This will automatically format your code every time you save a file.

### **Step 6: Build and Run**
- Open your C++ file in Sublime Text.
- Press Ctrl + Enter to build and run your code.
- The output.txt file will be generated with the program output.
- Your code will also be automatically formatted using the AStyle plugin.

By following these steps, your environment will be set up for efficient competitive programming with automatic code formatting and streamlined build and run commands in Sublime Text.ls


The cp template is saved in the `cp.cpp` file in the `Snippets` folder. Use the code in this to create a snippet in sublime text.
Go to `Tools` > `Developer` > `New Snippet`.  
For saving the content, go to https://snippet-generator.app/?description=&tabtrigger=&snippet=&mode=vscode and select `Sublime-Text` as an option.
