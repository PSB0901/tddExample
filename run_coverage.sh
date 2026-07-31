#!/usr/bin/env bash
set -euo pipefail

if ! command -v lcov >/dev/null 2>&1; then
  echo "lcov not found. Trying to install via apt-get..."
  if command -v apt-get >/dev/null 2>&1; then
    sudo apt-get update && sudo apt-get install -y lcov || {
      echo "Failed to install lcov. Please install 'lcov' manually and re-run this script." >&2
      exit 1
    }
  else
    echo "Package manager apt-get not available. Please install 'lcov' manually." >&2
    exit 1
  fi
fi

BUILD_DIR=build-coverage
mkdir -p ${BUILD_DIR}
cd ${BUILD_DIR}

cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_C_FLAGS="--coverage -O0 -g" -DCMAKE_CXX_FLAGS="--coverage -O0 -g" ..
cmake --build . -- -j
ctest --output-on-failure

# Capture coverage data
lcov --directory . --capture --output-file coverage.info
# Remove system and test framework files
lcov --remove coverage.info '/usr/*' '*/_deps/*' --output-file coverage.filtered.info

# Generate HTML report
genhtml coverage.filtered.info --output-directory coverage-report

echo "Coverage report generated at: ${BUILD_DIR}/coverage-report/index.html"
