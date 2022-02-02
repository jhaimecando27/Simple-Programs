# Program 2
(02/02/22) A Problem set from CSC 0212's (OOP) 1st Sem Final Examination.

## It's Instruction
* In Java make a function that will get the value of **ln(n!)**. Note: `ln(n * (n - 1) * (n - 2) * ...)` = `ln(n) + ln(n - 1) + ln(n - 2) ...`
* You may use `Math.log()` function in replace to `ln()`.
* Sample Output:
    * n = 3
    * Answer = 1.79
 
## My solution
* First thing come to my mind is the basic is factorial where I only used before for learning recursion. That means, my first plan is to make it recursion. Using about what is noted about the **ln(n!)**, my first initial plan for the `return` in my recursion is `Math.log(n) + fact(n - 1)`. I come up naming it `fact()` because it is similar as the factorial. I come up with this plan, because it will follow the concept of what is noted about the alternative formula for **ln(n!)** which is the `ln(n) + ln(n - 1) ...`, where it will first go at the very last `fact(n - #)`, which will stop by the base condition. Then it will perform the following formula which will be added to to the `Math.log(n)`, and go back to every recursion it went through start from its current position, and performing again the formula that it will be added to `Math.log(n)` until it go back at very beginning of the recursion.
* Also, I tried making it in iterative way. I still follow the concept of factorial in iterative way because it has the functionality that I need for this problem. In iterative way, I think of performing `Math.log(1)` and adding it to a temporary variable containing `0`. While value `1` in `Math.log(1)` will increment until it is equal to the given `n`.

  
