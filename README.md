# Bazel + FTXUI Example

A minimal example project demonstrating how to build and run a simple terminal UI using [FTXUI](https://github.com/ArthurSonzogni/FTXUI) with [Bazel](https://bazel.build/).

## Overview

This repository shows how to:

- Use Bazel to configure and build a C++ project.
- Integrate the FTXUI library for text-based user interfaces.
- Run a basic “Hello, FTXUI!” example.

## Prerequisites

- **C++ compiler** (gcc ≥ 9 or clang ≥ 10)
- **Bazel** (≥ 6.0)

Make sure both are installed and available on your `PATH`.

## Getting Started

1. **Clone the repository**

   ```bash
   git clone https://github.com/ArthurSonzogni/ftxui-bazel.git
   cd ftxui-bazel
    ````

2. **Fetch dependencies**

   Bazel will automatically download FTXUI as an external dependency when you build.

3. **Run the example**

   ```bash
   bazel build hello_ftxui_dom
   ```

   ```bash
   bazel build hello_ftxui_component
   ```

## Resources

* FTXUI GitHub: [https://github.com/ArthurSonzogni/FTXUI](https://github.com/ArthurSonzogni/FTXUI)
* Bazel Docs: [https://docs.bazel.build/](https://docs.bazel.build/)

---

Feel free to open issues or submit pull requests if you have suggestions or improvements!
