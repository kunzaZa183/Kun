import pygame, sys
from pygame.locals import *
from Person_231027_proj_Kun import *

# Create a screen that is 800 by 600 pixels
pygame.init()
screen = pygame.display.set_mode((800,600))

# Every 100 milliseconds check if a key is still pressed down
# Allows user to hold down the key to move
pygame.key.set_repeat(100, 100)

# create a person named guy at position (40,40)
guy = Person(40,40)

# A list that keeps track of the areas of screen that have changed
changedRecs=[]

#draw the starting screen
WHITE = (255,255,255)
screen.fill(WHITE)
pygame.display.update()

while True:

    # draw the scene
    screen.fill(WHITE)
    
    guy.draw(screen)
    
    # adds the current position of guy to the areas that have been changed
    changedRecs.append(guy.getRec())    
    
    #update only the changed areas of the screen
    pygame.display.update(changedRecs)

    # check for events
    for event in pygame.event.get():
        if event.type==QUIT or (event.type==KEYDOWN and event.key==K_ESCAPE):
            pygame.quit()
            sys.exit()
            
        elif event.type==KEYDOWN:
            #adds the old position of guy to the areas of guy that have been changed
            changedRecs.append(guy.getRec())
            
            
            # fill in code for the key presses
            # check for which key was pressed and
            # use the person object's methods to
            # move guy in the correct direction
            if event.key==K_UP: 
                guy.moveUp()
            elif event.key==K_DOWN:
                guy.moveDown()
            elif event.key==K_LEFT:
                guy.moveLeft()
            elif event.key==K_RIGHT:
                guy.moveRight()