# **CodeChronicles**  
*A CP Warrior's Dojo*

## **Setup Guide**
All the necessary files for running the final code is available in the `contest` folder.
Directory of sublime text packages: "home/avixii/.config/sublime-text/Packages/"

### **Step 1: Install Sublime Text 4**
- Install **Sublime Text 4** on your system. Follow the instructions according to your own system.

### **Step 2: Configure the Build System**
- Open **Sublime Text**.
- Go to **Tools** > **Build System** > **New Build System**.
- Copy and paste the following code into the new build system file. Custom name this file (Something like "cpcpp" ;)

```
{
    "cmd" : ["g++ -std=c++17 $file_name -o $file_base_name && timeout 1s ./$file_base_name<input.txt>output.txt"], 
    "selector" : "source.cpp",
    "shell": true,
    "working_dir" : "$file_path"
}

```

This build system will only work when you have the `input.txt` and `output.txt` files in the same directory as your code.

### **Step 3: Update Keybindings**
- Go to `Preferences` > `Keybindings`. Two files will open:
    - **Left Pane**: Default keybindings.
    - **Right Pane**: User settings.
- In the **right pane** (user settings), add the following code:

```
[
    {
        "keys": ["ctrl+shift+b"],
        "command": "build"
    }
]
```

This will bind the build command to the `Ctrl + Shift + b` key. If some code already exists add only the part within the curly braces.

### **Step 5: Install Package Control**
- Enter `ctrl+shift+p`. Type and enter `Install Package Control`.
- Again, Enter `ctrl+shift+p`. Type and enter `SublimeAStyleFormatter`.

### **Step 4: Install the "SublimeAStyleFormatter" Plugin**
- Open Command Palette (Ctrl + Shift + P), type `Package Control : Install Package`, and press Enter.
- Search for SublimeAStyleFormatter and press Enter to install it.

### **Step 5: Configure the Plugin**
- Go to `Preferences` > `Package Settings` > `SublimeAStyleFormatter` > `Settings - User`.
- Paste the following code to enable automatic formatting on file save:
```
{
    "autoformat_on_save": true
}
```

### **Step 6: Build and Run**
- Open your C++ file in Sublime Text.
- Press the keybinding (`Ctrl + Shift + b` in my case) to build and run your code.
- The input is taken from the `input.txt` file and output is redirected to `output.txt` file.
- Your code will also be automatically formatted using the AStyle plugin.


### **Step 7: CP Template as a Snippet**
- The most recently cp template is saved in the `cp.cpp` file in the `Snippets` folder. Use the code in this to create a snippet in sublime text.
- Go to `Tools` > `Developer` > `New Snippet`.  
- For saving the content, go to https://snippet-generator.app/?description=&tabtrigger=&snippet=&mode=vscode and select `Sublime-Text` as an option. Copy past


By following these steps, your environment will be set up for efficient competitive programming with automatic code formatting and streamlined build and run commands in Sublime Text.