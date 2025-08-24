from setuptools import Setup, Extension
from pybind11.setup_helpers import Pybind11Extension, build_ext
from pybind11 import get_cmake_dir
import pybind11 

ext_modules = [
    Pybind11Extension(
        "oracle_compute",
        [
            "src/oracle_binding.cpp",
            "../../src/c/oracle_core.c",
        ],
        include_dirs=[
            "../../src/c",
            "../../include",
            pybind11.get_include(),
        ],
        cxx_std=17,
        define_macros=[("VERSION_INFO", '"dev"')],
    ),
]

setup(
    name="oracle-compute",
    version="0.1.0",
    author="Ryan Tobin",
    author_email="ryantobin119@gmail.com",
    description="Python bindings for Oracle Precognitive Computation Engine",
    long_description="",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    python_requires=">3.8",
    install_requires=[
        "numpy>=1.20.0",
        "pybind11>=2.10.0",
    ],
    extras_require={
        "dev": ["pytest>=6.0", "black", "isort", "mypy"],
        "bench": ["pytest-benchmark"],
    },
)