# COMP 112 — C Programming Fundamentals, Conditionals and Loops

These notes are for beginner C programming revision. They cover the foundations needed before moving on to larger projects: variables, data types, input/output, operators, decision-making, loops, common errors, and practice questions.

---

## 1. Introduction to C

C is a compiled programming language. This means that you write C code in a source file, normally with a `.c` extension, and a compiler translates it into a program the computer can run.

```text
C source code (.c file) → compiler → executable program → output
```

C is:

- Case-sensitive: `mark`, `Mark`, and `MARK` are different names.
- Strict about punctuation: most statements require a semicolon (`;`).
- Commonly used in systems programming, embedded systems, operating systems, and performance-sensitive software.

---

## 2. The Structure of a C Program

A basic C program looks like this:

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, COMP 112!\n");

    return 0;
}
```

Expected output:

```text
Hello, COMP 112!
```

### Explanation

| Part | Meaning |
|---|---|
| `#include <stdio.h>` | Includes the standard input/output library. It allows use of `printf` and `scanf`. |
| `int main(void)` | The main function. Program execution starts here. |
| `{ }` | Curly braces create a block of code. |
| `printf()` | Displays output on the screen. |
| `\n` | Starts a new line. |
| `return 0;` | Ends the program successfully. |

### Statements

Most C statements end with a semicolon:

```c
int age = 20;
printf("%d\n", age);
```

### Comments

Comments explain code and are ignored by the compiler.

```c
// This is a single-line comment

/*
   This is a
   multi-line comment.
*/
```

Use comments to explain why code is written in a certain way.

---

## 3. Variables

A variable is a named memory location used to store data.

```c
int age;
age = 19;
```

You can also declare and initialise a variable in one line:

```c
int age = 19;
```

### Declaration, initialisation, and assignment

```c
int score;       // Declaration
score = 0;       // Initialisation
score = score + 5; // Assignment: score becomes 5
```

Read this statement:

```c
score = score + 5;
```

as:

> Take the current value of `score`, add 5, and store the result back in `score`.

The `=` symbol means assignment in C. It does not mean mathematical equality.

---

## 4. Naming Variables

Variable names are called identifiers.

A valid identifier:

- Can contain letters, numbers, and underscores.
- Cannot begin with a number.
- Cannot contain spaces or hyphens.
- Cannot use a C keyword such as `int`, `if`, or `return`.
- Is case-sensitive.

```c
int exam_mark;       // Valid
int numberOfBooks;   // Valid
int total_cost;      // Valid

int 2ndMark;         // Invalid: starts with a number
int exam-mark;       // Invalid: hyphen means subtraction
int float;           // Invalid: float is a keyword
```

Use meaningful names:

```c
int number_of_students;
double total_cost;
int pass_mark;
```

Avoid unclear names such as:

```c
int x;
int a;
int n1;
```

unless the purpose is obvious.

---

## 5. Data Types

A data type tells C what kind of information a variable stores.

| Type | Stores | Example |
|---|---|---|
| `int` | Whole numbers | `25`, `-8`, `0` |
| `float` | Decimal numbers, lower precision | `3.5f` |
| `double` | Decimal numbers, higher precision | `3.14159` |
| `char` | One character | `'A'`, `'7'`, `'?'` |

Examples:

```c
int number_of_students = 40;
float temperature = 28.5f;
double price = 150.75;
char grade = 'A';
```

Important:

```c
7      // Integer
7.0    // Decimal number
'7'    // Character
"7"    // Text/string
```

A `char` uses single quotation marks:

```c
char grade = 'B';
```

Text uses double quotation marks:

```c
printf("Hello\n");
```

---

## 6. Constants

A constant is a value that should not change while the program runs.

```c
const int PASS_MARK = 50;
const double VAT_RATE = 0.16;
```

Example:

```c
const int DAYS_IN_WEEK = 7;

printf("%d\n", DAYS_IN_WEEK);
```

Using constants makes code easier to understand and update.

---

## 7. Output with `printf`

`printf` displays information on the screen.

```c
printf("Welcome!\n");
```

To display variables, use conversion specifiers.

```c
int age = 20;
double height = 1.75;
char initial = 'M';

printf("Age: %d\n", age);
printf("Height: %.2f m\n", height);
printf("Initial: %c\n", initial);
```

