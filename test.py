# -*- coding: utf-8 -*-
"""
Created on Sat Sep 12 15:11:26 2015

Example usage of the imported C++ module.

Using a simple Rectangle class.

@author: dav
"""

import rectangle_wrapper

# initialise a rectangle object with x0, y0, x1, y1 coords
my_rectangle = rectangle_wrapper.PyRectangle(2,4,6,8)

print my_rectangle.getLength()
print my_rectangle.getHeight()
print my_rectangle.getArea()

