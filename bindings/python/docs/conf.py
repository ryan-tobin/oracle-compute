import os 
import sys 
sys.path.insert(0, os.path.abspath('..'))

project = 'Oracle Compute Python'
copyright = '2025, Ryan Tobin'
author = 'Ryan Tobin'

extensions = [
    'sphinx.ext.autodoc',
    'sphinx.ext.viewcode',
    'sphinx.ext.napoleon',
    'sphinx.ext.intersphinx',
]

html_theme = 'sphinx_rtd_theme'
