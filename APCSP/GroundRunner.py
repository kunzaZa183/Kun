import pygame, sys
from pygame.locals import *
from Ground import *

pygame.init()
screen = pygame.display.set_mode((800,600))

background = pygame.Surface((800,600))

# Create and draw the ground
draw(background)

# display the background
screen.blit(background,(0,0))

pygame.display.update()


# Event loop that runs until you exit
while True:
    for event in pygame.event.get():
        if event.type==QUIT or (event.type==KEYUP and event.key==K_ESCAPE):
            pygame.quit()
            sys.exit()

