# C Programming Notes

These notes use modern, portable C. The examples are written for C17, which is a widely supported version of the language. The original handout topics are all here; where its wording or code is outdated, this document says so plainly and gives the corrected version.

## Contents

1. [What C is](#1-what-c-is)
2. [Planning before coding](#2-planning-before-coding)
3. [A C program and its layout](#3-a-c-program-and-its-layout)
4. [Characters tokens keywords and names](#4-characters-tokens-keywords-and-names)
5. [Variables data types and input output](#5-variables-data-types-and-input-output)
6. [Operators and expressions](#6-operators-and-expressions)
7. [Selection with if else and switch](#7-selection-with-if-else-and-switch)
8. [Loops](#8-loops)
9. [Break and continue](#9-break-and-continue)
10. [Functions](#10-functions)
11. [Scope local global and parameter variables](#11-scope-local-global-and-parameter-variables)
12. [Arrays](#12-arrays)
13. [Handout corrections and modern notes](#13-handout-corrections-and-modern-notes)
14. [Practice checklist](#14-practice-checklist)

## 1 What C is

C is a compiled programming language. You write a source file such as `hello.c`; a compiler checks it and turns it into a program the computer can run.

C is widely used where performance, portability, and close control of memory or hardware matter: operating systems, embedded systems, compilers, network software, utilities, and performance-sensitive applications. It is not “low level” in the same way as assembly language, but it gives more direct control than many newer languages.

The important beginner idea is this:

```text
problem -> plan -> C source code -> compiler -> executable program -> output
```

## 2 Planning before coding

Before writing C, state the problem, identify the input and output, then make a short plan. This prevents a program from becoming a random collection of lines.

### Algorithm

An algorithm is a finite, precise sequence of steps for solving a problem. It should have an input, an output, and a stopping point.

Example: calculate an employee's pay.

```text
START
Read hours
Read rate
pay = hours * rate
Print pay
END
```

![Flowchart and pseudocode for calculating pay](assets/handout-figure-01.png)

### Pseudocode

Pseudocode is a plan written in clear, code-like English. It is not required to follow C syntax exactly. Its job is to make the logic clear before syntax becomes a distraction.

### Flowcharts

A flowchart is a visual plan. Common shapes are:

- Oval: start or end.
- Parallelogram: input or output.
- Rectangle: an action or calculation.
- Diamond: a decision with possible paths such as true and false.
- Arrow: direction of execution.

The handout also uses a square-area example to connect an algorithm, a flowchart, and a C program.

![Area of a square from algorithm to C program](assets/handout-figure-02.png)

### The three control structures

Every beginner program uses combinations of these three ideas:

1. **Sequence**: do one statement, then the next.
2. **Selection**: choose a path with `if` or `switch`.
3. **Repetition**: repeat work with a loop.

![Sequence structure](assets/handout-figure-05.png)

## 3 A C program and its layout

Here is a complete, small C program.

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, C!\n");
    return 0;
}
```

### Read it line by line

- `#include <stdio.h>` makes declarations from the standard input/output header available. `printf` is declared there.
- `int main(void)` defines the function where a normal C program begins. `int` says that it returns an integer; `void` says it takes no arguments.
- `{` and `}` mark the body of a function or a block.
- `printf("Hello, C!\n");` calls a library function. `\n` moves to the next line.
- `;` ends a statement.
- `return 0;` reports successful completion to the operating system.

### Preprocessor directives

Lines beginning with `#` are handled before ordinary C compilation. The most common directive is:

```c
#include <stdio.h>
```

Other useful examples are:

```c
#define DAYS_IN_WEEK 7
#include <math.h>
```

Preprocessor directives do **not** end with semicolons.

### Formatting

C is mostly free-format: spaces and line breaks usually do not change the meaning. Still, use consistent indentation. It makes bugs easier to see.

Good:

```c
if (score >= 50) {
    printf("Pass\n");
}
```

Harder to read:

```c
if(score>=50){printf("Pass\n");}
```

## 4 Characters tokens keywords and names

### Characters and tokens

A source file is made from characters. The compiler groups them into meaningful pieces called **tokens**. For beginner work, the main token categories are:

- Keywords: `int`, `if`, `while`, `return`.
- Identifiers: names you choose, such as `total` or `student_count`.
- Constants: fixed values such as `10`, `3.14`, and `'A'`.
- String literals: text in double quotes, such as `"Hello"`.
- Operators: symbols such as `+`, `==`, and `&&`.
- Punctuators: symbols such as `;`, `()`, `{}`, `[]`, and `,`.

### Keywords

Keywords have a fixed meaning in C and cannot be used as your own names. The handout's list of 32 keywords is historically accurate for an older C standard, but modern C has additional keywords. Learn the keywords as you meet them instead of trying to memorize a list first.

### Identifiers and variable names

An identifier names a variable, function, or other program item.

Valid names:

```c
int score;
int student_count;
double price2;
```

Invalid names:

```text
2score       starts with a digit
student name contains a space
total-cost   contains a minus sign
int          is a keyword
```

Rules:

- Start with a letter or `_`.
- After that, use letters, digits, or `_`.
- C is case-sensitive: `score`, `Score`, and `SCORE` are three different names.
- Prefer meaningful names such as `total_price`, not `x` or `a`, unless a short loop counter is genuinely clearer.

### Comments

Comments explain code for people. The compiler ignores them.

```c
// A single-line comment

/*
   A comment that can cover
   more than one line.
*/
```

## 5 Variables data types and input output

### Variables

A variable is a named place in memory that holds a value of a stated type.

```c
int age = 18;
double price = 49.95;
char grade = 'A';
```

`age`, `price`, and `grade` are variables. `18`, `49.95`, and `'A'` are values.

![A variable name, value, and memory location](assets/handout-figure-04.png)

### Basic types

| Type | Typical use | Example |
| --- | --- | --- |
| `char` | one character or a small integer | `char grade = 'A';` |
| `int` | whole numbers | `int count = 12;` |
| `float` | decimal numbers, usually less precision | `float temperature = 22.5f;` |
| `double` | decimal numbers, usually preferred in beginner programs | `double price = 49.95;` |
| `void` | no value or no parameters | `int main(void)` |

Other important forms include `short`, `long`, `long long`, `signed`, and `unsigned`. Their exact storage sizes depend on the computer, so do not assume that every `int` has the same number of bytes on every platform.

### Declaration and initialization

A declaration tells C a variable's type and name.

```c
int score;
```

Initialization gives it a starting value.

```c
int score = 0;
```

Initialize variables whenever practical. An ordinary local variable does **not** automatically contain zero; reading it before giving it a value is a bug.

### `printf` output

`printf` prints formatted output.

```c
int score = 85;
double average = 72.5;

printf("Score: %d\n", score);
printf("Average: %.1f\n", average);
```

Useful format specifiers:

| Value | `printf` | `scanf` |
| --- | --- | --- |
| `int` | `%d` | `%d` |
| `char` | `%c` | `%c` |
| `double` | `%f` | `%lf` |
| string stored in a character array | `%s` | `%s` |

`%.2f` means “print a floating-point value with two digits after the decimal point.”

### `scanf` input

`scanf` reads input. You normally pass the address of a variable by placing `&` before its name.

```c
int age;

printf("Enter your age: ");
if (scanf("%d", &age) != 1) {
    printf("That was not a valid whole number.\n");
    return 1;
}
```

Checking the result of `scanf` helps prevent bad input from being treated as a real value.

## 6 Operators and expressions

An operator combines, compares, or changes values. An expression is code that produces a value.

```c
int total = 8 + 2;       // expression: 8 + 2
int passed = total >= 10; // expression: total >= 10
```

![Operator examples from the handout](assets/handout-figure-03.png)

### Common operators

| Category | Operators | Meaning |
| --- | --- | --- |
| Arithmetic | `+ - * / %` | add, subtract, multiply, divide, remainder |
| Assignment | `= += -= *= /=` | store or update a value |
| Comparison | `< <= > >= == !=` | compare two values |
| Logical | `&& || !` | AND, OR, NOT |
| Increment and decrement | `++ --` | add or subtract one |

Examples:

```c
int remainder = 17 % 5;       // 2
int is_adult = age >= 18;     // 1 when true, 0 when false
total += 5;                   // same idea as total = total + 5;
```

### Assignment is not comparison

```c
score = 50;      // put 50 into score
score == 50;     // ask whether score equals 50
```

This difference is one of the most common beginner mistakes.

### Integer division

If both operands are integers, C discards the decimal part.

```c
int result = 5 / 2;          // result is 2
double exact = 5.0 / 2.0;    // exact is 2.5
```

Use parentheses when an expression could be misunderstood.

```c
double average = (double)sum / count;
```

## 7 Selection with if else and switch

A condition is true when it is nonzero and false when it is zero.

### `if` and `else`

```c
if (score >= 50) {
    printf("Pass\n");
} else {
    printf("Try again\n");
}
```

Use `else if` when there are several mutually exclusive choices.

```c
if (score >= 80) {
    printf("A\n");
} else if (score >= 70) {
    printf("B\n");
} else if (score >= 50) {
    printf("C\n");
} else {
    printf("Not yet passing\n");
}
```

The `examples/control_flow.c` program tests whether an entered number is even or odd.

### `switch`

Use `switch` when one expression is compared with several constant choices.

```c
switch (day) {
case 1:
    printf("Monday\n");
    break;
case 2:
    printf("Tuesday\n");
    break;
default:
    printf("Use a number from 1 to 2.\n");
    break;
}
```

Without `break`, C continues into the next `case`. That is called fall-through and should be deliberate.

## 8 Loops

A loop repeats a block while a condition allows it. Every loop needs a clear answer to this question: **what will eventually make it stop?**

### `while`

Use `while` when the condition should be checked before the first repetition.

```c
int number = 1;

while (number <= 5) {
    printf("%d ", number);
    ++number;
}
printf("\n");
```

![While loop flowchart](assets/handout-figure-06.png)

If the condition is false at the beginning, the body runs zero times.

### `do while`

Use `do ... while` when the body must run at least once. The semicolon after the condition is required.

```c
int number = 1;

do {
    printf("%d ", number);
    ++number;
} while (number <= 5);
printf("\n");
```

![Do while loop flowchart](assets/handout-figure-07.png)

### `for`

Use `for` when initialization, condition, and update belong naturally together.

```c
for (int number = 1; number <= 10; ++number) {
    printf("%d ", number);
}
printf("\n");
```

Read the header as:

```text
start; continue while this is true; update after each pass
```

![For loop flowchart](assets/handout-figure-08.png)

## 9 Break and continue

### `break`

`break` immediately leaves the nearest loop or `switch`.

```c
for (int number = 1; number <= 10; ++number) {
    if (number == 6) {
        break;
    }
    printf("%d ", number);
}
```

This prints `1 2 3 4 5` and then stops the loop.

![Break in a while loop](assets/handout-figure-09.png)

![Break in a do while loop](assets/handout-figure-10.png)

![Break in a for loop](assets/handout-figure-11.png)

### `continue`

`continue` skips the rest of the current loop pass and begins the next one.

```c
for (int number = 1; number <= 6; ++number) {
    if (number == 4) {
        continue;
    }
    printf("%d ", number);
}
```

This prints `1 2 3 5 6`.

![Continue in a while loop](assets/handout-figure-12.png)

Do not use `break` or `continue` when a clearer loop condition can express the same idea. They are useful tools, not a substitute for a good plan.

## 10 Functions

A function is a named piece of code that performs one job. Functions make programs easier to read, test, and reuse.

There are two broad categories:

- **Library functions** are supplied by C libraries, for example `printf`, `scanf`, and `sqrt`.
- **User-defined functions** are functions you write.

![Library and user-defined functions](assets/handout-figure-13.png)

### Function prototype, call, and definition

```c
#include <stdio.h>

int add_numbers(int first, int second);  // prototype

int main(void)
{
    int total = add_numbers(7, 10);      // call
    printf("Total = %d\n", total);
    return 0;
}

int add_numbers(int first, int second)  // definition
{
    return first + second;
}
```

A function prototype tells the compiler the function's name, return type, and parameter types before the call is compiled.

![Control moves from main to a user-defined function and back](assets/handout-figure-14.png)

### Parameters and arguments

In this call:

```c
total = add_numbers(7, 10);
```

`7` and `10` are **arguments**. In the function definition, `first` and `second` are **parameters**. C passes ordinary values by value: the function receives copies of those values.

![Passing arguments to a function](assets/handout-figure-15.jpeg)

### The four common beginner patterns

The handout groups functions by whether they take arguments and whether they return a value. That is a useful way to think about them:

| Arguments? | Return value? | Example use |
| --- | --- | --- |
| no | no | print a menu |
| no | yes | ask for and return one value |
| yes | no | display a formatted report |
| yes | yes | calculate and return a result |

The return type must match what the function actually returns. A function declared as `int` must return an `int` on every normal path. A function that returns nothing should be declared `void`.

### Library functions and headers

Use the header that declares the function.

```c
#include <stdio.h>  // printf, scanf
#include <math.h>   // sqrt
```

For example:

```c
double root = sqrt(25.0);
```

Some toolchains require an additional math-library option when compiling on Unix-like systems, often `-lm`. Read the compiler message if `sqrt` fails to link.

## 11 Scope local global and parameter variables

**Scope** is the part of a program where a name can be used.

### Local variables

A variable declared inside a function or block is local to that block.

```c
int main(void)
{
    int score = 80;

    if (score >= 50) {
        int bonus = 5;
        score += bonus;
    }

    // bonus cannot be used here.
    return 0;
}
```

### Global variables

A global variable is declared outside every function.

```c
int attempts = 0;

void record_attempt(void)
{
    ++attempts;
}
```

Globals can be accessed by functions declared after them in the same source file. Use them carefully: many functions changing one shared value can make a program difficult to understand. Prefer passing values through parameters when practical.

### Parameters

Parameters are local variables of a function.

```c
int square(int value)
{
    return value * value;
}
```

`value` exists only while `square` runs.

### Initialization and storage duration

- Automatic local variables are **not** initialized for you.
- Global variables and `static` variables are initialized to zero when you do not give them an explicit value.
- Give variables an initial value whenever that makes sense.

## 12 Arrays

An array stores a fixed-size sequence of values of one type.

```c
int scores[5];
```

This creates room for five `int` values. Array indexing starts at zero, so the valid positions are `scores[0]` through `scores[4]`.

```c
int scores[5] = {72, 85, 91, 68, 88};
```

![Array positions from first element to last element](assets/handout-figure-16.jpeg)

![An initialized array and its zero-based indexes](assets/handout-figure-17.jpeg)

### Accessing elements

```c
scores[0] = 75;               // first element
printf("%d\n", scores[2]);   // third element
```

Never access outside the valid range. If `scores` has five elements, `scores[5]` is invalid. C may not stop you; the result is undefined behavior and can damage unrelated program data.

### Looping through an array

```c
int scores[] = {72, 85, 91, 68, 88};
int count = (int)(sizeof scores / sizeof scores[0]);

for (int index = 0; index < count; ++index) {
    printf("%d\n", scores[index]);
}
```

The condition is `index < count`, not `index <= count`, because the final valid index is `count - 1`.

## 13 Handout corrections and modern notes

The teacher handout is a useful topic guide. These changes are deliberate corrections, not silent replacements.

| Handout wording or example | Correct modern note |
| --- | --- |
| `main()` or `void main()` | Use `int main(void)` for a beginner program. `void main()` is not standard C. |
| “All C programs use header files” | A program can compile without a header if it uses nothing that needs one. Headers declare library functions and shared declarations. |
| `#` must be in the first column | Leading whitespace is permitted before a preprocessing directive in modern C. |
| 32 C keywords | That is an older standard's list. Modern C has more keywords. |
| Five basic data types | A useful first list, but it is simplified; C also has modifiers and other type categories. |
| Local variables default to zero | False for ordinary local variables. Initialize them before use. |
| `total = x + y;` after declaring `sum` | Use one consistent name, for example `sum = x + y;`. |
| `scanf("%d, ", &a)` for one integer | Use `scanf("%d", &a)`. The comma in the format would require comma-shaped input. |
| `for (a; a <= 10; a += 2)` | The first expression is unnecessary if `a` was initialized earlier. Prefer a clear form such as `for (; a <= 10; a += 2)` or initialize in the loop. |
| A `break` test that is never reached | Trace the loop condition and update carefully; a condition such as `while (a < 4)` can never reach `if (a == 4)` inside its body. |
| `balance[9]` from a five-element array | Invalid. A five-element array has indexes `0` through `4`. |
| `sqrt` result placed in `float` | It works through conversion, but `sqrt` returns `double`; use `double` or `sqrtf` when you truly want `float`. |

## 14 Practice checklist

Work through these in order. Each can be a separate `.c` file.

1. Print your name and course on separate lines.
2. Read two integers and print their sum, product, and remainder.
3. Read a number and say whether it is positive, negative, or zero.
4. Print the even numbers from 2 to 20 with a `for` loop.
5. Keep asking for a number until the user enters zero; print the total.
6. Write a function `int larger(int first, int second)` that returns the larger value.
7. Store five marks in an array and print the highest mark.
8. Change one program on purpose to create a compiler error; read the message, fix it, and compile again.

## A simple study order

Do not try to memorize all of C at once. Work in this order:

```text
program layout
-> variables and printf
-> scanf and operators
-> if else
-> loops
-> functions
-> arrays
```

For every example, first predict what it will print. Then compile it. When it differs from your prediction, that is where learning happens.