Expected output:

```text
Age: 20
Height: 1.75 m
Initial: M
```

### Common `printf` conversion specifiers

| Specifier | Meaning |
|---|---|
| `%d` | Integer |
| `%f` | Decimal number |
| `%.2f` | Decimal number with two digits after the decimal point |
| `%c` | Single character |
| `%s` | Text/string |
| `%%` | Percent sign |

Examples:

```c
printf("%d\n", 25);
printf("%.2f\n", 12.5);
printf("%c\n", 'A');
printf("%s\n", "Hello");
printf("Score: 100%%\n");
```

### Escape sequences

| Escape sequence | Meaning |
|---|---|
| `\n` | New line |
| `\t` | Tab space |
| `\"` | Double quotation mark |
| `\\` | Backslash |

```c
printf("Name\tMark\n");
printf("Amina\t78\n");
printf("He said: \"Well done!\"\n");
```

Expected output:

```text
Name    Mark
Amina   78
He said: "Well done!"
```

---

## 8. Input with `scanf`

`scanf` reads input from the keyboard.

```c
int age;

printf("Enter your age: ");
scanf("%d", &age);

printf("You are %d years old.\n", age);
```

If the user enters `19`:

```text
Enter your age: 19
You are 19 years old.
```

### Why `&` is needed

The `&` tells C where to store the value entered by the user.

Correct:

```c
scanf("%d", &age);
```

Incorrect:

```c
scanf("%d", age);
```

### Common `scanf` conversion specifiers

| Variable type | `scanf` conversion |
|---|---|
| `int` | `%d` |
| `float` | `%f` |
| `double` | `%lf` |
| `char` | `%c` |

Examples:

```c
int number;
float temperature;
double price;
char grade;

scanf("%d", &number);
scanf("%f", &temperature);
scanf("%lf", &price);
scanf(" %c", &grade);
```

Notice the space before `%c`:

```c
scanf(" %c", &grade);
```

The space helps ignore an earlier newline left after keyboard input.

---

## 9. Worked Example: Average of Three Marks

```c
#include <stdio.h>

int main(void)
{
    double mark1, mark2, mark3;
    double average;

    printf("Enter three marks: ");
    scanf("%lf %lf %lf", &mark1, &mark2, &mark3);

    average = (mark1 + mark2 + mark3) / 3.0;

    printf("Average: %.2f\n", average);

    return 0;
}
```

Sample run:

```text
Enter three marks: 70 82 68
Average: 73.33
```

---

## 10. Arithmetic Operators

| Operator | Meaning | Example | Result |
|---|---|---:|---:|
| `+` | Addition | `8 + 3` | `11` |
| `-` | Subtraction | `8 - 3` | `5` |
| `*` | Multiplication | `8 * 3` | `24` |
| `/` | Division | `8 / 3` | `2` |
| `%` | Remainder | `8 % 3` | `2` |

Example:

```c
int first = 17;
int second = 5;

printf("Sum: %d\n", first + second);
printf("Difference: %d\n", first - second);
printf("Product: %d\n", first * second);
printf("Quotient: %d\n", first / second);
printf("Remainder: %d\n", first % second);
```

---

## 11. Integer Division

When both values are integers, C removes the decimal part.

```c
int result = 7 / 2;

printf("%d\n", result);
```

Output:

```text
3
```

To get `3.5`, make one number a decimal:

```c
double result = 7.0 / 2;

printf("%.1f\n", result);
```

Output:

```text
3.5
```

You can also cast:

```c
int total = 7;
int count = 2;

double average = (double) total / count;
```

The cast must happen before the division.

Correct:

```c
double average = (double) total / count;
```

Incorrect:

```c
double average = (double) (total / count);
```

The incorrect version performs integer division first.

---

## 12. Assignment Operators

| Short form | Same as |
|---|---|
| `x += 5;` | `x = x + 5;` |
| `x -= 5;` | `x = x - 5;` |
| `x *= 5;` | `x = x * 5;` |
| `x /= 5;` | `x = x / 5;` |
| `x %= 5;` | `x = x % 5;` |

Example:

```c
int total = 10;

total += 5;

printf("%d\n", total);
```

Output:

```text
15
```

---

## 13. Increment and Decrement

