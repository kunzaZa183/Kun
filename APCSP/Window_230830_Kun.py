import pygame
import sys
from math import pi


pygame.init()

screen = pygame.display.set_mode((640,480))

white = (255,255,255)
screen.fill(white)

#draw an 8 pane window

green = (0, 255, 0)

def rect(coordx, coordy, color):
    pygame.draw.rect(screen, color, (coordx, coordy, 50, 50), 5)
    
for i in range(1, 5):
    for j in range(1, 3):
      rect((j - 1) * 45 + 50, (i - 1) * 45 + 70, green)

#use different colors

red = (255, 0, 0)

# update the screen
pygame.display.update()

while (True):
    for event in pygame.event.get() :
         if ( event.type == pygame.QUIT or (event.type==pygame.KEYDOWN and event.key==pygame.K_ESCAPE)):
              pygame.quit() 
              sys.exit()
