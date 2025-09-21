# REPORT - Feature 2 : Multi-file Project using Make Utility

## 1) Explain the linking rule in this part's Makefile: `$(TARGET): $(OBJECTS)`.
This rule says: to make the final target (the executable), first ensure all the object files listed in `$(OBJECTS)` exist. Each object has its own rule (pattern rule) that compiles a corresponding `.c` into `.o`. After those object files are up-to-date, the link command is run to combine the `.o` files into the final executable. When linking directly against object files, each `.o` is provided on the link line (e.g., `gcc -o bin/client obj/a.o obj/b.o`).

**Difference vs linking against a library:** When linking against a library (static `.a` or shared `.so`), the linker uses the library archive as a collection of object files and pulls only the object code required to satisfy unresolved symbols. A library decouples the compilation of modules (you can archive many objects into `libfoo.a`) from final program linking; the Makefile typically depends on the library file (e.g., `lib/libfoo.a`) rather than listing many `.o` files. Rule forms differ: `$(TARGET): $(LIBS)` and link flags like `-L`/`-l` are used.

## 2) What is a git tag and why is it useful? Difference between simple tag and annotated tag.
A git tag marks a specific commit as important (e.g., release points). Tags are useful to identify versioned releases, checkout a particular version, and attach release metadata. 

- **Lightweight (simple) tag:** just a name pointing to a commit (like a branch that doesn’t move). No extra metadata.
- **Annotated tag:** stores metadata (tagger name, email, date) and a message, and is stored as a full object in Git. Annotated tags are recommended for public releases.

## 3) Purpose of creating a "Release" on GitHub & significance of attaching binaries
A GitHub Release packages a commit/tag with release notes and downloadable assets. It communicates an official release to users and provides easy access to compiled binaries or other artifacts. Attaching binaries (e.g., `bin/client`) lets users download and run the program immediately without building from source, which is crucial for non-developers, QA testers, or distribution.