```c
count++;  // Add 1
count--;  // Subtract 1
```

Example:

```c
int count = 4;

count++;

printf("%d\n", count);
```

Output:

```text
5
```

---

## 14. Comparison Operators

Comparison operators are used in conditions.

| Operator | Meaning |
|---|---|
| `==` | Equal to |
| `!=` | Not equal to |
| `>` | Greater than |
| `<` | Less than |
| `>=` | Greater than or equal to |
| `<=` | Less than or equal to |

Examples:

```c
mark == 50
mark != 50
mark > 50
mark < 50
mark >= 50
mark <= 50
```

### `=` versus `==`

```c
mark = 50;   // Assigns 50 to mark
mark == 50;  // Checks whether mark is equal to 50
```

This is a very common test and programming error.

---

## 15. Logical Operators

Logical operators combine conditions.

| Operator | Meaning |
|---|---|
| `&&` | AND |
| `||` | OR |
| `!` | NOT |

### AND: `&&`

Both conditions must be true.

```c
if (age >= 18 && has_id == 1) {
    printf("Entry allowed.\n");
}
```

### OR: `||`

At least one condition must be true.

```c
if (day == 6 || day == 7) {
    printf("Weekend.\n");
}
```

### NOT: `!`

Reverses a condition.

```c
if (!(mark >= 50)) {
    printf("Fail\n");
}
```

This is clearer when written as:

```c
if (mark < 50) {
    printf("Fail\n");
}
```

---

## 16. The `if` Statement

Use `if` when code should run only when a condition is true.

```c
if (temperature > 30) {
    printf("It is hot.\n");
}
```

If the temperature is 32, it prints:

```text
It is hot.
```

If the temperature is 25, nothing is printed.

Always use braces, even for one statement:

```c
if (temperature > 30) {
    printf("It is hot.\n");
}
```

---

## 17. `if ... else`

Use `if ... else` when there are two possible choices.

```c
if (mark >= 50) {
    printf("Pass\n");
} else {
    printf("Fail\n");
}
```

Only one block runs.

---

## 18. `if ... else if ... else`

Use this when there are several possible choices.

```c
if (mark >= 70) {
    printf("Distinction\n");
} else if (mark >= 60) {
    printf("Credit\n");
} else if (mark >= 50) {
    printf("Pass\n");
} else {
    printf("Fail\n");
}
```

Conditions are tested from top to bottom. Once one condition is true, C skips the remaining conditions.

The highest mark range must come first.

Incorrect order:

```c
if (mark >= 50) {
    printf("Pass\n");
} else if (mark >= 70) {
    printf("Distinction\n");
}
```

A mark of 75 would print `Pass`, because `75 >= 50` is already true.

---

## 19. Validating a Mark

A valid mark should be from 0 to 100.

```c
if (mark < 0 || mark > 100) {
    printf("Invalid mark.\n");
} else if (mark >= 70) {
    printf("Distinction\n");
} else if (mark >= 60) {
    printf("Credit\n");
} else if (mark >= 50) {
    printf("Pass\n");
} else {
    printf("Fail\n");
}
```

The correct range test is:

```c
mark >= 0 && mark <= 100
```

Do not write:

```c
mark >= 0 || mark <= 100
```

That condition is almost always true.

---

## 20. Nested `if`

A nested `if` is an `if` statement inside another `if`.

```c
if (age >= 18) {
    if (has_id == 1) {
        printf("Entry allowed.\n");
    } else {
        printf("Bring identification.\n");
    }
} else {
    printf("You must be at least 18.\n");
}
```

Use nested conditions when the second decision depends on the first decision.

---

## 21. Worked Example: Largest of Two Numbers

```c
#include <stdio.h>

int main(void)
{
    int first;
    int second;

    printf("Enter two whole numbers: ");
    scanf("%d %d", &first, &second);

    if (first > second) {
        printf("Largest: %d\n", first);
    } else if (second > first) {
        printf("Largest: %d\n", second);
    } else {
        printf("The numbers are equal.\n");
    }

    return 0;
}
```

Sample run:

```text
Enter two whole numbers: 14 9
Largest: 14
```

---

## 22. Worked Example: Even or Odd

