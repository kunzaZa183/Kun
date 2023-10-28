import pygame
from pygame.locals import *

class Person:
    # set all class variables in the constructor
    def __init__(self, newX, newY):
        self.x = newX
        self.y = newY
        self.steps = 10
        self.img = pygame.image.load("dude_231027_proj_Kun.gif")
    
    # draw your image
    def draw(self, window:pygame.Surface):
        window.blit(self.img, (self.x, self.y))
        self.windowx = window.get_width()
        self.windowy = window.get_height()
        
    # move left unless you hit the edge
    def moveLeft(self):
        self.x -= self.steps
        if self.x < 0:
            self.x = 0
    
    # move right unless you hit the edge
    def moveRight(self):
        self.x += self.steps
        if self.x > self.windowx - self.getRec()[2]:
            self.x = self.windowx - self.getRec()[2]
        
    # move up unless you hit the edge
    def moveUp(self):
        self.y -= self.steps
        if self.y < 0:
            self.y = 0
        
    # move down unless you hit the edge
    def moveDown(self):
        self.y += self.steps
        if self.y > self.windowy - self.getRec()[3]:
            self.y = self.windowy - self.getRec()[3]
    
    
    # This will be filled out in 2.ifs_collide_lab. 
    # It will return True if your person has 
    # collided with another object
    def collide(self, other):
        # Get other's x, y, width and height
        
        
        
        # Get person's width and height
        
        
        
        # check if person is to the right of the object
        # if self.x greater than (otherX + otherWidth)
            # person and object do not intersect
        
        
        # else check if the person is to the left of the object
        # elif(self.x + width) less than otherX
            # person and object do not intersect
        
        
        # elif person is above the object
            # person and object do not intersect
        
        
        # elif person is below the object
            # person and object do not intersect
        
        
        # else
            # person and object do intersect
        
        return False

    
    # DO NOT CHANGE THIS
    # This method returns a rectangle - (x, y, width, height) - that represents
    # the object
    def getRec(self):
        myRec = self.img.get_rect()
        return (self.x, self.y, myRec[2], myRec[3])