import pygame, sys
from pygame.locals import *
from SquaresCircles_230913_proj_Kun import *

pygame.init()
screen = pygame.display.set_mode((800,600))

#Colors the screen white
WHITE = (255, 255, 255)
screen.fill(WHITE)


# calls the method draw scene and sends it the screen to draw on

drawSquares(screen)

drawCircles(screen)
  
pygame.display.update()


while True:
    for event in pygame.event.get():
        # Check if the user closed the window
        if event.type==QUIT or (event.type==KEYUP and event.key==K_ESCAPE):
            pygame.quit()
            sys.exit()
            