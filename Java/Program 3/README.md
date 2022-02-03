# Program 3
(02/03/22) A Problem set from CSC 0212's (OOP) 1st Sem Final Examination.

## It's Instruction
Create an abstract class **Business** with the following Methods:
```
public void business_type();
public double gross();
```

Extends **Business** class into three classes namely Private, Public, NGO. The gross of each business type is computed given below: 

| Business Type | Tax                      |
|---------------|--------------------------|
| Private       | income * 0.25 - expenses |
| Public        | income * 0.2 - expenses  |
| NGO           | income * 0.1 - expenses  |

Additional Requirement:
    1. Overload double gross() where parameters include income and expenses whose data types are int and double.
    2. business_type() function displays the business type, i.e. Private, Public or NGO.
    3. Base abstract class constructor has only one parameter which is `String business_type`
 
 
## My solution
* I changed `public double gross()` to abstact `abstract double gross()`, it is because I having nothing to perform to `gross()` in **Business** class. About the final result of this program, I think of whenever this use the method Private, Public, or NGO it will automatically displays the Business Type.
* I be using a progject manager because I want separate the **Business** from the main. Also, I think it is make more sense If it is separated.

#### Disclaimer
* This is not my actual asnwer in the examination. I enhanced after taking the exam.
