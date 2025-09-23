## Q1) Explain the linking rule in this part's Makefile: $(TARGET): $(OBJECTS)  
**Answer:**  
- This rule says: to make the final target (the executable), first ensure all the object files listed in $(OBJECTS) exist.  
- Each object has its own rule (pattern rule) that compiles a corresponding .c into .o.  
- After those object files are up-to-date, the link command is run to combine the .o files into the final executable.  
- Example:  
  gcc -o bin/client obj/a.o obj/b.o  

Difference vs linking against a library:  
- When linking directly against object files, every .o is passed to the linker.  
- When linking against a library (.a or .so), the linker only pulls in the required object code from the archive to resolve unresolved symbols.  
- Libraries allow decoupling of module compilation from final linking.  
- In the Makefile, this looks like:  
  $(TARGET): $(LIBS)  
      gcc -o $(TARGET) -Llib -lmyutils  

---

## Q2) What is a git tag and why is it useful? Difference between simple tag and annotated tag.  
**Answer:**  
- A git tag marks a specific commit as important (e.g., release points).  
- Useful for identifying versioned releases, checking out a specific version, and attaching metadata for release management.  

Types of tags:  
1. Lightweight (simple) tag  
   - Just a name pointing to a commit.  
   - Similar to a branch that doesn’t move.  
   - No metadata (date, tagger, message).  

2. Annotated tag  
   - Stored as a full Git object.  
   - Contains metadata (tagger name, email, date, message, and optional GPG signature).  
   - Recommended for public releases.  

---

## Q3) Purpose of creating a "Release" on GitHub & significance of attaching binaries  
**Answer:**  
1. A GitHub Release packages a specific commit/tag with release notes and downloadable assets.  
2. It communicates an official version to users.  
3. It provides easy access to compiled binaries or artifacts.  
4. Attaching binaries allows users (especially non-developers or QA testers) to run the program without building from source.  

---

## Q4) What is Position-Independent Code (-fPIC)?  
**Answer:**  
- Position-Independent Code (PIC) means machine code that can run correctly regardless of where in memory it is loaded.  
- Shared libraries may be mapped into different processes at different addresses.  
- -fPIC ensures generated code uses relative addressing instead of absolute addresses.  
- 👉 Essential for .so files, because without PIC, a shared library would only work at one fixed memory address.  

---

## Q5) Explain the difference in file size between your static and dynamic clients  
**Answer:**  
1. Static client (client_static)  
   - Includes all functions from libmyutils.a inside the executable.  
   - Larger file size.  

2. Dynamic client (client_dynamic)  
   - Only contains references (symbols) to libmyutils.so.  
   - Actual code is loaded from the shared library at runtime.  
   - Smaller file size.  

👉 The difference exists because static linking copies code into the binary, while dynamic linking shares code at runtime.  

---

## Q6) What is LD_LIBRARY_PATH? Why was it necessary?  
**Answer:**  
- LD_LIBRARY_PATH is an environment variable that tells the dynamic loader (ld.so) where to search for shared libraries before system directories.  
- Example usage:  
  export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH  
  ./bin/client_dynamic  

- Necessary here because libmyutils.so is in the project’s ./lib/, not in system paths like /usr/lib.  
- This shows that the OS does not embed library paths into executables by default — instead, it is the dynamic loader’s responsibility to locate .so files at runtime.  
