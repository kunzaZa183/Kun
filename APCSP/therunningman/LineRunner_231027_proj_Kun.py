import pygame, sys
from pygame.locals import *
from Hopper_231027_proj_Kun import *
from WallTheRunningMan_231027_proj_Kun import *

# Create a screen that is 800 by 600 pixels
pygame.init()
screen = pygame.display.set_mode((800,600))

# Every 100 milliseconds check if a key is still pressed down
# allows user to hold down the key to move
pygame.key.set_repeat(100, 100)

# create a Hopper named guy at position (50,250)
guy = Hopper(50, 250)

# create a wall at position (500,250)
myWall = Wall(500, 250)

# create a variable to keep track of the wall's x position
wallX = 500

# create a variable to keep track of how fast the wall will move across the screen
wallSpeed = 25

# create a variable that tracks if the game is over
gameEnd = False

# create a variable to keep track of how many walls you jumped over
score = 0

# A list that keeps track of the areas of screen that have changed
changedRecs=[]

# draw the scene
WHITE = (255,255,255)
BLACK = (0,0,0)
screen.fill(WHITE)
pygame.draw.rect(screen, BLACK, (0,300, 800, 300), 0)

pygame.display.update()

# game loop
while True:
    
    # draw the scene
    screen.fill(WHITE)
    pygame.draw.rect(screen, BLACK, (0,300, 800, 300), 0)
    
    
    # If the game is over display "Game Over!
    
    font = pygame.font.Font(None, 36)
    if gameEnd: 
        text = font.render("Game Over!", 1, (10, 10, 10))
        
        
    # If the game is not over display the score
    else:
        text = font.render("Score: " + str(score), 1, (10, 10, 10))
        # move the wall to the left
        wallX -= wallSpeed
        
        
        # If the wall is at the left edge, move it to the right edge
        # Increase the speed that it moves across the screen
        # Increase the score
        if wallX <= 0:
            wallX = 850
            wallSpeed += 5
            score += 1
    
    # draw the text
    textpos = text.get_rect()
    textpos.centerx = 400
    screen.blit(text, textpos)
    changedRecs.append(textpos)
    

    # store the old positions of the moving sprites
    changedRecs.append(guy.getRec())  
    changedRecs.append(myWall.getRec())


    # move the moving sprites
    guy.update()
    myWall.setPos(wallX, 250)

    # store the new positions of the moving sprites
    changedRecs.append(guy.getRec())  
    changedRecs.append(myWall.getRec())

    # draw the moving sprites
    myWall.draw(screen)
    guy.draw(screen)
    
    # update the screen
    pygame.display.update(changedRecs)

    
    # If guy hits the wall, end the game
    if guy.collide(myWall):
        gameEnd = True
    
    # Determine which keys are pressed and move the appropriate direction
    for event in pygame.event.get():
        if event.type==QUIT or (event.type==KEYDOWN and event.key==K_ESCAPE):
            pygame.quit()
            sys.exit()
            
        elif event.type==KEYDOWN:
            if event.key==K_UP: 
                guy.moveUp()

            elif event.key==K_LEFT:
                guy.moveLeft()

            elif event.key==K_RIGHT:
                guy.moveRight()
    
         
    pygame.time.wait(100)