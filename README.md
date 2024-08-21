# Latin - Cyrillic Converter

**Latin - Cyrillic Converter** is a powerful yet simple Qt-based application designed for anyone who frequently needs to switch between Latin and Cyrillic alphabets. Whether you're working on documents, translating text, or writing code that requires both scripts, this tool provides a seamless experience for text conversion.

![latin-cyrillic-converter-capture](https://github.com/user-attachments/assets/fd0b04f1-154b-4341-b17d-2787398374a3)

## Features

- **Bidirectional Text Conversion**:
    - Convert text from Latin to Cyrillic and vice versa with just a click of a button.
    - The application handles the conversion accurately, respecting the nuances of both alphabets.
  
- **Real-Time Conversion**:
    - Keep the application open while you work on other tasks, and instantly convert text as you need it.
    - The app is lightweight and stays out of your way until you need it.

- **File Handling**:
    - **Open .txt Files**: Load a `.txt` file into the application to convert its content between Latin and Cyrillic scripts.
    - **Save Converted Files**: Export the converted text to a new `.txt` file, preserving the original content while generating the new script version.
    - Supports large files and handles them efficiently.

- **User-Friendly Interface**:
    - A clean and intuitive interface makes it easy to use even for those new to text conversion tools.
    - The application layout is simple, with clear buttons for converting, opening, and saving files.

## Building the Qt Application from Source

To build and run the **Latin - Cyrillic Converter** application from source, it would be best solution to open the application in [Qt Creator](https://www.qt.io/), then compile it to your liking. But if you want to do it manually, here are the steps you need to follow: 

1. **Clone the Repository:**
   - Ensure you have Git installed on your system.
   - Open your terminal or command prompt and navigate to the directory where you want to clone the repository.
   - Run the following command:
     ```
     git clone https://github.com/ali-begic/latin-cyrillic-converter
     ```
   - Navigate into the cloned directory:
     ```
     cd latin-cyrillic-converter
     ```

2. **Install Qt Dependencies:**
   - Ensure you have the necessary Qt libraries, compilers, and build tools installed. Refer to the official Qt documentation for platform-specific instructions:
     - [Qt Documentation for Windows](https://doc.qt.io/qt-6/windows-deployment.html)
     - [Qt Documentation for macOS](https://doc.qt.io/qt-6/macos-deployment.html)
     - [Qt Documentation for Linux](https://doc.qt.io/qt-6/linux-deployment.html)

3. **Configure and Build:**
   - Create a build directory and navigate into it:
     ```
     mkdir build
     cd build
     ```
   - Run `qmake` to generate the Makefile from the `.pro` file:
     ```
     qmake ../src/latinCyrillicConverter.pro
     ```
   - Compile the application:
      - On Windows with MSVC:
        ```
        nmake
        ```
      - On Windows with MinGW:
        ```
        mingw32-make
        ```
      - On macOS and Linux:
        ```
        make
        ```

4. **Run Your Application:**
   - After a successful build, the executable will be located in the build directory.
   - On Windows, you can find the executable in the release or debug directory depending on your build configuration.
   - Run the application:
     ```
     ./latinCyrillicConverter
     ```

Thank you for your interest in the **Latin - Cyrillic Converter** application!

## Using `windeployqt` for Windows Deployment

To deploy the **Latin - Cyrillic Converter** application on Windows, you can use the `windeployqt` tool. This tool automatically copies the necessary Qt runtime files (DLLs, plugins, etc.) to your application's deployment folder, making it easier to distribute the application.

### Steps to Use `windeployqt`:

1. **Build Your Application:**
   - Ensure that your application is fully built using the steps above.

2. **Open the Correct Command Prompt:**
   - Open the "Developer Command Prompt for VS 2022" or the "Qt MinGW" command prompt, depending on the compiler you used.

3. **Navigate to the Build Directory:**
   - Use the command prompt to navigate to the directory where your application’s executable is located:
     ```bash
     cd ../latin-cyrillic-converter/build/release
     ```

4. **Run `windeployqt`:**
   - Run the following command to deploy your application:
     ```bash
     windeployqt latinCyrillicConverter.exe
     ```

5. **Test the Deployed Application:**
   - After running `windeployqt`, test the application by running the executable in its deployment directory to ensure all dependencies are correctly deployed.

6. **Distribute the Application:**
   - You can now package the deployed files (including the executable and all copied DLLs and plugins) into a ZIP file, installer, or other distribution formats for distribution.

## Contributing

Contributions are welcome! If you find a bug, have a feature request, or want to improve the code, feel free to open an issue or submit a pull request.

## License

This project is licensed under the Apache-2.0 license - see the [LICENSE](LICENSE) file for details.

## Additional Notes

- Ensure that you have the correct version of Qt and associated build tools for your platform.
- If you encounter issues, check the Qt and compiler documentation or seek assistance on community forums.
- If the application still does not work properly, try running it as an administrator.

With **Latin - Cyrillic Converter**, you have a reliable tool that streamlines the process of converting text between two important scripts. Whether you’re writing, coding, or translating, this application simplifies the task and enhances your productivity.
