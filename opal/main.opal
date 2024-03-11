class MyAge {
  defaultAge = 15;
  const maxAge = 100; // Usage of TOKEN_CONST

  func checkAge() {
    if (this.defaultAge < 18) {
      return False; // TOKEN_BOOLEAN, TOKEN_IF, TOKEN_LESS
    } else if (this.defaultAge >= maxAge) { // TOKEN_ELSEIF, TOKEN_GREATER_EQUAL
      return "Too old"; // TOKEN_STRING
    } else {
      return True; // TOKEN_ELSE, TOKEN_BOOLEAN
    }
  }

  func newAge(increment = 1) { // TOKEN_ASSIGN, TOKEN_INT
    if (increment > 0) { // TOKEN_GREATER
      this.defaultAge += increment; // TOKEN_ASSIGN_ADD
    }
  }

  func resetAge() {
    this.defaultAge = 15; // TOKEN_ASSIGN
  }

  func isTeenager() {
    return this.defaultAge >= 13 && this.defaultAge <= 19; // TOKEN_OP_AND, TOKEN_OP_GREATER_EQUAL, TOKEN_OP_LESS_EQUAL
  }

  func celebrateBirthday() {
    this.newAge(); // TOKEN_DOT
    if (this.defaultAge == 18) { // TOKEN_OP_EQUAL
      console.log("Congratulations! You are now an adult."); // Imaginary function to demonstrate TOKEN_IDENTIFIER, TOKEN_DOT
    }
  }

  func compareAge(otherAge) {
    // Demonstrating TOKEN_OP_NOT_EQUAL, TOKEN_IDENTIFIER
    if (this.defaultAge != otherAge) {
      return False;
    }
    return True;
  }
}