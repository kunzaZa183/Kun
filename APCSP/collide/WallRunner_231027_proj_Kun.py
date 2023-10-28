import pygame, sys
from pygame.locals import *
from PersonWall_231027_proj_Kun import *
from Wall_231027_proj_Kun import *

# Creates a screen that is 800 x 600
pygame.init()
screen = pygame.display.set_mode((800,600))

# Every 100 milliseconds check if a key is still pressed down
# Allows user to hold down the key to move
pygame.key.set_repeat(100, 100)

# create a person at position (40,40)
guy = Person(40,40)
theWall = Wall(150,150)

# A list that keeps track of the areas of screen that have changed
changedRecs=[]

#draw the starting screen
WHITE = (255,255,255)
screen.fill(WHITE)
theWall.draw(screen)
pygame.display.update()

while True:
    # draw the scene
    screen.fill(WHITE)
    theWall.draw(screen)
    guy.draw(screen)
    
    # adds the current position of guy to the areas that have been changed
    changedRecs.append(guy.getRec())
    
    #update only the changed areas of the screen
    pygame.display.update(changedRecs)

    # check all events
    for event in pygame.event.get():
        if event.type==QUIT or (event.type==KEYDOWN and event.key==K_ESCAPE):
            pygame.quit()
            sys.exit()
            
        elif event.type==KEYDOWN:
            #add the old position of guy to the areas of guy that have been changed
            changedRecs.append(guy.getRec())
            # move according to the key pressed. If it hits the wall, move the opposite direction
            if event.key==K_UP: 
                guy.moveUp()
                if guy.collide(theWall):
                    guy.moveDown()

            elif event.key==K_DOWN:
                guy.moveDown()
                if guy.collide(theWall):
                    guy.moveUp()

            elif event.key==K_LEFT:
                guy.moveLeft()
                if guy.collide(theWall):
                    guy.moveRight()

            elif event.key==K_RIGHT:
                guy.moveRight()
                if guy.collide(theWall):
                    guy.moveLeft()