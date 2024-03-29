# Lexer Specifications for Opal

Lexer is responsible for breaking down the source code into Tokens, each representing a meaningful element of the programming language.

## Operators

- **Arithmetic:** `+`, `-`, `*`, `/`, `%` ✅
- **Assignment:** `=`, `+=`, `-=`, `*=`, `/=`, `%=` ✅
- **Comparison:** `==`, `!=`, `<`, `>`, `<=`, `>=` ✅
- **Logical:** `&&`, `||`, `!` ✅
- **Others:** Increment `++`, Decrement `--` ✅

## Literals

- **Integer:** Standard decimal notation. ✅
- **Floating Point:** Supports standard notation (e.g., `1.23`). ✅
- **String:** Enclosed in double quotes (`" "`) with support for escape sequences. ✅
- **Character:** Enclosed in single quotes (`' '`). ✅
- **Boolean:** `True`, `False`. ✅
- **Null:** A special literal representing the absence of a value, denoted as `Null`. ✅

## Keywords

- **Control Flow:** `if`, `elseif`, `else`, `for`, `while`, `switch`, `case`, `default`, `break`, `continue` ✅
- **Declaration/Definition:** `class`, `enum`, `func`, `const` ✅
- **Miscellaneous:** `return`, `new`, `this`, `super` ✅

## Identifiers

Identifiers such as variable names, function names, class names, etc., following the naming conventions of Opal. ✅

## Delimiters

- Parentheses: `(`, `)` ✅
- Braces: `{`, `}` ✅
- Brackets: `[`, `]` ✅
- Comma: `,` ✅
- Semicolon: `;` ✅
- Dot: `.` ✅

## Comments

- Single-line: `//` ✅
- Multi-line: `/* */` ✅

## Whitespace

Spaces, tabs, and newline characters are considered whitespace, used to separate Tokens without generating separate Tokens themselves.

## Upcoming Features (Planned Improvements)

- Enhanced error handling for syntax and lexical analysis.
- Support for additional literals and operators based on community feedback.
- Optimizations for faster lexical analysis and reduced memory usage.

> **Note:** This specification is subject to change as Opal evolves. Contributors are encouraged to propose enhancements or report issues on the GitHub repository.

# Parser Specifications for Opal

The parser interprets the Tokens generated by the lexer, validating the syntax and structure of the source code.

## Variables ❌

- **Declaration and initialization:** `x = 10` ✅
- **Dynamic typing:** No need to specify the type. For example, `y = "Hello, World!"`. ✅
- **Compound assignment operators:** Use `+=`, `-=`, `*=`, `/=` for updating variables. For example, `x += 5`. ✅
- **Arithmetic operations:** With automatic type inference, `z = x + 20`. ❌

## Control Structures ❌

### Conditionals

```opal
if (condition) {
    // code block to execute if condition is true
} elseif (condition) {
    // code block to execute if the condition is true
} else {
    // code block to execute if the conditions are false
}
```

### Loops

- **While loop:**

  ```opal
  while (condition) {
      // code block to execute as long as the condition is true
  }
  ```

- **For loop:**

  ```opal
  for (initialization; condition; increment) {
      // code block to execute for each iteration
  }
  ```

### Switch

```opal
switch (expression) {
    case value1:
        // code block to execute if the expression equals value1
    case value2:
        // code block to execute if the expression equals value2
    default:
        // code block to execute if none of the values match
}
```

## Functions ❌

```opal
func name(arg1, arg2) {
    return value
}
```

## Classes ❌

```opal
class Name {
    value
    otherValue

    Name(initValue) {
        this.value = initValue
        this.otherValue = 12  
    }
}
```

> **Note:** The Opal parser is designed to handle a wide range of programming constructs, including variables, control structures, functions, and classes. This specification outlines the fundamental elements that the parser can recognize and how it interprets them to form the structure of an Opal program.

# Semantic Analysis for Opal

In an interpreted language like Opal, semantic analysis is crucial for dynamic typing and runtime error detection. This phase ensures that the code adheres to the language's semantics, performing tasks such as type checking, scope resolution, and the identification of semantic errors.

## Type Checking ❌

- **Dynamic Typing:** Opal dynamically checks types at runtime, ensuring that operations are semantically correct for the given types.
- **Type Inference:** Opal infers the types of expressions to simplify the coding process, reducing the need for explicit type declarations.

## Scope Resolution ❌

- Ensures that variables and functions are declared within the correct scope before use.
- Manages nested scopes to maintain accessibility and visibility of identifiers.

## Error Reporting ❌

- Generates meaningful error messages for semantic inconsistencies.
- Indicates precise locations (line and character) for easier debugging.

# Runtime Environment for Opal

Opal's runtime environment is where the source code is directly executed. This environment is responsible for interpreting the code, managing memory, handling execution context, and providing built-in functions and libraries.

## Interpreter ❌

- **Direct Execution:** Source code is executed line-by-line or statement-by-statement, without the need for compilation into machine code.
- **Just-In-Time Compilation:** For performance-critical sections, Opal might implement JIT compilation, compiling code to machine code on-the-fly.

## Memory Management ❌

- **Garbage Collection:** Automatically manages memory allocation and reclamation to prevent memory leaks and optimize performance.
- **Dynamic Allocation:** Manages memory allocation for variables and data structures during execution.

## Execution Context ❌

- Maintains the state and context of the program, including call stacks, global and local variables, and function calls.

# Standard Library for Opal

Opal's standard library provides a comprehensive set of functionalities, from basic data structures to networking. It enriches the language, making it more powerful and versatile for various programming tasks.

## Core Data Structures ❌

- Includes arrays, maps, lists, and more, with functions for sorting, searching, and manipulation.

## File and Network I/O ❌

- Offers APIs for file operations and network communications, enabling Opal programs to interact with the external environment.

## Utility Functions ❌

- Provides essential utilities like string manipulation, date/time operations, and mathematical functions.

# Tooling for Opal

The development experience in Opal is enhanced by a suite of tools designed to improve productivity, manage project dependencies, and facilitate debugging.

## Integrated Development Environment (IDE) ❌

- Features such as syntax highlighting, code completion, and integrated debugging tools support development in Opal.

## Package Manager ❌

- Simplifies the management of libraries and dependencies, streamlining the installation and update process.