```c
#include <stdio.h>

int main(void)
{
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number % 2 == 0) {
        printf("Even\n");
    } else {
        printf("Odd\n");
    }

    return 0;
}
```

Sample run:

```text
Enter an integer: 17
Odd
```

---

## 23. `switch` Statement

Use `switch` when one value is compared with several fixed options.

```c
switch (choice) {
    case 1:
        printf("Add\n");
        break;

    case 2:
        printf("Subtract\n");
        break;

    case 3:
        printf("Exit\n");
        break;

    default:
        printf("Invalid choice\n");
        break;
}
```

### Parts of `switch`

| Part | Purpose |
|---|---|
| `switch (choice)` | Tests the value of `choice`. |
| `case 1:` | Runs when the value is 1. |
| `break;` | Leaves the switch statement. |
| `default:` | Runs if no case matches. |

### Why `break` matters

Without `break`, C continues into the next case.

```c
int choice = 1;

switch (choice) {
    case 1:
        printf("One\n");

    case 2:
        printf("Two\n");
        break;
}
```

Output:

```text
One
Two
```

Normally, place `break` at the end of each case.

---

## 24. Worked Example: Day of the Week

```c
#include <stdio.h>

int main(void)
{
    int day;

    printf("Enter a day number from 1 to 7: ");
    scanf("%d", &day);

    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid day number.\n");
            break;
    }

    return 0;
}
```

Sample run:

```text
Enter a day number from 1 to 7: 6
Saturday
```

---

## 25. Loops

A loop repeats code.

Every loop needs:

1. A starting value.
2. A condition.
3. An update.

For example:

```c
int number = 1;

while (number <= 5) {
    printf("%d\n", number);
    number++;
}
```

The loop starts at 1, continues while the number is at most 5, and increases the number each time.

---

## 26. `while` Loop

A `while` loop checks its condition before running its body.

```c
while (condition) {
    // Repeated code
}
```

Example:

```c
int number = 1;

while (number <= 5) {
    printf("%d\n", number);
    number++;
}
```

Output:

```text
1
2
3
4
5
```

A `while` loop may run zero times if the condition is false at the beginning.

---

## 27. `do ... while` Loop

A `do ... while` loop checks its condition after running the body.

```c
do {
    // Repeated code
} while (condition);
```

Example:

```c
int number = 6;

do {
    printf("%d\n", number);
    number++;
} while (number <= 5);
```

Output:

```text
6
```

It runs once even though the condition becomes false.

Use `do ... while` when code must run at least once, such as when displaying a menu.

---

## 28. `for` Loop

Use a `for` loop when repeating a known number of times.

```c
for (initialisation; condition; update) {
    // Repeated code
}
```

Example:

```c
for (int number = 1; number <= 5; number++) {
    printf("%d\n", number);
}
```

Output:

```text
1
2
3
4
5
```

The loop has three parts:

```c
for (int number = 1; number <= 5; number++)
```

| Part | Meaning |
|---|---|
| `int number = 1` | Start at 1 |
| `number <= 5` | Continue while number is at most 5 |
| `number++` | Add 1 after every repetition |

---

## 29. Comparing Loops

| Loop | When the condition is tested | Runs at least once? | Common use |
|---|---|---|---|
| `while` | Before the body | No | Unknown number of repetitions |
| `do ... while` | After the body | Yes | Menus and validation |
| `for` | Before the body | No | Known number of repetitions |

---

## 30. Counting Backwards

```c
for (int number = 10; number >= 0; number--) {
    printf("%d\n", number);
}

printf("Lift off!\n");
```

Output:

```text
10
9
8
7
6
5
4
3
2
1
0
Lift off!
```

---

## 31. Counting in Steps

Print even numbers from 2 to 10:

```c
for (int number = 2; number <= 10; number += 2) {
    printf("%d ", number);
}

printf("\n");
```

Output:

```text
2 4 6 8 10
```

---

## 32. Accumulators

An accumulator stores a running total.

### Sum accumulator

Start a sum at zero.

```c
int sum = 0;

for (int number = 1; number <= 5; number++) {
    sum += number;
}

printf("Sum: %d\n", sum);
```

Output:

```text
Sum: 15
```

### Product accumulator

Start a product at one.

```c
int product = 1;

for (int number = 1; number <= 4; number++) {
    product *= number;
}

printf("Product: %d\n", product);
```

