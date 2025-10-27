# NumC - A NumPy-like Library in C

A lightweight numerical computing library with a C backend and Python interface, inspired by NumPy.

## Features

### Core Functionality
- N-dimensional arrays with proper memory layout
- Broadcasting support for operations
- Rich set of mathematical operations
- Linear algebra operations (matmul, transpose, dot)
- Array creation functions (zeros, ones, arange, linspace, eye)
- Reductions and aggregations (sum, mean, max, min)
- Element-wise math functions (sqrt, exp, log, sin, cos)

### Python API
- Clean NumPy-like interface
- Operator overloading (+, -, *, /, @, **)
- NumPy interoperability (easy conversion)
- Similar function names and behavior

## Installation
```bash
git clone https://github.com/yourusername/numc.git
cd numc
make
pip install -e .
```

## Quick Start
```python
import numc as nc

# Create arrays
a = nc.zeros((3, 4))
b = nc.ones((3, 4))
c = nc.arange(0, 12).reshape((3, 4))

# Operations
d = a + b
e = c @ c.T  # Matrix multiplication

# Math functions
f = nc.sqrt(c)
g = nc.exp(c)

# Reductions
total = nc.sum(c)
average = nc.mean(c, axis=0)

# Broadcasting
x = nc.array([[1, 2, 3]])  # (1, 3)
y = nc.array([[1], [2], [3]])  # (3, 1)
z = x + y  # Broadcasts to (3, 3)
```

## Examples

### Linear Regression
```python
import numc as nc

# Generate data
X = nc.array([[1], [2], [3], [4]])
y = nc.array([[2], [4], [6], [8]])

# Add bias
X_b = nc.concatenate([nc.ones((4, 1)), X], axis=1)

# Gradient descent
w = nc.zeros((2, 1))
learning_rate = 0.01

for _ in range(100):
    y_pred = X_b @ w
    error = y_pred - y
    gradient = X_b.T @ error / 4
    w = w - learning_rate * gradient

print(f"Weights: {w.to_numpy()}")
```

### Image Processing
See `examples/image_processing.py`

### Neural Network Forward Pass
See `examples/neural_network.py`

## Architecture
```
NumC
├── C Backend (libnumc.so)
│   ├── ndarray structure with shape, strides, data
│   ├── Broadcasting logic
│   ├── Mathematical operations
│   └── Linear algebra routines
│
└── Python Interface
    ├── ndarray class with operator overloading
    ├── Top-level functions (zeros, ones, etc.)
    └── NumPy interoperability
```

### Memory Layout

NumC uses row-major (C-style) memory layout with explicit stride calculation:
- Contiguous memory allocation
- Stride-based indexing for efficient slicing
- Reference counting for memory management

### Broadcasting

Follows NumPy broadcasting rules:
- Dimensions are compared from right to left
- Dimensions must be equal or one of them must be 1
- Missing dimensions are treated as 1

## API Reference

### Array Creation
- `zeros(shape, dtype='float32')` - Create array of zeros
- `ones(shape, dtype='float32')` - Create array of ones
- `arange(start, stop, step, dtype='float32')` - Create evenly spaced values
- `linspace(start, stop, num, dtype='float32')` - Create evenly spaced values
- `eye(n, m, dtype='float32')` - Create identity matrix

### Operations
- `add`, `subtract`, `multiply`, `divide`, `power` - Arithmetic
- `matmul` (@), `dot` - Linear algebra
- `transpose`, `reshape` - Array manipulation
- `sum`, `mean`, `max`, `min` - Reductions (with axis support)

### Math Functions
- `sqrt`, `exp`, `log` - Basic math
- `sin`, `cos`, `tan` - Trigonometry

### Properties
- `shape` - Tuple of dimensions
- `ndim` - Number of dimensions
- `size` - Total number of elements
- `T` - Transpose

## Performance

NumC is not optimized for performance - it's a learning project to understand:
- How numerical computing libraries work internally
- Memory layout and stride calculations
- Broadcasting mechanics
- C/Python interop with ctypes

## Testing
```bash
# C tests
make test_c
./build/test_c

# Python tests
python tests/test_operations.py
python tests/test_broadcasting.py
python tests/test_linalg.py
```

## Contributing

This is a learning project, but contributions are welcome!
Areas that need work:
- [ ] Fancy indexing
- [ ] More dtypes
- [ ] Matrix decompositions (SVD, eigenvalues)
- [ ] Optimized BLAS integration
- [ ] Better error handling

## Learning Resources

- C memory management and pointers
- NumPy's internal array structure
- Broadcasting algorithm
- Python C extensions with ctypes
- Writing shared libraries

Useful resources:
- [NumPy Internals](https://numpy.org/devdocs/dev/internals.html)
- [From Python to Numpy](https://www.labri.fr/perso/nrougier/from-python-to-numpy/)
- [ctypes Documentation](https://docs.python.org/3/library/ctypes.html)

## License

MIT License

## Acknowledgments

Inspired by NumPy, PyTorch, and educational content from:
- Jake VanderPlas's Python Data Science Handbook
- Nicolas Rougier's "From Python to Numpy"
