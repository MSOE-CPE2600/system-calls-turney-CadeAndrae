# system-calls

## Files and Descriptions

### 1. **`finfo.c`**
- **Description**: Displays the file information about a given file provided via the command line.
- **Compilation**: `gcc finfo.c -o finfo`
- **Usage**: `./finfo <file_path>`
  - Example: `./finfo /path/to/file`

---

### 2. **`info.c`**
- **Description**: Provides data about the system using maintenance.
- **Compilation**: `gcc info.c -o info`
- **Usage**: `./info`

---

### 3. **`pinfo.c`**
- **Description**: Takes a single command line parameter that is a process identifier and print out the process ID, process priority, and scheduling method.
- **Compilation**: `gcc pinfo.c -o pinfo`
- **Usage**: `./pinfo <PID>` or `./pinfo` (for the current process)

---

### 4. **`pmod.c`**
- **Description**: Modifies its own priority to reduce it by 10, sleeps for 1,837,272,638 nanoseconds, prints a goodbye message, and exits.
- **Compilation**: `gcc pmod.c -o pmod`
- **Usage**: `./pmod`

---

## How to Compile All Programs

To compile all the programs, use the following commands:

```bash
gcc finfo.c -o finfo
gcc info.c -o info
gcc pinfo.c -o pinfo
gcc pmod.c -o pmod
