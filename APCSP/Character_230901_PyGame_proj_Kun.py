# all imports go at the top
import pygame, sys
from pygame.locals import *
import random
from math import pi

# create the screen
pygame.init()
screen = pygame.display.set_mode((800,600))


# Colors the screen white
screen.fill((255,255,255))

# Updates the display
pygame.display.update()

def randcolor():
    return (random.randint(0, 255), random.randint(0, 255), random.randint(0,255))

pygame.draw.polygon(screen, randcolor(), ((50, 0), (350, 0), (350, 300), (50, 300)), 5)

pygame.draw.circle(screen, randcolor(), (90, 40), 20)

pygame.draw.circle(screen, randcolor(), (290, 40), 20)

pygame.draw.circle(screen, randcolor(), (290, 250), 20)

pygame.draw.circle(screen, randcolor(), (80, 270), 20)

pygame.draw.circle(screen, randcolor(), (160, 80), 40, 5)

pygame.draw.circle(screen, randcolor(), (240, 80), 40, 5)

pygame.draw.line(screen, randcolor(), (125,200), (275,200), 10)

pygame.draw.rect(screen, randcolor(), (175, 205, 20, 20), 5)

pygame.draw.rect(screen, randcolor(), (205, 205, 20, 20), 5)

pygame.draw.ellipse(screen, randcolor(), (215, 65, 20, 40))

pygame.draw.ellipse(screen, randcolor(), (165, 65, 20, 40))

pygame.draw.arc(screen, randcolor(), (150, 120, 100, 100), pi / 4, pi / 4 * 3, 20)

pygame.display.update()

while True:
    for event in pygame.event.get() :
         if  (event.type == pygame.QUIT or (event.type==pygame.KEYDOWN and event.key==pygame.K_ESCAPE)):
              pygame.quit(); 
              sys.exit()
            