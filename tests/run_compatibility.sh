#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build"

echo "=== Compatibility Check ==="
echo "ROOT_DIR:  ${ROOT_DIR}"
echo "BUILD_DIR: ${BUILD_DIR}"
echo

if [[ ! -f "${BUILD_DIR}/libdcamera_source.dylib" || ! -f "${BUILD_DIR}/libdcamera_sink.dylib" ]]; then
  echo "Missing dylibs in ${BUILD_DIR}. Run:"
  echo "  cmake -S . -B build"
  echo "  cmake --build build -j 8"
  exit 1
fi

echo "[1/3] Export/dep check (verify_build.sh)"
(cd "${BUILD_DIR}" && "${ROOT_DIR}/verify_build.sh")
echo

echo "[2/3] Unit/integration tests"
(cd "${ROOT_DIR}/tests" && make run run_callback_passing run_auto_register \
  run_dylib_load_source_integration run_dylib_load_sink_integration run_thread_safety_source)
echo

echo "[3/3] Benchmarks (print-only)"
(cd "${ROOT_DIR}/tests" && make run_perf_source run_perf_sink)
echo

echo "OK"

