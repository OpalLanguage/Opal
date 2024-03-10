# Lexer Specifications for Opal

## Operators
- Arithmetic: `+`, `-`, `*`, `/`, `%` ✅
- Assignment: `=`, `+=`, `-=`, `*=`, `/=`, `%=` ❌
- Comparison: `==`, `!=`, `<`, `>`, `<=`, `>=` ❌
- Logical: `&&`, `||`, `!` ❌
- Others: Increment `++`, Decrement `--` ❌

## Literals
- Integer: Standard decimal. ✅
- Floating Point: Supports standard notation (e.g., `1.23`). ✅
- String: Enclosed in double quotes (`" "`) with support for escape sequences. ✅
- Character: Enclosed in single quotes (`' '`). ✅
- Boolean: `True`, `False`. ✅
- Null: A special literal representing the absence of a value, denoted as `Null`. ✅

## Keywords
- Control Flow: `if`, `else`, `for`, `while`, `switch`, `case`, `default`, `break`, `continue` ❌
- Declaration/Definition: `class`, `enum`, `func`, `const` ❌
- Miscellaneous: `return`, `new`, `this`, `super`, ❌

## Identifiers
- Variable names, function names, class names, etc., following the naming conventions of Opal.

## Delimiters
- Parentheses: `(`, `)` ❌
- Braces: `{`, `}` ❌
- Brackets: `[`, `]` ❌
- Comma: `,` ❌
- Semicolon: `;` ❌
- Dot: `.` ❌

## Comments
- Single-line: `//` ❌
- Multi-line: `/* */` ❌

## Whitespace
- Spaces, tabs, and newline characters are considered whitespace and are used to separate tokens without generating separate tokens themselves.

## Upcoming Features (Planned Improvements)
- Enhanced error handling for syntax and lexical analysis.
- Support for additional literals and operators based on community feedback.
- Optimizations for faster lexical analysis and reduced memory usage.

**Note:** This specification is subject to change as Opal evolves. Contributors are encouraged to propose enhancements or report issues on the GitHub repository.

# Parser Specifications for Opal

## Variables ❌
- Declaration and initialization: `x = 10`
- Dynamic typing, no need to specify type: `y = "Hello, World!"`
- Arithmetic operations, with automatic type inference: `z = x + 20` 

## Control Structures
### Conditionals ❌
- `if` statement:
  ```c
  if (condition) {
      // code block to execute if condition is true
  } elseif (condition) {
      // code block to execute if the condition is true
  } else {
      // code block to execute if the conditions are false
  }
  ```
### Loops ❌
- `while` loop:
  ```c
  while (condition) {
      // code block to execute as long as the condition is true
  }
  ```
- `for` loop:
  ```c
  for (initialization; condition; increment) {
      // code block to execute for each iteration
  }
  ```
### Switch ❌
- `switch` statement:
  ```c
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
- Function declaration:
  ```c
  func name(arg1, arg2) {
      return value
  }
  ```

## Classes ❌
- Class definition:
  ```c
  class Name {
      value
      otherValue

      Name(initValue) {
          this.value = initValue
          this.otherValue = 12  
      }
  }
  ```

**Note:** The Opal parser is designed to handle a wide range of programming constructs, including variables, control structures, functions, and classes. This specification outlines the fundamental elements that the parser can recognize and how it interprets them to form the structure of an Opal program.
