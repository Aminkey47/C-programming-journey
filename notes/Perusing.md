# C Programming — Revision Notes

> **Purpose:** Personal revision notes for C programming.
>
> **Progress:** Fundamentals — keywords, identifiers, variables, and control structures.
>
> **Approach:** Understand concepts, practise with code, and test yourself.

---

## Table of Contents

1. [Introduction to C Programming](#1-introduction-to-c-programming)
2. [Variables and Data Types](#2-variables-and-data-types)
3. [Keywords](#3-keywords)
4. [Identifiers](#4-identifiers)
5. [Keywords vs Identifiers](#5-keywords-vs-identifiers)
6. [Control Structures](#6-control-structures)
7. [Understanding the Example Program](#7-understanding-the-example-program)
8. [Variables vs Functions](#8-variables-vs-functions)
9. [Common Mistakes](#9-common-mistakes)
10. [Revision Questions](#10-revision-questions)
11. [Answer Key](#11-answer-key)
12. [Topics to Study Next](#12-topics-to-study-next)

---

## 1. Introduction to C Programming

C is a general-purpose programming language used to develop operating systems, embedded systems, utilities, and many other types of software.

A C program consists of instructions that tell the computer what to do.

Example:

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
```

### Understanding the program

- `#include <stdio.h>` — includes the standard input/output header, which provides declarations for functions such as `printf()` and `scanf()`.
- `int main(void)` — defines the program's main function, where execution begins.
- `{ }` — marks the beginning and end of a block of code.
- `printf()` — displays output.
- `return 0;` — indicates successful completion of `main`.
- `;` — terminates a statement in C.

**Important:** `main` and `printf` are not C keywords. `#include` is a preprocessor directive.

---

## 2. Variables and Data Types

### What is a variable?

A variable is a named object used to store a value that a program can access and, when appropriate, modify.

Think of it as a labelled box containing data.

Example:

```c
int marks = 75;
```

This statement declares a variable called `marks` and initialises it with the value `75`.

### Breaking it down

| Component | Meaning                 |
| --------- | ----------------------- |
| `int`     | The data type: integer  |
| `marks`   | The variable name       |
| `=`       | The assignment operator |
| `75`      | The initial value       |
| `;`       | Ends the statement      |

### Common data types

| Data type | Purpose                                                                                    | Example                 |
| --------- | ------------------------------------------------------------------------------------------ | ----------------------- |
| `int`     | Stores integer values                                                                      | `int age = 20;`         |
| `float`   | Stores floating-point values                                                               | `float height = 1.75f;` |
| `double`  | Stores floating-point values with greater precision than `float` on common implementations | `double price = 99.99;` |
| `char`    | Stores a character                                                                         | `char grade = 'A';`     |

### Changing a variable's value

```c
int balance = 5000;

balance = 3000;
```

After the second statement, `balance` contains `3000`.

The first statement declares and initialises the variable. The second assigns a new value to it.

### Getting input from a user

```c
#include <stdio.h>

int main(void) {
    int marks;

    printf("Enter your marks: ");
    scanf("%d", &marks);

    printf("Your marks are %d\n", marks);

    return 0;
}
```

- `scanf()` reads input.
- `%d` specifies an integer conversion.
- `&marks` supplies the address where the entered integer will be stored.
- `%d` in `printf()` specifies where the integer value should appear in the output.
- `\n` moves the output to a new line.

For this simple example, the user should enter a valid integer.

---

## 3. Keywords

### Definition

A keyword is a reserved word in C that has a predefined meaning in the language.

Examples:

```c
int
if
else
while
for
return
switch
```

For example:

```c
int age = 20;

if (age >= 18) {
    printf("You are an adult.\n");
}
```

Here:

- `int` declares the integer type.
- `if` introduces a conditional statement.

### Can a keyword be used as a variable name?

No. A keyword such as `int` or `while` cannot be used as an ordinary identifier.

Invalid example:

```c
int while = 10;
```

Valid example:

```c
int count = 10;
```

### How should I learn keywords?

Instead of memorising the entire list without context:

1. Learn the purpose of each keyword as you encounter it.
2. Use it in small programs.
3. Practise identifying keywords in code.
4. Review the keyword list provided by your lecturer before examinations.

**Exam tip:** You may be asked to define a keyword, name five keywords, or identify keywords in a program.

The handout's list of 32 keywords corresponds to an older C standard. The set of keywords depends on the C standard being studied, so follow the list specified in your course.

---

## 4. Identifiers

### Definition

An identifier is a name used to identify a program entity, such as a variable or function.

Examples:

```c
int score;
int student_count;
double price2;
```

The identifiers are:

- `score`
- `student_count`
- `price2`

### Rules for naming identifiers

1. An identifier must start with a letter or an underscore (`_`).
2. After the first character, it can contain letters, digits, and underscores.
3. Spaces are not allowed.
4. Hyphens are not allowed.
5. A C keyword cannot be used as an ordinary identifier.
6. C is case-sensitive.

### Valid and invalid identifiers

| Identifier      | Valid?             | Reason                                                                                  |
| --------------- | ------------------ | --------------------------------------------------------------------------------------- |
| `score`         | Yes                | Starts with a letter                                                                    |
| `student_count` | Yes                | Underscore is allowed                                                                   |
| `price2`        | Yes                | A digit can appear after the first character                                            |
| `_score`        | Yes, syntactically | Starts with an underscore; beginners should generally prefer ordinary descriptive names |
| `2score`        | No                 | Starts with a digit                                                                     |
| `student name`  | No                 | Contains a space                                                                        |
| `total-cost`    | No                 | Contains a hyphen                                                                       |
| `int`           | No                 | It is a keyword                                                                         |

### Case sensitivity

```c
int score = 50;
int Score = 70;
int SCORE = 90;
```

These are three different identifiers because C is case-sensitive.

### Choosing good names

Prefer descriptive identifiers:

```c
int student_marks;
double total_price;
int number_of_students;
```

Avoid unclear names unless there is a good reason:

```c
int x;
int a;
```

Short names such as `i` are common for loop counters.

---

## 5. Keywords vs Identifiers

| Keyword                                  | Identifier                                                                       |
| ---------------------------------------- | -------------------------------------------------------------------------------- |
| Reserved by the C language               | Names a program entity                                                           |
| Has a predefined meaning                 | Chosen by the programmer, subject to naming rules                                |
| Cannot be used as an ordinary identifier | Must not conflict with reserved keywords or other applicable naming restrictions |
| Examples: `int`, `if`, `while`           | Examples: `marks`, `score`, `student_count`                                      |

Example:

```c
int score = 75;

if (score >= 50) {
    printf("You passed!\n");
}
```

Identification:

- `int` — keyword.
- `score` — identifier.
- `if` — keyword.
- `75` and `50` — integer constants.
- `=` — assignment operator.
- `>=` — greater-than-or-equal-to operator.

**Remember:** C provides the keywords; the programmer chooses identifiers.

---

## 6. Control Structures

Control structures determine the order in which instructions in a program are executed.

The three basic control structures are:

1. Sequence
2. Selection
3. Repetition

### 6.1 Sequence

Sequence means executing instructions in order, one after another.

Example:

```c
int a = 5;
int b = 3;
int sum = a + b;

printf("%d\n", sum);
```

Execution:

1. Declare and initialise `a`.
2. Declare and initialise `b`.
3. Calculate and store the sum.
4. Display the result.

Output:

```text
8
```

**Key idea:** Sequence = order.

### 6.2 Selection

Selection allows a program to choose which instructions to execute based on a condition.

Common selection statements include `if`, `if-else`, and `switch`.

Example:

```c
int marks = 75;

if (marks >= 50) {
    printf("You passed!\n");
} else {
    printf("You failed.\n");
}
```

The condition `marks >= 50` checks whether the marks are greater than or equal to 50.

- If the condition is true, the program prints `You passed!`.
- If the condition is false, the program prints `You failed.`.

Examples:

| Marks | Condition | Output      |
| ----: | --------- | ----------- |
|    75 | True      | You passed! |
|    50 | True      | You passed! |
|    42 | False     | You failed! |

**Key idea:** Selection = decision.

### 6.3 Repetition

Repetition means executing a block of instructions multiple times. It is also called iteration or looping.

C provides three main loop statements:

- `for`
- `while`
- `do-while`

Example:

```c
for (int i = 1; i <= 3; i++) {
    printf("Keep learning C!\n");
}
```

Understanding the loop:

| Component     | Purpose                                 |
| ------------- | --------------------------------------- |
| `int i = 1`   | Initialises the counter                 |
| `i <= 3`      | Checks whether the loop should continue |
| `i++`         | Increments the counter by one           |
| `printf(...)` | Instruction repeated by the loop        |

The loop executes for `i = 1`, `i = 2`, and `i = 3`. When `i` becomes `4`, the condition is false and the loop stops.

Output:

```text
Keep learning C!
Keep learning C!
Keep learning C!
```

**Key idea:** Repetition = looping.

---

## 7. Understanding the Example Program

This program combines all three control structures.

```c
#include <stdio.h>

int main(void) {

    // SEQUENCE: Execute instructions in order
    int marks;

    printf("Enter your marks: ");
    scanf("%d", &marks);

    // SELECTION: Make a decision
    if (marks >= 50) {
        printf("You passed!\n");
    } else {
        printf("You failed.\n");
    }

    // REPETITION: Print a message three times
    for (int i = 1; i <= 3; i++) {
        printf("Keep learning C!\n");
    }

    return 0;
}
```

### How the program works

**Step 1 — Sequence**

The program declares `marks`, prompts the user, and reads the entered value.

**Step 2 — Selection**

The `if-else` statement checks whether the entered marks are at least 50.

**Step 3 — Repetition**

The `for` loop prints a message three times, regardless of whether the student passed or failed.

**Step 4 — End**

`return 0;` indicates that `main` has completed successfully.

### Example run

Input:

```text
Enter your marks: 75
```

Output:

```text
You passed!
Keep learning C!
Keep learning C!
Keep learning C!
```

The three structures can work together in the same program, but a program does not have to use all three.

---

## 8. Variables vs Functions

This is an introduction only. Detailed study of functions will come later.

A **variable** stores data.

```c
int age = 20;
```

A **function** is a named block of code that performs a task and may receive parameters or return a value.

For example, `printf()` is a function that displays formatted output.

| Variable               | Function                                                     |
| ---------------------- | ------------------------------------------------------------ |
| Stores data            | Performs a task                                              |
| Example: `age`         | Example: `printf()`                                          |
| Has a type and a value | Has a return type, name, parameters, and a body when defined |

Remember the basic distinction: a variable stores information; a function performs a task.

---

## 9. Common Mistakes

### Mistake 1: Using a keyword as a variable name

Incorrect:

```c
int while = 5;
```

Correct:

```c
int counter = 5;
```

### Mistake 2: Starting an identifier with a digit

Incorrect:

```c
int 2marks = 70;
```

Correct:

```c
int marks2 = 70;
```

### Mistake 3: Confusing assignment with comparison

```c
marks = 50;
```

This assigns the value `50` to `marks`.

```c
marks >= 50
```

This compares `marks` with `50` and evaluates to true or false.

### Mistake 4: Forgetting the loop's stopping condition

```c
for (int i = 1; i <= 3; i++) {
    printf("Hello\n");
}
```

The loop stops because `i` eventually becomes `4`, making `i <= 3` false.

### Mistake 5: Assuming a loop runs only when a condition is true initially

A `for` loop checks its condition before each iteration. If the condition is initially false, the loop body does not execute at all.

---

## 10. Revision Questions

Try answering these without looking at the notes.

### Section A: Definitions

1. Define a keyword in C and give two examples.
2. What is an identifier? Give two examples.
3. Differentiate between a keyword and an identifier.
4. What is a variable?
5. State the three basic control structures in C.

### Section B: Understanding

6. Why is `2marks` an invalid identifier?
7. Why is `student_count` a valid identifier?
8. Explain the difference between `score` and `Score` in C.
9. What is the purpose of `if-else`?
10. What is repetition in programming?

### Section C: Code Analysis

11. Identify the keywords and identifier in this statement:

    ```c
    int score = 75;
    ```

12. What does this program print?

    ```c
    int marks = 42;

    if (marks >= 50) {
        printf("Pass\n");
    } else {
        printf("Fail\n");
    }
    ```

13. How many times does the following loop execute?

    ```c
    for (int i = 1; i <= 4; i++) {
        printf("Hello\n");
    }
    ```

14. Identify the control structure used in the following example:

    ```c
    if (age >= 18) {
        printf("Adult\n");
    }
    ```

15. What is the difference between a variable and a function?

---

## 11. Answer Key

1. A keyword is a reserved word with a predefined meaning in C. Examples: `int`, `while`.
2. An identifier is a name used for a program entity. Examples: `score`, `student_count`.
3. A keyword is reserved by the language; an identifier names a program entity.
4. A variable is a named object used to store a value.
5. Sequence, selection, and repetition.
6. It starts with a digit.
7. It starts with a letter and contains an allowed underscore.
8. C is case-sensitive, so they are different identifiers.
9. It selects which block to execute based on whether a condition is true or false.
10. Repetition means executing instructions multiple times.
11. `int` is the keyword; `score` is the identifier; `75` is the integer constant.
12. `Fail`.
13. Four times.
14. Selection.
15. A variable stores data; a function performs a task.

---

## 12. Topics to Study Next

Continue from this point in your course:

- [ ] Operators and expressions
- [ ] Arithmetic, relational, and logical operators
- [ ] More practice with `if`, `if-else`, and `switch`
- [ ] `for`, `while`, and `do-while` loops in more detail
- [ ] User input and output with `scanf()` and `printf()`
- [ ] Functions — study later in detail
- [ ] Small practice projects, such as a grading system and ATM simulation

---

## Final Revision Reminder

Do not learn C by memorising definitions alone.

For every concept:

1. Understand what it means.
2. Identify it in a code example.
3. Write a small program that uses it.
4. Explain it in your own words.
5. Test yourself without looking at the notes.

**Progress principle:** Understand → Practise → Recall → Repeat.
