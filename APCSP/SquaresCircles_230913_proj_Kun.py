import pygame
from pygame.locals import *

def drawSquares(window):
    # Create variables to keep track of size and position
    posx = 0; posy = 0
    height = 100
    # Use a loop to draw squares until the size is too small
    while height > 0:
        pygame.draw.rect(window, (0, 0, 255), (posx, posy, height, height))
        posx += height
        posx += 10
        height -= 10
        posy += 10

    pass
        
        
def drawCircles(window):
    # Create variables to keep track of size, position and color
    posx = 300; posy = 300
    radius = 100
    greenness = 255
    # Use a loop to draw circles until the size is too small

    for i in range(10):
        pygame.draw.circle(window, (0, greenness, 0), (posx, posy), radius)
        radius -= 10
        greenness -= 25
    pass