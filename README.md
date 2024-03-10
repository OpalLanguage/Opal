# Lexer Specifications for Opal

## Operators
- Arithmetic: `+`, `-`, `*`, `/`, `%` ✅
- Assignment: `=`, `+=`, `-=`, `*=`, `/=`, `%=` ❌
- Comparison: `==`, `!=`, `<`, `>`, `<=`, `>=` ❌
- Logical: `&&`, `||`, `!` ❌
- Bitwise: `&`, `|`, `^`, `~`, `<<`, `>>` ❌
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
