import pygame, random
from pygame.locals import *
import pygame.locals


# draw the grass and rocks
def draw(window:pygame.Surface):
    # Load grass.gif and rock.gif into variables
    grass = pygame.image.load("grass.gif")
    rock = pygame.image.load("rock.gif")

    # Create variables to keep track of where to
    # draw the grass
    xPos = 0
    yPos = 0
    
    
    
    # Outer loop runs as long as x is 
    # not past the right edge of the screen
    
    # Inner loop runs as long as y is 
    # not past the bottom edge of the screen
        
    # Draws the grass and increases the y
    for i in range(0, 800, 50):
        for j in range(0, 600, 50):
            window.blit(grass, (xPos + i, yPos + j))
    
    for i in range(30):
        window.blit(rock, (random.randint(0, 800 - rock.get_rect().width), random.randint(0, 600 - rock.get_rect().height)))


            
        # Increase the x and reset the y
        
    
    
    # Draw 30 rocks in random x and y positions

