class MyAge {
  defaultAge = 15
  const maxAge = 100

  func checkAge() {
    if (this.defaultAge < 18) {
      return False
    } elseif (this.defaultAge >= maxAge) {
      return "Too old"
    } else {
      return True
    }
  }

  func newAge(increment = 1) {
    if (increment > 0) {
      this.defaultAge += increment
    }
  }

  func resetAge() {
    this.defaultAge = 15
  }

  func isTeenager() {
    return this.defaultAge >= 13 && this.defaultAge <= 19
  }

  func celebrateBirthday() {
    this.newAge()
    if (this.defaultAge == 18) {
      console.log("Congratulations! You are now an adult.")
    }
  }

  func compareAge(otherAge) {
    if (this.defaultAge != otherAge) {
      return False
    }
    return True
  }
}