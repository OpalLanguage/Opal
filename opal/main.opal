class MyAge {
  defaultAge = 15

  fun checkAge() {
    if (this.defaultAge < 18) {
      return false
    }

    return true
  }

  fun newAge() {
    defaultAge++
  }
}