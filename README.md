# Formal-SW-project

## CBMC

1. Detecting Buffer Overflows caused by strcpy using CBMC:

```
cbmc cbmc_buffer_overflow.c --function string_to_buf --unwind 135 --bounds-check --pointer-check
```

2. To run the program after I fixed the bugs:
```
cbmc cbmc_buffer_overflow_bug_free.c --function string_to_buf --unwind 135 --bounds-check --pointer-check
```

3. Using CBMC for detecting the use of a banned C function:
```
cbmc verify_gets.c --unwind 135 --bounds-check --pointer-check
```

4. Checking the detection of the banned function after adding assertions:
```
cbmc verify_gets_bug_free.c --unwind 135 --bounds-check --pointer-check
```

5. Try running the following function with threads:
```
cbmc threads.c --unwind 2 --pointer-check --bounds-check
```

This will result in a `pointer handling for concurrency is unsound error` error for CBMC 5.11 and will verify and show there are errors for version 5.8

## Clang-Tidy

1. Detecting Buffer Overflows caused by strcpy using Clang-Tidy:

```
clang-tidy cbmc_buffer_overflow.c -checks="clang-analyzer-*" -- -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

2. Using Clang-Tidy for detecting the use of a banned C function:
```
clang-tidy verify_gets.c -checks="clang-analyzer-*" 
```