Output:

```text
Product: 24
```

Do not start a product at zero, because multiplying by zero always gives zero.

---

## 33. Sentinel-Controlled Loops

A sentinel is a special value that tells a loop to stop.

Example: enter marks until `-1` is entered.

```c
#include <stdio.h>

int main(void)
{
    int mark;
    int total = 0;
    int count = 0;

    printf("Enter a mark (-1 to finish): ");
    scanf("%d", &mark);

    while (mark != -1) {
        total += mark;
        count++;

        printf("Enter a mark (-1 to finish): ");
        scanf("%d", &mark);
    }

    if (count > 0) {
        printf("Average: %.2f\n", (double) total / count);
    } else {
        printf("No marks entered.\n");
    }

    return 0;
}
```

Sample run:

```text
Enter a mark (-1 to finish): 60
Enter a mark (-1 to finish): 75
Enter a mark (-1 to finish): 90
Enter a mark (-1 to finish): -1
Average: 75.00
```

The program checks `count > 0` to avoid division by zero.

---

## 34. `break`

`break` immediately exits the nearest loop or `switch`.

```c
for (int number = 1; number <= 10; number++) {
    if (number == 6) {
        break;
    }

    printf("%d ", number);
}

printf("\nFinished\n");
```

Output:

```text
1 2 3 4 5
Finished
```

---

## 35. `continue`

`continue` skips the rest of the current loop repetition and moves to the next one.

```c
for (int number = 1; number <= 10; number++) {
    if (number % 2 == 0) {
        continue;
    }

    printf("%d ", number);
}

printf("\n");
```

Output:

```text
1 3 5 7 9
```

The even numbers are skipped.

---

## 36. Infinite Loops

An infinite loop continues forever unless something stops it.

```c
while (1) {
    // Repeats forever
}
```

Another form:

```c
for (;;) {
    // Repeats forever
}
```

Example with `break`:

```c
int choice;

while (1) {
    printf("Enter 0 to stop: ");
    scanf("%d", &choice);

    if (choice == 0) {
        break;
    }

    printf("You entered %d\n", choice);
}

printf("Goodbye.\n");
```

### Accidental infinite loop

```c
int number = 1;

while (number <= 5) {
    printf("%d\n", number);
}
```

This never stops because `number` is never updated.

Correct version:

```c
int number = 1;

while (number <= 5) {
    printf("%d\n", number);
    number++;
}
```

---

## 37. Combining Loops and Conditions

### Count passes

```c
#include <stdio.h>

int main(void)
{
    int mark;
    int passes = 0;

    for (int student = 1; student <= 5; student++) {
        printf("Enter mark for student %d: ", student);
        scanf("%d", &mark);

        if (mark >= 50) {
            passes++;
        }
    }

    printf("Number of passes: %d\n", passes);

    return 0;
}
```

Sample run:

```text
Enter mark for student 1: 46
Enter mark for student 2: 80
Enter mark for student 3: 50
Enter mark for student 4: 39
Enter mark for student 5: 75
Number of passes: 3
```

---

## 38. Sum Even Numbers

```c
int sum = 0;

for (int number = 1; number <= 10; number++) {
    if (number % 2 == 0) {
        sum += number;
    }
}

printf("Sum of even numbers: %d\n", sum);
```

Output:

```text
Sum of even numbers: 30
```

---

## 39. Input Validation with `do ... while`

```c
int mark;

do {
    printf("Enter a mark from 0 to 100: ");
    scanf("%d", &mark);

    if (mark < 0 || mark > 100) {
        printf("Invalid mark. Try again.\n");
    }
} while (mark < 0 || mark > 100);

printf("Accepted mark: %d\n", mark);
```

Sample run:

```text
Enter a mark from 0 to 100: 120
Invalid mark. Try again.
Enter a mark from 0 to 100: 73
Accepted mark: 73
```

---

## 40. Flags

A flag is a variable used to remember whether something has happened.

```c
int found_zero = 0;
int value;

for (int position = 1; position <= 5; position++) {
    printf("Enter value %d: ", position);
    scanf("%d", &value);

    if (value == 0) {
        found_zero = 1;
        break;
    }
}

if (found_zero == 1) {
    printf("Zero was entered.\n");
} else {
    printf("Zero was not entered.\n");
}
```

