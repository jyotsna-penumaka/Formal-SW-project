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

6. Running queue with the bug:
```
cbmc queue_bug.c --function ubarray_harness --unwind 100 --bounds-check --pointer-check 
```

7. Running queue bug free:
```
cbmc queue_bug_free.c --function ubarray_harness --unwind 100 --bounds-check --pointer-check 
```

8. Running the code with the out of bounds bug:
```
cbmc cbmc_index_ob.c --function f --unwind 100 --bounds-check --pointer-check 
```

9. Running the bug free version of the out of bounds bug code:
```
cbmc cbmc_index_ob_bug_free.c --function f --unwind 100 --bounds-check --pointer-check 
```

10. Running the code with the memory leak:
```
cbmc cbmc_memory_leak.c --function f --unwind 100 --bounds-check --pointer-check --memory-leak-check 
```

11. Running memory leak bug free:
```
cbmc cbmc_memory_leak_fixed.c --function f --unwind 100 --bounds-check --pointer-check 
```

11. Running the malloc bug that cbmc couldnt detect:
```
cbmc cbmc_read_from_uninitialised.c --bounds-check --pointer-check 
```

## Clang-Tidy

1. Detecting Buffer Overflows caused by strcpy using Clang-Tidy:

```
clang-tidy cbmc_buffer_overflow.c -checks="clang-analyzer-*" -- -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

2. Using Clang-Tidy for detecting the use of a banned C function:
```
clang-tidy verify_gets.c -checks="clang-analyzer-*" 
```
