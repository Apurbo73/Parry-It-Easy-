### Parry-It-Easy

This C++ program solves a combat-style decision problem where, for each enemy (test case), you must decide to **either dodge** or **parry**. Each action has a skill threshold. Here's a concise explanation:

---

### **Overview:**

For each test case:

* `A[i]`: skill required to **dodge** the `i-th` enemy.
* `B[i]`: skill required to **parry** the `i-th` enemy (but costs 1 skill point).
* `X`: your initial skill level.

The goal is to **maximize the number of parries** you can make while still being able to finish the sequence of `N` enemies, using optimal dodge/parry choices.

---

### **Logic Breakdown:**

1. **Precompute `need[]`:**
   Working backwards, `need[i]` tells the *minimum skill* needed at enemy `i` to finish all remaining enemies optimally.

   * `dodge_need = max(A[i], need[i+1])`
   * `parry_need = max(B[i], need[i+1] + 1)` (since parry costs 1)
   * `need[i] = min(dodge_need, parry_need)`

2. **Simulation Forward:**
   If `X < need[0]`, it's impossible to complete, output `0`.
   Otherwise, simulate choices forward:

   * Prefer **parry** if possible (skill `≥ B[i]` and remaining skill `≥ need[i+1]` after reducing 1).
   * Else, try **dodge** (skill `≥ A[i]`).
   * If neither is possible, set `parryCount = 0` and break.

---

### **Output:**

For each test case, print the **maximum number of parries** that still allow survival through all enemies.

This program determines how many enemies a player can parry (instead of just dodging) while still surviving through all N enemies, given an initial skill level X. For each enemy, dodging requires a skill ≥ A[i], while parrying requires a skill ≥ B[i] and consumes 1 skill point. The program calculates a need[] array backward, which stores the minimum skill required at each point to survive the remaining enemies optimally, choosing the cheaper of dodge or parry for each.

Then it simulates the battle from the beginning using the initial skill X. At each step, it checks whether parrying is possible without losing the ability to finish the game. If so, it parries and counts it; otherwise, it checks if dodging is possible. If neither is possible, it breaks out and reports 0. The result is the maximum number of parries that can be performed while ensuring the player survives all enemy encounters.
