import pygame
import sys


pygame.init()

screen = pygame.display.set_mode((640,480))

white = (255,255,255)
screen.fill(white)

# make a few colors
black = (0, 0, 0)
blue = (0, 0, 255)
red = (255, 0, 0)
green = (0, 128, 0)

pygame.draw.rect(screen, green, (30,30,50,50),4)
pygame.display.update()

while (True):
    for event in pygame.event.get() :
         if ( event.type == pygame.QUIT or (event.type==pygame.KEYDOWN and event.key==pygame.K_ESCAPE)):
              pygame.quit(); 
              sys.exit()
            