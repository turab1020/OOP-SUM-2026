# 📘 OOP C++ Codes — Complete Explanation & Dry Runs

> A comprehensive, organized reference for every code snippet from the OOP course.  
> Each code is explained with its **concept**, **dry run**, **expected output**, and **key takeaways**.

---

## 📑 Table of Contents

| # | Topic | Section |
|---|-------|---------|
| **Part 1** | **Jagged Arrays & Dynamic Memory** | [Jump](#part-1--jagged-arrays--dynamic-memory) |
| 1 | Jagged Array from 2D Array (Identifier Filtering) | [Code 1](#code-1-jagged-array-from-2d-char-array-with-identifier-filtering) |
| 2 | Jagged Array from Delimited String (Variant A) | [Code 2](#code-2-jagged-array-from-delimited-string--variant-a-passing-offset) |
| 3 | Jagged Array from Delimited String (Variant B) | [Code 3](#code-3-jagged-array-from-delimited-string--variant-b-relative-index) |
| 4 | Jagged Array from `#` Delimited String (Single-Pass) | [Code 4](#code-4-jagged-array-from--delimited-string--single-pass) |
| 5 | Same as Code 4 but with `{0}` init | [Code 5](#code-5-jagged-array-with-0-initialization-vs-manual-0) |
| **Part 2** | **Classes, Constructors, Deep Copy, Destructors** | [Jump](#part-2--classes-constructors-deep-copy-destructors) |
| 6 | Array of Object Pointers (Heap) | [Code 6](#code-6-dynamic-array-of-point-object-pointers) |
| 7 | Array of Objects with Initializer List `{x,y}` | [Code 7](#code-7-static-array-of-objects-with-brace-initializer-list) |
| 8 | Array of Objects — Implicit Single-Arg Constructor | [Code 8](#code-8-array-of-objects--implicit-single-arg-constructor-calls) |
| 9 | Array of Objects — Default Constructor | [Code 9](#code-9-array-of-objects--default-constructor-then-manual-assignment) |
| 10 | Dynamic Allocation in Loop + `delete` | [Code 10](#code-10-dynamic-allocation-inside-a-loop-with-delete) |
| 11 | Scope-Based Destruction (Single Block) | [Code 11](#code-11-scope-based-destruction--single-block) |
| 12 | Scope-Based Destruction (While Loop) | [Code 12](#code-12-scope-based-destruction--while-loop) |
| **Part 3** | **Copy Constructor Scenarios (Deep vs Shallow)** | [Jump](#part-3--copy-constructor-scenarios-deep-vs-shallow) |
| 13 | Deep Copy + Modify Copy's Pointer | [Code 13](#code-13-deep-copy-constructor--modifying-the-copys-pointer) |
| 14 | Deep Copy + `delete` Inside `print()` | [Code 14](#code-14-deep-copy--delete-inside-print-dangerous) |
| 15 | Shallow Copy + `delete` Inside `print()` (Crash!) | [Code 15](#code-15-shallow-copy--delete-inside-print-crash-scenario) |
| **Part 4** | **Classes, `this` Pointer, Encapsulation** | [Jump](#part-4--classes-this-pointer-encapsulation) |
| 16 | Ambiguous Constructors (Default vs Parameterized) | [Code 16](#code-16-ambiguous-constructor-calls) |
| 17–21 | Student Class Evolution (Simplest → `this` Pointer) | [Codes 17–21](#codes-17-21-student-class-evolution) |
| **Part 5** | **Member Initializer List & `const` Data Members** | [Jump](#part-5--member-initializer-list--const-data-members) |
| 22 | Initializer List — Basic | [Code 22](#code-22-member-initializer-list--basic) |
| 23 | Initializer List — with `const` Member | [Code 23](#code-23-initializer-list-with-const-data-member) |
| 24 | Initializer List — `const` with Name Shadowing | [Code 24](#code-24-initializer-list-with-const--name-shadowing) |
| **Part 6** | **Static Members & Static Functions** | [Jump](#part-6--static-members--static-functions) |
| 25 | Static Member Variable — Basic | [Code 25](#code-25-static-member-variable--basic-usage) |
| 26 | Static Function Restrictions (Compile Error) | [Code 26](#code-26-static-function-trying-to-access-non-static-compile-error) |
| 27 | Static `print()` Can't Access Non-Static (Compile Error) | [Code 27](#code-27-static-print-cant-access-non-static-members) |
| 28 | Static Variable + Constructor Counting | [Code 28](#code-28-static-variable-with-constructor-counting) |
| **Part 7** | **Method Chaining (`return *this`)** | [Jump](#part-7--method-chaining-return-this) |
| 29 | Setters — No Chaining (void) | [Code 29](#code-29-setters-returning-void--no-chaining) |
| 30 | Method Chaining — Return by Value (Copies!) | [Code 30](#code-30-method-chaining--return-by-value-creates-copies) |
| 31 | Method Chaining — Return by Reference ✅ | [Code 31](#code-31-method-chaining--return-by-reference-correct) |
| **Part 8** | **Operator Overloading** | [Jump](#part-8--operator-overloading) |
| 32 | `operator++` — `void` (Pre & Post) | [Code 32](#code-32-operator-void-pre-and-post) |
| 33 | Pre-Increment `Point&`, Post-Increment `void` | [Code 33](#code-33-pre-increment-returning-point-post-returning-void) |
| 34 | Post-Increment Returning Dangling Reference ⚠️ | [Code 34](#code-34-post-increment-returning-dangling-reference-%EF%B8%8F) |
| 35 | `operator==` — By Value | [Code 35](#code-35-operator-by-value) |
| 36 | `operator==` and `operator!=` — By Reference | [Code 36](#code-36-operator-and-operator-by-reference) |
| 37 | `operator+` — Member Function (`p1 + 10`) | [Code 37](#code-37-operator-as-member-function-p1--10) |
| 38 | `operator+` — Explicit Call `.operator+(10)` | [Code 38](#code-38-operator-explicit-call-syntax) |
| 39 | `operator+` — Non-Member + Friend (`10 + p1`) | [Code 39](#code-39-operator-non-member-friend-function-10--p1) |
| 40 | `operator+` — Friend (p1 + int) | [Code 40](#code-40-operator-friend-function-point--int) |
| 41 | `operator+` — Non-Member Calling Member | [Code 41](#code-41-operator-non-member-calling-member-operator) |
| 42 | `operator+` — Explicit Non-Member Call | [Code 42](#code-42-operator-explicit-non-member-call) |
| 43 | `operator+` — Point + Point (Static Temp Bug) | [Code 43](#code-43-operator-point--point-static-temp-bug) |
| 44 | `operator+` — Dangling Reference ⚠️ | [Code 44](#code-44-operator-point--point-dangling-reference-%EF%B8%8F) |
| 45 | `operator=` — `void` Return | [Code 45](#code-45-assignment-operator-void-return) |
| 46 | `operator=` — Deep Copy with Null Checks | [Code 46](#code-46-assignment-operator-deep-copy-with-null-pointer-checks) |
| 47 | `operator[]` — Subscript Overloading | [Code 47](#code-47-operator-subscript-overloading) |
| 48 | `MyArray` without `operator[]` | [Code 48](#code-48-myarray-without-operator-overloading) |
| 49 | `operator<<` — `void` Return | [Code 49](#code-49-operator-void-return) |
| 50 | `operator<<` and `operator>>` — Chaining | [Code 50](#code-50-operator-and-operator-with-chaining) |
| **Part 9** | **Returning Reference vs Pointer from Functions** | [Jump](#part-9--returning-reference-vs-pointer-from-functions) |
| 51 | Return `int&` (lvalue) | [Code 51](#code-51-function-returning-int-reference) |
| 52 | Return `int*` (pointer) | [Code 52](#code-52-function-returning-int-pointer) |
| **Part 10** | **Composition, Aggregation, Association, Dependency** | [Jump](#part-10--composition-aggregation-association-dependency) |
| 53 | Composition — Pass by Value (Copy Constructor Calls) | [Code 53](#code-53-composition--pass-by-value-triggers-copy-constructor) |
| 54 | Composition — Pass by Reference | [Code 54](#code-54-composition--pass-by-reference) |
| 55 | Composition — Member Init Order Matters | [Code 55](#code-55-composition--member-initialization-order) |
| 56 | Composition — Friend Class (Private Members) | [Code 56](#code-56-composition-with-friend-class) |
| 57 | Aggregation / Association — Pointer-Based | [Code 57](#code-57-aggregation--association-pointer-based) |
| 58 | Dependency — Temporary Usage | [Code 58](#code-58-dependency-relationship) |
| **Part 11** | **Inheritance** | [Jump](#part-11--inheritance) |
| 59 | Basic Inheritance — All Public | [Code 59](#code-59-basic-single-inheritance--all-public) |
| 60 | Inheritance — Private Member in Base (Error) | [Code 60](#code-60-inheritance--private-member-in-base-class-compile-error) |
| 61 | Inheritance — Protected Member in Base | [Code 61](#code-61-inheritance--protected-member-in-base-class) |
| 62 | Inheritance — Accessing Protected from Outside (Error) | [Code 62](#code-62-inheritance--accessing-protected-from-main-error) |
| 63 | Access Specifiers in Inheritance Chain | [Code 63](#code-63-access-specifiers-in-an-inheritance-chain) |
| 64 | Multiple Inheritance — Basic | [Code 64](#code-64-multiple-inheritance--default-constructors) |
| 65 | Multiple Inheritance — Parameterized + Order | [Code 65](#code-65-multiple-inheritance--parameterized-constructors--order) |
| 66 | Multiple Inheritance — Ambiguous `print()` (Error) | [Code 66](#code-66-multiple-inheritance--ambiguous-print-error) |
| 67 | Multiple Inheritance — Resolved `print()` | [Code 67](#code-67-multiple-inheritance--resolving-ambiguity-with-scope) |
| 68 | Multiple Inheritance — Child Overrides `print()` | [Code 68](#code-68-multiple-inheritance--child-overrides-print) |
| 69 | Inheritance vs Composition Comparison | [Code 69](#code-69-inheritance-vs-composition-comparison) |
| **Part 12** | **Copy Constructor in Inheritance Chains** | [Jump](#part-12--copy-constructor-in-inheritance-chains) |
| 70 | Copy Constructor — `A(obj.a)` in B's Copy | [Code 70](#code-70-copy-constructor-chain--passing-member-values) |
| 71 | Copy Constructor — Passing `obj` to Parent (Slicing) | [Code 71](#code-71-copy-constructor-chain--passing-object-slicing) |
| **Part 13** | **Upcasting (Object Slicing, Ref, Ptr)** | [Jump](#part-13--upcasting-object-slicing-ref-ptr) |
| 72 | Upcasting — Assignment, Reference, Pointer | [Code 72](#code-72-upcasting--slicing-reference-and-pointer) |
| **Part 14** | **Passing Variables & Arrays to Functions (Val / Ref / Ptr)** | [Jump](#part-14--passing-variables--arrays-to-functions-val--ref--ptr) |
| 73 | Single Variable — By Value | [Code 73](#code-73-single-variable--pass-by-value) |
| 74 | Single Variable — By Reference | [Code 74](#code-74-single-variable--pass-by-reference) |
| 75 | Single Variable — By Pointer | [Code 75](#code-75-single-variable--pass-by-pointer) |
| 76 | 1D Array — Standard Decay | [Code 76](#code-76-1d-array--standard-pointer-decay) |
| 77 | 1D Array — Via Double Pointer | [Code 77](#code-77-1d-array--via-double-pointer) |
| 78 | 2D Array — Standard Syntax | [Code 78](#code-78-2d-array--standard-fixed-column-syntax) |
| 79 | 2D Array — Via Triple Pointer | [Code 79](#code-79-2d-array--via-triple-pointer-fully-dynamic) |
| — | Side-by-Side Comparison Tables | [Comparison](#-master-comparison-tables) |

---

# Part 1 — Jagged Arrays & Dynamic Memory

## Code 1: Jagged Array from 2D Char Array with Identifier Filtering

```cpp
#include <iostream>
using namespace std;
char** createJagged(char arr[][20], int n, int& rows, char identifier)
{
    char** jg;
    rows = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == identifier)
            rows++;
    }
    jg = new char*[rows];
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == identifier)
        {
            int col = 0;
            for (int j = 1; arr[i][j] != '\0'; j++)
            {
                if (arr[i][j] != ' ')
                    col++;
            }
            jg[ind] = new char[col + 1];
            for (int j = 1, k = 0; arr[i][j] != '\0'; j++)
            {
                if (arr[i][j] != ' ')
                    jg[ind][k++] = arr[i][j];
            }
            jg[ind][col] = '\0';
            ind++;
        }
    }
    return jg;
}

int main()
{
    char arr[6][20] = {"Ahello how are you?","BI am fine","Awhats up","A??","BNothing","AFine Thanks"};
    int rows = 0;
    char** jag = createJagged(arr, 6, rows, 'A');
    for (int i = 0; i < rows; i++)
    {
        cout << jag[i] << endl;
    }
}
```

### 🧠 Concept Covered
- **Jagged arrays** (2D arrays with variable column sizes)
- **Dynamic memory allocation** (`new`)
- **Pass by reference** (`int& rows`) — caller gets updated `rows` count
- **Filtering** rows based on a first-character identifier

### 🔍 Dry Run

**Input:** The 2D array has 6 strings. We filter for `'A'`:
| Index | String | Starts with 'A'? |
|-------|--------|:-:|
| 0 | `"Ahello how are you?"` | ✅ |
| 1 | `"BI am fine"` | ❌ |
| 2 | `"Awhats up"` | ✅ |
| 3 | `"A??"` | ✅ |
| 4 | `"BNothing"` | ❌ |
| 5 | `"AFine Thanks"` | ✅ |

**Pass 1:** Count rows → `rows = 4`. Allocate `jg = new char*[4]`.

**Pass 2:** For each matching row, skip index `0` (the identifier) and skip spaces:
- `"Ahello how are you?"` → skip `A`, skip spaces → `"hellhowareyou?"`  (14 chars)
- `"Awhats up"` → skip `A`, skip spaces → `"whatsup"` (7 chars)
- `"A??"` → skip `A`, skip spaces → `"??"` (2 chars)
- `"AFine Thanks"` → skip `A`, skip spaces → `"FineThanks"` (10 chars)

### ✅ Expected Output
```
hellhowareyou?
whatsup
??
FineThanks
```

### 💡 Key Takeaways
- `rows` is passed **by reference** so the caller (`main`) knows how many rows were created.
- The first character (`arr[i][0]`) acts as an identifier/tag; it's excluded from the copied data.
- Spaces are stripped from the result.
- Each row of the jagged array has exactly the right amount of memory allocated.

---

## Code 2: Jagged Array from Delimited String — Variant A (Passing Offset)

```cpp
#include <iostream>
using namespace std;
int returnSizeandIndex(char arr[], int i, int& index);
char** createJaggedArray(char arr[], int& nrows)
{
    char** jg;
    nrows = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == '#') nrows++;
    }
    jg = new char*[nrows];
    int col = 0, ind = 0, k = 0;
    int nextindex = 0;
    for (int i = 0; arr[i] != '\0'; i = k)
    {
        int col = 0;
        col = returnSizeandIndex(&arr[i], i, nextindex);
        jg[ind] = new char[col + 1];
        for (int l = 0; l < col; l++)
        {
            jg[ind][l] = arr[k];
            k++;
        }
        jg[ind][col] = '\0';
        ind++;
        k = nextindex;
    }
    return jg;
}
int returnSizeandIndex(char arr[], int k, int& index)
{
    int s = 0;
    int i = 0;
    for (; arr[i] != ','; i++)
    {
        s++;
    }
    while (arr[i] != '#') { i++; }
    index = k + i + 1;
    return s;
}
int main()
{
    char arr[] = "Ahmad Ali,A,23#Fahad Khan,B,344#Faran,B,67#Adnan Shahid,A,67#";
    int nrows = 0;
    char** jag = createJaggedArray(arr, nrows);
    for (int i = 0; i < nrows; i++)
    {
        cout << jag[i] << endl;
    }
}
```

### 🧠 Concept Covered
- Parsing a **flat delimited string** into a jagged array
- Delimiters: `,` separates fields, `#` separates records
- **Passing `&arr[i]`** — pointer arithmetic to pass sub-array starting at index `i`
- `returnSizeandIndex` takes the **absolute offset** `i` (labeled `k`) so it can compute the global `nextindex`

### 🔍 Dry Run

**Input:** `"Ahmad Ali,A,23#Fahad Khan,B,344#Faran,B,67#Adnan Shahid,A,67#"`

- Count `#` → `nrows = 4`
- **Record 0:** From index 0. `returnSizeandIndex` scans `"Ahmad Ali,A,23#..."`. Counts until `,` → `s = 9` (`"Ahmad Ali"`). Then scans until `#` → `i = 14`. `index = 0 + 14 + 1 = 15`. Copy 9 chars → `"Ahmad Ali"`.
- **Record 1:** From index 15. Scans `"Fahad Khan,B,344#..."`. Until `,` → `s = 10`. Until `#` → `i = 16`. `index = 15 + 16 + 1 = 32`. Copy 10 chars → `"Fahad Khan"`.
- **Record 2:** From index 32. `"Faran,B,67#..."`. Until `,` → `s = 5`. Until `#` → `i = 10`. `index = 32 + 10 + 1 = 43`. Copy → `"Faran"`.
- **Record 3:** From index 43. `"Adnan Shahid,A,67#"`. Until `,` → `s = 12`. Until `#` → `i = 17`. `index = 43 + 17 + 1 = 61`. Copy → `"Adnan Shahid"`.

### ✅ Expected Output
```
Ahmad Ali
Fahad Khan
Faran
Adnan Shahid
```

### 💡 Key Takeaways
- The helper function receives both a **pointer to the sub-array** (`&arr[i]`) AND the **absolute offset** (`i`). This is because the helper works with local indices but needs to return a global `nextindex`.
- Only the **name** (text before the first `,`) is extracted for each record.

---

## Code 3: Jagged Array from Delimited String — Variant B (Relative Index)

This is identical to Code 2 except:

```cpp
int returnSizeandIndex(char arr[], int& index)
{
    // ...
    index = i + 1;  // relative to the passed sub-array, NOT absolute
    // ...
}
```

### 🧠 Key Difference
In Code 2, `index = k + i + 1` (absolute). In Code 3, `index = i + 1` (relative to `&arr[i]`).

### ⚠️ Bug
Since `createJaggedArray` does `k = nextindex`, and `nextindex` is now relative (e.g., `15` instead of `15`), the **first record works** but subsequent records will have `k` set to a **relative offset** instead of absolute, causing incorrect data extraction. The `i = k` at the loop top then uses this wrong value.

> **Note:** Actually on careful inspection, the original function call in variant B passes `&arr[i]` but does NOT pass `i`, so `index = i + 1` is relative to the start of the sub-array passed. But the calling code uses `k = nextindex` expecting an absolute index. This means `nextindex` will be wrong for records after the first one — it will be a small number instead of the real position.

### 💡 Key Takeaway
This code demonstrates a common **bug when mixing relative and absolute indexing** with pointer arithmetic. Compare carefully with Code 2 to understand why passing the offset matters.

---

## Code 4: Jagged Array from `#` Delimited String — Single-Pass

```cpp
char** createJaggedArray(char arr[], int& nrows)
{
    // ... count '#' for nrows ...
    int col = 0, ind = 0, k = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] != '#')
            col++;
        else
        {
            jg[ind] = new char[col + 1];
            for (int j = 0; j < col; j++)
            {
                jg[ind][j] = arr[k];
                k++;
            }
            jg[ind][col] = '\0';
            col = 0;
            ind++;
            if (arr[k] != '\0')
                k++;   // skip the '#'
        }
    }
    return jg;
}
```

**Input:** `"hello how are you?#I am fine#what up#nothing#good work#"`

### 🧠 Concept Covered
- **Single-pass parsing** using two indices: `i` (scanner) and `k` (copier)
- `i` counts characters until `#`, then `k` copies them
- Manual `'\0'` placement at end of each row

### 🔍 Dry Run

| Record | Text | `col` | Allocated |
|--------|------|:-----:|:---------:|
| 0 | `"hello how are you?"` | 18 | `char[19]` |
| 1 | `"I am fine"` | 9 | `char[10]` |
| 2 | `"what up"` | 7 | `char[8]` |
| 3 | `"nothing"` | 7 | `char[8]` |
| 4 | `"good work"` | 9 | `char[10]` |

### ✅ Expected Output
```
hello how are you?
I am fine
what up
nothing
good work
```

---

## Code 5: Jagged Array with `{0}` Initialization vs Manual `\0`

This code is **identical** to Code 4 except for one line:

```cpp
jg[ind] = new char[col + 1] {0};   // <-- value-initializes all bytes to 0
// jg[ind][col] = '\0';             // <-- this line is commented out
```

### 🧠 Concept Covered
- `new char[col + 1]{0}` → **value-initialization**: all bytes are set to `0` (which is `'\0'`)
- Since every byte is already `'\0'`, the explicit `jg[ind][col] = '\0'` is unnecessary
- Both approaches produce the **exact same output**

### 💡 Key Takeaway
`new Type[n]{0}` zero-initializes all elements. Without `{0}`, `new char[n]` leaves memory **uninitialized** (garbage values), so you must manually place `'\0'`.

---

# Part 2 — Classes, Constructors, Deep Copy, Destructors

## Code 6: Dynamic Array of Point Object Pointers

```cpp
class Point {
public:
    int *x;
    int y;
    Point(int x = 0, int y = 0)
    {
        cout << "const called " << x << " " << y << endl;
        (this->x) = new int;
        *(this->x) = x;
        this->y = y;
    }
    Point(Point& p) {
        cout << "my deep copy const" << endl;
        this->x = new int(*p.x);
        y = p.y;
    }
    void print()
    {
        cout << *x << " " << y << endl;
    }
    ~Point()
    {
        cout << "Deleting " << *x << " " << y << endl;
        delete x;
        x = nullptr;
    }
};
int main()
{
    Point** p = new Point*[5];
    for (int i = 0; i < 5; i++)
    {
        p[i] = new Point(i, i * 10);
    }
    for (int i = 0; i < 5; i++)
    {
        (*p[i]).print();
        p[i]->print();
    }
    for (int i = 0; i < 5; i++)
    {
        delete p[i];
    }
    delete[] p;
}
```

### 🧠 Concepts Covered
- **Array of pointers to objects** (`Point** p`)
- **Dynamic allocation** of both the pointer array and each object
- **`this` pointer** to resolve name conflicts
- **Deep copy constructor** (`new int(*p.x)` allocates new memory)
- **Destructor** cleans up dynamically allocated `x`
- Two ways to access members: `(*p[i]).print()` and `p[i]->print()` — both are identical

### 🔍 Dry Run

**Construction phase:**
```
const called 0 0
const called 1 10
const called 2 20
const called 3 30
const called 4 40
```

**Print phase** (each object prints twice — once via `(*)` and once via `->`):
```
0 0
0 0
1 10
1 10
2 20
2 20
3 30
3 30
4 40
4 40
```

**Destruction phase:**
```
Deleting 0 0
Deleting 1 10
Deleting 2 20
Deleting 3 30
Deleting 4 40
```

### 💡 Key Takeaways
- `Point** p = new Point*[5]` → allocates an array of 5 **pointers**, NOT 5 objects.
- Each `p[i] = new Point(...)` creates a single object on the heap.
- You must `delete p[i]` for each object, THEN `delete[] p` for the array.
- `(*ptr).member` ≡ `ptr->member`.

---

## Code 7: Static Array of Objects with Brace Initializer List

```cpp
Point(int x, int y = 0)   // Note: no default for x
// ...
int main()
{
    Point list[5]{ {1,10},{2,20},{3,30},{4,40},{5,50} };
    for (int i = 0; i < 5; i++)
    {
        list[i].print();
    }
}
```

### 🧠 Concept Covered
- **Static array of objects** (stack-allocated)
- **Brace-enclosed initializer list** `{ {1,10}, {2,20}, ... }`
- Each `{x, y}` pair calls the parameterized constructor

### 🔍 Dry Run
```
const called 1 10
const called 2 20
const called 3 30
const called 4 40
const called 5 50
1 10
2 20
3 30
4 40
5 50
Deleting 5 50    ← destructors called in REVERSE order (stack unwinding)
Deleting 4 40
Deleting 3 30
Deleting 2 20
Deleting 1 10
```

### 💡 Key Takeaway
Stack objects are destroyed in **reverse order** of construction (LIFO).

---

## Code 8: Array of Objects — Implicit Single-Arg Constructor Calls

```cpp
Point(int x, int y = 0)  // y has default value 0
// ...
int main()
{
    Point list[5]{ 1, 2, 3, 4, 5 };  // <-- flat list, no braces!
}
```

### 🧠 Concept Covered
- When each element has **only one value**, it calls `Point(int x, int y=0)` with `y` defaulting to `0`
- `{1, 2, 3, 4, 5}` → `Point(1,0)`, `Point(2,0)`, `Point(3,0)`, `Point(4,0)`, `Point(5,0)`

### ✅ Expected Output
```
const called 1 0
const called 2 0
const called 3 0
const called 4 0
const called 5 0
1 0
2 0
3 0
4 0
5 0
Deleting 5 0
Deleting 4 0
Deleting 3 0
Deleting 2 0
Deleting 1 0
```

### 💡 Key Takeaway
If the constructor has default parameters, a flat initializer list can invoke it with partial arguments.

---

## Code 9: Array of Objects — Default Constructor Then Manual Assignment

```cpp
Point(int x = 0, int y = 0)  // BOTH have defaults
// ...
int main()
{
    Point list[5];  // default constructor called 5 times
    for (int i = 0; i < 5; i++)
    {
        *(list[i].x) = i;      // modify the dynamically allocated int
        list[i].y = i * 10;
    }
    for (int i = 0; i < 5; i++)
    {
        list[i].print();
    }
}
```

### 🧠 Concept Covered
- **Default constructor** with default parameters allows `Point list[5]` without arguments
- Objects are first created with `x=0, y=0`, then modified manually

### ✅ Expected Output
```
const called 0 0
const called 0 0
const called 0 0
const called 0 0
const called 0 0
0 0
1 10
2 20
3 30
4 40
Deleting 4 40
Deleting 3 30
Deleting 2 20
Deleting 1 10
Deleting 0 0
```

### 💡 Key Takeaway
Without default parameter values, `Point list[5];` would fail to compile because there's no matching constructor for zero arguments.

---

## Code 10: Dynamic Allocation Inside a Loop with `delete`

```cpp
int main()
{
    Point p1(2, 3), p2(4, 5);
    int i = 1;
    while (i <= 3)
    {
        Point *p = new Point(i, i * 10);
        i++;
        delete p;  // destructor called immediately
        cout << "inside loop" << endl;
    }
    cout << "Outside loop" << endl;
}
```

### 🧠 Concept Covered
- **Dynamic allocation** inside a loop
- `new` creates on the heap → persists until `delete`
- `delete p` → calls destructor immediately, memory freed

### 🔍 Dry Run
```
const called 2 3         ← p1
const called 4 5         ← p2
const called 1 10        ← loop i=1
Deleting 1 10            ← delete p
inside loop
const called 2 20        ← loop i=2
Deleting 2 20
inside loop
const called 3 30        ← loop i=3
Deleting 3 30
inside loop
Outside loop
Deleting 4 5             ← p2 destructor (reverse order)
Deleting 2 3             ← p1 destructor
```

### 💡 Key Takeaway
`delete` on a heap object calls the destructor **immediately**. Stack objects (`p1`, `p2`) are destroyed when `main()` ends, in reverse order.

---

## Code 11: Scope-Based Destruction — Single Block

```cpp
int main()
{
    Point p1(2, 3), p2(4, 5);
    int i = 1;
    {
        Point p(i, i * 10);    // created inside a block
        i++;
        cout << "inside loop" << endl;
    }  // <-- p destroyed here (end of block)
    cout << "Outside loop" << endl;
}
```

### 🧠 Concept Covered
- **Block scope** `{ }` — stack objects created inside a block are destroyed when the block ends
- Not a loop — executes only once

### ✅ Expected Output
```
const called 2 3
const called 4 5
const called 1 10
inside loop
Deleting 1 10        ← block ends, p destroyed
Outside loop
Deleting 4 5         ← p2 destroyed
Deleting 2 3         ← p1 destroyed
```

---

## Code 12: Scope-Based Destruction — While Loop

```cpp
int main()
{
    Point p1(2, 3), p2(4, 5);
    int i = 1;
    while (i <= 3)
    {
        Point p(i, i * 10);   // stack object
        i++;
        cout << "inside loop" << endl;
    }  // p destroyed at end of EACH iteration
    cout << "Outside loop" << endl;
}
```

### 🧠 Concept Covered
- A stack object created inside a loop **is constructed and destroyed every iteration**

### ✅ Expected Output
```
const called 2 3
const called 4 5
const called 1 10
inside loop
Deleting 1 10          ← end of iteration 1
const called 2 20
inside loop
Deleting 2 20          ← end of iteration 2
const called 3 30
inside loop
Deleting 3 30          ← end of iteration 3
Outside loop
Deleting 4 5
Deleting 2 3
```

### 💡 Key Takeaway — Code 10 vs Code 12
| | Code 10 (Heap `new/delete`) | Code 12 (Stack in loop) |
|-|-|-|
| Allocation | Manual (`new`) | Automatic (stack) |
| Deallocation | Manual (`delete`) | Automatic (end of scope) |
| Same behavior? | **Yes** — destructor called every iteration | **Yes** — destructor called every iteration |
| Risk | Memory leak if you forget `delete` | None — automatic cleanup |

---

# Part 3 — Copy Constructor Scenarios (Deep vs Shallow)

## Code 13: Deep Copy Constructor — Modifying the Copy's Pointer

```cpp
int main()
{
    Point p(1, 1), p1(2, 3);
    Point p2 = p1;          // Copy constructor called
    *(p2.x) = 100;          // Modify p2's x
    p1.print();
    p2.print();
}
```

### 🧠 Concept Covered
- `Point p2 = p1;` → calls the **copy constructor** (NOT `operator=`)
- The deep copy constructor does `this->x = new int(*p.x)` → allocates **separate memory**
- Modifying `*(p2.x) = 100` does **NOT** affect `p1.x`

### 🔍 Dry Run
```
const called 1 1         ← p
const called 2 3         ← p1
my deep copy const       ← p2 = p1 → copy constructor
2 3                      ← p1.print() → still 2, unchanged!
100 3                    ← p2.print() → modified to 100
Deleting 100 3           ← p2 destructor
Deleting 2 3             ← p1 destructor
Deleting 1 1             ← p destructor
```

### 💡 Key Takeaway
**Deep copy** = independent objects. Changing one doesn't affect the other.

---

## Code 14: Deep Copy + `delete` Inside `print()` (Dangerous!)

```cpp
void print()
{
    cout << *x << " " << y << endl;
    delete x;    // ⚠️ deletes x inside print!
}
// No destructor defined
```

```cpp
int main()
{
    Point p1(2, 3);
    Point p2 = p1;     // deep copy
    p1.print();         // prints 2 3, then deletes p1.x
    p2.print();         // prints 2 3, then deletes p2.x (separate memory)
}
```

### 🧠 Concept Covered
- Even with deep copy, if `print()` **deletes** the pointer, the object becomes invalid
- Works "by luck" here because p1 and p2 have **separate memory** (deep copy)
- No explicit destructor → compiler's default destructor runs (no double-free since `x` was already freed)

### ⚠️ Warning
This is **terrible design**. `print()` should never `delete` data members. If a destructor also existed with `delete x`, you'd get a **double-free crash**.

### ✅ Expected Output
```
const called 2 3
my deep copy const
2 3
2 3
```
(No crash because of deep copy — two separate allocations deleted independently)

---

## Code 15: Shallow Copy + `delete` Inside `print()` (CRASH Scenario!)

```cpp
Point(Point& p) {
    cout << "my copy const" << endl;
    this->x = p.x;       // ⚠️ SHALLOW COPY: both point to same memory!
    y = p.y;
}
void print()
{
    cout << *x << " " << y << endl;
    delete x;             // deletes the shared memory
}
```

```cpp
int main()
{
    Point p1(2, 3);
    Point p2 = p1;     // shallow copy: p2.x == p1.x (same address)
    p1.print();         // prints 2 3, deletes the shared memory
    p2.print();         // ⚠️ UNDEFINED BEHAVIOR: p2.x is dangling!
}
```

### 🧠 Concept Covered
- **Shallow copy**: `this->x = p.x` → both objects' `x` points to the **same** `int`
- When `p1.print()` deletes `x`, `p2.x` becomes a **dangling pointer**
- `p2.print()` tries to dereference freed memory → **crash or garbage**

### 🔍 Memory Diagram
```
After construction:
p1.x ──→ [2]  ← same memory
p2.x ──↗

After p1.print():
p1.x ──→ [FREED]
p2.x ──↗       ← dangling!
```

### ✅ Expected Output (Likely)
```
const called 2 3
my copy const
2 3
[CRASH / garbage value] 3
```

### 💡 Key Takeaway
**Shallow copy + manual memory management = disaster.** If any member is a pointer to dynamically allocated memory, you **must** implement a deep copy constructor.

---

# Part 4 — Classes, `this` Pointer, Encapsulation

## Code 16: Ambiguous Constructor Calls

```cpp
class Student {
    // ...
public:
    Student() {                    // default constructor
        cout << "object created const called" << endl;
        name = "xyz";
        rollno = 0;
    }
    Student(int rollno = 0) {     // parameterized with default
        cout << "object created para 1 const called" << endl;
        name = "xyz";
        this->rollno = rollno;
    }
    // ...
};
int main()
{
    Student s1, s2(4);  // ⚠️ s1 is AMBIGUOUS!
}
```

### 🧠 Concept Covered
- **Ambiguity between constructors**: `Student s1;` matches BOTH `Student()` AND `Student(int rollno=0)` (with default)
- The compiler can't decide which to call → **compile-time error**
- `Student s2(4);` is fine — only matches the parameterized constructor

### ⚠️ Compile Error
```
error: call of overloaded 'Student()' is ambiguous
```

### 💡 Key Takeaway
Don't have both a default constructor and a parameterized constructor whose all parameters have defaults — they'll conflict on zero-argument calls.

---

## Codes 17-21: Student Class Evolution

These codes show a progression from simple to complete class design:

### Code 17 (Simplest — No `this`, No Constructor)
```cpp
class Student {
    int rollno; string name; float cgpa;
public:
    void setData(int r, string n, float c) {
        rollno = r; name = n; cgpa = c;
    }
    void printData() {
        cout << name << rollno << cgpa << endl;
    }
};
```
**Concept:** Basic class with private data, public setter/getter. No name conflict so `this` not needed.

### Code 18 (Adding `this` pointer)
```cpp
void setData(int rollno, string n, float cgpa) {
    cout << "this " << this << endl;        // prints object address
    (*this).rollno = rollno;                // explicit this
    name = n;
    this->cgpa = cgpa;                      // arrow notation
}
```
**Concept:** When parameter names **shadow** member names, `this->` or `(*this).` is needed to access the data member.

### Code 19 (Separated declaration and definition)
```cpp
void Student::setData(int rollno, string n, float cgpa)  // defined outside class
```
**Concept:** Member functions can be **declared** inside the class and **defined** outside using `ClassName::`.

### Code 20 (Adding Default Constructor)
```cpp
Student() {
    cout << "object created const called" << endl;
    name = "xyz"; rollno = 0;
}
```
**Concept:** Default constructor initializes members to safe defaults when object is created without arguments.

### Code 21 (Adding Getters/Setters)
```cpp
void setRollNo(int rollno) { this->rollno = rollno; }  // mutator
int getRollNo() { return this->rollno; }                // accessor
float calculate(float marks) { return marks / 300 * 100; }  // private utility
```
**Concept:** **Encapsulation** — private data, public interface. `calculate()` is a **utility function** (private helper).

### ✅ Common Output for All Variants
```
Address s1 0x...
this 0x...          (same as s1's address)
83.3333
Ali123.88
Address s2 0x...
this 0x...          (same as s2's address)
83.3333
Ahmad133.98
```

### 💡 Key Takeaway
`this` is a pointer to the **current object**. It's implicitly passed to every non-static member function. Use `this->member` when local variable names shadow data member names.

---

# Part 5 — Member Initializer List & `const` Data Members

## Code 22: Member Initializer List — Basic

```cpp
class Point {
public:
    int x;
    int y;
    Point(int i, int j) : x(i), y(j) {  // initializer list
        // body empty
    }
    void print() { cout << x << " " << y << endl; }
};
int main()
{
    Point a(2, 3);
    a.print();
}
```

### ✅ Output
```
2 3
```

### 🧠 Concept
The **member initializer list** `: x(i), y(j)` initializes members **before** the constructor body executes. This is more efficient than assignment inside the body (especially for non-primitive types).

---

## Code 23: Initializer List with `const` Data Member

```cpp
class Point {
public:
    const int c;     // const member!
    int x, y;
    Point(int i, int j) : x(i), y(j), c(34) { }
};
```

### 🧠 Concept
- `const` data members **cannot be assigned** in the constructor body
- They **must** be initialized via the **initializer list**
- `c = 34;` in the body would cause a compile error

### ✅ Output
```
2 3 34
```

---

## Code 24: Initializer List with `const` + Name Shadowing

```cpp
Point(int x, int y) : x(x), y(y), c(34) { }
```

### 🧠 Concept
- In the initializer list, `x(x)` — the outer `x` refers to the **member**, the inner `x` refers to the **parameter**
- This is **valid** and commonly used (unlike in the body, where `x = x` would be a no-op)

### ✅ Output
```
2 3 34
```

---

# Part 6 — Static Members & Static Functions

## Code 25: Static Member Variable — Basic Usage

```cpp
class Point {
    int x, y;
public:
    static int count;
    Point(int x, int y) {
        this->x = x; this->y = y;
    }
    void print() { cout << x << " " << y << endl; }
    ~Point() { cout << "Destrutor of " << x << " " << y << endl; }
};
int Point::count = 0;  // definition outside class
int main()
{
    Point::count = 10;
    cout << Point::count << endl;
}
```

### ✅ Output
```
10
```

### 🧠 Concept
- `static int count` belongs to the **class**, not to any object
- Must be **defined** outside the class: `int Point::count = 0;`
- Can be accessed without any object: `Point::count`
- No objects created → no constructors/destructors called

---

## Code 26: Static Function Trying to Access Non-Static (Compile Error!)

```cpp
static void myStaticFun()
{
    cout << "Its static" << endl;
    cout << "count= " << count << endl;   // ✅ OK: count is static
    print();     // ❌ ERROR: can't call non-static function
    x = 45;      // ❌ ERROR: can't access non-static member
}
```

### 🧠 Concept
- Static functions have **no `this` pointer**
- They can only access **static members/functions**
- They cannot access instance members (`x`, `y`) or call non-static functions (`print()`)

### ⚠️ Compile Errors
```
error: cannot call member function 'void Point::print()' without object
error: invalid use of member 'Point::x' in static member function
```

---

## Code 27: Static `print()` Can't Access Non-Static Members

```cpp
static void print()
{
    cout << x << " " << y << endl;  // ❌ ERROR
}
```

Same concept as Code 26 — a static function cannot access `x` or `y`.

---

## Code 28: Static Variable with Constructor Counting

```cpp
static int count;
Point(int x, int y) {
    this->x = x; this->y = y;
    count++;  // increments shared counter
}
// ...
int Point::count = 0;
int main()
{
    Point::count = 10;
    cout << Point::count << endl;          // 10
    Point p1(1,1), p2(2,2), p3(3,3);      // count incremented 3 times
    cout << Point::count << endl;          // 13
    cout << p1.count << endl;              // 13 (same static)
    p3.count = 30;                         // modifies the shared count
    cout << p2.count << endl;              // 30 (everyone sees 30)
}
```

### ✅ Output
```
10
const called
const called
const called
13
Its static
count= 13
13
30
```

### 💡 Key Takeaway
All objects share the **same** `count`. Changing it through `p3.count` is visible via `p2.count` and `Point::count`. Static members exist once per class, not per object.

---

# Part 7 — Method Chaining (`return *this`)

## Code 29: Setters Returning `void` — No Chaining

```cpp
void setX(int a) { this->x = a; }
void setY(int a) { y = a; }
// Usage:
p1.setX(2);
p1.setY(3);
p1.print();
```

### ✅ Output
```
const called
Calling setX
Calling setY
2 3
Destrutor of 2 3
```

No chaining possible: `p1.setX(2).setY(3)` would fail because `setX` returns `void`.

---

## Code 30: Method Chaining — Return by Value (Creates Copies!)

```cpp
Point setX(int a) {           // returns Point BY VALUE (copy!)
    this->x = a;
    return *this;             // returns a COPY of the object
}
Point setY(int a) {
    y = a;
    return *this;
}
// Usage:
p1.setX(2).setY(3).print();
p1.print();
```

### 🔍 Dry Run
1. `p1.setX(2)` → sets `p1.x = 2`, returns a **copy** of `p1` (let's call it `temp1` with `x=2, y=0`)
2. `temp1.setY(3)` → sets `temp1.y = 3`, returns another **copy** (`temp2` with `x=2, y=3`)
3. `temp2.print()` → prints `2 3`
4. `p1.print()` → prints `2 0` ← `p1.y` was never changed! Only copies were modified.

### ✅ Output
```
const called
0x7fff...
Calling setX 0x7fff...    (this = &p1)
Calling setY 0x7fff...    (this = &temp1, different address!)
0x7fff... 2 3             (temp2.print)
0x7fff... 2 0             (p1.print — y still 0!)
```

### ⚠️ Problem
Returning by value creates **temporary copies**. `setY(3)` modifies the copy, not the original `p1`.

---

## Code 31: Method Chaining — Return by Reference (Correct ✅)

```cpp
Point& setX(int a) {          // returns Point BY REFERENCE
    this->x = a;
    return *this;              // returns the SAME object
}
Point& setY(int a) {
    y = a;
    return *this;
}
// Usage:
p1.setX(2).setY(3).print();
p1.print();
```

### 🔍 Dry Run
1. `p1.setX(2)` → sets `p1.x = 2`, returns **reference to `p1`**
2. (reference to `p1`).`setY(3)` → sets `p1.y = 3`, returns **reference to `p1`**
3. (reference to `p1`).`print()` → prints `2 3`
4. `p1.print()` → prints `2 3` ← same object, correctly modified!

### ✅ Output
```
const called
0x7fff5000
Calling setX 0x7fff5000   (this = &p1)
Calling setY 0x7fff5000   (this = &p1 — SAME address!)
0x7fff5000 2 3
0x7fff5000 2 3            (p1 correctly has x=2, y=3)
Destrutor of 2 3
```

### 💡 Key Takeaway
For **method chaining** to modify the original object, **return by reference** (`Point&`).

---

# Part 8 — Operator Overloading

## Code 32: `operator++` void (Pre and Post)

```cpp
void operator++()        // pre-increment
{
    this->x++;
    y++;
}
void operator++(int)     // post-increment (dummy int parameter)
{
    this->x++;
    y++;
}
// Usage:
++p1;       // calls operator++()
p1.print();
p1++;       // calls operator++(int)
p1.print();
```

### 🧠 Concept
- Pre-increment: `operator++()` (no parameter)
- Post-increment: `operator++(int)` (dummy `int` parameter to differentiate)
- Both return `void` here — can't do `p2 = ++p1`

### ✅ Output
```
const called
pre
 2 2
post
 3 3
Destrutor of 3 3
```

---

## Code 33: Pre-Increment Returning `Point&`, Post Returning `void`

```cpp
Point& operator++()      // pre: returns reference
{
    this->x++; y++;
    return *this;
}
void operator++(int)     // post: returns void
{
    this->x++; y++;
}
// Usage:
Point p2 = ++p1;         // pre → returns p1 by reference, copy-constructs p2
```

### 🔍 Dry Run
```
const called          ← p1(1,1)
pre                   ← ++p1 → p1 becomes (2,2)
                      ← Point p2 = (result of ++p1) → copy constructor? 
                         Actually since it returns a reference, p2 is initialized from p1
 2 2                  ← p1.print()
 2 2                  ← p2.print() (copy of p1 after increment)
```

### 💡 Key Takeaway
Pre-increment returns `*this` by reference — allows chaining and assignment. `Point p2 = ++p1` first increments `p1`, then copy-constructs `p2` from the result.

---

## Code 34: Post-Increment Returning Dangling Reference ⚠️

```cpp
Point& operator++(int)   // ⚠️ returns REFERENCE to local!
{
    Point temp(*this);     // save current state
    this->x++; y++;        // increment this
    return temp;           // ⚠️ temp is LOCAL — destroyed after function returns!
}
```

### ⚠️ Problem
`temp` is a **stack variable** inside `operator++`. Returning a **reference** to it means the caller gets a reference to **destroyed memory**. This is **undefined behavior**.

### 💡 Correct Post-Increment Pattern
```cpp
Point operator++(int) {        // return by VALUE, not reference
    Point temp(*this);
    this->x++; y++;
    return temp;               // return copy of old state
}
```

---

## Code 35: `operator==` by Value

```cpp
bool operator==(Point p2)   // p2 passed BY VALUE → copy constructor called!
{
    return this->x == p2.x && this->y == p2.y;
}
// Usage:
(p1 == p2) ? cout << "same" : cout << "not same";
```

### ✅ Output (p1(1,1), p2(2,2))
```
const called       ← p1
const called       ← p2
not same
Destrutor of 2 2   ← copy of p2 (parameter) destroyed
Destrutor of 2 2   ← p2 destroyed
Destrutor of 1 1   ← p1 destroyed
```

### 💡 Key Takeaway
Passing `Point p2` **by value** creates a copy. Prefer passing **by reference** (`const Point& p2`) to avoid unnecessary copies.

---

## Code 36: `operator==` and `operator!=` by Reference

```cpp
bool operator==(Point& p2)
{
    return this->x == p2.x && this->y == p2.y;
}
bool operator!=(Point& p2)
{
    return !(*this == p2);   // reuses operator==
}
```

### 🧠 Concept
- `operator!=` is implemented in terms of `operator==` — DRY principle
- `*this == p2` is equivalent to `this->operator==(p2)`
- Pass by reference → no copies made

### ✅ Output (p1(1,1), p2(1,1))
```
const called
const called
same
Destrutor of 1 1
Destrutor of 1 1
```

---

## Code 37: `operator+` as Member Function (`p1 + 10`)

```cpp
Point& operator+(int n)
{
    static Point temp(0, 0);   // static → persists across calls
    temp.x = this->x + n;
    temp.y = this->y + n;
    return temp;
}
// Usage:
Point p2 = p1 + 10;
```

### 🧠 Concept
- Member function `operator+` → left operand must be a `Point` object
- `static Point temp` avoids dangling reference problem (persists after function returns)
- `p1 + 10` → `p1.operator+(10)`

### ✅ Output
```
const called    ← p1(1,1)
const called    ← static temp(0,0) — created once
Calling + op
 11 11
```

---

## Code 38: `operator+` Explicit Call Syntax

```cpp
Point p2 = p1.operator+(10);   // explicit call — same as p1 + 10
```

Identical behavior to Code 37. Just shows that `p1 + 10` is syntactic sugar for `p1.operator+(10)`.

---

## Code 39: `operator+` Non-Member Friend Function (`10 + p1`)

```cpp
class Point {
    // ...
    friend Point& operator+(int n, Point& p1);  // friend declaration
};
Point& operator+(int n, Point& p1)  // non-member
{
    static Point temp(0, 0);
    temp.x = p1.x + n;    // can access private x because of friend
    temp.y = p1.y + n;
    return temp;
}
// Usage:
Point p2 = 10 + p1;
```

### 🧠 Concept
- `10 + p1` → left operand is `int`, not a `Point`, so member function won't work
- Must be a **non-member function**: `operator+(int, Point&)`
- Declared as **`friend`** to access private `x`, `y`

### ✅ Output
```
const called      ← p1(1,1)
const called      ← static temp(0,0)
Calling + op
 11 11
```

---

## Code 40: `operator+` Friend Function (`Point + int`)

```cpp
friend Point& operator+(Point& p1, int n);     // friend declaration
Point& operator+(Point& p1, int n) { ... }     // non-member definition
// Usage:
Point p2 = p1 + 10;
```

Same as Code 37's effect but implemented as a **non-member friend** instead of a member function.

---

## Code 41: `operator+` Non-Member Calling Member Operator

```cpp
Point& operator+(int n)          // member function
{
    static Point temp(0, 0);
    temp.x = this->x + n;
    temp.y = this->y + n;
    return temp;
}
// Non-member:
Point& operator+(int n, Point& p1)
{
    return p1 + n;    // calls p1.operator+(n)
}
// Usage:
Point p2 = 10 + p1;
```

### 🧠 Concept
The non-member `operator+(int, Point&)` delegates to the member `operator+(int)` — no `friend` needed since the non-member calls a public member function.

---

## Code 42: `operator+` Explicit Non-Member Call

```cpp
Point p2 = operator+(10, p1);   // explicit call of non-member operator
```

Same as `10 + p1` — just explicit syntax.

---

## Code 43: `operator+` Point + Point (Static Temp Bug)

```cpp
Point& operator+(const Point& p2)
{
    static Point temp(0, 0);       // ⚠️ single static temp
    temp.x = this->x + p2.x;
    temp.y = this->y + p2.y;
    return temp;
}
// Usage:
Point p1(1,1), p2(2,2), p4(3,3);
Point p3 = p1 + p2 + p4;
Point p5 = p1 + p2;
```

### 🔍 Dry Run — The Bug
1. `p1 + p2` → `temp = (3,3)`, returns reference to `temp`
2. `(temp) + p4` → `temp.x = temp.x + p4.x = 3+3 = 6`, `temp.y = 6`. Returns reference to `temp`
3. `p3 = temp` → `p3 = (6,6)` ✅
4. `p5 = p1 + p2` → `temp = (3,3)`, `p5 = (3,3)`

### ✅ Output
```
const called    ← p1
const called    ← p2
const called    ← p4
const called    ← temp (static, created once)
Calling + op    ← p1+p2
Calling + op    ← result+p4
 3 3            ← p5 = p1+p2 (latest temp value)
 6 6            ← p3 (captured before p5 overwrote temp... WAIT)
```

Actually: Since `p3` was assigned first but `p5 = p1+p2` overwrites `temp` to `(3,3)`, and `p3` is a **copy** of `temp` at the time of assignment... `p3` got `(6,6)`, then `p5` gets `(3,3)`. But if `p3` stored a reference, it would see `(3,3)`. Since `Point p3 = ...` invokes copy construction, `p3` has its own copy `(6,6)`.

### ⚠️ Warning
Using `static` local variables in operators is **fragile** and **not thread-safe**. Each call overwrites the same object.

---

## Code 44: `operator+` Point + Point (Dangling Reference ⚠️)

```cpp
Point& operator+(const Point& p2)
{
    Point temp(0, 0);           // LOCAL temp — destroyed at function end!
    temp.x = this->x + p2.x;
    temp.y = this->y + p2.y;
    return temp;                // ⚠️ dangling reference!
}
```

### ⚠️ UNDEFINED BEHAVIOR
`temp` is a local variable. Returning a reference to it is **always wrong**. The reference points to destroyed memory.

### 💡 Correct Pattern
```cpp
Point operator+(const Point& p2) const {   // return by VALUE
    return Point(this->x + p2.x, this->y + p2.y);
}
```

---

## Code 45: Assignment Operator — `void` Return

```cpp
void operator=(Point& p1)
{
    cout << "My = op" << endl;
    this->x = p1.x;
    this->y = p1.y;
}
// Usage:
Point p1(1,1), p2(2,2);
p2 = p1;
```

### 🧠 Concept
- `p2 = p1` → calls `p2.operator=(p1)` (NOT copy constructor — both already exist)
- **Copy constructor** is called when: `Point p2 = p1;` (initialization)
- **Assignment operator** is called when: `p2 = p1;` (both already constructed)
- Returns `void` → can't chain: `p3 = p2 = p1` would fail

### ✅ Output
```
const called    ← p1(1,1)
const called    ← p2(2,2)
My = op         ← p2 = p1
 1 1            ← p2.print()
Destrutor of 1 1
Destrutor of 1 1
```

---

## Code 46: Assignment Operator — Deep Copy with Null Pointer Checks

```cpp
Point& operator=(Point& p1)
{
    cout << "my == deep copy operator" << endl;
    if (this != &p1)   // self-assignment check
    {
        this->y = p1.y;
        if (this->x == nullptr && p1.x != nullptr)
        {
            this->x = new int(*(p1.x));     // allocate new
        }
        else if (this->x != nullptr && p1.x == nullptr)
        {
            delete this->x;                 // free existing
            this->x = nullptr;
        }
        else if (this->x != nullptr && p1.x != nullptr)
        {
            *(this->x) = *(p1.x);           // copy value
        }
    }
    return *this;
}
```

### 🧠 Concept — Deep Copy Assignment Operator
This is the **robust** version with:
1. **Self-assignment check** (`if (this != &p1)`) — prevents deleting your own data
2. **Null pointer handling** — 4 cases:
   - Both null → do nothing for `x`
   - `this` null, `p1` not null → allocate and copy
   - `this` not null, `p1` null → delete and nullify
   - Both not null → copy value (no allocation needed)
3. **Returns `*this` by reference** → enables chaining (`p3 = p2 = p1`)

---

## Code 47: `operator[]` Subscript Overloading

```cpp
class Myarray {
public:
    int* arr;
    int size;
    Myarray(int s) {
        size = s;
        arr = new int[size];
    }
    ~Myarray() { delete[] arr; }
    int& operator[](int index)     // returns REFERENCE
    {
        return (this->arr[index]);
    }
};
int main()
{
    Myarray obj(5);
    obj[0] = 4;        // uses operator[] as lvalue
    cout << obj[0];    // uses operator[] as rvalue
}
```

### 🧠 Concept
- `operator[]` returns `int&` (reference) → can be used on **both sides** of `=`
- `obj[0] = 4` → `operator[](0)` returns reference to `arr[0]`, assigns `4`
- `cout << obj[0]` → `operator[](0)` returns reference, value `4` is read

### ✅ Output
```
4
```

### 💡 Key Takeaway
Returning by **reference** from `operator[]` allows the subscript to work as an **lvalue** (left side of assignment).

---

## Code 48: MyArray without `operator[]` Overloading

```cpp
int main()
{
    Myarray obj(5);
    obj.arr[0] = 4;        // direct access to the internal array
    cout << obj.arr[0];
}
```

### 🧠 Concept
Without `operator[]`, you must access the internal array directly: `obj.arr[0]`. This **breaks encapsulation** — the user needs to know about the internal `arr` pointer.

---

## Code 49: `operator<<` — `void` Return

```cpp
friend void operator<<(ostream& o, Point& p);

void operator<<(ostream& o, Point& p)
{
    o << p.x << " " << p.y << endl;
}
// Usage:
cout << p1;    // works
cout << p1 << p2;  // ❌ ERROR: returns void, can't chain
```

### 🧠 Concept
- `cout << p1` → `operator<<(cout, p1)` → works
- `cout << p1 << p2` → `(operator<<(cout, p1)) << p2` → `void << p2` → **ERROR**

### 💡 Key Takeaway
To support chaining (`cout << p1 << p2`), `operator<<` must return `ostream&`.

---

## Code 50: `operator<<` and `operator>>` with Chaining

```cpp
friend ostream& operator<<(ostream& o, Point& p);
friend istream& operator>>(istream& i, Point& p);

ostream& operator<<(ostream& o, Point& p)
{
    o << p.x << " " << p.y << endl;
    return o;          // enables chaining
}
istream& operator>>(istream& i, Point& p)
{
    cout << "Enter x and y" << endl;
    i >> p.x >> p.y;
    return i;          // enables chaining
}
// Usage:
cin >> p1 >> p2;       // works — chained input
cout << p1 << p2;      // works — chained output
```

### 🧠 Concept
- Both operators are **non-member friends** (left operand is `ostream`/`istream`, not `Point`)
- Return `ostream&` / `istream&` to enable **chaining**
- Must be `friend` to access private `x`, `y`

---

# Part 9 — Returning Reference vs Pointer from Functions

## Code 51: Function Returning `int` Reference

```cpp
int global = 10;
int& fun()
{
    return global;     // returns reference to global
}
int main()
{
    fun() = 12;        // assigns 12 to global through reference
    cout << global << endl;
}
```

### ✅ Output
```
12
```

### 🧠 Concept
`fun()` returns a **reference** to `global`. So `fun() = 12` is like `global = 12`. The function call is an **lvalue**.

---

## Code 52: Function Returning `int` Pointer

```cpp
int global = 10;
int* fun()
{
    return &global;    // returns pointer to global
}
int main()
{
    *fun() = 12;       // dereference pointer, assign 12
    cout << global << endl;
}
```

### ✅ Output
```
12
```

### 🧠 Concept
Same effect as Code 51 but using a **pointer** instead of a reference. `*fun()` dereferences the returned pointer.

---

# Part 10 — Composition, Aggregation, Association, Dependency

## Code 53: Composition — Pass by Value (Triggers Copy Constructor)

```cpp
class Person {
public:
    Address add;
    Person(int c, string n, Address a) : add(a.house, a.area, a.city) {
        // Address 'a' is a copy (passed by value)!
    }
    void changeAddress(Address a) {
        add = a;   // another copy
    }
};
int main() {
    Address a1(23, "AIT", "Lahore");
    Address a2(45, "DHA", "ISB");
    Person p1(23425, "Ali", a1);    // a1 is COPIED into parameter 'a'
    p1.changeAddress(a2);           // a2 is COPIED
}
```

### 🧠 Concept
- **Composition**: `Person` **owns** `Address` (embedded as a member, not a pointer)
- Passing `Address a` **by value** → triggers the **copy constructor** for `Address`
- More copies = more overhead

### 🔍 Dry Run — Extra Copies
```
Creating addressHouse number = 23 Area =AIT city= Lahore     ← a1 created
Creating addressHouse number = 45 Area =DHA city= ISB         ← a2 created
Creating addressHouse number = 23 Area =AIT city= Lahore     ← copy of a1 (parameter)
Creating addressHouse number = 23 Area =AIT city= Lahore     ← Person's add member
Creating person Ali
DestroyingHouse number = 23 Area =AIT city= Lahore           ← parameter copy destroyed
...
```

### 💡 Key Takeaway
Pass objects **by reference** (`Address& a`) to avoid unnecessary copies.

---

## Code 54: Composition — Pass by Reference

```cpp
Person(int c, string n, Address& a, DOB& dob)
    : add(a.house, a.area, a.city), dob(dob.day, dob.mon, dob.year) { }
```

### 🧠 Concept
- `Address& a` → no copy of `a` when calling the constructor
- The **member** `add` is still constructed independently (composition = owns its own copy)
- Passing by reference is **more efficient** — avoids creating temporary copies

---

## Code 55: Composition — Member Initialization Order

```cpp
class Person {
    DOB dob;       // declared FIRST
    Address add;   // declared SECOND
    Person(...) : cnic(c), name(n), dob(dob.day,dob.mon,dob.year), add(a.house, a.area, a.city) { }
};
```

### 🧠 Concept
Members are initialized in the order they are **declared in the class**, NOT the order in the initializer list.

Since `DOB dob` is declared before `Address add`, `dob` is constructed first regardless of the initializer list order.

### ✅ Output Order
```
Creating DOB...       ← dob first (declared first)
Creating address...   ← add second (declared second)
Creating person Ali
```

### ⚠️ On destruction, the reverse order applies:
```
Destroying person Ali
Destroying address...   ← add destroyed first (reverse of construction)
Destroying DOB...       ← dob destroyed last
```

---

## Code 56: Composition with Friend Class

```cpp
class Address {
private:                          // everything is private!
    int house; string area; string city;
    Address(int h, string a, string c) : ... { }
    void print() { ... }
    ~Address() { ... }
    friend class Person;          // Person can access everything
};
class DOB {
private:
    int day, mon, year;
    // ...
    friend class Person;
};
class Person {
    DOB dob;
    Address add;
    Person(...) : add(h, ar, ci), dob(d, mo, yr) {
        // Can call private constructors because Person is a friend!
    }
};
```

### 🧠 Concept
- `Address` and `DOB` have **all private** members (even constructors!)
- `friend class Person` grants `Person` full access to private members
- Only `Person` can create `Address` and `DOB` objects — enforces that these types are **only used within Person**

---

## Code 57: Aggregation / Association (Pointer-Based)

```cpp
class Person {
    Address* add;                    // pointer — doesn't OWN the Address
    Person(int c, string n, Address* a) : add(a) {
        // just stores the pointer — no copy, no new allocation
    }
    void changeAddress(Address* a) {
        add = a;                     // just re-point
    }
    ~Person() {
        // does NOT delete add — Person doesn't own it
    }
};
int main() {
    Address a1(23, "AIT", "Lahore");
    Address a2(45, "DHA", "ISB");
    Person p1(23425, "Ali", &a1);   // p1 points to a1
    p1.changeAddress(&a2);          // now points to a2
}
// a1 and a2 continue to exist independently after p1 is destroyed
```

### 🧠 Concept — Composition vs Aggregation

| Aspect | Composition (Code 54) | Aggregation (Code 57) |
|--------|----------------------|----------------------|
| Member type | `Address add;` (object) | `Address* add;` (pointer) |
| Ownership | Person **owns** Address | Person **uses** Address |
| Lifetime | Address dies with Person | Address lives independently |
| Copying | Makes its own copy | Shares existing object |
| Destructor | May need to delete | Should NOT delete |

---

## Code 58: Dependency Relationship

```cpp
class Teacher {
public:
    int id;
    void PrintStudent(Student* s) {    // uses Student temporarily
        s->print();
    }
};
```

### 🧠 Concept
- **Dependency**: `Teacher` temporarily **uses** `Student` via a function parameter
- `Student` is NOT a member of `Teacher` — no ownership, no aggregation
- The weakest relationship type in UML

---

# Part 11 — Inheritance

## Code 59: Basic Single Inheritance — All Public

```cpp
class Student {
public:
    int rollno; string name;
    Student(int rollno, string name) : rollno(rollno), name(name) {
        cout << "Created student" << endl;
    }
    void print() { cout << rollno << " " << name << endl; }
    ~Student() { cout << "destroyed student" << endl; }
};

class Undergraduate : public Student {
public:
    int fypid; string fyptitle;
    Undergraduate(int fypid, string title)
        : fypid(fypid), fyptitle(title), Student(12, "Ali") {
        cout << "Created Undergraduate student" << endl;
    }
    void print() {
        Student::print();      // call parent's print
        cout << fypid << " " << fyptitle << endl;
    }
    ~Undergraduate() { cout << "destroyed Undergraduate" << endl; }
};

int main() {
    Student s1(12, "Ahmad");
    s1.print();
    Undergraduate s2(234, "Deep learning");
    s2.Student::print();       // explicitly call parent's print
    s2.print();                // calls Undergraduate's print
}
```

### 🔍 Dry Run
```
Created student            ← s1
12 Ahmad                   ← s1.print()
Created student            ← base part of s2 (Student(12,"Ali"))
Created Undergraduate student  ← s2's own constructor
12 Ali                     ← s2.Student::print()
12 Ali                     ← Student::print() called inside s2.print()
234 Deep learning          ← Undergraduate's own data
destroyed Undergraduate    ← s2's destructor (child first)
destroyed student          ← s2's base destructor (parent second)
destroyed student          ← s1's destructor
```

### 💡 Key Takeaways
- Base class constructor runs **before** derived constructor
- Destructors run in **reverse**: derived destructor first, then base
- `s2.Student::print()` explicitly calls the base version
- `s2.print()` calls the derived version (hides the base version)

---

## Code 60: Inheritance — Private Member in Base Class (Compile Error)

```cpp
class Student {
    int rollno;    // PRIVATE
    // ...
};
class Undergraduate : public Student {
    void print() {
        cout << rollno << ...;  // ❌ ERROR: rollno is private in Student
    }
};
```

### ⚠️ Compile Error
Private members are **never accessible** in derived classes, regardless of inheritance type.

---

## Code 61: Inheritance — Protected Member in Base Class

```cpp
class Student {
protected:
    int rollno;     // PROTECTED — accessible in derived, not in main
public:
    string name;
    // ...
};
class Undergraduate : public Student {
    void print() {
        cout << rollno << ...;  // ✅ OK — protected is accessible in child
    }
};
```

### 🧠 Concept
`protected` = accessible within the class AND its derived classes, but NOT from outside (`main`).

---

## Code 62: Inheritance — Accessing Protected from Main (Error)

```cpp
int main() {
    Undergraduate s2(234, "Deep learning");
    s2.rollno = 34;  // ❌ ERROR: rollno is protected — not accessible from main!
}
```

### ⚠️ Compile Error
Protected members can only be accessed within the class hierarchy, not from external code like `main()`.

---

## Code 63: Access Specifiers in an Inheritance Chain

```cpp
class A {
    int a;         // private
protected:
    int b;         // protected
public:
    int c;         // public
    void print() { cout << a << b << c; }
};

class B : private A {     // ⚠️ private inheritance
    int d;
protected:
    int e;
public:
    int f;
    void print() {
        A::print();                 // ✅ can call (it's public in A, now private in B)
        cout << a << b << c;        // ❌ a is private in A — NEVER accessible
                                    // ✅ b (was protected, now private in B)
                                    // ✅ c (was public, now private in B)
    }
};

class C : public B {
    void print() {
        cout << a << b << c;        // ❌ ALL three are PRIVATE in B (private inheritance)
        cout << d << e << f;        // ❌ d is private in B
                                    // ✅ e is protected in B
                                    // ✅ f is public in B
    }
};
```

### 🧠 Access Specifier Rules

| Base member access | `public` inheritance | `protected` inheritance | `private` inheritance |
|:--:|:--:|:--:|:--:|
| `public` | → `public` | → `protected` | → `private` |
| `protected` | → `protected` | → `protected` | → `private` |
| `private` | ❌ inaccessible | ❌ inaccessible | ❌ inaccessible |

With `class B : private A`, all of A's public and protected members become **private** in B. So class C (which inherits from B) cannot access any of A's original members.

---

## Code 64: Multiple Inheritance — Default Constructors

```cpp
class A { public: A() { cout << "A created"; } ~A() { cout << "A destroyed"; } };
class B { public: B() { cout << "B created"; } ~B() { cout << "B destroyed"; } };
class C : public B, public A {
    public: C() { cout << "C created"; } ~C() { cout << "C destroyed"; }
};
int main() { C obj; }
```

### 🔍 Dry Run
```
B created      ← B is listed FIRST in inheritance list
A created      ← A is listed SECOND
C created      ← C's own constructor
C destroyed    ← reverse order
A destroyed
B destroyed
```

### 💡 Key Takeaway
In multiple inheritance, base constructors are called in the order they appear in the **inheritance list** (`class C : public B, public A`), NOT the initializer list.

---

## Code 65: Multiple Inheritance — Parameterized Constructors + Order

```cpp
class C : public B, public A {
    int c;
    C(int a, int b, int c) : c(c), A(b), B(a) { }
    //                        ↑ init list order doesn't matter!
    // Construction order: B first, then A (inheritance list order)
};
int main() {
    C obj(1, 2, 3);   // B gets 1, A gets 2, c gets 3
}
```

### ✅ Output
```
B created      ← B(1) — first in inheritance list
A created      ← A(2) — second in inheritance list
C created
C destroyed
A destroyed
B destroyed
```

---

## Code 66: Multiple Inheritance — Ambiguous `print()` (Error!)

```cpp
class A { void print() { cout << "printing"; } };
class B { void print() { cout << "printing"; } };
class C : public B, public A { /* no print() */ };

int main() {
    C obj(1, 2, 3);
    obj.print();    // ❌ AMBIGUOUS: which print()? A's or B's?
}
```

### ⚠️ Compile Error
```
error: request for member 'print' is ambiguous
```

---

## Code 67: Multiple Inheritance — Resolving Ambiguity with Scope

```cpp
int main() {
    C obj(1, 2, 3);
    obj.A::print();    // ✅ explicitly calls A's print
    obj.B::print();    // ✅ explicitly calls B's print
}
```

### ✅ Output
```
B created
A created
C created
printing A
printing B
C destroyed
A destroyed
B destroyed
```

---

## Code 68: Multiple Inheritance — Child Overrides `print()`

```cpp
class C : public B, public A {
    void print() { cout << "printing" << endl; }   // C has its own print()
};
int main() {
    C obj(1, 2, 3);
    obj.print();    // ✅ calls C's print() — no ambiguity
}
```

### 🧠 Concept
When the derived class defines its own `print()`, it **hides** both parent versions. No ambiguity.

---

## Code 69: Inheritance vs Composition Comparison

**Code A — Inheritance:**
```cpp
class B : public A {
    int b;
    B(int a, int b) : A(a), b(b) { }
    void print() { cout << a << " " << b; }   // access 'a' directly
};
```

**Code B — Composition:**
```cpp
class B {
    A obj;           // has-a relationship
    int b;
    B(int a, int b) : obj(a), b(b) { }
    void print() { cout << obj.a << " " << b; }  // access through obj.a
};
```

Both produce the same output (`2 3`), but:

| Aspect | Inheritance | Composition |
|--------|-------------|-------------|
| Relationship | "is-a" | "has-a" |
| Access to A's members | Direct (`a`) | Through object (`obj.a`) |
| Coupling | Tight | Loose |
| Flexibility | Less flexible | More flexible |

---

# Part 12 — Copy Constructor in Inheritance Chains

## Code 70: Copy Constructor Chain — Passing Member Values

```cpp
class A {
    A(A& obj) : a(obj.a) { cout << "Copy const of A"; }
};
class B : public A {
    B(B& obj) : A(obj.a), b(obj.b) { cout << "Copy const of B"; }
    //           ↑ passes int value → calls A's PARAMETERIZED constructor!
};
class C : public B {
    C(C& obj) : B(obj), c(obj.c) { cout << "Copy const of C"; }
    //           ↑ passes B& → calls B's COPY constructor
};
```

### 🔍 Dry Run for `C objc2 = objc;`
```
para of A          ← A(obj.a) = A(5) → parameterized, not copy!
Copy const of B    ← ... wait, B's copy gets `obj` of type C&
```

Actually in `B(B& obj) : A(obj.a)` — `obj.a` is an `int`, so it calls `A(int a)` (parameterized constructor), NOT the copy constructor of A.

### ✅ Output
```
para of A       ← parameterized A(5) called from B's copy constructor
para of B       ... (this chain depends on exact call path)
```

### 💡 Key Takeaway
`A(obj.a)` passes an `int` → calls **parameterized** constructor. To call A's **copy** constructor, pass an `A` object: `A(obj)` (which works via object slicing).

---

## Code 71: Copy Constructor Chain — Passing Object (Slicing)

```cpp
class B : public A {
    B(B& obj) : A(obj), b(obj.b) { }
    //           ↑ passes B& to A(A&) → object SLICING! Calls A's copy constructor
};
class C : public B {
    C(C& obj) : B(obj), c(obj.c) { }
    //           ↑ passes C& to B(B&) → slicing again
};
```

### 🔍 Dry Run for `C objc2 = objc;` where `objc(5,6,7)`
```
Copy const of A    ← A(obj) — obj is sliced to A&, copies a=5
Copy const of B    ← B(obj) — copies b=6
Copy const of C    ← copies c=7
```

### ✅ Output
```
para of A
para of B
para of C          ← creating objc(5,6,7)
Copy const of A    ← copying: A part
Copy const of B    ← copying: B part  
Copy const of C    ← copying: C part
5 6 7              ← objc2 values correct!
```

### 💡 Key Takeaway
When passing a derived object to a base reference parameter (`A(obj)` where `obj` is `C&`), **object slicing** occurs — only the base part is "seen". This correctly invokes the base copy constructor.

---

# Part 13 — Upcasting (Object Slicing, Ref, Ptr)

## Code 72: Upcasting — Slicing, Reference, and Pointer

```cpp
class A { public: int a; void print() { cout << "Print of A"; } };
class B : public A { public: int b; void print() { cout << "Print of B"; } };
class C : public B { public: int c; void print() { cout << "Print of C"; } };

int main()
{
    A obja(2);
    B objb(3, 4);
    C objc(5, 6, 7);

    obja = objb;           // ① Object slicing: only A part copied
    cout << obja.a << endl;

    A& ref = objc;         // ② Reference to base: no slicing, but sees only A
    cout << ref.a << endl;
    ref.print();           // calls A::print() (static binding)

    A* ptr = &objb;        // ③ Pointer to base
    ptr->print();          // calls A::print() (static binding)
    cout << ptr->a << endl;
}
```

### 🔍 Dry Run
```
obja.a = 3          ← objb's a was 3, copied to obja (b=4 is sliced off)
ref.a = 5           ← objc's a was 5
Print of A          ← ref.print() — static binding, calls A's version
Print of A          ← ptr->print() — static binding, calls A's version
3                   ← ptr->a = objb.a = 3
```

### 🧠 Three Forms of Upcasting

| Method | What happens | Data loss? | Type? |
|--------|-------------|:----------:|-------|
| `obja = objb` | **Object slicing** — only base members copied | ✅ Yes | Actual A object |
| `A& ref = objc` | Reference to base part, no data loss in memory | ❌ No | Still C in memory |
| `A* ptr = &objb` | Pointer to base part, no data loss in memory | ❌ No | Still B in memory |

### ⚠️ Static Binding
Without `virtual`, `ref.print()` and `ptr->print()` call `A::print()` even though the actual object is `C`/`B`. This is **static (compile-time) binding**. To get **dynamic (runtime) binding**, use `virtual` functions (polymorphism).

---

# 📋 Master Summary — Concepts Covered

| Concept | Code(s) |
|---------|:-------:|
| Jagged Arrays / Dynamic 2D Arrays | 1–5 |
| Dynamic Memory (`new` / `delete`) | 1–6, 10 |
| Pass by Reference (`&`) | 1–5, 36, 54 |
| Pass by Value (copies) | 35, 53 |
| `this` pointer | 17–21 |
| Constructors (Default, Parameterized) | 7–9, 16 |
| Constructor Ambiguity | 16 |
| Member Initializer List | 22–24, 55 |
| `const` Data Members | 23–24 |
| Copy Constructor — Deep vs Shallow | 13–15 |
| Destructor Ordering (Stack LIFO) | 7, 10–12 |
| Scope-Based Destruction | 11–12 |
| Static Members & Functions | 25–28 |
| Method Chaining (`return *this`) | 29–31 |
| `operator++` (Pre/Post) | 32–34 |
| `operator==`, `operator!=` | 35–36 |
| `operator+` (Member, Friend, Non-Member) | 37–44 |
| `operator=` (Assignment) | 45–46 |
| `operator[]` (Subscript) | 47–48 |
| `operator<<`, `operator>>` (I/O) | 49–50 |
| Return by Reference vs Pointer | 51–52 |
| Composition | 53–56 |
| Aggregation / Association | 57 |
| Dependency | 58 |
| Friend Class / Function | 39–40, 49–50, 56 |
| Single Inheritance | 59–62 |
| Access Specifiers in Inheritance | 60–63 |
| Multiple Inheritance | 64–68 |
| Ambiguity in Multiple Inheritance | 66–68 |
| Copy Constructor in Inheritance | 70–71 |
| Upcasting & Object Slicing | 72 |
| Inheritance vs Composition | 69 |
| Dangling References ⚠️ | 34, 44 |
| Static Local Variables in Operators | 37, 43 |

| Passing by Value / Reference / Pointer | 73–75 |
| 1D Array via Pointer & Double Pointer | 76–77 |
| 2D Array via Standard & Triple Pointer | 78–79 |

---

# Part 14 — Passing Variables & Arrays to Functions (Val / Ref / Ptr)

This section covers one of the **most important foundational topics** in C++: how data is passed to functions and what can be modified in each scenario. We progress from a single `int` all the way to fully dynamic 2D arrays via triple pointers.

---

## 🎯 The Big Picture — Why Does This Matter?

When you call a function with an argument, C++ can pass it in **three fundamentally different ways**:

| Method | Syntax | What the function gets | Can it change the original? |
|--------|--------|----------------------|:-:|
| **By Value** | `void f(int x)` | A **copy** of the variable | ❌ No |
| **By Reference** | `void f(int& x)` | An **alias** (another name) for the variable | ✅ Yes |
| **By Pointer** | `void f(int* x)` | The **address** of the variable | ✅ Yes (via `*x`) |

This same principle **scales up** to arrays:
- A **1D array** is already a pointer (`int*`), so to modify *which array* a variable points to, you need a **double pointer** (`int**`)
- A **2D dynamic array** is a pointer-to-pointer (`int**`), so to modify it, you need a **triple pointer** (`int***`)

---

## 📐 Level 1: Single Variable (`int`, `char`, etc.)

### Code 73: Single Variable — Pass by Value

```cpp
#include <iostream>
using namespace std;

// Function receives 'x' BY VALUE:
// A COPY of whatever is passed is created inside a new stack frame.
// The original variable in the caller is completely unaffected.
void modify(int x)    // 'x' is a brand-new local variable, initialized with a COPY of 'a'
{
    x = 100;          // Only modifies the LOCAL copy 'x', not the original 'a' in main
    cout << "Inside function: x = " << x << endl;  // Prints 100 (the local copy)
}   // 'x' is destroyed here when the function returns — the copy is gone

int main()
{
    int a = 5;        // Declare 'a' on the stack, initialize to 5
    cout << "Before: a = " << a << endl;  // Prints 5

    modify(a);        // Pass 'a' BY VALUE: the VALUE 5 is copied into parameter 'x'
                      // 'a' itself is NEVER touched by modify()

    cout << "After:  a = " << a << endl;  // Still prints 5 — 'a' was never changed
}
```

#### 🔍 Dry Run & Memory Diagram

```
Before call:        During call:           After call:
┌──────────┐       ┌──────────┐           ┌──────────┐
│ a  = 5   │       │ a  = 5   │ (main)    │ a  = 5   │ ← UNCHANGED
└──────────┘       ├──────────┤           └──────────┘
                   │ x  = 5   │ (copy)
                   │ x  = 100 │ (modified)
                   └──────────┘ (destroyed)
```

#### ✅ Output
```
Before: a = 5
Inside function: x = 100
After:  a = 5
```

#### 💡 Key Point
`x` is a **completely independent copy**. Modifying `x` has **zero effect** on `a`.

---

### Code 74: Single Variable — Pass by Reference

```cpp
#include <iostream>
using namespace std;

// Function receives 'x' BY REFERENCE (int&):
// 'x' is NOT a new variable — it's an ALIAS (another name) for the caller's variable.
// No copy is made. Any change to 'x' IS a change to the original.
void modify(int& x)    // 'x' becomes another name for 'a' — same memory location
{
    x = 100;           // This directly modifies 'a' in main! They share the same address.
    cout << "Inside function: x = " << x << endl;  // Prints 100
}   // Nothing to destroy — 'x' was just an alias, not a separate variable

int main()
{
    int a = 5;         // Declare 'a' on the stack, initialize to 5
    cout << "Before: a = " << a << endl;  // Prints 5

    modify(a);         // Pass 'a' BY REFERENCE: no copy is made
                       // Inside modify(), 'x' IS 'a' — same memory address

    cout << "After:  a = " << a << endl;  // Prints 100 — 'a' was changed via 'x'
}
```

#### 🔍 Dry Run & Memory Diagram

```
Before call:        During call:           After call:
┌──────────┐       ┌──────────┐           ┌──────────┐
│ a  = 5   │       │ a  = 5   │           │ a  = 100 │ ← CHANGED!
└──────────┘       │ x ══════►│ (alias)   └──────────┘
                   │ a  = 100 │ (via x)
                   └──────────┘
```

#### ✅ Output
```
Before: a = 5
Inside function: x = 100
After:  a = 100
```

#### 💡 Key Point
`x` is **not a separate variable** — it's another name for `a`. Any change to `x` directly modifies `a`.

---

### Code 75: Single Variable — Pass by Pointer

```cpp
#include <iostream>
using namespace std;

// Function receives 'x' BY POINTER (int*):
// 'x' is a pointer variable that holds the ADDRESS of the original variable.
// The pointer itself is a copy, but it POINTS TO the original data.
void modify(int* x)    // 'x' stores the memory address of 'a' (e.g., 0x7fff1234)
{
    *x = 100;          // DEREFERENCE: go to the address stored in 'x', change the value there
                       // Since x holds &a, this writes 100 directly into 'a's memory
    cout << "Inside function: *x = " << *x << endl;  // *x reads 'a's value → prints 100
}   // The pointer 'x' is destroyed, but 'a' (which it pointed to) remains changed

int main()
{
    int a = 5;         // Declare 'a' on the stack, initialize to 5
    cout << "Before: a = " << a << endl;  // Prints 5

    modify(&a);        // '&a' = address-of operator → passes the ADDRESS of 'a'
                       // Inside modify(), x = &a, so *x accesses 'a' directly

    cout << "After:  a = " << a << endl;  // Prints 100 — 'a' was changed via *x
}
```

#### 🔍 Dry Run & Memory Diagram

```
Before call:        During call:              After call:
┌──────────┐       ┌──────────────┐          ┌──────────┐
│ a  = 5   │       │ x = &a ──────┼──→ a=5   │ a  = 100 │ ← CHANGED!
│ addr:100 │       │ *x = 100     │    a=100  └──────────┘
└──────────┘       └──────────────┘
```

#### ✅ Output
```
Before: a = 5
Inside function: *x = 100
After:  a = 100
```

#### 💡 Key Point
`x` is a pointer that **holds the address** of `a`. Using `*x = 100` modifies the value stored at that address, which is `a` itself.

---

### 🔄 Side-by-Side: Single Variable — All Three Methods

```cpp
// --- THREE FUNCTIONS, THREE PASSING METHODS ---

void byValue(int x)    { x = 100;  }   // 'x' is a COPY of the argument → original unchanged
void byRef(int& x)     { x = 100;  }   // 'x' IS the argument (alias) → original IS changed
void byPtr(int* x)     { *x = 100; }   // 'x' holds ADDRESS of argument → *x changes original

int main()
{
    int a = 5, b = 5, c = 5;  // Three separate variables, all start at 5

    byValue(a);    // Passes a COPY of 'a' (value 5). Function modifies copy. a stays 5.
    byRef(b);      // 'x' becomes an alias for 'b'. x=100 means b=100. b is now 100.
    byPtr(&c);     // Passes ADDRESS of 'c'. *x=100 writes 100 to c's address. c is now 100.

    cout << a << " " << b << " " << c << endl;
    // Output: 5 100 100
    // a=5 (untouched), b=100 (via ref), c=100 (via pointer)
}
```

| Aspect | By Value | By Reference | By Pointer |
|--------|:--------:|:------------:|:----------:|
| Syntax in declaration | `int x` | `int& x` | `int* x` |
| Syntax at call site | `f(a)` | `f(a)` | `f(&a)` |
| Gets a copy? | ✅ Yes | ❌ No | ❌ No |
| Can modify original? | ❌ No | ✅ Yes | ✅ Yes (via `*x`) |
| Can be `nullptr`? | N/A | ❌ No | ✅ Yes |
| Extra indirection? | None | None (compiler handles) | Manual (`*`) |
| Common use | Read-only, small types | Modify original, large objects | Dynamic memory, optional params |

---

### ⚠️ Critical Subtlety: Pointer Value vs Pointed-To Value

When you pass a **pointer by value**, you can change what the pointer **points to** (the data), but you **cannot** change the pointer itself from the caller's perspective:

```cpp
// SCENARIO 1: Pointer passed BY VALUE — can't change where the original pointer points
void cantRepoint(int* ptr)    // 'ptr' is a COPY of the pointer from main
{
    int local = 999;           // A local variable on the stack
    ptr = &local;              // Changes the LOCAL copy of the pointer to point to 'local'
    // BUT: the original pointer 'p' in main() is a DIFFERENT variable!
    // It still points to wherever it was pointing before this call.
    // ALSO: 'local' will be destroyed when this function returns,
    // so even the local ptr would be dangling.
}

// SCENARIO 2: Pointer passed BY REFERENCE — CAN change the original pointer
void canRepoint(int*& ptr)    // 'ptr' is a REFERENCE to the original pointer variable 'p'
{                             // int*& means: reference to a pointer-to-int
    ptr = new int(999);       // This changes 'p' in main() to point to new heap memory!
    // Since ptr IS p (alias), p now points to a new int containing 999.
}

// SCENARIO 3: Double pointer — CAN change the original pointer via one dereference
void canRepointViaDoublePtr(int** ptr)   // 'ptr' holds the ADDRESS of pointer 'p'
{                                        // int** means: pointer to a pointer-to-int
    *ptr = new int(999);     // *ptr = dereference once → gives us the original pointer 'p'
    // So *ptr = new int(999) means p = new int(999) — changes 'p' in main!
}

int main()
{
    int a = 5;                 // Stack variable, value 5
    int* p = &a;               // 'p' is a pointer that stores the address of 'a'

    cantRepoint(p);            // Passes a COPY of 'p'. Function can't change where 'p' points.
    cout << *p << endl;        // Still prints 5 — 'p' still points to 'a'

    canRepoint(p);             // Passes 'p' BY REFERENCE. Function changes 'p' itself.
    cout << *p << endl;        // Prints 999 — 'p' now points to new heap memory
    delete p;                  // Free the heap memory allocated by canRepoint

    p = &a;                    // Reset 'p' to point back to 'a'
    canRepointViaDoublePtr(&p); // Passes ADDRESS of 'p'. Function changes 'p' via *ptr.
    cout << *p << endl;        // Prints 999 — 'p' now points to new heap memory
    delete p;                  // Free the heap memory allocated by canRepointViaDoublePtr
}
```

#### 🧠 Rule of Thumb
> **To modify a variable of type `T` from inside a function, pass `T&` or `T*`.**
> - To modify an `int` → pass `int&` or `int*`
> - To modify an `int*` (pointer) → pass `int*&` or `int**`
> - To modify an `int**` (double pointer) → pass `int**&` or `int***`

---

## 📐 Level 2: 1D Array — Standard vs Double Pointer

### Code 76: 1D Array — Standard Pointer Decay

```cpp
#include <iostream>
using namespace std;

// Receives a pointer to the first element of the array (array "decays" to int*)
// Since arr holds the ADDRESS of the actual data, modifying arr[i] modifies the real data.
void modifyElements(int* arr, int size)  // 'arr' = copy of pointer to first element
{                                        // 'size' = copy of the array length
    for (int i = 0; i < size; i++)       // Loop through each index from 0 to size-1
        arr[i] = arr[i] * 10;            // arr[i] is *(arr + i): access element at offset i
                                         // ✅ This DOES modify the original array because
                                         //    arr holds the real memory address of the data
}

// This function TRIES to resize but FAILS — demonstrates the trap!
void tryToResizeBAD(int* arr, int size)  // 'arr' is a LOCAL COPY of the pointer
{
    arr = new int[10];   // ❌ Changes the LOCAL copy of the pointer to point to new memory
    // The original array pointer in main() is COMPLETELY UNAFFECTED!
    // The caller still has the old pointer. This new memory is now a MEMORY LEAK
    // because nobody has a reference to it after this function returns.
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};  // Stack array of 5 ints. 'arr' = address of first element.

    cout << "Before: ";                          // Label for output
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";  // Print each element
    cout << endl;                                // Newline after printing

    modifyElements(arr, 5);  // 'arr' decays to int* (pointer to arr[0])
                             // Function can modify arr[0]..arr[4] because it has their address

    cout << "After:  ";                          // Label for output
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";  // Print modified elements
    cout << endl;                                // Each element is now 10x the original
}
```

#### 🔍 Dry Run
```
Before: 1 2 3 4 5
After:  10 20 30 40 50
```

#### 🧠 Concept
- When you pass an array name (`arr`), it **decays** to a pointer to the first element (`int*`)
- You **CAN** modify the array's **elements** (because you have the address of the data)
- You **CANNOT** resize or re-point the array (because the pointer itself is passed by value)

#### Memory Diagram
```
main:                        function:
┌─────────────────────┐     ┌──────────────────┐
│ arr → [1][2][3][4][5]│     │ arr (copy of ptr)│
│ addr: 0x1000        │     │ = 0x1000 ────────┼──→ [1][2][3][4][5]
└─────────────────────┘     │                  │    [10][20][30]...
                            └──────────────────┘
```

---

### Code 77: 1D Array — Via Double Pointer

```cpp
#include <iostream>
using namespace std;

// Creates a new 1D array and makes the CALLER's pointer point to it.
// int** arr: 'arr' holds the ADDRESS of the caller's pointer variable (myArr).
//            *arr gives us the ACTUAL pointer variable in main.
// int& size: passed by reference so we can tell main how big the array is.
void createArray(int** arr, int& size)
{
    size = 5;                      // Set the size (caller sees this change via reference)
    *arr = new int[size];          // *arr = myArr in main. This allocates 5 ints on heap
                                   // and makes main's 'myArr' point to that new memory.

    for (int i = 0; i < size; i++) // Loop through each index 0 to 4
        (*arr)[i] = (i + 1) * 10;  // (*arr)[i] = myArr[i] in main
                                   // Sets values: 10, 20, 30, 40, 50
                                   // Parentheses needed: (*arr)[i] not *arr[i]
                                   // because *arr[i] would mean *(arr[i]) — wrong!
}

// Resizes the array: allocates new memory, copies old data, frees old, re-points.
// int** arr: again, holds the ADDRESS of main's pointer so we can re-point it.
// int& size: reference so we can update the caller's size variable.
// int newSize: the desired new size (passed by value — we only read it).
void resizeArray(int** arr, int& size, int newSize)
{
    int* temp = new int[newSize];           // Step 1: Allocate NEW array of newSize

    for (int i = 0; i < size && i < newSize; i++)  // Step 2: Copy old data to new array
        temp[i] = (*arr)[i];               // Copy element-by-element from old array
                                            // i < size: don't read past old array end
                                            // i < newSize: don't write past new array end

    delete[] (*arr);                        // Step 3: FREE old memory (avoid memory leak)
                                            // *arr is the old array pointer (myArr in main)

    *arr = temp;                            // Step 4: Re-point main's pointer to new array
                                            // After this, myArr in main points to 'temp'

    size = newSize;                         // Step 5: Update size (caller sees via reference)
}

int main()
{
    int* myArr = nullptr;   // Pointer to int, starts as null (no array yet)
    int size = 0;           // Current array size, starts at 0

    createArray(&myArr, size);  // &myArr = address of the pointer variable itself
                                // Inside createArray: *arr = myArr, so *arr = new int[5]
                                // makes myArr point to new heap memory
                                // size is updated to 5 via reference

    cout << "Created: ";                         // Label
    for (int i = 0; i < size; i++)               // Loop 0 to 4
        cout << myArr[i] << " ";                 // Print: 10 20 30 40 50
    cout << endl;

    resizeArray(&myArr, size, 8);  // Resize from 5 to 8 elements
                                   // Old data (10-50) copied, positions 5-7 are uninitialized

    cout << "Resized: ";                         // Label
    for (int i = 0; i < size; i++)               // Loop 0 to 7
        cout << myArr[i] << " ";                 // Print: 10 20 30 40 50 0 0 0
    cout << endl;                                // (positions 5-7 may be 0 or garbage)

    delete[] myArr;   // Free the final array. MUST do this to avoid memory leak.
                      // After resizeArray, myArr points to the 'temp' allocation.
}
```

#### 🔍 Dry Run
```
Created: 10 20 30 40 50
Resized: 10 20 30 40 50 0 0 0
```

#### 🧠 Concept
- `int** arr` = pointer to a pointer. `*arr` gives you the **original pointer** in `main`
- `*arr = new int[5]` → modifies `myArr` in `main` to point to new heap memory
- This is the **only way** a function can allocate/resize an array and have the caller see it

#### Memory Diagram
```
main:                          createArray:              After:
┌──────────────┐              ┌──────────────────┐     ┌──────────────┐
│ myArr = null │              │ arr = &myArr ─────┼──→  │ myArr ───────┼──→ [10][20][30][40][50]
└──────────────┘              │ *arr = new int[5]│     └──────────────┘     (heap memory)
                              └──────────────────┘
```

#### 💡 Alternative: Return the Pointer
```cpp
// Alternative approach: RETURN the pointer instead of using double pointer
int* createArray(int& size) {        // Returns int* — the pointer to the new array
    size = 5;                         // Set size via reference so caller knows
    int* arr = new int[size];         // Allocate on heap (local pointer, but heap persists)
    for (int i = 0; i < size; i++)    // Fill array with 10, 20, 30, 40, 50
        arr[i] = (i+1) * 10;
    return arr;  // Return the pointer — heap memory survives after function returns
                 // Unlike a local variable, heap memory isn't destroyed on return
}
// Usage: int* myArr = createArray(size);  // myArr receives the returned pointer
```
Both approaches work, but the double-pointer version is useful when the function needs to modify **multiple** pointer variables or when the return value is used for error codes.

---

### 🔄 Side-by-Side: 1D Array Passing Methods

| Aspect | `int* arr` (Standard) | `int** arr` (Double Pointer) | Return `int*` |
|--------|:---------------------:|:----------------------------:|:-------------:|
| Modify **elements**? | ✅ Yes (`arr[i] = ...`) | ✅ Yes (`(*arr)[i] = ...`) | ✅ Yes (after return) |
| Modify/resize **the array itself**? | ❌ No | ✅ Yes (`*arr = new ...`) | ✅ Yes (via return) |
| Syntax at call site | `f(arr)` | `f(&arr)` | `arr = f()` |
| Typical use | Read/modify elements | Create/resize from function | Create from function |

---

## 📐 Level 3: 2D Array — Standard vs Triple Pointer

### Code 78: 2D Array — Standard Fixed-Column Syntax

```cpp
#include <iostream>
using namespace std;

// Function to modify a 2D array with FIXED column size.
// int arr[][3]: the column count (3) MUST be specified at compile time.
//   - This is because the compiler needs to know column count to calculate
//     memory offsets: arr[i][j] = *(base + i*COLS + j)
//   - Without COLS, it can't do the address math
// int rows: how many rows the array has (passed separately since rows can vary)
void modify2D(int arr[][3], int rows)
{
    for (int i = 0; i < rows; i++)        // Outer loop: iterate through each row
        for (int j = 0; j < 3; j++)       // Inner loop: iterate through each column (0,1,2)
            arr[i][j] *= 10;              // Multiply each element by 10
                                          // ✅ This DOES modify the original array
                                          // because arr decays to int(*)[3] — a pointer
                                          // to the actual memory
}

int main()
{
    // Declare a 2x3 2D array on the stack.
    // Memory layout is CONTIGUOUS: [1][2][3][4][5][6] in one block
    int arr[2][3] = {{1,2,3}, {4,5,6}};  // Row 0: {1,2,3}, Row 1: {4,5,6}

    modify2D(arr, 2);  // 'arr' decays to pointer-to-first-row: int (*)[3]
                       // Passes 2 as the number of rows
                       // Function multiplies every element by 10

    // Print the modified array
    for (int i = 0; i < 2; i++) {         // Loop through 2 rows
        for (int j = 0; j < 3; j++)       // Loop through 3 columns per row
            cout << arr[i][j] << " ";     // Print each element followed by space
        cout << endl;                     // Newline after each row
    }
    // Output:
    // 10 20 30
    // 40 50 60
}
```

#### ✅ Output
```
10 20 30
40 50 60
```

#### 🧠 Concept
- `int arr[][3]` → the **number of columns must be specified** at compile time
- The array decays to a pointer to the first row: `int (*arr)[3]`
- You **CAN** modify elements, but **CANNOT** resize or change dimensions
- Columns are **fixed** — not flexible

---

### Code 79: 2D Array — Via Triple Pointer (Fully Dynamic)

```cpp
#include <iostream>
using namespace std;

// Creates a fully dynamic 2D array and makes the caller's pointer point to it.
// int*** arr: TRIPLE pointer. 'arr' holds the address of main's 'matrix' (which is int**).
//   - *arr  = matrix       (the double pointer in main)
//   - **arr = matrix[0]    (first row pointer)
//   - ***arr = matrix[0][0] (first element)
// int& rows, int& cols: passed by reference so caller knows dimensions after creation.
void create2D(int*** arr, int& rows, int& cols)
{
    rows = 3;                           // Set dimensions — caller sees via reference
    cols = 4;

    *arr = new int*[rows];              // *arr = matrix in main
                                        // Allocate an array of 3 int-pointers on the heap
                                        // Each pointer will point to one row

    for (int i = 0; i < rows; i++)      // Loop through each row (0, 1, 2)
    {
        (*arr)[i] = new int[cols];      // (*arr)[i] = matrix[i] in main
                                        // Allocate 4 ints for this row on the heap

        for (int j = 0; j < cols; j++)  // Loop through each column (0, 1, 2, 3)
            (*arr)[i][j] = (i * cols) + j + 1;
            // Fill with sequential values: row0=[1,2,3,4], row1=[5,6,7,8], row2=[9,10,11,12]
            // Formula: (row_index * num_cols) + col_index + 1
    }
}

// Adds one new row to an existing 2D dynamic array.
// int*** arr: triple pointer so we can re-point main's 'matrix' to a bigger array.
// int& rows: reference so we can increment the caller's row count.
// int cols: passed by value — we just read it, don't need to change it.
void addRow(int*** arr, int& rows, int cols)
{
    int** temp = new int*[rows + 1];    // Step 1: Allocate a NEW row-pointer array
                                        // with space for one MORE row than before

    for (int i = 0; i < rows; i++)      // Step 2: Copy existing row POINTERS (not data!)
        temp[i] = (*arr)[i];            // Each temp[i] points to the SAME row data
                                        // We're reusing the existing row allocations

    temp[rows] = new int[cols];         // Step 3: Allocate memory for the NEW row
                                        // temp[rows] = the last slot (new row)

    for (int j = 0; j < cols; j++)      // Step 4: Initialize new row elements to 0
        temp[rows][j] = 0;

    delete[] (*arr);                    // Step 5: FREE the OLD row-pointer array
                                        // Note: we only delete the pointer ARRAY,
                                        // not the row data (which temp still references)

    *arr = temp;                        // Step 6: Re-point main's 'matrix' to new array
                                        // After this, matrix in main = temp

    rows++;                             // Step 7: Increment row count (caller sees via ref)
}

// Prints the 2D array. Only needs int** (not int***) because it doesn't modify the pointer.
void print2D(int** arr, int rows, int cols)  // arr = copy of the pointer (read-only access)
{
    for (int i = 0; i < rows; i++) {         // Loop through each row
        for (int j = 0; j < cols; j++)       // Loop through each column in this row
            cout << arr[i][j] << "\t";       // Print element with tab separator
                                              // arr[i][j] = *(*(arr+i)+j)
        cout << endl;                        // Newline after each row
    }
}

// Frees all dynamically allocated memory for the 2D array.
// MUST free each row first, THEN the row-pointer array.
void free2D(int** arr, int rows)
{
    for (int i = 0; i < rows; i++)  // Step 1: Free each individual row
        delete[] arr[i];             // delete[] because each row was allocated with new int[cols]

    delete[] arr;                    // Step 2: Free the row-pointer array itself
                                     // delete[] because it was allocated with new int*[rows]
    // ORDER MATTERS: if you delete[] arr first, you lose access to arr[i] pointers!
}

int main()
{
    int** matrix = nullptr;   // Double pointer — will point to the row-pointer array
                              // Starts as null (no 2D array exists yet)
    int rows = 0, cols = 0;   // Dimensions — will be set by create2D via references

    create2D(&matrix, rows, cols);  // &matrix = address of the double pointer itself
                                    // Inside: *arr = matrix, so the function can make
                                    // 'matrix' point to newly allocated memory
                                    // After: matrix → int*[3] → each → int[4]

    cout << "Original (" << rows << "x" << cols << "):" << endl;
    print2D(matrix, rows, cols);    // Pass matrix (int**) by value — just reading

    addRow(&matrix, rows, cols);    // &matrix again — function may re-point 'matrix'
                                    // After: matrix → int*[4] (one more row)

    cout << "After addRow (" << rows << "x" << cols << "):" << endl;
    print2D(matrix, rows, cols);    // Now prints 4 rows × 4 cols

    free2D(matrix, rows);  // Clean up ALL heap memory (4 rows + the pointer array)
                           // Without this, we'd have a massive memory leak
}
```

#### 🔍 Dry Run
```
Original (3x4):
1    2    3    4
5    6    7    8
9    10   11   12
After addRow (4x4):
1    2    3    4
5    6    7    8
9    10   11   12
0    0    0    0
```

#### 🧠 Concept
- `int*** arr` → pointer to a `int**` → lets the function modify `matrix` in `main`
- `*arr = new int*[rows]` → allocates the row-pointer array, visible to caller
- `(*arr)[i] = new int[cols]` → allocates each row
- `addRow` can **resize** the 2D structure because it modifies the original `int**` pointer

#### Memory Diagram
```
main:                            create2D:
┌────────────────┐              ┌──────────────────┐
│ matrix = null  │              │ arr = &matrix ────┼──→ matrix
└────────────────┘              │ *arr = new int*[3]│
                                └──────────────────┘

After create2D:                  After addRow:
┌──────────────┐                 ┌──────────────┐
│ matrix ──────┼──→ int*[3]      │ matrix ──────┼──→ int*[4]     (new array!)
└──────────────┘    │ ──→ [1][2][3][4]            │ ──→ [1][2][3][4]
                    │ ──→ [5][6][7][8]            │ ──→ [5][6][7][8]
                    │ ──→ [9][10][11][12]         │ ──→ [9][10][11][12]
                                                  │ ──→ [0][0][0][0]  (new row!)
```

#### 💡 Why Triple Pointer?
Because `matrix` is of type `int**`. To modify `matrix` itself from a function, we need `int***` (a pointer to `int**`). The chain is:
- `int***` → dereference once → `int**` (the row-pointer array)
- `int**` → dereference once → `int*` (a single row)
- `int*` → dereference once → `int` (a single element)

---

### 🔄 Side-by-Side: 2D Array Passing Methods

| Aspect | `int arr[][N]` (Fixed) | `int** arr` (Dynamic) | `int*** arr` (Triple Ptr) |
|--------|:----------------------:|:---------------------:|:-------------------------:|
| Column size | Fixed at compile time | Flexible | Flexible |
| Modify **elements**? | ✅ Yes | ✅ Yes | ✅ Yes (via `(*arr)[i][j]`) |
| Modify/resize **structure**? | ❌ No | ❌ No (pointer is a copy) | ✅ Yes |
| Typical use | Simple stack arrays | Read/modify elements | Create/resize from function |
| Memory | Stack or contiguous | Heap (rows separate) | Heap (rows separate) |

---

## 📊 Master Comparison Tables

### Table A: The Pointer Level Ladder

| What you want to modify | What you need to pass | Why |
|:-:|:-:|:-:|
| `int` value | `int*` or `int&` | Need access to the variable's address |
| `int*` pointer | `int**` or `int*&` | Need access to the pointer's address |
| `int**` double pointer | `int***` or `int**&` | Need access to the double pointer's address |

> **Pattern: To modify a `T`, pass `T*` or `T&`. Always one level of indirection higher.**

---

### Table B: Everything at a Glance — Single Value

| | `void f(int x)` | `void f(int& x)` | `void f(int* x)` |
|:--|:-:|:-:|:-:|
| **Function receives** | Copy of value | Alias to original | Address of original |
| **Change value?** | ❌ Copy only | ✅ `x = 10` | ✅ `*x = 10` |
| **Can be null?** | No | No | Yes |
| **Call syntax** | `f(a)` | `f(a)` | `f(&a)` |
| **Performance** | Copy overhead | No copy | No copy |
| **Best for** | Small types, read-only | Modifying originals | Optional params, legacy C |

---

### Table C: Everything at a Glance — 1D Array

| | `void f(int* arr, int n)` | `void f(int** arr, int& n)` |
|:--|:-:|:-:|
| **Function receives** | Address of first element | Address of the pointer variable |
| **Change elements?** | ✅ `arr[i] = ...` | ✅ `(*arr)[i] = ...` |
| **Resize/reallocate?** | ❌ Can't | ✅ `*arr = new int[...]` |
| **Call syntax** | `f(arr, n)` | `f(&arr, n)` |
| **Best for** | Modify existing array | Create/resize arrays |

---

### Table D: Everything at a Glance — 2D Array

| | `void f(int arr[][N], int rows)` | `void f(int** arr, int r, int c)` | `void f(int*** arr, int& r, int& c)` |
|:--|:-:|:-:|:-:|
| **Columns** | Fixed at compile time | Dynamic | Dynamic |
| **Change elements?** | ✅ | ✅ | ✅ |
| **Resize?** | ❌ | ❌ | ✅ |
| **Memory** | Stack (contiguous) | Heap (separate rows) | Heap (separate rows) |
| **Call syntax** | `f(arr, rows)` | `f(arr, r, c)` | `f(&arr, r, c)` |
| **Best for** | Known-size arrays | Read/modify dynamic 2D | Create/resize 2D from function |

---

### 🧠 Common Exam Traps

> [!CAUTION]
> **Trap 1: "I passed a pointer, why didn't my array change?"**
> You can modify the **elements** through `int*`, but you cannot make the pointer itself point somewhere else. The pointer was passed by value!

> [!CAUTION]
> **Trap 2: "Why does `int arr[][3]` work but `int arr[][]` doesn't?"**
> The compiler needs the column count to calculate memory offsets: `arr[i][j]` = `*(arr + i*COLS + j)`. Without knowing `COLS`, it can't do the math.

> [!CAUTION]
> **Trap 3: "Is `int arr[]` the same as `int* arr` in a function parameter?"**
> **Yes!** In function parameters (and ONLY there), `int arr[]` decays to `int* arr`. They are identical. But as variable declarations, they are different (`int arr[5]` is a stack array, `int* arr` is a pointer).

> [!CAUTION]
> **Trap 4: "When is copy constructor called vs assignment operator?"**
> - `Point p2 = p1;` → **Copy constructor** (object being created for the first time)
> - `p2 = p1;` → **Assignment operator** (both objects already exist)
> This applies to passing objects by value to functions too — it triggers the copy constructor!

---

> **Document generated from CODES.txt — OOP Course @ FAST**