---

## 41. Nested Loops

A nested loop is a loop inside another loop.

```c
for (int row = 1; row <= 3; row++) {
    for (int column = 1; column <= 4; column++) {
        printf("* ");
    }

    printf("\n");
}
```

Output:

```text
* * * *
* * * *
* * * *
```

Multiplication table example:

```c
for (int row = 1; row <= 3; row++) {
    for (int column = 1; column <= 3; column++) {
        printf("%d ", row * column);
    }

    printf("\n");
}
```

Output:

```text
1 2 3
2 4 6
3 6 9
```

---

## 42. Trace Tables

A trace table helps you understand what happens inside a program.

Example:

```c
int sum = 0;

for (int i = 1; i <= 4; i++) {
    sum += i;
}

printf("%d\n", sum);
```

| Iteration | `i` | `sum` after `sum += i` |
|---:|---:|---:|
| 1 | 1 | 1 |
| 2 | 2 | 3 |
| 3 | 3 | 6 |
| 4 | 4 | 10 |

Output:

```text
10
```

When tracing code, write down variable values after each important statement.

---

## 43. Common Mistakes

| Mistake | Problem | Correct version |
|---|---|---|
| `if (mark = 50)` | Assigns 50 instead of comparing | `if (mark == 50)` |
| `scanf("%d", mark)` | Missing variable address | `scanf("%d", &mark)` |
| `scanf("%f", &price)` when `price` is `double` | Wrong conversion | `scanf("%lf", &price)` |
| `7 / 2` expected to be 3.5 | Integer division | `7.0 / 2` |
| Missing `break` in `switch` | Falls into the next case | Add `break;` |
| Missing loop update | Creates an infinite loop | Update the counter |
| Sum not initialised | Contains an unpredictable value | `int sum = 0;` |
| Product starts at zero | Product always remains zero | `int product = 1;` |
| Range test uses `||` instead of `&&` | Almost every value passes | Use `&&` for a range |
| Comparing a char to `"Y"` | `"Y"` is text, not one character | Use `'Y'` |
| Semicolon after `if` | The condition controls nothing | Remove the semicolon |
| Dividing by zero | Invalid calculation | Check the divisor first |

### Semicolon after `if`

Incorrect:

```c
if (age >= 18); {
    printf("Adult\n");
}
```

This prints `Adult` regardless of age.

Correct:

```c
if (age >= 18) {
    printf("Adult\n");
}
```

---

## 44. Worked Example: Positive, Negative, or Zero

```c
#include <stdio.h>

int main(void)
{
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number > 0) {
        printf("Positive\n");
    } else if (number < 0) {
        printf("Negative\n");
    } else {
        printf("Zero\n");
    }

    return 0;
}
```

Sample run:

```text
Enter an integer: -12
Negative
```

---

## 45. Worked Example: Discount Calculator

Apply a 10% discount to purchases of KSh 5,000 or more.

```c
#include <stdio.h>

int main(void)
{
    double purchase;
    double amount_due;

    printf("Enter purchase amount: ");
    scanf("%lf", &purchase);

    if (purchase >= 5000.0) {
        amount_due = purchase * 0.90;
        printf("Discount applied.\n");
    } else {
        amount_due = purchase;
        printf("No discount.\n");
    }

    printf("Amount due: KSh %.2f\n", amount_due);

    return 0;
}
```

Sample run:

```text
Enter purchase amount: 6000
Discount applied.
Amount due: KSh 5400.00
```

---

## 46. Worked Example: Multiplication Table

```c
#include <stdio.h>

int main(void)
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    for (int multiplier = 1; multiplier <= 10; multiplier++) {
        printf("%d x %d = %d\n", number, multiplier, number * multiplier);
    }

    return 0;
}
```

Sample run for input `4`:

```text
Enter a number: 4
4 x 1 = 4
4 x 2 = 8
4 x 3 = 12
4 x 4 = 16
4 x 5 = 20
4 x 6 = 24
4 x 7 = 28
4 x 8 = 32
4 x 9 = 36
4 x 10 = 40
```

---

## 47. Worked Example: Factorial

The factorial of a positive integer is:

```text
5! = 5 × 4 × 3 × 2 × 1 = 120
```

