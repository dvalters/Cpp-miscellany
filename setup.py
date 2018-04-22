# -*- coding: utf-8 -*-
"""
Created on Sat Sep 12 15:11:26 2015

@author: dav
"""

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

setup(ext_modules=[Extension("rectangle_wrapper", ["rectangle_wrapper.pyx", "Rectangle.cpp"], language="c++",)],
      cmdclass = {'build_ext': build_ext})