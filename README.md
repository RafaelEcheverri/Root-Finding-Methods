# Numerical Root-Finding Methods — C++

Three iterative root-finding algorithm implementations, exploring both the Regula Falsi (false position) method and the Secant method for solving nonlinear equations numerically.

## What it does

- **`regula_falsi_v1.cpp`** — Modified Regula Falsi method with a relaxation factor of 0.9, solving `f(x) = x³ - 2x - 5` for its root within a user-specified interval and convergence criterion.
- **`regula_falsi_v2_optimized.cpp`** — Same method with a reduced relaxation factor (0.75), included to directly compare convergence behavior. The lower relaxation factor reduces overshoot and converges in fewer iterations under the same test parameters.
- **`secant_method.cpp`** — Secant method implementation solving `f(x) = eˣ - (1 + x + x²/2)`, using two initial points to iteratively approximate the root without requiring derivative calculations.

## Why two Regula Falsi versions

The two versions aren't duplicates — they're a direct experiment in tuning the relaxation factor to reduce overshoot near the root. Comparing `v1` and `v2` under identical inputs shows the optimized version converging faster (fewer iterations to reach the same convergence criterion), which is a common tradeoff explored in numerical methods: stability vs. speed of convergence.

## Tools & Language

- **Language:** C++
- Standard library only (`<iostream>`, `<cmath>`) — no external dependencies

## How to run

Each file is a standalone, compilable program:

```bash
g++ regula_falsi_v1.cpp -o regula_falsi_v1
./regula_falsi_v1
```

You'll be prompted for:
- The search interval bounds (`a`, `b`)
- A convergence criterion (`epsilon`) — how small the interval must shrink before the root is accepted
- The maximum number of iterations allowed

Same usage pattern applies to `regula_falsi_v2_optimized.cpp` and `secant_method.cpp`.

## Background

Built to explore and compare classical numerical root-finding techniques — methods widely used in engineering and scientific computing when a closed-form solution isn't available or practical.
