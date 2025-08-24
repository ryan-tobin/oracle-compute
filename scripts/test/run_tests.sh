#!/bin/bash
set -euo pipefail

echo "Running Oracle Test Suite"

# Rust tests
echo "Running Rust tests..."
cargo test --workspace --all-features

# C tests
echo "Running C tests..."
cd tests/unit
make test_c
cd ../..

# Python tests
echo "Running Python tests..."
cd bindings/python
python -m pytest tests/ -v
cd ../..

# JavaScript tests
echo "Runnign JavaScript tests..."
cd bindings/javascript
npm test
cd ../..

# Integration tests
echo "Running integration tests..."
cd test/integration
python test_end_to_end.py
cd ../..

# Property-based tests
echo "Running property tests..."
cd tests/property
cargo test
python -m pytest . -v
cd ../..

echo "All tests passed"
