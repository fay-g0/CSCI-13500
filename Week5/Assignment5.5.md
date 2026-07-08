# Pointer Detective
Welcome to the agency detective. We ran into a couple of tough cases, and we need your help. As the best pointer detective in town, we thought of you first. 

## Introduction

A mysterious bug has appeared in several C++ programs. Your job as a **Pointer Detective** is to investigate each program and determine what is happening behind the scenes.

For **each mystery**, complete the following tasks **before running the program**:

1. Predict the program's output.
2. Explain **why** the output occurs.
3. Draw the call stack while the function executes.
4. Identify whether the function uses:
   - Pass by Copy
   - Pass by Reference
   - Pass by Pointer

After completing your predictions, compile and run the program to verify your answers.

---

# Mystery #1 – The Copycat

**Concepts:** Pass by Copy, Scope, Call Stack

```cpp
#include <iostream>

void addFive(int number)
{
    number += 5;
    std::cout << "Inside addFive(): " << number << std::endl;
}

int main()
{
    int value = 10;

    addFive(value);

    std::cout << "In main(): " << value << std::endl;
}
```

### Questions

1. What is the output of this program?
Inside addFive(): 15 ; In Main(): 10
2. Why doesn't `value` change after calling `addFive()`?
When addfive(value) was called, the value being 10 is copied into a new place called number. Changing number only affected the copy; so the value in main() remains as a separate memory location.
3. Where does the variable `number` exist?
Number exists inside addFive()'s stack frame. It is a local variable that only exists within addFive() upon executing the code.
4. Draw the call stack while `addFive()` is executing.
addFive()
    number = 15
main()
    value = 10
5. What happens to `number` after the function returns?
After the function returns, the stack frame is destroyed and number no longer exists. The function uses a pass by copy function.
---

# Mystery #2 – The Mirror

**Concepts:** References, `const`, Modifying Variables

```cpp
#include <iostream>

void investigate(int& suspect, const int& clue)
{
    suspect += clue;

    std::cout << "Inside investigate(): "
         << suspect << " " << clue << std::endl;
}

int main()
{
    int score = 10;
    int bonus = 5;

    investigate(score, bonus);

    std::cout << score << " " << bonus << std::endl;
}
```

### Questions

1. What is the output of this program?
Inside investigate(): 15 5 ; 15 5
2. Why does `score` change while `bonus` does not?
'score' changes because suspect modifies it directly. 'clue' references to 'bonus', but it's 'const', and the function never tries to modify 'clue'-it's only read from. 'bonus' itself was never intended to change here; only 'score' is written to (suspect += clue).
3. Why is `clue` declared as a `const` reference?
It singals and called at compile time that 'investigate()' will only read 'bonus' through 'clue, never modify it.
4. What would happen if the function attempted to modify `clue`?
If the function were to attempt to modify it, there would be a compile error, like "error: assignment of read-only reference clue'.
5. Draw the call stack while `investigate()` is executing.
investigate()
    suspect -> score (main)
    clue -> bonus (main)

main()
    score = 15
    bonus = 5
---

# Mystery #3 – Following the Pointer

**Concepts:** Raw Pointers, Dereferencing, `nullptr`

```cpp
#include <iostream>

void investigate(int* evidence)
{
    if (evidence != nullptr)
    {
        *evidence *= 2;
    }
}

int main()
{
    int clue = 7;

    investigate(&clue);

    std::cout << clue << std::endl;
}
```

### Questions

