
# 🧠 Strategy Design Pattern – Notes

## 📌 What is it?

- A **behavioral design pattern**.
- Allows selecting **algorithms or behaviors at runtime**.
- Helps manage **code variations** without changing the client code.

---

## ❓ Why Use It?

- Inheritance leads to **code duplication** when multiple child classes override similar methods.
- Promotes **flexibility**, **reusability**, and **clean separation** of concerns.
- Adheres to **SOLID principles**, especially:
  - **Open/Closed Principle** (open for extension, closed for modification)
  - **Single Responsibility Principle**

---

## 🚗 Real-Life Analogy (used in video)

- Vehicle Example:
  - **PassengerVehicle**, **OffRoadVehicle**, **SportsVehicle**
  - Each may need a **different driving behavior**
  - Instead of writing new code in each class, delegate to a **DriveStrategy**

---

## 🧱 Core Structure

```java
interface DriveStrategy {
    void drive();
}

class NormalDrive implements DriveStrategy {
    public void drive() {
        System.out.println("Normal Drive Capability");
    }
}

class SportsDrive implements DriveStrategy {
    public void drive() {
        System.out.println("Sports Drive Capability");
    }
}

class Vehicle {
    DriveStrategy driveStrategy;

    Vehicle(DriveStrategy driveStrategy) {
        this.driveStrategy = driveStrategy;
    }

    void drive() {
        driveStrategy.drive();
    }
}
```

---

## ✅ Benefits

- Avoids **code duplication**
- Behavior can be **changed dynamically**
- Easy to **add new behaviors** without modifying existing code
- Encourages use of **composition over inheritance**

---

## 🔁 When to Use

- When multiple classes only differ in **how they perform a certain behavior**.
- When you want to **dynamically change** behavior at runtime.
- When using **too many if-else or switch statements** to manage behavior.

---

## ⚠️ Caution

- Don’t overuse — use only when **behavior variation is real and likely to grow**.
- Can add **extra complexity** if misused.

# Strategy Pattern Refactoring — Summary of Changes

This document describes the key changes made to both the `WithoutStrategy` and `WithStrategy` folders in the `2.Strategy` module.

---

## 1. **WithoutStrategy Folder**

- Each car class (e.g., `SportsCar`, `PassengerCar`) had its own hardcoded driving logic.
- No use of polymorphism for driving behavior.
- Adding a new driving style required modifying each car class.

---

## 2. **WithStrategy Folder**

- **Applied the Strategy Pattern:**  
  - Introduced a `DriveStrategy` interface and concrete strategies (`NormalDrive`, `SportsDrive`, etc.).
  - Each car class now takes a `std::unique_ptr<DriveStrategy>` in its constructor, allowing dynamic assignment of driving behavior.
- **Class Structure Improvements:**  
  - Constructors and destructors are properly declared in headers and defined in `.cpp` files.
  - Removed extra qualification from constructor declarations in headers.
  - Used `explicit` keyword for single-argument constructors to prevent implicit conversions.
  - Used `std::move` to transfer ownership of strategy objects.
- **File Organization:**  
  - Moved all implementation code out of `main.cpp` and into the appropriate `.cpp` files.
  - `main.cpp` now only contains program logic and object creation.
- **CMake and Includes:**  
  - Updated `CMakeLists.txt` to include the correct header directories.
  - Ensured all source and header files are properly included and compiled.
- **Best Practices:**  
  - Used `#pragma once` in all header files.
  - Used smart pointers for memory safety.
  - Ensured destructors are `virtual` in base classes for proper cleanup.

---

## **Summary Table**

| Aspect                | WithoutStrategy                | WithStrategy (After Refactor)         |
|-----------------------|-------------------------------|---------------------------------------|
| Driving Logic         | Hardcoded in each car class   | Encapsulated in strategy classes      |
| Adding New Behavior   | Modify each car class         | Add new strategy class only           |
| Memory Management     | Manual or raw pointers        | `std::unique_ptr` and `std::move`     |
| File Organization     | Mixed, some logic in main.cpp | Separated headers and implementations |
| CMake Setup           | Basic                         | Improved include paths, organization  |
| OOP Principles        | Violates Open/Closed          | Follows Open/Closed, Strategy Pattern |

---

## **How to Use**

- To add a new driving behavior, create a new class implementing `DriveStrategy` and pass it to any car class.
- To add a new car type, inherit from `Vehicle` and accept a `DriveStrategy` in the constructor.

---

**This refactoring demonstrates the benefits of the Strategy Pattern:**

- Cleaner code
- Easier extension
- Better separation of concerns
- Improved maintainability
