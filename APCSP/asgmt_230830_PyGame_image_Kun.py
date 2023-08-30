# all imports go at the top
import pygame, sys
from pygame.locals import *
from asgmt_230830_graphics_Kun import *

# create the screen
pygame.init()
screen = pygame.display.set_mode((800,600))


# Colors the screen white
screen.fill((255,255,255))


# Calls the method draw scene and sends it the screen to draw on
drawScene(screen)

# Updates the display
pygame.display.update()

while True:
    for event in pygame.event.get() :
         if  (event.type == pygame.QUIT or (event.type==pygame.KEYDOWN and event.key==pygame.K_ESCAPE)):
              pygame.quit()
              sys.exit()