1. What is the output of this program?
The output is 14.
2. Why do we pass `&clue` instead of `clue`?
'investigate' expects an 'int*' not an int. '&clue' gets the address of 'clue' in memory so the function can reach into main()'s stack frame and modify the original variable.
3. What does `*evidence` do?
It dereferences the and goes to the address stored in 'evidence' and then accesses the value there. '*evidence *= 2' means that the value doubled at the address.
4. Why is the `nullptr` check important?
The check is important since it dereferences a null pointer as undefined behavior-which is typically a crash. The check also guards against being given an invalid address.
5. What would happen if the function was called as `investigate(nullptr);`?
If the functionw as called 'investigate(nullptr);' 'evidence' would be 'nullptr', the 'if' check would fail, the body would be skipped entirely, and the function would do nothing. There would be no crash as well due to the guard.
6. Draw the call stack while `investigate()` is executing.
investigate()
    evidence = 0x7ffe //points to 'clue'
main()
    clue = 14 //address still being 0x7ffe

This function uses pass by pointer.

---

# Mystery #4 – The Master Case

**Concepts:** Pass by Copy, Pass by Reference, Pass by Pointer, Return Values

```cpp
#include <iostream>

int mysteryA(int x)
{
    x += 10;
    return x;
}

void mysteryB(int& y)
{
    y *= 2;
}

void mysteryC(int* z)
{
    if (z != nullptr)
    {
        (*z)--;
    }
}

int main()
{
    int value = 5;

    value = mysteryA(value);
    mysteryB(value);
    mysteryC(&value);

    std::cout << value << std::endl;
}
```

### Questions

1. Predict the output of the program.
29
2. Draw the call stack after each function call.
mysteryA()
    x = 15 (copy of 5)
main()
    value = 5

mysteryB()
    y -> value (main)

main()
    value = 15 -> 30

mysteryC()
    z - address of value -> +value
main()
    value = 30 -> 29
3. Which function uses:
   - Pass by Copy? mysteryA
   - Pass by Reference? mysteryB
   - Pass by Pointer? mysteryC
4. Which functions modify the original variable?
mysteryB and mysteryC end up modifying the original variable.
5. Why does `mysteryA()` return a value, while `mysteryB()` and `mysteryC()` do not?
mysteryA takes x by copy, which means it does not affect 'main()''s 'value' direcetly. The only way it can ge tthe modified result back to the caller is to 'return' it and let the caller assign it. mysteryB and mysteryC already have direct access to 'value', so they modify it in place - no return value is needed.
6. Which approach would you choose if your goal was to modify the original variable? Explain your reasoning.
I would choose pass by reference since it modifies the original directly and an easier to read syntax than pointers. It also cannot be null. 

---

# Reflection

Answer the following questions in complete sentences.

1. What is the difference between passing a variable by copy, by reference, and by pointer
Passing a variable by copy duplcates the value into a new variable, where changes inside the dunction never affect the original. Passing by reference gives the function an alias for the original variable - no copy is made, and change inside the function directly change the caller's variable. Passing by pointer gives the function the memory address of the original variable. THe function has to explicitly dereference the pointer in order to read or modify the value it points to, and the pointer can be reassigned or set to 'nullptr'.
2. When would you choose to use a reference instead of a pointer?
Knowing when you will always have a valid object to work with, and you don't need to adjust the reference to point somewhere else later.
3. Why might a function accept a pointer instead of a reference?
Pointers support cases where references cannot where 'no value' is represented through 'nullptr'.
4. What role does the `const` keyword play when working with references and pointers?
'const' is able to communicate and enforce that the references or pointed data will not be modified through that specific reference/pointer. 'const int&' means that the value will be read but it will not change it. This is useful when you are passing large objects in an efficient way without have to copy while still keeping the caller's data safe. 'const' is also a compiler-enforced promise to not modify anything.
5. How does understanding the call stack help explain why variables change—or do not change—during function calls?
Understanding the call stack helps explain why each function call gets its own stack with its own local variables. Pass by copy parameters live inside the new frame, so modifying them can never go back into the caller's frame. Pass by reference and pass by pointer parameters, instead of holding independent copies, hold an alies that points back to the caller's stack frame. Any changes made through them can reach far and modify the original variable. Being able to visualize the stack helps imagine how some functions can reach back and change a caller's data while others physically cannot.