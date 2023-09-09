import pygame, sys
from pygame.locals import *

pygame.init()
screen = pygame.display.set_mode((800,600))

keys = "Begin"

while True:

    for event in pygame.event.get():
        # Check the event types
        if event.type==QUIT or (event.type==KEYUP and event.key==K_ESCAPE):
            pygame.quit()
            sys.exit()
            
        # If the event is a key up, check which key was pressed
        elif event.type==KEYUP:
            # Print which arrow key was pressed
            if event.key==K_UP: 
                keys = "Up Key"

            elif event.key==K_DOWN:
                keys = "Down Key"

            elif event.key==K_LEFT:
                keys = "Left Key"

            elif event.key==K_RIGHT:
                keys = "Right Key"
            
            elif event.key == K_0:
                keys = "Zero Key"

            elif event.key == K_1:
                keys = "One Key"
            
            elif event.key == K_2:
                keys = "Two Key"
                
    # Draws everything on the screen
    screen.fill((255,255,255))
    
    font = pygame.font.Font(None, 48)
    
    text = font.render(keys, 1, (0, 0, 0))
    
    textpos = text.get_rect()
    textpos.centerx = 400
    textpos.centery = 300
    screen.blit(text, textpos)
    
    pygame.display.update()
