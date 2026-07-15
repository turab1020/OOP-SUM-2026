# Practice Pack

This folder groups the OOP course examples into runnable practice files.

The original source material is covered by concept, not duplicated 1:1 file-by-file. Each file focuses on one behavior family and includes short dry-run notes in comments.

## Map

| Practice file | Covers original codes |
|---|---|
| `01_pointers_and_passing.cpp` | 73-79 |
| `02_jagged_arrays.cpp` | 1-5 |
| `03_copy_semantics.cpp` | 13-16, 45-46, 70-72 |
| `04_constructors_this_static.cpp` | 7-12, 16-28 |
| `12_deep_copy.cpp` | deep copy only |
| `13_shallow_copy.cpp` | shallow copy only |
| `14_jagged_array.cpp` | jagged array with fixed row lengths |
| `15_variable_size_jagged_array.cpp` | jagged array with variable row lengths |
| `16_2d_array.cpp` | 2D array basics |
| `05_method_chaining_and_increment.cpp` | 29-34 |
| `06_operator_arithmetic_equality.cpp` | 35-44 |
| `07_stream_subscript_and_return.cpp` | 47-52 |
| `08_composition_aggregation_dependency.cpp` | 53-58 |
| `09_inheritance_basics.cpp` | 59-63 |
| `10_multiple_inheritance.cpp` | 64-69 |

## What to look for

- `int` by value vs by reference vs by pointer.
- How a function can change a pointer variable itself with `int*&` or `int**`.
- When copy constructor runs versus assignment operator.
- How `this` solves name shadowing and helps chaining.
- Which scenarios modify the original object and which only modify a copy.
- Student class evolution, including the ambiguous constructor case and the `this` pointer sequence, is grouped in `04_constructors_this_static.cpp`.

## Notes

- The error-only variants from the source are shown as commented examples in the relevant files.
- The dangerous shallow-copy crash scenario is explained, but the practice files keep execution safe.
- `README` is the main comparison guide for dry runs and theory.
