class MyAge {
  defaultAge = 15

  func checkAge() {
    if (this.defaultAge < 18) {
      return False
    }

    return True
  }

  func newAge() {
    this.defaultAge++
  }
}