```c
#include <stdio.h>

int main(void)
{
    int number;
    int factorial = 1;

    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined here for negative numbers.\n");
    } else {
        for (int value = 1; value <= number; value++) {
            factorial *= value;
        }

        printf("%d! = %d\n", number, factorial);
    }

    return 0;
}
```

Sample run:

```text
Enter a non-negative integer: 5
5! = 120
```

---

## 48. Worked Example: Menu Program

```c
#include <stdio.h>

int main(void)
{
    int choice;

    do {
        printf("\n1. Say hello\n");
        printf("2. Say goodbye\n");
        printf("0. Exit\n");
        printf("Choose an option: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Hello!\n");
                break;

            case 2:
                printf("Goodbye!\n");
                break;

            case 0:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid option.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
```

---

## 49. Exercises

### Variables and Input/Output

1. Write a program that displays your name, course code, and favourite number.
2. Read two integers and display their sum, difference, product, quotient, and remainder.
3. Read the length and width of a rectangle, then display its area and perimeter.
4. Read a temperature in Celsius and convert it to Fahrenheit.

```text
Fahrenheit = (Celsius × 9 / 5) + 32
```

5. Read a character grade and display it.

### Conditions

6. Read an integer and state whether it is even or odd.
7. Read an age and display `Child` for below 13, `Teenager` for 13–19, and `Adult` for 20 and above.
8. Read three integers and display the largest.
9. Read a mark and display `Distinction`, `Credit`, `Pass`, or `Fail`.
10. Reject invalid marks below 0 or above 100.
11. Use `switch` to identify whether a letter is a vowel.
12. Use `switch` to display the day of the week from a number between 1 and 7.

### Loops

13. Print numbers from 1 to 20.
14. Print numbers from 20 down to 1.
15. Print all multiples of 3 from 3 to 60.
16. Find the sum of numbers from 1 to `n`.
17. Read 10 marks and calculate the average.
18. Read positive integers until the user enters `0`, then display the total and count.
19. Keep asking for a number between 1 and 5 using `do ... while`.
20. Print a 5 by 5 square of asterisks using nested loops.

### Combining Conditions and Loops

21. Print numbers from 1 to 50 but skip multiples of 5.
22. Read up to 10 integers but stop if a negative number is entered.
23. Read 8 marks and count passes and fails.
24. Create a menu with options to calculate a square, determine even/odd, and exit.
25. Read numbers until `-1` is entered, then display the largest number entered.

---

## 50. Revision Checklist

Before your test, make sure you can do all of these without copying:

- [ ] Explain the purpose of `#include <stdio.h>`.
- [ ] Write a complete C program using `main`.
- [ ] Declare `int`, `float`, `double`, and `char` variables.
- [ ] Explain declaration, initialisation, and assignment.
- [ ] Use `printf` correctly.
- [ ] Use `scanf` correctly, including `&`.
- [ ] Know the difference between `%f` and `%lf` in `scanf`.
- [ ] Explain integer division.
- [ ] Use arithmetic and assignment operators.
- [ ] Explain the difference between `=` and `==`.
- [ ] Use `&&`, `||`, and `!`.
- [ ] Write `if`, `if ... else`, and `if ... else if`.
- [ ] Use nested `if` statements.
- [ ] Write a `switch` statement with `break` and `default`.
- [ ] Write `for`, `while`, and `do ... while` loops.
- [ ] Identify a loop's start, condition, and update.
- [ ] Use counters, totals, accumulators, and flags.
- [ ] Use sentinel values correctly.
- [ ] Use `break` and `continue`.
- [ ] Avoid infinite loops.
- [ ] Trace a short C program by hand.
- [ ] Test normal, boundary, and invalid values.

---

## 51. Test-Day Method

When answering a C programming question:

1. Identify the inputs.
2. Identify the required output.
3. Choose appropriate variables and data types.
4. Write the calculation or decision in plain English first.
5. Decide whether you need `if`, `switch`, a loop, or a combination.
6. For loops, identify the start, condition, and update.
7. Check special cases such as zero, invalid marks, and boundary values.
8. Check your semicolons, braces, quotation marks, conversion specifiers, and `&` symbols.
9. Trace the program with sample values before finishing.

A good beginner C program is clear, correct, and easy to explain.